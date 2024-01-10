# include "../includes/ft_irc.hpp"


// KICK <channel> <nick> [<reason>]
void msgAllUserInChannel(User const &user, Channel *channel, std::string const &nameKicked, std::string const &reason);

void ircKick(std::string &msg, User &user, Server &server)
{
	Channel *channel;
	std::vector<std::string> msgSplit = splitString(msg, ' ');
	if (msgSplit.size() < 3)
	{
		msgError461(user);
		return ;
	}
	channel = findChanelbyNameMatt(msgSplit[1], server.channels);
	if (channel == NULL)														// on verifie que le channel existe
		msgError403(user, msgSplit[1]);
	if(findElement(user, channel->users) == false)								// on verifie que l'utilisateur est bien dans le channel
		msgError442(user, msgSplit[1]);
	if (checkRightsUserInChannel(channel, &user, OPERATOR) != OPERATOR)			// on verifie que l'utilisateur est bien operateur du channel
		msgError482(user, msgSplit[1]);
	if (findUserByName(channel->users, msgSplit[msgSplit.size() - 1]) != NULL)	//ajout du message de kick s'il n'y en a pas
		msgSplit.push_back(":" + user.nickname);
	for(std::vector<std::string>::iterator it = msgSplit.begin() + 2; it != msgSplit.end() - 1; ++it)	// envoie les messages de kick a tous les users du channel
	{
		try
		{
			User *userKicked = findUserByName(channel->users, *it);
			if(userKicked == NULL)
				msgError441(user, *it, *channel);
			else
			{
				msgAllUserInChannel(user, channel, userKicked->nickname, msgSplit[msgSplit.size() - 1]);
				std::string msgPart;
				msgPart = "PART #" + channel->name + " " + msgSplit[msgSplit.size() - 1] + "\r\n";
				ircPart(msgPart, *userKicked, server, 0);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

// :dan!d@localhost KICK #test alice :nah mate
void msgAllUserInChannel(User const &user, Channel *channel, std::string const &nameKicked, std::string const &reason)
{
	std::stringstream ss;

	for (std::vector<User *>::iterator it = channel->users.begin(); it != channel->users.end(); it++)
	{
		ss << ":" << user.nickname << " KICK #" << channel->name << " " << nameKicked << " " << reason + "\r\n";
		send((*it)->_fdUser, ss.str().c_str(), ss.str().size(), 0);
		ss.str("");
	}
}

// ERR_NOSUCHNICK (401)
// ERR_NOSUCHCHANNEL (403)
// ERR_USERNOTINCHANNEL (441)
// ERR_NOTONCHANNEL (442)
// ERR_BADCHANMASK (476)
// ERR_CHANOPRIVSNEEDED (482)
// DOC 1------------------------------------------------------------------------
// KICK message
//       Commande : KICK
//    Paramètres : <channel> <utilisateur> *( "," <utilisateur> ) [<commentaire>]

// La commande KICK peut être utilisée pour demander le retrait forcé d'un
// utilisateur d'un canal. Elle provoque le retrait forcé de <utilisateur> du
// <canal>. Si aucun commentaire n'est donné, le serveur DEVRA utiliser un message
// par défaut à la place.

// Le serveur NE DOIT PAS envoyer de messages KICK avec plusieurs utilisateurs
// aux clients. Cela est nécessaire pour maintenir la compatibilité descendante
// avec les logiciels clients existants.

// Les serveurs PEUVENT limiter le nombre d'utilisateurs cibles par commande KICK
// via le paramètre TARGMAX de RPL_ISUPPORT, et abandonner silencieusement les
// cibles si le nombre de cibles dépasse la limite.


// DOC 2------------------------------------------------------------------------
// La commande KICK permet à un opérateur de canal de retirer un utilisateur de son canal.

// KICK <canal> <pseudo> [<raison>]
// <canal> : Canal à partir duquel l'utilisateur doit être expulsé.
// <pseudo> : Pseudo de l'utilisateur à expulser.
// <raison> : Une raison facultative à donner à l'utilisateur (et à tout le monde
// dans le canal).

// Certains logiciels serveur permettent de spécifier plusieurs canaux ou
// pseudonymes en les séparant par des virgules (par exemple, KICK #v3 tom,jerry).
// Cependant, ce n'est pas universellement supporté, donc limitez-vous à un canal
// et un pseudo par commande d'expulsion.

// Un message KICK envoyé par le serveur indique qu'une expulsion a eu lieu. Dans
// ce cas, le <préfixe> est l'utilisateur ayant effectué l'expulsion. Si la
// commande KICK d'un utilisateur est réussie, ils reçoivent l'un de ces messages.
// De plus, l'utilisateur expulsé et tous les autres clients du canal reçoivent
// également un message KICK. Par exemple, si dan, alice et matthew sont sur le
// canal #v4, et que dan expulse matthew, les trois clients recevront un message
// KICK indiquant que dan a retiré matthew du canal.

// Il est possible de spécifier plusieurs canaux ou pseudonymes, et les clients
// exécutent les demandes une par une (en ne retournant qu'un canal/pseudo dans
// chaque message KICK qu'ils envoient). Cela est affiché dans les exemples
// ci-dessous.

// La commande KICK est réservée aux opérateurs de canal, parfois avec des niveaux
// de permission alternatifs ajoutés au serveur (tels que le halfop).

// Si l'utilisateur qui effectue l'expulsion n'a pas les autorisations
// appropriées, le serveur renvoie ERR_CHANOPRIVSNEEDED et continue. Si le nom du
// canal est entièrement invalide (ne commence pas par #, etc.), le serveur peut
// renvoyer ERR_BADCHANMASK (ou plus probablement ERR_NOSUCHCHANNEL). Si
// l'utilisateur à expulser n'est pas sur le réseau, l'opérateur du canal envoie
// ERR_NOSUCHNICK. Si l'utilisateur à expulser existe mais n'est pas sur le canal,
// l'opérateur du canal envoie ERR_USERNOTINCHANNEL. Et si le canal n'existe pas,
// ERR_NOSUCHCHANNEL est retourné.


