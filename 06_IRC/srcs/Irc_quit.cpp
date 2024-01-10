# include "../includes/ft_irc.hpp"

void irc_quit(std::string &message, User &user, Server &server)
{
	std::string mess;
	if (message.size() > 4 && message[4] == ':')
		mess = message.substr(5, message.size());
	else
		mess = message.substr(4, message.size());
	std::string msg;
	if (mess.empty())
		msg = "";
	else
		msg = message;
	std::string rpl_quit = ":" + user.nickname + "-!" + user.nickname[0] + "@" + user.nickname + " QUIT :" + msg + "\r\n";
	partAllChannelUserIsIn(user, server);
	for (std::vector<struct pollfd>::iterator it2 = server.fdP.begin(); it2 != server.fdP.end(); ++it2)
	{
		if ((*it2).fd == user._fdUser)
		{
			close((*it2).fd);
			(*it2).fd = -1;
		}
	}
	server.deleteUserByNick(user.nickname);
}

void partAllChannelUserIsIn(User &user, Server &server)
{
	std::string rpl_part;
	int i = 0;

	rpl_part = "PART #";
	std::vector<Channel *>::iterator it = server.channels.begin();
	for (; it != server.channels.end(); ++it)
	{
		if (findUserInChannel(*it, &user) == true)
		{
			rpl_part += (*it)->name + ",#";
			i++;
		}
	}
	if (i == 1)
	{
		std::vector<Channel *>::iterator it2 = server.channels.begin();
		for (; it2 != server.channels.end(); ++it2)
		{
			if (findUserInChannel(*it2, &user) == true)
			{
				rpl_part = "PART #" + (*it2)->name + "\r\n";
			}
		}
		ircPart(rpl_part, user, server, 1);
	}
	else
	{
		rpl_part.erase(rpl_part.size() - 2, rpl_part.size());
		rpl_part += "\r\n";
		ircPart(rpl_part, user, server, 1);
	}
}


