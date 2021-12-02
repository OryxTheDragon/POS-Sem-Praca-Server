#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "data.h"

#include <list>
#include <string>

class Server {
public:
    static Server &getInstance() {
        static Server instance;
        return instance;
    }

    Reply registerNewUser(const int socketFD);

    Reply unregisterUser(const int socketFD);

    Reply authorizeUser(const int socketFD);

    Reply deauthorizeUser(const int socketFD);

    Reply getMessage(const int socketFD);

    Reply sendNewMessages(const int socketFD);

private:
    std::list<messageData> unreadMessages;

    Server() {}

    bool checkRegisteredUser(const userData &user, const bool comparePassword = false);

    bool checkAuthorization(const int socketFD);

    void deleteRegisteredUser(const std::string registeredLogin);

    void deleteAuthorizedIP(const std::string authorizedIP);

    std::string getIP(const int socketFD);

    std::string getLoginByAuthorization(const int socketFD);

    void addNewMessage(const messageData &message);

public:
    Server(Server const &) = delete;

    void operator=(Server const &) = delete;
};

#endif //SERVER_SERVER_H
