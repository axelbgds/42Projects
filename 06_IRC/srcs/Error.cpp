# include "../includes/ft_irc.hpp"

/// @brief Erreur qui se produit quand l'utilisateur n'existe pas
void msgError401(User const &user, std::string const &userInvited)
{
	std::stringstream ss;
	ss << IPHOST << userInvited << ERRORI401;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI401);
}
/// @brief Erreur qui se produit quand le channel n'existe pas
void msgError403(User const &user, std::string const &channel)
{
	std::stringstream ss;
	ss << IPHOST << channel << ERRORI403;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI403);
}

/// @brief Erreur qui se produit l'utilisateur cible un autre utilisateur qui n'est pas dans le channel
void msgError441(User const &user, std::string const &userInvited, Channel const &channel)
{
	std::stringstream ss;
	ss << IPHOST << userInvited << " " << channel.name << ERRORI441;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI441);
}

/// @brief Erreur qui se produit quand celui qui invite n'est pas dans le channel
void msgError442(User const &user, std::string const &channel)
{
	std::stringstream ss;
	ss << IPHOST << channel << ERRORI442;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI442);
}
/// @brief Returned when a client tries to invite <nick> to a channel they’re already joined to.
void msgError443(User const &user, std::string const &userInvited, Channel const &channel)
{
	std::stringstream ss;
	ss << IPHOST << userInvited << " " << channel.name << ERRORI443;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI443);
}
/// @brief Erreur qui se produit quand il n'y a pas assez de paramètres
void msgError461(User const &user)
{
	std::stringstream ss;
	ss << IPHOST << ERRORI461;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI461);
}
/// @brief Le client ne possède pas les privilèges appropriés pour le canal
void msgError482(User const &user, std::string const &channel)
{
	std::stringstream ss;
	ss << IPHOST << channel << ERRORI482;
	send(user._fdUser, ss.str().c_str(), ss.str().size(), 0);
	errorCmd = true;
	throw std::runtime_error(ERRORI482);
}
