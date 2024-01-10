#include "../includes/ft_irc.hpp"

void msgError(std::string const &code, User &user, std::string const &msg);
void msgError(std::string const &code, std::string &channel, User &user, std::string const &msg);
void msgErrorTest(std::string &channel, User &user, std::string const &msg);
void msgError696(std::string const &code, User &user, std::string const &msg, Channel *chan, std::string modeLetter);


//-------------------------------Copelien form--------------------------------//
Channel::Channel(User *user, std::string &name)
{
	this->maxUsers = 10;
	this->nbUsers = 1;
	this->name = name;
	this->invitedUsers.push_back(user);
	this->initModeMap();
	this->password = "";
	this->modeLMaxUser = DEFAULTMAXUSER;
}

Channel::Channel(Channel const &src)
{
	*this = src;
}

Channel::~Channel()
{
}

Channel &	Channel::operator=(Channel const &rSym)
{
	if (this != &rSym)
	{
		this->maxUsers = rSym.maxUsers;
		this->nbUsers = rSym.nbUsers;
		this->name = rSym.name;
		this->users = rSym.users;
		this->operators = rSym.operators;
		this->invitedUsers = rSym.invitedUsers;
	}
	return *this;
}
//------------------------------Getter & Setter-------------------------------//
//-------------------------------Other function-------------------------------//

int Channel::addUser(User *user, std::string &password)
{
	if (this->password != "")
	{
		if (this->password.compare(password) == 0)
		{
			std::cout << GREEN << ON_BLACK << "password ok" <<  RESET << std::endl;
			this->users.push_back(user);
			this->operators.insert(std::make_pair(user, false));
			this->nbUsers++;
			return 0;
		}
		else
			return -1;
	}
	else if (findUserInChannel(this, user) == false && this->password == "")
	{
		std::cout << GREEN << ON_BLACK << "it's channel without pass" << RESET << std::endl;
		this->operators.insert(std::make_pair(user, false));
		this->users.push_back(user);
		this->nbUsers++;
		return 0;
	}
	else
		return -1;
}



void Channel::deleteUserInOperator(User *user)
{
	std::map<User *, bool>::iterator it = this->operators.begin();

	while (it != this->operators.end())
	{
		if (it->first == user)
		{
			this->operators.erase(it);
			return;
		}
		it++;
	}
}

bool Channel::ft_checkMode(Channel *channel, std::string mode)
{
	std::map<std::string, bool>::iterator it = channel->modeTab.find(mode);
	if (it != channel->modeTab.end())
	{
		if (it->second == true)
			return true;
	}
	return false;
}

void Channel::ft_insertChanMode(std::string strmess, User &user, Channel &chan)
{
	char symbol;
	std::string tempFor;
	if (!strmess.empty() && (strmess[0] == '+' || strmess[0] == '-'))
		symbol = strmess[0];
	else
	{
		msgError696("686", user, ERRORM696, &chan, "");
		return;
	}
	strmess.erase(0, 1);
	if (!strmess.empty())
	{
		tempFor = strmess;
		for (size_t i = 0; i < tempFor.size(); i++)
		{
			if (tempFor[i] == ' ')
				break;
			else if (tempFor[i] == 't')
				chan.setModeT(symbol, user);
			else if (tempFor[i] == 'b')
				return;
			else if (tempFor[i] == 'i')
				chan.setModeI(symbol, user);
			else if (tempFor[i] == 'l')
				chan.setModeL(symbol, strmess, user);
			else if (tempFor[i] == 'k')
				chan.setModeK(symbol, strmess, user);
			else if (tempFor[i] == 'o')
				chan.setModeO(symbol, strmess, chan, user);
			else if (tempFor[i] == '+' || tempFor[i] == '-')
				symbol = tempFor[i];
			else
				std::cout << "Command is not supported." << std::endl;
		}
	}
	else
		msgError696("686", user, ERRORM696, &chan, "");
}

void Channel::initModeMap()
{
	std::map<std::string, bool> tab;
	tab.insert(std::pair<std::string, bool>("modeT", false));
	tab.insert(std::pair<std::string, bool>("modeO", false));
	tab.insert(std::pair<std::string, bool>("modeL", false));
	tab.insert(std::pair<std::string, bool>("modeK", false));
	tab.insert(std::pair<std::string, bool>("modeI", false));
	this->modeTab = tab;
}

void Channel::setModeI(char c, User &user)
{
	std::map<std::string, bool>::iterator it = this->modeTab.find("modeI");
	std::stringstream ss;
	if (it != modeTab.end())
	{
		if (c == '+')
		{
			it->second = true;
			std::cout << "mode +i added" << std::endl;
			ss << ":" << user.nickname << " MODE #" << this->name << " +i :You set the channel mode to 'invite only'.\r\n";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		}
		else
		{
			it->second = false;
			std::cout << "mode -i removed" << std::endl;
			ss << ":" << user.nickname << " MODE #" << this->name << " -i :You remove the 'invite only' mode from the channel.\r\n";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		}
	}
}

void Channel::setModeK(char symbol, std::string &strmess, User &user)
{
	std::map<std::string, bool>::iterator it = this->modeTab.find("modeK");
	std::string temp;
	std::stringstream ss;

	if (symbol == '-')
	{
		it->second = false;
		this->password = "";
		ss << ":" << user.nickname << " MODE #" << this->name << " -k :" << temp << "\r\n";
		std::cout << "Key removed" << std::endl;
		send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		return;
	}
	else
	{
		if (strmess.find(" ") != std::string::npos)
			strmess.erase(0, (strmess.find(" ") + 1));
		else
		{
			std::cout << "Wrong param mode" << std::endl;
			msgError696("696", user, ERRORM696, this, "");
			return;
		}
		if (!strmess.empty())
		{
			temp = strmess.substr(0, strmess.find(" "));
			for (size_t i = 0; i < temp.size(); i++)
			{
				if (temp[i] == '#' || temp[i] == ',')
				{
					msgErrorTest(this->name, user, ERRORM525);
					std::cout << "Key is not well formed" << std::endl;
					return;
				}
			}
			this->password = temp;
			it->second = true;
		}
		else
		{
			std::cout << "Wrong param mode" << std::endl;
			msgError696("696", user, ERRORM696, this ,"");
			return;
		}
	}
	std::cout << "Mode +k added and password '" << temp << "' is active" << std::endl;
	ss << ":" << user.nickname << " MODE #" << this->name << " +k :" << temp << "\r\n";
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
}

void Channel::setModeL(char symbol, std::string &strmess, User &user)
{
	int resultat;
	std::stringstream ss;
	std::string temp;
	std::map<std::string, bool>::iterator it = this->modeTab.find("modeL");
	if (symbol == '-')
	{
		this->modeLMaxUser = DEFAULTMAXUSER;;
		if (it != modeTab.end())
			it->second = false;
		std::cout << "mode -l correctly removed" << std::endl;
		ss << ":" << user.nickname << " MODE #" << this->name << " -l :You remove the channel limit.\r\n";
		send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		return;
	}
	else if (strmess.find(" ") != std::string::npos)
	{
		strmess.erase(0, (strmess.find(" ") + 1));
		temp = strmess.substr(0, strmess.find(" "));
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (!temp.empty() && !std::isdigit(temp[i]))
			{
				std::cout << "not a number, mode +l cancelled" << std::endl;
				msgError696("696", user, ERRORM696, this, "");
				return;
			}
		}
	}
	try
	{
		resultat = std::atoi(temp.c_str());
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Erreur d'argument invalide : " << e.what() << std::endl;
		return;
	} catch (const std::out_of_range& e)
	{
		std::cerr << "Dépassement de capacité : " << e.what() << std::endl;
		return;
	}
	it->second = true;
	this->modeLMaxUser = resultat;
	std::stringstream ss2;
	ss2 << resultat;
	std::string resultatStr = ss2.str();
	std::cout << "mode +l correctly added with " << this->modeLMaxUser << std::endl;
	ss << ":" << user.nickname << " MODE #" << this->name << " +l " << resultatStr << "\r\n";
	std::cout << ss.str() << std::endl;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
}

void Channel::setModeO(char symbol, std::string &strmess, Channel &chan, User &user)
{
	int err = 0;
	std::stringstream ss;
	std::string nameParse;
	if (strmess.find(" ") == std::string::npos)
		err = 1;
	strmess.erase(0, (strmess.find(" ") + 1));
	if (strmess.size() <= 0 || err == 1)
	{
		msgError696("696", user, ERRORM696, this, "");
		return;
	}
	nameParse = strmess.substr(0, strmess.find(" "));
	User *tempUser = findUserByName(chan.users, nameParse);
	if (tempUser == NULL)
	{
		std::cout << "L'utilisateur n'existe pas" << std::endl;
		msgError("401", user, ERRORI401);
		errorCmd = false;
		return;
	}
	std::map<User*, bool>::iterator it = this->operators.begin();
	it = this->operators.find(tempUser);
	for (; it != this->operators.end(); it++)
	{
		if (it->first->nickname == tempUser->nickname)
			break;
	}
	if (symbol == '-')
	{
		if (it != this->operators.end())
		{
			it->second = false;
			ss << user.nickname << " #" << chan.name << " :You take channel operator privileges from '" << it->first->nickname << "'.\r\n";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
			std::cout << "Operator " << tempUser->nickname << " removed" << std::endl;
			ss.str("");
			ss << tempUser->nickname << " #" << chan.name << " :" << user.nickname << " takes channel operator privileges from you.\n\r";
			send((*it->first)._fdUser, ss.str().c_str(), ss.str().size(), 0);
		}
	}
	else if (symbol == '+')
	{
			it->second = true;
			std::cout << "User "<< nameParse << " is now an operator" << std::endl;
			ss << ":" << user.nickname << " MODE #" << chan.name << " +o " << it->first->nickname << " :\n\r";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
			ss.str("");
			ss << ":" << user.nickname << " MODE #" << chan.name << " +o " << it->first->nickname << " :\n\r";
			send((*tempUser)._fdUser, ss.str().c_str(), ss.str().size(), 0);
	}
	ft_majName(*it->first, chan, 0);
}

void Channel::setModeT(char c, User &user)
{
	std::map<std::string, bool>::iterator it = this->modeTab.find("modeT");
	std::stringstream ss;
	if (it != modeTab.end())
	{
		if (c == '+')
		{
			it->second = true;
			std::cout << " Mode +t successfully added" << std::endl;
			ss << ":" << user.nickname << " MODE #" << this->name << " +t :You switch on 'topic protection'.\r\n";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		}
		else
		{
			it->second = false;
			std::cout << " Mode -t successfully removed" << std::endl;
			ss << ":" << user.nickname << " MODE #" << this->name << " -t :You switch off 'topic protection'.\r\n";
			send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
		}
	}
}

bool Channel::checkModeL()
{
	long unsigned int count = 1;
	std::vector<User*>::iterator it = this->users.begin();
	for (; it != this->users.end(); it++)
	{
		count++;
	}
	if (count < this->modeLMaxUser)
		return true;
	return false;
}

//------------------------------Ostream overload------------------------------//
std::ostream &	operator<<(std::ostream & o, Channel const &rSym)
{
	(void)rSym;
	o << "nothing";
	return o;
}

Channel *findChanelbyNameMatt(std::string name, std::vector<Channel *> &chanelList)
{
	if (name.compare(0, 1, "#") == 0 || name.compare(0, 1, "&") == 0)
		name.erase(0, 1);
	for (std::vector<Channel *>::iterator it = chanelList.begin(); it != chanelList.end(); it++)
	{
		std::cout << (*it)->name << "|";
		if ((*it)->name == name)
			return (*it);
	}
	return NULL;
}

void	Channel::channelSendLoop(std::string message, int & sFd)
{
	std::vector<User *>::iterator	it = this->users.begin();

	while (it != this->users.end())
	{
		if (sFd != (*it)->_fdUser)
		{
			send((*it)->_fdUser, message.c_str(), message.length(), 0);
			printMessageSendToClient("Channel send loop - user", (*(*it)), message);
		}
		it++;
	}
}

bool	Channel::isInChannel(User *user)
{
	if (!user)
		return false;

	std::vector<User *>::iterator		it = this->users.begin();

	while (it != this->users.end())
	{
		if (user == *it)
			return true;
		it++;
	}
	return false;
}

void Channel::deleteUserInChannel(User &user)
{
	std::vector<User *>::iterator		it = this->users.begin();

	while (it != this->users.end())
	{
		if (&user == *it)
		{
			this->users.erase(it);
			this->nbUsers--;
			return;
		}
		it++;
	}
}

User *Channel::getOperator()
{
	std::map<User *, bool>::iterator	it = this->operators.begin();

	while (it != this->operators.end())
	{
		if (it->second == true)
			return it->first;
		it++;
	}
	return NULL;
}

void Channel::getDateTime()
{
	std::time_t rawtime;
	std::tm *timeinfo;
	char buffer[80];
	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(buffer, sizeof(buffer), "%y%m%d%H%M%S", timeinfo);
	std::ostringstream oss;
	oss << buffer;
	this->creationDate = oss.str();
}

bool UserCompare::operator()(User* a, User* b) const
{
	return (a->nickname < b->nickname);
}
