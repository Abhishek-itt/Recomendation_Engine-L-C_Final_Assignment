#include <iostream> 
#include <thread>

#include "RequestHandler/SocketServer.h"
#include "RequestHandler/ClientRequestHandler.h"

int main() {
    SocketServer server(8080);

    while(true)
    {
    server.acceptConnection();
        std::thread serverThread([&]() {
            while (true) {
                std::string request = server.receiveMessage();
                std::cout << "Request: " << request << std::endl;
                if (request == "exit") {
                    break;
                }
                if (request == "") {
                    break;
                }
                ClientRequestHandler handler;
                std::string response = handler.HandleRequest(request);
                server.sendMessage(response);
                std::cout << "Response: " << response << std::endl;
            }
        });

        serverThread.detach();
    }
    return 0;
}