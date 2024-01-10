
#pragma once

#include "ft_irc.hpp"
#include <map>
#include <cctype>
#include <iostream>
#include <string>

extern bool errorCmd;

struct UserCompare
{
	bool operator()(User *a,User *b) const;
};


class Channel
{
//-----------------------------------Public-----------------------------------//
	public:
//-------------------------------Copelien form--------------------------------//
		Channel(User *user, std::string &cmd);
		Channel(Channel const &src);
		~Channel();
		Channel &	operator=(Channel const &rSym);
		/// @brief map of mode soit "modeI", "modeK", "modeL", "modeO", "modeT"
		std::map<std::string, bool> modeTab;
		void (Channel::*ftPtr[5])(User &user);
		long unsigned int modeLMaxUser;
		int						maxUsers;
		int						nbUsers;
		std::string				name;
		std::string				topic;
		std::string				creationDate;
		std::string				password;
		std::vector<User *>		users;
		std::map<User *, bool, UserCompare>		operators;
		std::vector<User *>		invitedUsers;

		void	channelSendLoop(std::string message, int & sFd);
		bool	isInChannel(User *user);
//-----------------------------Operators overload-----------------------------//
//------------------------------Getter & Setter-------------------------------//



//-------------------------------Other function-------------------------------//

		int addUser(User *user, std::string &cmd);
		void deleteUserInChannel(User &user);
		void ft_insertChanMode(std::string strmess, User &user, Channel &chan);
		bool ft_checkMode(Channel *channel, std::string mode); // exemple de string : "modeI", "modeL" etc...
		void initModeMap();
		bool checkModeL();
		void setModeO(char symbol, std::string &strmess, Channel &chan, User &user);
		void setModeK(char symbol, std::string &strmess, User &user);
		void setModeL(char symbol, std::string &strmess, User &user);
		void setModeT(char c, User &user);
		void setModeI(char c, User &user);
		void deleteUserInOperator(User *user);
		User *getOperator();
		void getDateTime();
		void getCreationDateTimeString();

		/// @brief
		/// @param nameMode soit "modeI", "modeK", "modeL", "modeO", "modeT"
		/// @return
		bool checkRights(std::string &nameMode)
		{
			return (modeTab[nameMode]);
		}

//----------------------------------Exeption----------------------------------//
		class UserIsAlredyInChannelException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("User is already in channel");
				};
		};
//----------------------------------Private-----------------------------------//
	private:
		Channel(){}; // default constructor
};

//------------------------------Ostream overload------------------------------//

std::ostream &	operator<<(std::ostream & o, Channel const &rSym);

//-------------------------------Other function-------------------------------//

Channel *findChanelbyNameMatt(std::string name, std::vector<Channel *> &chanelList);


