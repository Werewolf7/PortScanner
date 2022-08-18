#include "../headers/WinSockErrorInfo.h"

void WinSockErrorInfo::PrintToConsoleErrorInfo()
{
    switch (WSAGetLastError())
    {
        case WSANOTINITIALISED:
            std::cout << " Not start WinSock" << std::endl;
            break;
        case WSAENETDOWN:
            std::cout << " NetWork failed" << std::endl;
            break;
        case WSAEADDRINUSE:
            std::cout << " Socket in use " << std::endl;
            break;
        case WSAEINTR:
            std::cout << " Call  WSACancelBlockingCall" << std::endl;
            break;
        case WSAEADDRNOTAVAIL:
            std::cout << " Address not valid " << std::endl;
            break;
        case WSAETIMEDOUT:
            std::cout << " Connection Time Out " << std::endl;
            break;
        case WSAENOTSOCK:
            std::cout << " Not Socket " << std::endl;
            break;
        case WSAECONNREFUSED:
            std::cout << " Reject connection" << std::endl;
            break;
        default:
            std::cout << " Undefined" << std::endl;
            break;
    }
}