#include "../headers/WinSockErrorInfo.h"

void ScanPortsRun()
{
    for (u_short testPort = 2828; testPort < 65535; ++testPort) {

        SOCKET sock;
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (INVALID_SOCKET == sock) {
            std::cout << "INVALID_SOCKET \nStatus code: " << WSAGetLastError();
        } else {
            SOCKADDR_IN socketAddr;
            socketAddr.sin_family = AF_INET;
            socketAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.1");
            socketAddr.sin_port = htons(testPort);
            int size = sizeof(socketAddr);
            sock = connect(sock, (LPSOCKADDR) &socketAddr, size);

            if (sock == SOCKET_ERROR) {
                WinSockErrorInfo::PrintToConsoleErrorInfo();
            } else {
                std::cout << "Port: " << testPort << std::endl;

            }
            closesocket(sock);

            std::cout << "Iteration number: " << testPort;
        }
    }
}

int main() {

    WSADATA wsaData;

    if (FAILED(WSAStartup(MAKEWORD(2, 2), &wsaData)))
    {
        std::cout << "Error init \nStatus code: " << WSAGetLastError();
    }
    else
    {
        ScanPortsRun();
    }
    WSACleanup();
    return 0;
}
