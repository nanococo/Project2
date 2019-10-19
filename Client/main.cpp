#include <iostream>
#include <winsock2.h>
using namespace std;

int main(){
    while(true){
        string op;
        cout<<"Welcome to the supermarket"<<endl;
        cout<<"1. Buy"<<endl;
        cout<<"s. exit"<<endl;
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