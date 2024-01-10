#include "../includes/ft_irc.hpp"

void irc_topic(std::string &message, User &user, Server &server)
{

	//std::cout << YELLOW <<  ON_BLACK << "TOPIC : " << message << user.nickname << server.fdNb << RESET << std::endl;

	//trois cas possible :
		// "/TOPIC #test :New topic" = L'utilisateur définit le sujet (le topic n'existait pas, il est remplace)
		// "/TOPIC #test :another topic" = Change le sujet du canal #test en "another topic" (change le topic par un nouveau topic).
		// "/TOPIC #test" =  Vérifie le sujet de #test et l'envoi au user.
	//ATTENTION dans le sujet 42 il est precise qu'il doit y avoir un mode T qui permet ou non le changment de TOPIC par un simple USER

	/////////////// MESSAGE 0 (n'arrive jamais) /////////////////
	if (message[0] == '\0')
	{
		std::string err_need_more_param = ":127.0.0.1 461 " + user.nickname + " TOPIC :Not enough parameters\r\n";
		send(user._fdUser, err_need_more_param.c_str(), err_need_more_param.length(), 0);
		printMessageSendToClient("IRC_TOPIC - err_need_more_param", user, err_need_more_param);
		return;
	} // <- au cas ou le client n'envoie pas le channel (jamais vu)

	///////////////// PARSING /////////////////

	std::string channel;				// <- servira a stocker le nom du chan
	std::string other;					// <-servira de tampon, puis a stocker le reste du message
	other = message.substr(7);			// <- enleve le "TOPIC #"
	// on separe le channel_name du reste en coupant au premier espace
	ssize_t i = other.find(' ');		// <- cherche le premier espace
	channel = other.substr(0, i);		// recupere le mot entre 0 et le 1er espace qui est logique ment le nom du channel
	i = other.find(':');				// je reutilise i et je cherche un : .
	// ssize_t renvoie -1 s'il n'en trouve pas (si j == -1 ca veut dire que nous sommes dans le cas d'une demande de topic (commande "/TOPIC" sans argument))
	if (i == -1)
	{
		std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - ASK" << RESET << std::endl;
		// j'isole le nom du channel sans \r\n ou \n
		i = channel.find("\r\n");
		if (i == -1)
			i = channel.find("\n");
		other = channel.substr(0, i);
		channel = other;

		// maintenant verifions si le channel existe...
		std::vector<Channel*>::iterator it = server.getChannelByName(channel);
		if (it == server.channels.end())
		{
			std::cout << RED <<  ON_BLACK << "[COMMAND]TOPIC - ASK - channel dosn't exist" << RESET << std::endl;
			std::string err_not_valid_name = ":127.0.0.1 403 " + user.nickname + " #" + channel + " :No such channel\r\n";
			send(user._fdUser, err_not_valid_name.c_str(), err_not_valid_name.length(), 0);
			printMessageSendToClient("IRC_TOPIC - err_not_valid_name - 1", user, err_not_valid_name);
			return;
		}
		else
		{
			if (!(*it)->isInChannel(&user) && checkRightsUserInChannel(*it, &user, OPERATOR) == false)
			{
				std::cout << RED <<  ON_BLACK << "[COMMAND]TOPIC - ASK - channel found but user not in it" << RESET << std::endl;
				std::string err_not_valid_name = ":127.0.0.1 442 " + user.nickname + " #" + channel + " :You're not on that channel\r\n";
				send(user._fdUser, err_not_valid_name.c_str(), err_not_valid_name.length(), 0);
				printMessageSendToClient("IRC_TOPIC - err_not_valid_name - 2", user, err_not_valid_name);
				return;
			}
			else
			{
				if ((*it)->topic.empty()) // <- le topic n'a pas ete cree
				{
					std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - ASK - channel found - user found - no topic" << RESET << std::endl;
					std::string err_no_topic = ":127.0.0.1 331 " + user.nickname + " #" + channel + " :No topic is set\r\n";
					send(user._fdUser, err_no_topic.c_str(), err_no_topic.length(), 0);
					printMessageSendToClient("IRC_TOPIC - err_no_topic", user, err_no_topic);
					return;
				}
				else
				{
					std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - ASK - channel found - user found - topic found" << RESET << std::endl;
					std::string rpl_topic = ":127.0.0.1 332 " + user.nickname + " #" + channel + " :" + (*it)->topic + "\r\n";
					send(user._fdUser, rpl_topic.c_str(), rpl_topic.length(), 0);
					printMessageSendToClient("IRC_TOPIC - rpl_topic", user, rpl_topic);
					return;
				}
			}
		}
	}
	else
	{
		std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE" << RESET << std::endl;
		message = other.substr(channel.size() + 2); // je recupere dans message ce qu'il y a apres le nom du channel et le " :" qui le suit
		std::cout << "|" << message << "|" << std::endl;
		// j'isole le message sans \r\n ou \n
		i = message.find("\r\n");
		if (i == -1)
			i = message.find("\n");
		other = message.substr(0, i);
		message = other;
		if (message.size() < 2)
		{
			std::cout << GREEN << ON_BLACK << "[COMMAND]TOPIC - change - no topic is set" << RESET << std::endl;
			std::string err_no_topic = ":127.0.0.1 331 " + user.nickname + " #" + channel + " :No topic is set\r\n";
		}
		// maintenant verifions si le channel existe...
		std::vector<Channel*>::iterator it = server.getChannelByName(channel);
		if (it == server.channels.end())
		{
			std::cout << RED <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel dosn't exist" << RESET << std::endl;
			std::string err_not_valid_name = ":127.0.0.1 403 " + user.nickname + " #" + channel + " :No such channel\r\n";
			send(user._fdUser, err_not_valid_name.c_str(), err_not_valid_name.length(), 0);
			printMessageSendToClient("IRC_TOPIC - err_not_valid_name - 3", user, err_not_valid_name);
			return;
		}
		else
		{
			std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel found" << RESET << std::endl;
			//je verifie que le user est sur le channel
			if (!(*it)->isInChannel(&user) && checkRightsUserInChannel(*it, &user, OPERATOR) == false)
			{
				std::cout << RED <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel found but user not in it" << RESET << std::endl;
				std::string err_not_valid_name = ":127.0.0.1 442 " + user.nickname + " #" + channel + " :You're not on that channel\r\n";
				send(user._fdUser, err_not_valid_name.c_str(), err_not_valid_name.length(), 0);
				printMessageSendToClient("IRC_TOPIC - err_not_valid_name - 4", user, err_not_valid_name);
				return;
			}
			else
			{
				std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel found - user found" << RESET << std::endl;
				//verif du mode T (topic ne peut etre changer que par un operateur)
				if (checkMode(*it, "modeT") == true)
				{
					if (checkRightsUserInChannel(*it, &user, OPERATOR) == false)
					{
						std::cout << RED <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel found - user found but ModeT is on and user not an operator" << RESET << std::endl;
						std::string err_not_op = ":127.0.0.1 482 " + user.nickname + " #" + channel + " :You're not channel operator\r\n";
						send(user._fdUser, err_not_op.c_str(), err_not_op.length(), 0);
						printMessageSendToClient("IRC_TOPIC - err_not_op - 4", user, err_not_op);
						return;
					}
					else
					{
						std::cout << YELLOW <<  ON_BLACK << "[COMMAND]TOPIC - CHANGE - channel found - user found - TOPIC changing" << RESET << std::endl;
						std::cout << "|" << message << "|" << std::endl;
						(*it)->topic = message;
						std::string rpl_topic = ":" + user.nickname + " TOPIC #" + channel + " :" + message + "\r\n";
						(*it)->channelSendLoop(rpl_topic, user._fdUser);
					}
				}
			}
		}
	}
}
