# include "../includes/ft_irc.hpp"

void	irc_userhost(std::string &message, User &user, Server &server)
{
	std::cout << "message recu dans IRC_USERHOST |" << message << "|" << std::endl;
	std::string copy = message.substr(9); // j'enleve de USERHOST et l'espace.
	std::string rpl_userhost;

	ssize_t pos = copy.find("\n");
	if (pos == -1)
		std::cout << "probleme de format USERHOST sans \r\n" << std::endl;
	else
		message = copy.substr(0, pos);

	std::vector<User *>::iterator it = server.users.begin();
	std::vector<User *>::iterator ite = server.users.end();
	while (it != ite)
	{
		std::cout << "dans le boucle IRC_USERHOST |" << (*it)->nickname << "|" << message << "|" << std::endl;
		if ((*it)->nickname == message)
		{
			rpl_userhost = "127.0.0.1 302 :"+ message + "[]=+@127.0.0.1\r\n";
			send(user._fdUser, rpl_userhost.c_str(), rpl_userhost.length(), 0);
			printMessageSendToClient("IRC_USERHOST - reponse positive", user, rpl_userhost);
			return;
		}
		++it;
	}
	std::string err_no_such_nick = "127.0.0.1 401 " + message + " :No such nickname\r\n";
	send(user._fdUser, err_no_such_nick.c_str(), err_no_such_nick.length(), 0);
	printMessageSendToClient("IRC_USERHOST - reponse negative", user, err_no_such_nick);
	return;
}
