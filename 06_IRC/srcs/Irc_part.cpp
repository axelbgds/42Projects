#include "../includes/ft_irc.hpp"

class Irc_part_error : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class irc_part_rpl : public std::exception
{
	public:
		virtual const char* what() const throw();
};

void ircPart(std::string &strmess, User &user, Server &server, int partOrQuit)
{
	std::string message = strtok((char *)strmess.c_str() + 5, "\r\n");
	std::string chan;
	std::vector<std::string> chann;
	std::string reason;

	if (message.compare(0, 1, "#") == 0)
		message.erase(0, 1);
	else
		errorP461(user);
	if (message.empty())
		errorP461(user);
	if (message.find(" ") != std::string::npos && message.find(",") != std::string::npos) // #lol,#ok,#ok2 :reason
	{
		chan = message.substr(0, message.find(" "));
		message.erase(0, message.find(" ") + 1);
		if (message.find(":") != std::string::npos)
			reason = message.substr(message.find(":") + 1, message.size());
	}
	else if (message.find(" ") != std::string::npos && message.find(",") == std::string::npos) // #lol :reason
	{
		chan = message.substr(0, message.find(" "));
		message.erase(0, message.find(" ") + 1);
		if (message.find(":") != std::string::npos)
			reason = message.substr(message.find(":") + 1, message.size());
	}
	else if (message.find(" ") == std::string::npos && message.find(",") != std::string::npos) // #lol,#ok,#ok2
	{
		chan = message.substr(0, message.size());
		reason = user.nickname + " has left the channel";
	}
	else if (message.find(" ") == std::string::npos && message.find(",") == std::string::npos) // #lol
	{
		chan = message;
		reason = user.nickname + " has left the channel";
	}
	if (chan.find(",") != std::string::npos)
	{
		while (chan.find(",") != std::string::npos)
		{
			chann.push_back(chan.substr(0, chan.find(",")));
			chan.erase(0, chan.find(",") + 1);
			if (chan.compare(0, 1, "#") == 0)
				chan.erase(0, 1);
			else
				errorP461(user);
		}
		chann.push_back(chan);
	}
	else
		chann.push_back(chan);
	sendPartToAllUsersInChannel(chann, user, reason, server, partOrQuit);
}

void sendPartToAllUsersInChannel(std::vector<std::string> &chann, User &user, std::string &reason, Server &server, int partOrQuit)
{
	std::stringstream rpl_part;

	std::vector<std::string>::iterator it = chann.begin();
	for (; it != chann.end(); it++)
	{
		Channel *chan = findChannelByName(server.channels, *it);
		if (chan == NULL)
		{
			errorP403(it, user);
			continue;
		}
		if (findUserInChannel(chan, &user) == false)
		{
			errorP442(chan, user);
			continue;
		}
		std::vector<User *>::iterator cuser = chan->users.begin();
		for (; cuser != chan->users.end(); cuser++)
		{
			if ((*cuser)->_fdUser != user._fdUser || ((*cuser)->_fdUser == user._fdUser && partOrQuit == 0) || (partOrQuit == 1 && (*cuser)->_fdUser != user._fdUser))
			{
				rpl_part << ":" << user.nickname << "!" << user.nickname[0] << "@" << user.nickname << " PART #" << chan->name << " :" << reason << "\r\n";
				send((*cuser)->_fdUser, rpl_part.str().c_str(), rpl_part.str().length(), 0);
				rpl_part.str("");
				if (checkRightsUserInChannel(chan, &user, OPERATOR) == true)
					inheritanceOperator(*chan, user);
				else
					chan->operators.erase(&user);
			}
		}
		chan->deleteUserInChannel(user);
	}
	while (deleteChannelIfEmpty(server))
		;
}

void inheritanceOperator(Channel &chan, User &user)
{
	std::cout << GREEN << ON_BLACK <<  user.nickname << " is leaving the channel " << "#" << chan.name << RESET << std::endl;
	std::map<User *, bool>::iterator it3 = chan.operators.begin();
	for (; it3 != chan.operators.end(); it3++)
	{
		if (it3->first->nickname == user.nickname)
		{
			chan.operators.erase(it3);
			break;
		}
	}
	std::map<User *, bool>::iterator it = chan.operators.begin();
	if (it == chan.operators.end())
		return;
	for (; it != chan.operators.end(); it++)
	{
		if (it->second == true)
			return;
	}
	std::stringstream rpl_oper;
	chan.operators.begin()->second = true;
	std::vector<User *>::iterator it2 = chan.users.begin();
	rpl_oper << ":" << user.nickname << " MODE #" << chan.name << " +o " << chan.operators.begin()->first->nickname << "\r\n";
	std::cout << GREEN << ON_BLACK << "rpl_inheritanceOperator : " << rpl_oper.str() << " Become a canal operator " << "#" << chan.name << RESET << std::endl;
	for (; it2 != chan.users.end(); it2++)
	{
		if ((*it2)->_fdUser != user._fdUser)
		{
			send((*it2)->_fdUser, rpl_oper.str().c_str(), rpl_oper.str().length(), 0);
			rpl_oper.str("");
		}
	}
}



int deleteChannelIfEmpty(Server &server)
{
	for (std::vector<Channel*>::iterator it = server.channels.begin(); it != server.channels.end(); it++)
	{
		std::vector<User *>::iterator it2 = (*it)->users.begin();
		if (it2 == (*it)->users.end())
		{
			delete (*it);
			server.channels.erase(it);
			return 1;
		}
	}
	return 0;
}

void errorP461(User &user)
{
	std::stringstream err_part;

	err_part << IPHOST << " 461 " << user.nickname << " PART :Not enough parameters\r\n";
	send(user._fdUser, err_part.str().c_str(), err_part.str().length(), 0);
	printMessageSendToClient("IRC_PART - err_part", user, err_part.str());
	throw Irc_part_error();
}

void errorP442(Channel *chan, User &user)
{
	std::stringstream err_part;

	std::cout << RED << ON_BLACK << ":You're not on that channel " << chan->name <<  RESET << std::endl;
	err_part << IPHOST << "442 " << user.nickname << " #" << chan->name << " :You're not on that channel\r\n";
	send(user._fdUser, err_part.str().c_str(), err_part.str().length(), 0);
}

void errorP403(std::vector<std::string>::iterator &it, User &user)
{
	std::stringstream err_part;

	std::cout << RED << ON_BLACK <<  ":No such channel " << *it << RESET << std::endl;
	err_part << IPHOST << "403 " << user.nickname << " #" << *it << " :No such channel\r\n";
	send(user._fdUser, err_part.str().c_str(), err_part.str().length(), 0);
}


const char* Irc_part_error::what() const throw()
{
	return ("IRC_PART - error");
}

const char* irc_part_rpl::what() const throw()
{
	return ("IRC_PART - rpl");
}



