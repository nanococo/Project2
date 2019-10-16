#include <iostream>
#include <thread>
#include <cmath>

using namespace std;
void f1(double id){
    int stress = pow(10, id);
    cout<< stress<<endl;
}
void f2(double id){
    int stress = pow(10,id);
    cout << stress << endl;
}


int main() {
    //creates the new thread
    thread th1 (f1, 629182.2398381389128);
    //joins the given thread to the main in order to excecute it
    th1.join();


    thread th2 (f2, 5.21312412);
    th2.join();

    return 0;
}
