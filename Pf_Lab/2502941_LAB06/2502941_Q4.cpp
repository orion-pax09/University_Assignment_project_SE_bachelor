#include <iostream>
using namespace std;
int main(){
    int batting_average;
    int bowling_average;
    int strike_rate;
    cout << "Enter the batting average:"<<endl;
    cin >> batting_average;
    cout << "Enter the bowling average:"<<endl;
    cin >> bowling_average;
    cout << "Enter the strike rate:"<<endl;
    cin >>strike_rate;
    if (batting_average<0|| bowling_average <0 ||strike_rate<0){
        cout << "Invalid input. They can't be less than 0 or negative value"<<endl;
        return 0;
    }
    else if (batting_average >= 45 && bowling_average >=60){
        cout << "This player should be categorized as a batsman"<<endl;
        if (batting_average >= 50 && strike_rate <= 70){
            cout << "He should play in tests"<<endl;
        }
        else{
            cout << "He should play in ODI"<<endl;
        }
    }
    else if ( batting_average>=40 && bowling_average <=30){
        cout <<"This player should be categorized as all rounder"<<endl;
        if (batting_average >= 40 && bowling_average <= 25){
            cout << "He should play in tests";
        }
        else{
            cout << "He should play ODI";
        }
    }
    
    else{
        cout << "This player should be a part of reserve team";

    }
    return 0;
}