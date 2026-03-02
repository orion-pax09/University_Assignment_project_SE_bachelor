#include <iostream>
using namespace std;
int main(){
    int starting_balance;
    cout << "Enter the starting balance:"<<endl;
    cin >> starting_balance;
    float annual_interest=0;
    cout << "Enter the annual interest rate:"<<endl;
    cin >> annual_interest;
    int No_Of_Month;
    cout << "Enter the number of month passed:"<<endl;
    cin >> No_Of_Month;
    int deposit_amount;
    int withdrawn_Amount;
    float balance=starting_balance;
    int total_withdraw=0;
    int total_deposit=0;
    float monthly_interest;
    if (starting_balance < 0 || annual_interest < 0 || No_Of_Month < 0 )
    {
        cout << "Invalid.Account has ended"<<endl;
    }
    else if (starting_balance > 0 && annual_interest > 0 && No_Of_Month > 0)
    {
        for(int i=1; i<=No_Of_Month; i++)
        {
            cout << "Enter the amout to be deposited during "<<" "<< i <<" "<<":"<<endl;
            cin >> deposit_amount;
            cout << "Enter the amount to be withdrawn during "<<" "<<i<<endl;
            cin >> withdrawn_Amount;
            if (deposit_amount >= 0 && withdrawn_Amount >= 0)
            {
                if (withdrawn_Amount <= balance){
                balance +=deposit_amount;
                balance -= withdrawn_Amount;
                total_deposit +=deposit_amount;
                total_withdraw +=withdrawn_Amount;
                monthly_interest = balance * (annual_interest / 100.0) / 12;
                balance +=monthly_interest;
                }
                else{
                    cout << "Accont has ended.";
                }
            }
            else if (deposit_amount < 0 || withdrawn_Amount <0)
            {
                cout << "Invalid. Account has ended."<<endl;
            }
            else
            {
                cout << "Invalid.Enter the deposit money in number"<<endl;
            }
    }           
    cout << "Ending balance is:"<<" "<<balance<<endl;
    cout << "Your total withdrawl amount:"<< " "<<total_withdraw<<endl;
    cout << "Your total deposit amount:"<< " "<<total_deposit<<endl;
}
    else
    {
        cout << "Enter the input in positive numbers"<<endl;
    }
}



