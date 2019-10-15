#include "src/helpers/helpers.h"

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

    //isles.fullInOrder();

//    ClientData found = clients.searchClient(1234567);
//    cout << found.getName() << endl;


    return 0;

}