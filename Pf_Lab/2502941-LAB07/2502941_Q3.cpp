#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the positive number:"<<endl;
    cin >> n;
    int num1=0;
    int num2=1;
    for (int i=1; i <=n; i++){
        int sum = num1 + num2 ;
        num1 = num2;
        num2 = sum;
        cout << num1 <<endl;
    }
}