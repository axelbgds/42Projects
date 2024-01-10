#pragma once

# include "ft_irc.hpp"

class Channel;

class Server
{
	private:

		void							_initServerSocket();
		int								_serverSocket;
		struct sockaddr_in				_adress;
		const int						_port;
		std::string						_password;

	public:

		std::vector<struct pollfd>		fdP;
		std::vector<User*>				users;
		std::vector<Channel*>			channels;
		int								fdNb;
		bool							ERROR;

		Server(const int port, const std::string& password);
		~Server();


		int								getServerSocket() const;
		std::vector<User *>::iterator	getUser(int fd);


		bool haveN(const std::string& str);
		void protocolNewUser(int newFd);
		void passProtocol(std::string buffer, User *newuser);
		void CapProtocol(std::string buffer, User *newuser);
		void NickProtocol(int newFd, std::string buffer, User *newuser);
		void UserProtocol(std::string buffer, User *newuser);
		int checkNick(int & fd, std::string nickname);
		void sendError(int fd, std::string error);
		void resizeBuffer(std::string &buffer);
		void deleteUser(int fd);
		void validateBuffer(std::string &buffer, int newFd, User *newuser);
		std::vector<Channel *>::iterator	getChannelByName(std::string name);
		void deleteAll();
		std::string	reBuildCmd(int & fd, std::string str);
		void	deleteUserByNick(std::string nick);


		class PassException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class UserException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NickException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class CapException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};
