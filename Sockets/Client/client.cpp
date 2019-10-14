#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    cout<<"<---------Client--------->"<<endl;

    //Local Variable
    WSADATA WinSockData;
    int     iWsaStartup;
    int     iWsaCleanup;

    SOCKET  TCPClientSocket;
    int     iCloseSocket;

    struct  sockaddr_in TCPServerAdd{};

    int iConnect;

    int iRecv;
    char RecvBuffer[4096];
    int  iRecvBuffer = sizeof(RecvBuffer)+1;

    int iSend;
    char SendBuffer[4096] = "Hello from client";
    int  iSendBuffer = sizeof(SendBuffer)+1;

    //WSA StatUp
    iWsaStartup = WSAStartup(MAKEWORD(2,2), &WinSockData);

    if(iWsaStartup != 0){
        cout<<"WSAStartup Failed"<<endl;
    }
    cout<<"WSAStartUp success"<<endl;

    //Socket Creation
    TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(TCPClientSocket == INVALID_SOCKET){
        cout<<"Faild socket creation"<<WSAGetLastError()<<endl;
    }
    cout<<"Successful socket creation";

    //Add structure
    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
    TCPServerAdd.sin_port = htons(8000);

    //Conection
    iConnect = connect(TCPClientSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
    if(iConnect == SOCKET_ERROR){
        cout<< "Connection failed"<<endl;
    }
    cout<<"Connection Success"<<endl;

    //Send data
    iSend = send(TCPClientSocket, SendBuffer, iSendBuffer, 0);
    if(iSend == SOCKET_ERROR){
        cout<<"Send failed"<<endl;
    }
    cout<<"Data sent successful"<<endl;

    iRecv = recv(TCPClientSocket, RecvBuffer, iRecvBuffer, 0);
    if(iRecv == SOCKET_ERROR){
        cout<<"No data recived"<<endl;
    }
    cout<<RecvBuffer<<endl;

    //Close socket
    iCloseSocket = closesocket(TCPClientSocket);
    if(iCloseSocket == SOCKET_ERROR){
        cout<<"Socket close error"<<endl;
    }
    cout<<"Socket closed"<<endl;

    //CleanUp
    iWsaCleanup = WSACleanup();



    return 0;
}