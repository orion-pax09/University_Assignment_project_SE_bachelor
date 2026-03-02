#include <iostream>
#include <string>
using namespace std;
int main(){

     int n ; 
     cout << "Enter the n size: ";
     cin >> n ;
     int* array = new int [n];
     for (int i = 0 ; i < n ; i++){
          for (int j = 0 ; j < n ; j++){
               if ( i==j || j == n-1-i){
                    cout << "*";
               }
              
               else{
                    cout << " ";
               }
          }
          cout << endl;
     }

}