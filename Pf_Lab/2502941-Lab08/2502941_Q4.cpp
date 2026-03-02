                                        `#include <iostream>
#include <math.h>
using namespace std;
int factorial(int num){
    int factorial =1;
    for (int i=1; i <= num; i++){
        factorial = factorial * i ;
    }
    return factorial;
}
double cos_calculation(double x, int n){
    x = x*(3.14/180);
    double sign = -1;
    double sum=1;
    for (int i=2;i<=n; i +=2){
        double Cos = sign * (pow(x,i)/factorial(i));
        sum +=Cos;
        sign *= -1;
    }
    return sum;
}
int main(){
    int X;
    cout << "Enter the value of x:"<<endl;
    cin >> X;
    int N;
    cout << "Enter the interger n:"<<endl;
    cin >> N;
    if (N<0){
        cout << "Enter the integer number greater than 1"<<endl;
    }
    else{
        cout << "cos"<<"("<<X<<")"<<": "<<cos_calculation(X,N)<<endl;
    }
    return 0;
}