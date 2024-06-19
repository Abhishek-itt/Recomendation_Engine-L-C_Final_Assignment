#include <iostream>

#include "ClientRequestHandler.h"
#include "RequestTypes.h"

int main()
{
    SocketServer server(8888);
    ClientRequestHandler clientRequestHandler;

    server.acceptConnection();
    while (true) {
        std::string request = server.receiveMessage();
        std::cout << "Request: \n" << request << std::endl;
        if (request.empty()) {
            break;
        }
        else
        {
            std::string response = clientRequestHandler.handleClientRequest(request);
            std::cout << "Response: \n" << response << std::endl;
            server.sendMessage(response);
        }
    }
}
