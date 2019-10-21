#include <iostream>
#include <winsock2.h>
using namespace std;

int main(){
    //Socket structure
    WSADATA WinSockData;
    int     iWsaStartup;
    int     iWsaCleanup;

    SOCKET  TCPClientSocket;
    int     iCloseSocket;

    struct  sockaddr_in TCPServerAdd{};

    int iConnect;

    // mensaje para recivir
    int iRecv;
    char RecvBuffer[4096];
    int  iRecvBuffer = sizeof(RecvBuffer)+1;

    //mensaje para enviar
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
    //----------------------


    //Este va a ser el chat
    while(true){
        string op;
        cout<<"Welcome to the supermarket"<<endl;
        cout << "1) Login" <<endl;
        cout << "2) Unregistered client" << endl;
        cout << "3) Exit"<<endl;
        cin>>op;

        if(op == "1"){
            string id;
            cout<<"Please enter your id"<<endl;
            cin >> id;



            //validacion con el arbol b
            if(true){
                while(true) {
                    string buyingOp;
                    cout << "1. Check info" << endl;
                    cout << "2. Buy" << endl;
                    cout << "3. Search" << endl;
                    cout << "s. back"<<endl;
                    cin >> buyingOp;

                    if (buyingOp == "1") {
                        while(true){
                            string check;
                            cout<<"1. Check a price"<<endl;
                            cout<<"2. Check a basic product"<<endl; //Si es de la canasta basica o no
                            cout<<"3. Chcek tax amount"<<endl;
                            cout<<"s. back"<<endl;
                            cin >> check;

                            if(check == "1"){
                                //check price of a product
                                char caca[4096]="hola";
                                send(TCPClientSocket, caca, sizeof(caca), 0);
                                recv(TCPClientSocket, RecvBuffer, sizeof(RecvBuffer), 0);
                            }
                            else if(check == "2"){
                                //check if a product is basic
                            }
                            else if(check == "3"){
                                //check tax amount
                            }
                            else if (check == "s"){
                                break;
                            }
                        }

                    }
                    else if (buyingOp == "2") {
                        //Buy function;
                    }
                    else if (buyingOp == "3 ") {
                        while(true){
                            string searchOp;

                            cout<<"1. Search brands"<<endl;
                            cout<<"2. Search products"<<endl;
                            cout<<"3. Search aisles"<<endl;
                            cout<<"s. back"<<endl;

                            cin>>searchOp;

                            if(searchOp == "1"){
                                //muestra todas las marcas de un producto
                            }
                            else if(searchOp== "2"){
                                // muestra todos los productos de un pasillo
                            }
                            else if(searchOp == "3"){
                                // muestra todos los pasilos
                            }
                            else if(searchOp == "s"){
                                break;
                            }

                        }
                    }
                    else if (buyingOp == "4"){
                        break;
                    }
                }
            }
            //Si no existe en en arbol b
            else{
                string noBuyOp;
                cout<<"1. Check a price"<<endl;
                cout<<"2. Check a basic product"<<endl; //Si es de la canasta basica o no
                cout<<"3. Chcek tax amount"<<endl;
                cout<<"s. back"<<endl;

                cin>>noBuyOp;
                if(noBuyOp == "1"){
                    //check price of a product
                }
                else if(noBuyOp == "2"){
                    //check if a product is basic
                }
                else if(noBuyOp == "3"){
                    //check tax amount
                }
                else if (noBuyOp == "s"){
                    break;
                }

            }

        }
        else if(op == "s"){
            cout<<"Tanks for buying with us"<<endl;
            break;
        }
    }

    return 0;
}