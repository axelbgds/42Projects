#include "../includes/Server.hpp"

Server::Server(const int port, const std::string& password) : _port(port), _password(password.substr(0, password.find('\r')))
{
	this->_initServerSocket();
	fdNb = 0;
	fdP.push_back(pollfd());
	fdP[0].fd = this->_serverSocket;
	fdP[0].events = POLLIN;
	ERROR = false;
}

Server::~Server()
{
	std::cout << GREEN << ON_BLACK << "Server is shutting down..." << RESET << std::endl;
	for (size_t i = 0; i < this->fdP.size(); ++i)
	{
		if (this->fdP[i].fd != this->_serverSocket && this->fdP[i].fd != -1)
			close(this->fdP[i].fd);
	}
	close(this->_serverSocket);
}


void Server::_initServerSocket()
{
	int opt = 1;
	//int addrlen = sizeof(this->_adress);
	if ((this->_serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw std::runtime_error("[ERROR] : can't create a socket, please check your permissions or cpu arch.");
	if (setsockopt(this->_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
		throw std::runtime_error("[ERROR] : can't set options of socket, please check your permissions or cpu arch.");
	int flags = fcntl(this->_serverSocket, F_GETFL, 0);
	if (flags == -1)
		throw std::runtime_error("[ERROR] : can't get socket flags, please check your permissions or cpu arch.");
	if (fcntl(this->_serverSocket, F_SETFL, flags | O_NONBLOCK) == -1)
		throw std::runtime_error("[ERROR] : can't set socket to non-blocking mode, please check your permissions or cpu arch.");
	std::memset(&this->_adress, 0, sizeof(this->_adress));
	this->_adress.sin_family = AF_INET;
	this->_adress.sin_addr.s_addr = inet_addr("127.0.0.1");
	this->_adress.sin_port = htons(this->_port);
	if (bind(this->_serverSocket, (struct sockaddr*)&this->_adress, sizeof(this->_adress)) < 0)
		throw std::runtime_error("[ERROR] : can't get local address information, bind failed, please check your permissions or cpu arch.");
	if (listen(this->_serverSocket, 3) < 0)
		throw std::runtime_error("[ERROR] : can't listen on the address, please check your permissions or cpu arch.");
}

int Server::getServerSocket() const
{
	return (this->_serverSocket);
}

bool Server::haveN(const std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '\n')
			return (true);
	}
	return (false);
}

void Server::resizeBuffer(std::string &buffer)
{
	ssize_t pos = buffer.find("\r\n");
	if (pos == -1)
	{
		 pos = buffer.find("\n");
		 if (pos >= 0)
		 	buffer.resize(pos);
	}
}

void Server::protocolNewUser(int newFd)
{
	char str[BUFFSIZE + 1];
	User *newuser = new User(newFd);
	this->users.push_back(newuser);
	ERROR = false;
	newuser->_forNcProtocol = 1;
	ssize_t byteRead;
	fdP.push_back(pollfd());
	this->fdP[this->fdNb].fd = newFd;
	this->fdP[this->fdNb].events = POLLIN;

	while (1)
	{
		byteRead = read(newFd, str, BUFFSIZE);
		str[byteRead] = '\0';
		std::string buffer(str);
		validateBuffer(buffer, newFd, newuser);
		if (newuser->_forNcProtocol == 5 ||	byteRead == 0)
			break;
	}

	std::string message = newuser->nickname + IPHOST + " 001  Welcome to the Internet Relay Network\n" + newuser->nickname + "!" + newuser->username +"@127.0.0.1\r\n";
	send(newFd, message.c_str(), message.length(), 0);
	std::cout << YELLOW << ON_BLACK << "New user " << newuser->nickname << " succesfully registered with id " << newFd << "." << RESET << std::endl;
}

void Server::validateBuffer(std::string &buffer, int newFd, User *newuser)
{
	if (newuser->_forNcProtocol == 1)
		this->CapProtocol(buffer, newuser);
	else if (newuser->_forNcProtocol == 2)
		this->passProtocol(buffer, newuser);
	else if (newuser->_forNcProtocol == 3)
		this->NickProtocol(newFd, buffer, newuser);
	else if (newuser->_forNcProtocol == 4)
		this->UserProtocol(buffer, newuser);
}

void Server::passProtocol(std::string buffer, User *newUser)
{
	char *token;
	std::string pass;
	token = strtok(&buffer[0] + 5, "\r\n");
	pass = token;

	if (pass[0] == ':')
		pass.erase(0, 1);
	if (buffer.compare(0, 4, "PASS") != 0)
		sendError(newUser->_fdUser, ERRORP421);
	else if (pass.size() == 0)
		sendError(newUser->_fdUser, ERRORP461);
	else if (pass != this->_password)
		sendError(newUser->_fdUser, ERRORP464);
	if (ERROR == true)
	{
		deleteUser(newUser->_fdUser);
		throw NickException();
	}
	std::cout << YELLOW << ON_BLACK << "buffer [pass] ok : " << pass.size() << " " << pass << RESET << std::endl;
	newUser->_forNcProtocol++;
}

void Server::CapProtocol(std::string buffer, User *newUser)
{
	if (buffer.compare(0, 3, "CAP") != 0)
		sendError(newUser->_fdUser, ERRORC421);
	if (ERROR == true)
		throw CapException();
	std::cout << YELLOW << ON_BLACK << "buffer [cap] ok : " << buffer.size() << " " << buffer << RESET << std::endl;
	newUser->_forNcProtocol++;
}

void Server::NickProtocol(int newFd, std::string buffer, User *newUser)
{
	std::string nick;
	nick = strtok(&buffer[0] + 5, "\r\n");

	if (buffer.compare(0, 4, "NICK") != 0)
		sendError(newUser->_fdUser, ERRORN421);
	else if (nick.size() == 0)
		sendError(newUser->_fdUser, ERRORN431);
	else if (this->checkNick(newFd, nick) == 432)
		sendError(newUser->_fdUser, ERRORN432);
	else if (this->checkNick(newFd, nick) == 433)
		sendError(newUser->_fdUser, ERRORN433);
	if (ERROR == true)
	{
		deleteUser(newFd);
		throw NickException();
	}
	std::cout << YELLOW << ON_BLACK << "buffer [nick] ok : " << nick.size() << " " << nick << RESET << std::endl;
	newUser->nickname = nick;
	newUser->_forNcProtocol++;
}

int		Server::checkNick(int & fd, std::string nickname)
{
	const std::string invalidChars = "# :";

	for (size_t i = 0; i < invalidChars.size(); ++i)
	{
		char c = invalidChars[i];
		if (nickname.find(c) != std::string::npos)
			return 432;
	}
	std::vector<User *>::iterator	it = this->users.begin();
	while (it != this->users.end())
	{
		if ((*it)->_fdUser != fd && (*it)->nickname == nickname)
			return 433;
		it++;
	}
	return 0;
}

void Server::UserProtocol(std::string buffer, User *newUser)
{
	std::string uname;
	uname = strtok(&buffer[0] + 5, "\r\n");

	if (buffer.compare(0, 4, "USER") != 0)
		sendError(newUser->_fdUser, ERRORU421);
	else if (uname.size() == 0 || uname.find(':') == std::string::npos)
		sendError(newUser->_fdUser, ERRORU461);
	std::string	username = uname.substr(0, uname.find(' '));
	uname.erase(0, uname.find(' ') + 1);
	if (uname.compare(0, 3, "8 *") && ERROR == false)
		sendError(newUser->_fdUser, ERRORU461);
	uname.erase(0, 5);
	std::string	realname = uname;
	if (ERROR == true)
	{
		deleteUser(newUser->_fdUser);
		throw NickException();
	}
	std::cout << YELLOW << ON_BLACK << "buffer [user] ok : " << uname.size() << " " << uname << RESET << std::endl;
	newUser->username = username;
	newUser->realname = uname;
	newUser->_forNcProtocol++;
}

void Server::sendError(int fd, std::string error)
{
	std::stringstream ERR_error;
	ERR_error << IPHOST << error;
	send(fd, ERR_error.str().c_str(), ERR_error.str().size(), 0);
	ERROR = true;
}

std::vector<User *>::iterator Server::getUser(int fd)
{
	std::vector<User *>::iterator	user = this->users.begin();

	while (user != this->users.end())
	{
		if ((*user)->_fdUser == fd)
			return (user);
		user++;
	}
	return this->users.end();
}

std::vector<Channel *>::iterator	Server::getChannelByName(std::string name)
{
	if (name[0] == '#')
		name = name.substr(1);

	std::vector<Channel *>::iterator	it = this->channels.begin();

	if (it == this->channels.end())
		return this->channels.end();
	while (it != this->channels.end())
	{
		ssize_t i = 0;
		i = (*it)->name.find("\r\n");
		if (i == -1)
			i = (*it)->name.find("\n");
		(*it)->name = (*it)->name.substr(0, i);

		if ((*it)->name.compare(0, (*it)->name.length(), name) == 0)
			return it;
		++it;
	}
	return this->channels.end();
}

void Server::deleteAll()
{
	std::vector<User *>::iterator	user = this->users.begin();

	while (user != this->users.end())
	{
		delete *user;
		user++;
	}
	std::vector<Channel *>::iterator	channel = this->channels.begin();

	while (channel != this->channels.end())
	{
		delete *channel;
		channel++;
	}
	delete this;
}

void Server::deleteUser(int fd)
{
	for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end(); it++)
	{
		if ((*it)->_fdUser == fd)
		{
			delete (*it);
			this->users.erase(it);
			break;
		}
	}
}

void Server::deleteUserByNick(std::string nick)
{
	for (std::vector<User *>::iterator it = users.begin(); it != users.end(); it++)
	{
		if ((*it)->nickname == nick)
		{
			delete (*it);
			users.erase(it);
			break;
		}
	}
}

std::string	Server::reBuildCmd(int & fd, std::string str)
{
	int		rc;
	char	buffer[BUFFSIZE + 1];

	while (this->haveN(str) == false)
	{
		std::cout << "str quand ctrl D : " << str << std::endl;
		rc = recv(fd, buffer, sizeof(buffer), 0);
		buffer[rc] = '\0';
		str += buffer;
	}
	return str;
}

const char* Server::PassException::what() const throw()
{
	return "Error during PASS command";
}


const char* Server::CapException::what() const throw()
{
	return "Error during CAP command";
}

const char* Server::NickException::what() const throw()
{
	return "Error during NICK command";
}

const char* Server::UserException::what() const throw()
{
	return "Error during USER command";
}
