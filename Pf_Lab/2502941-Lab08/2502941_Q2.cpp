#include <iostream>
using namespace std;
float residential_company(int n){
    return 4.50 + 20.50 + (n*7.50);
}
float customer_Service(int n){
float billprocessingfee = 15.0;
float basicservice_fee = 75.0;
if (n <= 10){
    billprocessingfee += 75.0;
}
else{
    billprocessingfee += 75.0 + (n - 10) * 50.0;
}
billprocessingfee +=50.0;
return billprocessingfee;
}
int main(){
int premium_channel;
cout << "Enter the number of premium channel: ";
cin >> premium_channel;
int choice;
cout << "Enter the choices...press (1) for residential bill and (2) for costumer bill: ";
cin >> choice;
if (choice == 1){
    cout << "Account number: ($) "<< residential_company(premium_channel);
}
else if (choice ==2 )
{
    int basic_connection;
    cout << "ENter the number of basic connection: ";
    cin >> basic_connection;
    int account_no;
    cout << "Enter the account number: ";
    cin >> account_no;
    cout << "Account number: ($) "<< customer_Service(basic_connection);
}
}