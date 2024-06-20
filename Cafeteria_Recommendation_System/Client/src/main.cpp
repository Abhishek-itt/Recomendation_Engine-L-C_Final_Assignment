#include <iostream>

#include "View/AdminView.h"
#include "Controller/SocketController.h"

int main()
{
    AdminView adminView;
    adminView.adminLoginPage();


 
    return 0;
}

//   // sendBuffer ="1\nFOOD2\n45\n1\ndessc\n";
//             // sendBuffer = "2\n3\n";
//             // sendBuffer = "3\n4\n";
//             // sendBuffer = "4\n";
//             // sendBuffer = "1\nfist\nlast\nuser\n1234\nEmployee\n";
//             // sendBuffer = "6\n5\ndavid_lee\n3\n4\nnot Good Yuck\n";
//             // sendBuffer = "7\n5\n";
            
//             std::cout << "sendBuffer: " << sendBuffer << std::endl;
//             adminController.send(sendBuffer);