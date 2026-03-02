#include <iostream>
using namespace std;
int main(){
    const int n=10;
    int arry[n]={1,2,3,4,5,6,7,8,9,10};
        cout << "----Before swapping----"<<endl;
        for (int i = 0 ; i < n ; i++){
            cout << arry[i]<< " ";
        }
        cout << endl;
        for (int i = 0 ; i < n ; i +=2 ){
            int temp = arry[i];
            arry[i] = arry[i+1];
            arry[i+1]= temp;
        }
        cout << "----After swapping once-----"<<endl;
        for (int i = 0 ; i < n ; i++){
            cout << arry[i]<< " ";
        }
        cout << endl;
        for (int i = 0 ; i < n ; i +=2 ){
            int temp = arry[i+1];
            arry[i+1] = arry[i];
            arry[i]= temp;
        }
        cout << "----After swapping twice-----"<<endl;
        for (int i = 0 ; i < n ; i++){
            cout << arry[i]<< " ";
        }
}