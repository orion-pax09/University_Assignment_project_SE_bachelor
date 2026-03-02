#include <iostream>
#include <string>
using namespace std;
int main(){
    int button;
    char bank_name;
    string name_beneficiary;
    string my_name="Muhammad Hamza Khan";
    double balance=25000;
    double transfer_Amount;
    char mobile_bundles;
    int choice;
    cout <<"--Welcome to AUCT Bank--"<<endl;
    cout <<"1.My Account"<<endl;
    cout <<"2.Funds Transfer"<<endl;
    cout <<"3.Load Mobile Bundles"<<endl;
    cout <<"Enter the button of 1,2,3 to choose:";
    cin >> button;
    switch(button){
        case 1:
        cout << my_name<<endl;
        cout << "Current balance:"<<"RS."<<balance<<endl;
        break;
        case 2:
        cout << "Enter the beneficiary name:";
        cin >> name_beneficiary;
        cout << "Select the bank of beneficiary"<<endl;
        cout << "a. Alfalah Bank"<<endl;
        cout << "b. Bank of Punjab"<<endl;
        cout << "c. Fast bank"<<endl;
        cin >> bank_name;
        switch(bank_name){
        case 'A':
        case 'a':
        cout << "Enter the transfer amount"<<endl;
        cin >> transfer_Amount;
        if (balance > 5000 && transfer_Amount <=balance){
        balance = balance - transfer_Amount;
        cout << "Rs."<<transfer_Amount<<" "<<"has been transferred to "<< " "<< name_beneficiary<<"."<<endl;
        cout << "Your current balance is:"<< balance;}
        else {
                cout << "Low balance"<<endl;
            }
        break;
            case 'B':
            case 'b':
            cout << "Beneficiary does not have Bank of punjab account";
            break;
            case 'C':
            case 'c':
            cout << "Beneficiary does not have Fast Bank account";
            break;
            default:
            cout << "Invalid. press a/b/c to to select bank account";
            break;             
        }
        break;
        case 3:
        cout << "u. Ufone"<<endl;
        cout << "t. Telenor"<<endl;
        cout << "Enter u or t to select ufone or telenor"<<endl;
        cin >> mobile_bundles;
        if (balance>5000){
            switch (mobile_bundles){
            case 'U':
            case 'u':
            cout <<"1. Super card plus"<<endl;
            cout <<"2. Super card gold"<<endl;
            cout << "Enter 1 or 2 to select card:";
            cin >> choice;
            switch (choice){
                case 1:
                balance=balance - 699;
                cout <<"Super card plus has been loaded.Your current balance is Rs."<<balance<<endl;
                break;
                case 2:
                balance=balance - 1099;
                cout <<"Super card gold has been loaded.Your current balance is Rs."<<balance<<endl;
                break;
                default:
                cout << "Invalid. Enter 1 or 2 to select super card";
                break;
            }
            break;
        }
            case 'T':
            case 't':
            cout << "1. Monthly easy card"<<endl;
            cout << "2. Weekly easy card"<<endl;
            cout << "Enter 1 or 2 to select card:";
            cin >> choice;
            switch (choice)
            {
            case 1:
            balance = balance - 700;
                cout << "Monthly easy card has been loaded.Your balance is Rs."<<balance<<endl;
                break;
            case 2:
            balance=balance - 300;
                cout << "Weekly easy card has been loaded.Your balance is Rs."<<balance <<endl;
                break;
            default:
                cout << "Invalid. Enter 1 or 2 to select super card";
                break;
            }
            break;
        }
            else{
            cout <<"Balance is less than Rs.5000 so balance is low";
        }
            
        }
        


       }

    
         
        

    