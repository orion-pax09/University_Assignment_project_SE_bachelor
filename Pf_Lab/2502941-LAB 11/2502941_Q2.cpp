#include <iostream>
#include <string>
using namespace std;
void concantenatewitsr(string &triangle){
    int size;
    cout << "Enter the size: ";
    cin >> size;
    char ch;
    
        for (int i = 0 ; i < size ; i++){
            cout << "What character should be printed in line <"<<i<<">: ";
            cin >> ch;
            triangle +=ch;
        }
        int index = 0 ;
        for (int i = size ; i >= 1 ; i--){
            for (int j = 1 ; j <=i ; j++){
                cout << triangle[index];
            }
            cout << endl;
            index++;
        }            
    }
int main(){
    string triangle="";
    concantenatewitsr(triangle);
    return 0;

}