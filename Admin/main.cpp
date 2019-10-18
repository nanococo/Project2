#include "src/helpers/helpers.h"
#include "src/modules/modules.h"

int main() {
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

    cout << aisles.getNodeByAisleCode(1)->getProductAisleTreePointer()->isProdCodeOnTree(20) << endl;

    while (true){
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
    }


    return 0;

}