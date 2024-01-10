////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                   INVITE                                   //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

# include "../includes/ft_irc.hpp"

//INVITE <nickname> <channel>
void ircInvite(std::string &msg, User &user, Server &server)
{
	std::vector<std::string> msgVec;

	msgVec = splitString(msg, ' ');												// on split le message format : INVITE <nickname> <channel>
	if (msgVec.size() <= 2)
		msgError461(user);
	Channel *channel = findChanelbyNameMatt(msgVec[2], server.channels);
	if (channel == NULL)
	{
		msgError403(user, msgVec[2]);											// on verifie que le channel existe
	}
	User *userInvited = findUserByName(server.users, msgVec[1]);
	if (userInvited == NULL)													// on verifie que l'utilisateur existe
		msgError401(user, msgVec[1]);
	if(!checkMode(channel, "modeI"))											// si le channel est public
	{
		std::cerr << GREEN << ON_BLACK << "le channel n'est pas prive" << RESET << std::endl;
		return ;
	}
 	if (checkRightsUserInChannel(channel, &user, OPERATOR) == false)			//on verifie que l'utilisateur est bien operateur du channel
			msgError482(user, msgVec[2]);
	if (findElement(*userInvited, channel->invitedUsers) == true)				// on verifie que l'utilisateur n'est pas deja invité
		msgError443(user, msgVec[1], *channel);
	channel->invitedUsers.push_back(userInvited);								// on ajoute l'utilisateur a la liste des invites
	std::stringstream ss;
	ss << IPHOST << userInvited->nickname << " " << channel->name << "\r\n";
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
}
