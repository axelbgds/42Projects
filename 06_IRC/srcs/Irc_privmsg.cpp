# include "../includes/ft_irc.hpp"

// a rajouter a ft_irc.hpp
#define ERROR403 " :No such channel\r\n"
#define ERROR461 " JOIN :Not enough parameters\r\n"
Channel	*findChannelByName(std::vector<Channel *> &channels, std::string const &cmd);

class Irc_privmsg_error : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class Irc_privmsg_rpl : public std::exception
{
	public:
		virtual const char* what() const throw();
};

const char* Irc_privmsg_error::what() const throw()
{
	return "Error during IRC_PRIVMSG command";
}

const char* Irc_privmsg_rpl::what() const throw()
{
	return "RPL during IRC_PRIVMSG command";
}

void	sendSomething(User* it, std::string str, std::string functionName, std::string partOfTheFunction)
{
	send(it->_fdUser, str.c_str(), str.length(), 0);
	std::string str2 = functionName + " - " + partOfTheFunction;
	printMessageSendToClient(str2, *it, str);
}

bool	findUserInServer(Server *server, User *user)
{
	for (std::vector<User *>::iterator it = server->users.begin(); it != server->users.end(); ++it)
	{
		if ((*it)->_fdUser == user->_fdUser)
			return true;
	}
	return false;
}

void irc_Privmsg(std::string &msg, User &user, Server &Server)
{
	ssize_t i = 0;
	msg = msg.substr(8); // Remove the command "PRIVMSG "
	if (msg[0] == '\0')
	{
		msgError("461", user, ERROR461);
		throw Irc_privmsg_error();
	}
	i = msg.find(" :");
	if (i == -1)
	{
		std::cout << RED << ON_BLACK << "Usage: /PRIVMSG destinataire(un ou plusieurs separes par une virgule sans espace) :message (ne pas oublier les :)" << RESET << std::endl;
		throw Irc_privmsg_error();
	}
	std::string messageToSend = msg.substr(i + 2, msg.size());
	std::string rpl_privmsg;
	std::string listOfUser = msg.substr(0, i);
	i = listOfUser.find(',');
	if (i == -1) // un seul user a qui envoye le message
	{
		if (listOfUser[0] == '#')
		{
			Channel *chan = findChannelByName(Server.channels, listOfUser.substr(1, listOfUser.size()));
			if (chan)
			{
				rpl_privmsg = ":" + user.nickname + " PRIVMSG #" + chan->name + " :" + messageToSend;
				if (findUserInChannel(chan, &user) == true)
				{
					for (std::vector<User *>::iterator it2 = chan->users.begin(); it2 != chan->users.end(); it2++)
					{
						if (chan->users.size() == 1) // pour si la personne est seule sur le chan
						{
							sendSomething(&user, "alone", "IRC_PRIVMSG", "irc_privmsg - you're alone in this channel");
							break;
						}
						if ((*it2)->_fdUser != user._fdUser) //pour ne pas l'envoyer a l'expediteur
							sendSomething((*it2), rpl_privmsg, "IRC_PRIVMSG", "irc_privmsg - privmsg sur un chan envoi a tous les users");
					}
				}
				else
				{
					// je previens l'envoyeur que le msg n'est pas parvenu parce que le pseudo n'existe pas
					std::string err_cannot_send_to_chan = "127.0.0.1 404 " + chan->name + " :Cannot send to channel\r\n";
					sendSomething(&user, err_cannot_send_to_chan, "IRC_PRIVMSG", "err le user n'est pas dans le chan avec lequel il souhaite communiquer");
				}
			}
			else // il n'a pas trouve le channel
			{
				std::cout << RED <<  ON_BLACK << "[COMMAND]PRIVMSG - message sur un # mais pas de chan trouve - channel dosn't exist" << RESET << std::endl;
				std::string err_no_such_channel = listOfUser + ERROR403;
				sendSomething(&user, err_no_such_channel, "RC_PRIVMSG", "message sur un # mais pas de chan trouve - channel dosn't exist");
			}
		}
		else // c'est un PRIVMSG a un seul user
		{
			if (findUserInServer(&Server, &user) == true)
			{
				for (std::vector<User *>::iterator it = Server.users.begin(); it != Server.users.end(); it++)
				{
					if (listOfUser == (*it)->nickname)
					{
						//le user existe je lui envoie le msg norme
						rpl_privmsg = ":" + user.nickname + " PRIVMSG " + (*it)->nickname + " :" + messageToSend;
						sendSomething((*it), rpl_privmsg, "IRC_PRIVMSG", "irc_privmsg - section mp vers un seul user");
					}
				}
			}
			else
			{
				// je previens l'envoyeur que le msg n'est pas parvenu parce que le pseudo n'existe pas
				std::string err_no_such_nick = "127.0.0.1 401 " + listOfUser + " :No such nickname\r\n";
				sendSomething(&user, err_no_such_nick, "RC_PRIVMSG", "ERR msg n'est pas parvenu parce que le pseudo n'existe pas");
			}
		}
	}
	else // c'est plusieurs users
	{
		std::string reste;
		std::string destinator;
		while (i != -1)
		{
			reste = listOfUser.substr(i + 1, listOfUser.size());
			destinator = listOfUser.substr(0, i);
			for (std::vector<User *>::iterator it = Server.users.begin(); it != Server.users.end(); it++)
			{
				if (destinator == (*it)->nickname)
				{
					//le destinator existe je lui envoie le msg
					rpl_privmsg = "PRIVMSG " + (*it)->nickname + " :" + messageToSend;
					irc_Privmsg(rpl_privmsg, user, Server);
				}
			}
			if (!listOfUser.find(','))
			{
				std::string err_no_such_nick = "127.0.0.1 401 " + listOfUser + " :No such nickname\r\n";
				sendSomething(&user, err_no_such_nick, "RC_PRIVMSG", "ERR message multiple - msg au dernier user de la lliste - n'est pas parvenu parce que le pseudo n'existe pas");
			}
			listOfUser = reste;
			i = listOfUser.find(',');
		} // je refait le message pour le dernier user
		for (std::vector<User *>::iterator it = Server.users.begin(); it != Server.users.end(); it++)
		{
			if (listOfUser == (*it)->nickname)
			{
				//le user existe je lui envoie le msg
				rpl_privmsg = "PRIVMSG " + (*it)->nickname + " :" + messageToSend;
				irc_Privmsg(rpl_privmsg, user, Server);
			}
			else
			{
				if (!listOfUser.find(','))
				{
					std::string err_no_such_nick = "127.0.0.1 401 " + listOfUser + " :No such nickname\r\n";
					sendSomething(&user, err_no_such_nick, "RC_PRIVMSG", "ERR message multiple - msg au dernier user de la lliste - n'est pas parvenu parce que le pseudo n'existe pas");
				}
			}
		}
	}
	return ;
}
