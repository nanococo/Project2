#include <iostream>
#include <winsock2.h>
#include <cstring>
using namespace std;

int main()
{
    cout<< "<-------TCP server------>"<<endl;
    cout<<endl;

    WSADATA  WinsockData;
    int      iWsaStartup;
    int      iWsaCleanup;

    SOCKET TCPServerSocket;
    int    iCloseSocket;

    struct sockaddr_in TCPServerAdd{};
    struct sockaddr_in TCPClientAdd{};
    int iTCPClientAdd = sizeof(TCPClientAdd);

    int iBind;
    int iListen;

    SOCKET sAcceptSocket;

    int iSend;
    // Aqui esta el mensaje default
    char SenderBuffer[4096] = "Holis del server";
    int iSenderBuffer = sizeof(SenderBuffer)+1;

    int  iRecv;
    char RecvBuffer[4096];
    int  iRecvBuffer = sizeof(RecvBuffer)+1;

    iWsaStartup = WSAStartup(MAKEWORD(2,2), &WinsockData);

    if(iWsaStartup != 0){
        cout<<"WSAStartup Failed"<<endl;
    }
    cout<<"WSAStartUp success"<<endl;

    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
    TCPServerAdd.sin_port = htons(8000);

    //Socket creation
    TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(TCPServerSocket == INVALID_SOCKET){
        cout<<"Faild socket creation"<<WSAGetLastError()<<endl;
    }
    cout<<"Successful socket creation";

    //Bind
    iBind = bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
    if(iBind == SOCKET_ERROR){
        cout<<"Failed bind"<<endl;
    }
    cout<<"Successful bind"<<endl;

    //Listen
    iListen = listen(TCPServerSocket, 5);
    if(iListen == SOCKET_ERROR){
        cout<<"Failed listen"<<endl;
    }
    cout<<"Successful listen"<<endl;

    //Accept request
    sAcceptSocket = accept(TCPServerSocket, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);
    if(sAcceptSocket == INVALID_SOCKET){
        cout<<"Conection failed"<<endl;
    }
    cout<<"Conection accepted"<<endl;

    //Aqui el mae recibe el request
    iRecv = recv(sAcceptSocket, RecvBuffer, iRecvBuffer, 0);
    if(RecvBuffer == "1"){

        //Aqui el mae tendria que re-definir las varas para que mande lo que quiere

        //Se hace un if por cada request


        iSend = send(sAcceptSocket, SenderBuffer, iSenderBuffer, 0);
        if(iSend == SOCKET_ERROR){
            cout<<"Send failed"<<endl;
        }
        cout<<"Data sent successful"<<endl;
    }
    else if(iRecv == SOCKET_ERROR){
        cout<<"No data recived"<<endl;
    }
    cout<<RecvBuffer<<endl;

    //Close socket
    iCloseSocket = closesocket(TCPServerSocket);
    if(iCloseSocket == SOCKET_ERROR){
        cout<<"Socket close error"<<endl;
    }
    cout<<"Socket closed"<<endl;

    //CleanUp
    iWsaCleanup = WSACleanup();


    return 0;
}