#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the positive number"<<endl;
    cin >> n;
    int result=1;
    if (n >=1){
        for (int i=1; i <=n ; i++){
            result = result * i;
            cout << "Factorial of "<< ":"<<result<<endl;
            }
        }
    else if ( n ==0 ){
        cout << "Factorial of zero is 1"<<endl;
    }
 
    else{
        cout << "Invalid.";
    }
}
