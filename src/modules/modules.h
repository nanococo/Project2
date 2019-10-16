#pragma once

#include "../TreesHandlers/BinarySearchTree.h"
#include "../TreesHandlers/BTreeClients.h"
#include "../helpers/clientQueue.h"
#include "../helpers/quickSortHelper.h"
#include "../helpers/salesList.h"

using namespace std;
class modules {
public:
    static void insertModule(BinarySearchTree &aisles, BTreeClients &clients);
    static void checkModule(BinarySearchTree &aisles, AATree &inventory);
    void billingModule(BinarySearchTree &aisles, clientQueue &clientsQ, BTreeClients &clients, AATree &inventory, salesList &sales);
    void modifyModule(BinarySearchTree &aisles, AATree &inventory);

private:
    float basicProd = 0.01;
    float nonBasicProd = 0.13;
};


void modules::insertModule(BinarySearchTree &aisles, BTreeClients &clients) {
    string op;
    while (true){
        cout << "Welcome to Insert menu. Please choose an option" << endl;
        cout << "1) Insert Aisle" << endl;
        cout << "2) Insert Product" << endl;
        cout << "3) Insert Brand" << endl;
        cout << "4) Insert Client" << endl;
        cout << "5) Exit" << endl;
        cin >> op;
        if (op=="1"){
            try{
                string name;
                string aisleCodeString;
                int aisleCode;

                cout << "You have chosen to insert new Aisle." << endl;
                cout << "Type new Aisle code (numbers): " << endl;
                cin >> aisleCodeString;
                aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                cout << "Type new Aisle name: " << endl;
                cin >> name;

                if(!aisles.isAisleCodeInTree(aisleCode)){
                    aisles.insert(new BSNode(aisleCode, name));
                } else {
                    cout << "ERROR: Aisle code is already present on tree. Try Again." << endl;
                }

            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }

        } else if (op=="2"){
            try{
                string name;
                string aisleCodeString;
                string prodCodeString;
                int aisleCode;
                int prodCode;

                cout << "You have chosen to insert new Product" << endl;
                cout << "Type Aisle code where to insert: " << endl;
                cin >> aisleCodeString;
                aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                cout << "Type new prod code to insert: " << endl;
                cin >> prodCodeString;
                prodCode = stoi(prodCodeString); //Throws invalid_argument

                cout << "Type new Aisle name: " << endl;
                cin >> name;

                if(aisles.isAisleCodeInTree(aisleCode)){
                    auto *bsNode = aisles.getNodeByAisleCode(aisleCode);
                    if(!bsNode->getProductAisleTreePointer()->isProdCodeOnTree(prodCode)){
                        bsNode->getProductAisleTreePointer()->insert(bsNode->getProductAisleTreePointer()->getAVLRoot(), prodCode, name);
                    } else {
                        cout << "ERROR: Prod code is already present on tree. Try Again." << endl;
                    }
                } else {
                    cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
                }
            } catch (std::invalid_argument& e) {
                cout << "Value is not numeric. Please try again" << endl;
            }

        } else if (op=="3"){
            try{
                string name;
                string aisleCodeString;
                string prodCodeString;
                string brandCodeString;
                string amountString;
                string priceString;
                int aisleCode;
                int prodCode;
                int brandCode;
                int amount;
                int price;

                cout << "You have chosen to insert new Product" << endl;
                cout << "Type Aisle code where to insert: " << endl;
                cin >> aisleCodeString;
                aisleCode = stoi(aisleCodeString); //Throws invalid_argument

                cout << "Type Prod code where to insert: " << endl;
                cin >> prodCodeString;
                prodCode = stoi(prodCodeString); //Throws invalid_argument

                cout << "Type new Brand code where to insert: " << endl;
                cin >> brandCodeString;
                brandCode = stoi(brandCodeString); //Throws invalid_argument

                cout << "Type new Aisle name: " << endl;
                cin >> name;

                cout << "Type Amount: " << endl;
                cin >> amountString;
                amount = stoi(amountString); //Throws invalid_argument

                cout << "Type Price: " << endl;
                cin >> priceString;
                price = stoi(priceString); //Throws invalid_argument


                if(aisles.isAisleCodeInTree(aisleCode)){
                    auto *bsNode = aisles.getNodeByAisleCode(aisleCode);
                    if(bsNode->getProductAisleTreePointer()->isProdCodeOnTree(prodCode)){
                        auto *avlNode = bsNode->getProductAisleTreePointer()->getNodeByProdCode(prodCode);
                        if(!avlNode->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)){
                            avlNode->getProductAisleBrandTreePointer()->insert(brandCode, name, amount, price);
                        } else {
                            cout << "ERROR: Brand code is already present on tree. Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: No Prod code present on tree. Try Again." << endl;
                    }
                } else {
                    cout << "ERROR: No Aisle code present on tree. Try Again." << endl;
                }
            } catch (std::invalid_argument& e) {
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op=="4"){
            try {
                string clientIdString;
                string name;
                string phoneNumber;
                string email;
                string cityCode;
                int clientId;


                cout << "You have chosen to insert Client." << endl;
                cout << "Type your id (Numeric): " << endl;
                cin >> clientIdString;
                clientId = stoi(clientIdString);

                cout << "Type new Client name: " << endl;
                cin >> name;
                cout << "Type new Client email: " << endl;
                cin >> email;
                cout << "Type new Client city code: " << endl;
                cin >> cityCode;
                cout << "Type new Client phone Number: " << endl;
                cin >> phoneNumber;

                if(clients.search(clientId) == nullptr){
                    clients.insert(clientId, ClientData(name, cityCode, phoneNumber, email));
                } else {
                    cout << "ERROR: Client id present on tree. Try Again." << endl;
                }


            }catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }

        } else if (op=="5"){
            break;
        }
    }
}
void modules::modifyModule(BinarySearchTree &aisles, AATree &inventory) {
    string op;
    while (true){
        cout << "Welcome to modify menu. Please choose an option." << endl;
        cout << "1) Modify Price" << endl;
        cout << "2) Modify Tax %" << endl;
        cout << "3) Modify Product status (Basic or Normal)" << endl;
        cout << "4) Exit" << endl;

        cin >> op;

        if(op=="1"){
            try {
                cout << "Please select an aisle (numeric code): " << endl;

                //Prints aisles
                aisles.printAisleForPurchase();

                string chosenAisleString;
                int chosenAisle;
                cin >> chosenAisleString;
                chosenAisle = stoi(chosenAisleString);

                if (aisles.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                        cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                        selectedAisle->getProductAisleTreePointer()->printProductsForPurchase(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                        string chosenProdString;
                        int chosenProd;
                        cin >> chosenAisleString;
                        chosenProd = stoi(chosenAisleString);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenAisle)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                string brandCodeString;
                                int brandCode;

                                cin >> brandCodeString;
                                brandCode = stoi(brandCodeString);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                    auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                    cout << "Please type new price (numbers):" << endl;
                                    int newPrice = 0;
                                    cin >> newPrice;

                                    selectedBrand->setPrice(newPrice);

                                    cout << "Price successfully changed. " << endl;

                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op=="2"){
            try {
                while (true){
                    string taxOp;
                    cout << "Please select which tax you'd like to modify: " << endl;
                    cout << "1) Basic Product Tax" << endl;
                    cout << "2) Normal Product Tax" << endl;
                    cout << "3) Return" << endl;

                    cin >> taxOp;

                    if(taxOp=="1"){
                        string newTaxValString;
                        cout << "Please type new tax value in decimals: " << endl;
                        cin >> newTaxValString;
                        this->basicProd = stof(newTaxValString);
                    } else if (taxOp=="2"){
                        string newTaxValString;
                        cout << "Please type new tax value in decimals: " << endl;
                        cin >> newTaxValString;
                        this->nonBasicProd = stof(newTaxValString);
                    } else if (taxOp=="3"){
                        break;
                    }
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op=="3"){
            try {
                cout << "Please select an aisle (numeric code): " << endl;

                //Prints aisles
                aisles.printAisleForPurchase();

                string chosenAisleString;
                int chosenAisle;
                cin >> chosenAisleString;
                chosenAisle = stoi(chosenAisleString);

                if (aisles.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                        cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                        selectedAisle->getProductAisleTreePointer()->printProductsForPurchase(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                        string chosenProdString;
                        int chosenProd;
                        cin >> chosenAisleString;
                        chosenProd = stoi(chosenAisleString);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenAisle)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                string brandCodeString;
                                int brandCode;

                                cin >> brandCodeString;
                                brandCode = stoi(brandCodeString);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {

                                    string checkInventoryCode = chosenAisleString;
                                    checkInventoryCode.append(chosenProdString);
                                    checkInventoryCode.append(brandCodeString);

                                    if(inventory.isDataPresent(checkInventoryCode)){
                                        cout << "Please type if is basic prod (Y/N): " << endl;
                                        bool isBasic;
                                        string isBasicString;
                                        cin >> isBasicString;

                                        while(true){
                                            if(isBasicString=="Y" || isBasicString=="y"){
                                                isBasic = true;
                                                break;
                                            } else if (isBasicString=="N" || isBasicString=="n"){
                                                isBasic = false;
                                                break;
                                            } else {
                                                cout << "That is not an accepted value. Please try again." << endl;
                                            }
                                        }
                                        inventory.getNodeByAisleProdBrandCode(checkInventoryCode)->setIsBasicProd(isBasic);
                                        cout << "Successfully modified to status of: " << isBasic << endl;
                                    } else {
                                        cout << "ERROR: No such element on inventory on system. Please Try Again." << endl;
                                    }
                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op=="4") {
            break;
        }
    }
}
void modules::checkModule(BinarySearchTree &aisles, AATree &inventory) {
    string op;

    while (true){
        cout << "Welcome to check modules. Please choose an option: " << endl;
        cout << "1) Check Price" << endl;
        cout << "2) Check product tax" << endl;
        cout << "3) Check product price" << endl;
        cout << "4) Exit" << endl;

        cin >> op;

        if(op=="1"){
            try {
                cout << "Please select an aisle (numeric code): " << endl;

                //Prints aisles
                aisles.printAisleForPurchase();

                string chosenAisleString;
                int chosenAisle;
                cin >> chosenAisleString;
                chosenAisle = stoi(chosenAisleString);

                if (aisles.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                        cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                        selectedAisle->getProductAisleTreePointer()->printProductsForPurchase(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                        string chosenProdString;
                        int chosenProd;
                        cin >> chosenAisleString;
                        chosenProd = stoi(chosenAisleString);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenAisle)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                string brandCodeString;
                                int brandCode;

                                cin >> brandCodeString;
                                brandCode = stoi(brandCodeString);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                    auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                    cout << "Price: " << selectedBrand->getPrice() << endl;

                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if (op=="2"){
            try {
                cout << "Please select an aisle (numeric code): " << endl;

                //Prints aisles
                aisles.printAisleForPurchase();

                string chosenAisleString;
                int chosenAisle;
                cin >> chosenAisleString;
                chosenAisle = stoi(chosenAisleString);

                if (aisles.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                        cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                        selectedAisle->getProductAisleTreePointer()->printProductsForPurchase(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                        string chosenProdString;
                        int chosenProd;
                        cin >> chosenAisleString;
                        chosenProd = stoi(chosenAisleString);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenAisle)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                string brandCodeString;
                                int brandCode;

                                cin >> brandCodeString;
                                brandCode = stoi(brandCodeString);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                    auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);
                                    cout << "Product Price: " << selectedBrand->getPrice() << endl;

                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op == "3"){
            try {
                cout << "Please select an aisle (numeric code): " << endl;

                //Prints aisles
                aisles.printAisleForPurchase();

                string chosenAisleString;
                int chosenAisle;
                cin >> chosenAisleString;
                chosenAisle = stoi(chosenAisleString);

                if (aisles.isAisleCodeInTree(chosenAisle)) {
                    auto *selectedAisle = aisles.getNodeByAisleCode(chosenAisle);

                    if (selectedAisle->getProductAisleTreePointer() != nullptr) {
                        cout << "Please select a product for aisle (numeric code): " << selectedAisle->getName() << endl;

                        selectedAisle->getProductAisleTreePointer()->printProductsForPurchase(selectedAisle->getProductAisleTreePointer()->getAVLRoot());

                        string chosenProdString;
                        int chosenProd;
                        cin >> chosenAisleString;
                        chosenProd = stoi(chosenAisleString);

                        if (selectedAisle->getProductAisleTreePointer()->isProdCodeOnTree(chosenAisle)) {
                            auto *selectedProd = selectedAisle->getProductAisleTreePointer()->getNodeByProdCode(chosenProd);

                            if (selectedProd->getProductAisleBrandTreePointer() != nullptr) {
                                cout << "Please select a brand for product (numeric code): " << selectedProd->getName() << endl;

                                selectedProd->getProductAisleBrandTreePointer()->printBrandsForPurchase();

                                string brandCodeString;
                                int brandCode;

                                cin >> brandCodeString;
                                brandCode = stoi(brandCodeString);

                                if (selectedProd->getProductAisleBrandTreePointer()->isBrandCodeOnList(brandCode)) {
                                    auto *selectedBrand = selectedProd->getProductAisleBrandTreePointer()->getNodeByBrandCode(brandCode);

                                    cout << "Price: " << selectedBrand->getPrice() << endl;

                                } else {
                                    cout << "ERROR: No such brand on system. Please Try Again." << endl;
                                }
                            } else {
                                cout << "ERROR: There are no Brands associated to given Aisle" << endl;
                            }
                        } else {
                            cout << "ERROR: No such product on system. Please Try Again." << endl;
                        }
                    } else {
                        cout << "ERROR: There are no Products associated to given Aisle" << endl;
                    }
                } else {
                    cout << "ERROR: No such aisle on system. Please Try Again." << endl;
                }
            } catch (std::invalid_argument& e){
                cout << "Value is not numeric. Please try again" << endl;
            }
        } else if(op=="4"){
            break;
        }
    }
}

void modules::billingModule(BinarySearchTree &aisles, clientQueue &clientsQ, BTreeClients &clients, AATree &inventory, salesList &sales) {

    bool billingMenuExit = false;
    string aisleCode;
    string prodCode;
    string brandCode;
    int amount;
    struct Node *a = nullptr;
    string clientId;
    string clientName;
    string clientPhone;
    string clientEmail;

    while (!billingMenuExit){
        try {
            cout << "Welcome to billing menu. Please select an option: " << endl;
            cout << "1) Bill first client in line" << endl;
            cout << "2) Return" << endl;

            string op;
            cin >> op;

            if(op=="1"){

                if(!clientsQ.isEmpty()){
                    clientQueueNode *firstInLine = clientsQ.getLastElement();
                    //clientNode *currentClient = clients.getClientByClientId(firstInLine->getClientId());
                    ClientData currentClient = clients.searchClient(stoi(firstInLine->getClientId()));
                    cout << "Currently billing: " << currentClient.getName() << endl;
                    clientId = firstInLine->getClientId();
                    clientName = currentClient.getName();
                    clientPhone = currentClient.getPhoneNumber();
                    clientEmail = currentClient.getEmail();

                    //PERFORM QUICK SORT ON ITEMS
                    while (firstInLine->getFirstClientProd()!= nullptr){

                        clientProductStackNode *cartProducts = firstInLine->getFirstClientProd();

                        //Deletes tops element of stack
                        if(cartProducts->getNextNode() == nullptr){
                            aisleCode = cartProducts->getAisleCode();
                            prodCode = cartProducts->getProdCode();
                            brandCode = cartProducts->getBrandCode();
                            amount = cartProducts->getAmount();
                            push(&a, amount, aisleCode, prodCode, brandCode);
                            firstInLine->setFirstClientProd(nullptr);
                            delete cartProducts;

                        } else {
                            while (cartProducts->getNextNode()->getNextNode() != nullptr){
                                cartProducts = cartProducts->getNextNode();
                            }
                            aisleCode = cartProducts->getNextNode()->getAisleCode();
                            prodCode = cartProducts->getNextNode()->getProdCode();
                            brandCode = cartProducts->getNextNode()->getBrandCode();
                            amount = cartProducts->getNextNode()->getAmount();
                            push(&a, amount, aisleCode, prodCode, brandCode);
                            clientProductStackNode *temp = cartProducts->getNextNode();
                            cartProducts->setNextNode(nullptr);
                            delete temp;
                        }

                    }
                    //Actual quicksort excution
                    quickSort(&a);

                    struct Node *tmp = a;

                    //Billing loop
                    float finalPrice = 0;
                    float priceWithTax = 0;
                    int productPrice = 0;
                    float taxRate;

                    //Outfile prep work
                    ofstream outfile ("../bills/"+clientId+"_Bill.txt");
                    outfile << "Client ID: " << clientId << endl;
                    outfile << "Name: " << clientName << endl;
                    outfile << "Phone Number: " << clientPhone << endl;
                    outfile << "Email: " << clientEmail << endl;
                    outfile << endl;


                    while (tmp!=nullptr){

                        productPrice = aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getProductAisleBrandTreePointer()->getNodeByBrandCode(stoi(tmp->brandCode))->getPrice();
                        //productPrice = aisleList.getNodeByAisleCode(tmp->aisleCode)->getProductAisleListPointer()->getNodeByProdCode(tmp->prodCode)->getAisleProductBrandListPointer()->getNodeByBrandCode(tmp->brandCode)->getPrice();
                        if(inventory.isBasicProduct(tmp->aisleCode+tmp->prodCode+tmp->brandCode)){
                            priceWithTax = ((float)productPrice*this->basicProd)+(float)productPrice;
                            finalPrice += priceWithTax;
                        } else {
                            priceWithTax = ((float)productPrice*this->nonBasicProd)+(float)productPrice;
                            finalPrice += priceWithTax;
                        }


                        //Updates elements in sales list
                        if(!sales.isElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode)){
                            sales.appendAtEnd(new salesNode(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount));
                        } else {
                            sales.updateElementInList(tmp->aisleCode, tmp->prodCode, tmp->brandCode, tmp->amount);
                        }

                        cout << "Sales list: " << endl;
                        sales.printList();

                        outfile << "Amount: " << tmp->amount << "; ProdCode: " << tmp->prodCode << "; Name: " << aisles.getNodeByAisleCode(stoi(tmp->aisleCode))->getProductAisleTreePointer()->getNodeByProdCode(stoi(tmp->prodCode))->getName() << "; Price: " << productPrice << "; Tax Rate: " << taxRate << "; Total: " << priceWithTax << endl;

                        tmp = tmp->next;
                    }
                    outfile << "Total Final Price: " << finalPrice << endl;
                    outfile << flush;
                    outfile.flush();
                    outfile.close();

                    //Adds spent amount for reports
                    currentClient.setAmountSpent(currentClient.getAmountSpent()+finalPrice);
                    currentClient.incBillingCount();

                    //Delete las client in queue and delete struct helper
                    clientsQ.deleteAtEnd();
                    deleteList(&a);
                } else {
                    cout << "There is no one in line to be billed" << endl;
                }

            } else if(op=="2"){
                billingMenuExit = true;
            }
        } catch (class elementNotFound& e){
            cout << "Element nof found error" << endl;
        }

    }
}
