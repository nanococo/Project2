#include "src/helpers/helpers.h"
#include "src/modules/modules.h"
#include <winsock2.h>


void clientHandler(SOCKET client, modules &mod, AATree &inventory, clientQueue &clientsQ, BinarySearchTree &aisles, BTreeClients &clients, BTreeAdmins &admins, salesList &sales){
    char sendBuff[512]="hola";
    int s = sizeof(sendBuff);
    send(client, sendBuff, s, 0);
    while(true) {
        char recvBuffer[4096];
        int sizeOfRecv = sizeof(recvBuffer);
        int request = recv(client, recvBuffer, sizeOfRecv, 0);
        int sendToClient;
        cout<<recvBuffer<<endl;
        if (request == SOCKET_ERROR) {
            cout << "No socket detected" << endl;
            break;
        }
        else {
            //Si el mae recibe un '1' en la posicion 0 del char entonces entra aqui
            //Vamos a tener que manejarlo asi
            if (recvBuffer[0] == '1') {

                char data[4096] = "data1";
                int dataSize = sizeof(data) + 1;

                sendToClient = send(client, data, dataSize, 0);
                if (sendToClient == SOCKET_ERROR) {
                    cout << "data sending unsuccessful" << endl;
                }
            } else if (recvBuffer[0] == 's'){
                char data[4096] = "s";
                int dataSize = sizeof(data) + 1;

                send(client, data, dataSize, 0);

                break;
            }
        }
    }
}
void test(){
    cout<<"yes"<<endl;
}
void clientJoiner(SOCKET client, sockaddr_in &TCPClientAdd, int &iTCPClientAdd, modules &mod, AATree &inventory, clientQueue &clientsQ, BinarySearchTree &aisles, BTreeClients &clients, BTreeAdmins &admins, salesList &sales){
    int iListen = listen(client, 5);
    if(iListen == SOCKET_ERROR){
        cout<<"Failed listen"<<endl;
    }
    cout<<"Successful listen"<<endl;

     while(true){
        //Accept request
        SOCKET sAcceptSocket;
        sAcceptSocket = accept(client, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);
        if(sAcceptSocket == INVALID_SOCKET){
            cout<<"Conection failed"<<endl;
        }
        else{

            thread newClient(clientHandler, sAcceptSocket, ref(mod), ref(inventory), ref(clientsQ), ref(aisles), ref(clients), ref(admins), ref(sales));
            newClient.detach();
        }
    }
    thread newThread(test);
    newThread.join();
}

int main() {
    //Socket structure
    BinarySearchTree aisles;
    BTreeClients clients(3);
    BTreeAdmins admins(3);
    AATree inventory;
    initAisleTree(aisles);
    initAislesProductTree(aisles);
    initAislesProductBrandTree(aisles);
    initClients(clients);
    initAdmins(admins);
    initInventory(inventory);

    clientQueue clientsQ;
    salesList sales;
    modules mod;


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
    char SenderBuffer[4096] = "hello from server";
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

    //--------------------------------------

    
//TODO aqui lo intenté xd
   thread joiner (clientJoiner, TCPServerSocket, ref(TCPClientAdd), ref(iTCPClientAdd), ref(mod), ref(inventory), ref(clientsQ), ref(aisles), ref(clients), ref(admins), ref(sales));
   joiner.detach();



    bool isServerBlocked = false;

    while (true){

        try{
            string adminIdString;
            int adminId;
            cout << "Welcome to Krogers Admin Module. Please log in with your id (THIS WILL BLOCK ALL CLIENT ACTION). " << endl;
            cin >> adminIdString;

            adminId = stoi(adminIdString);
            if (admins.search(adminId)!= nullptr){
                isServerBlocked = true; /**THIS BLOCKS SERVER USAGE FOR CLIENTS**/

                string op;
                cout << "Welcome to Krogers Admin Modules. Please choose an option" << endl;
                cout << "1) Insert" << endl;
                cout << "2) Modify" << endl;
                cout << "3) Check values" << endl;
                cout << "4) Billing" << endl;
                cout << "5) Check Gondolas" << endl;
                cout << "6) Check Inventory" << endl;
                cout << "7) Reporting" << endl;
                cin >> op;
                if(op == "1") {
                    mod.insertModule(aisles, clients);
                } else if (op=="2"){
                    mod.modifyModule(aisles, inventory);
                } else if (op=="3"){
                    mod.checkModule(aisles, inventory);
                } else if (op=="4"){
                    mod.billingModule(aisles, clientsQ, clients, inventory, sales);
                } else if (op=="5"){
                    mod.checkGondolas(inventory, sales, aisles);
                } else if (op=="6"){
                    mod.reloadInventory(inventory);
                } else if(op=="7"){
                    mod.reportingModuleMainMenu(aisles, sales, clients, inventory);
                } else {
                    break;
                }
            } else {
                cout << "No admin with given ID found. Please try again. " << endl;
            }

        } catch (std::invalid_argument &e){
            cout << "This is not a valid numeric id. Please try again." << endl;
        }
    }


    return 0;

}

