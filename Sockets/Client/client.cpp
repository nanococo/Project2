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

    //Chat con el Server
    while(true){
        recv(TCPClientSocket, RecvBuffer, iRecvBuffer, 0);
        //Esto sirve para ver que va a mandar el mae
        string request;
        cin>>request;

        if(request == "1"){
            //Aqui el mae manda el 1 para que el server lo identifique bien y enteinda que queremos el dato 1
            char sendRequest[4096]="1";
            int sizeOfRequest = sizeof(sendRequest)+1;
            send(TCPClientSocket, sendRequest, sizeOfRequest, 0);

        }
        //Si request == "s" el mae manda una s que el server interpreta como una salida
        //Ahora que lo estoy viendo creo que aqui se puede hacer el break de una lololol
        else if(request == "s"){
            char sendRequest[4096]="s";
            int sizeOfRequest = sizeof(sendRequest)+1;
            send(TCPClientSocket, sendRequest, sizeOfRequest, 0);

        }
        if(RecvBuffer[0]=='s'){
            cout<<"End of connection"<<endl;
            break;
        }

        cout<<RecvBuffer<<endl;
    }

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