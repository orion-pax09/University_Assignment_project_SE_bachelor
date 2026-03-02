#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int Rand_num = rand() % 100 +1;
    int attempt=10;
    int num;
        while (attempt >=1){
        cout << "Enter the guess number:"<<endl;
        cin >> num;
        if (num == Rand_num && attempt >=1){
            cout << "You guessed correctly in"<<" "<<attempt<<" "<<"attempts"<<endl;
            break;
        }
        else if (num > Rand_num && attempt >=1){
            cout << "You guessed too high.Try again"<<endl;
            cout << "You have"<<" "<<attempt << " "<< "attempts."<<endl;;
        }
        else if ( num < Rand_num && attempt >=1){
            cout << "You guessed too low.Try again."<<endl;;
            cout << "You have"<<" "<<attempt << " "<< "attempts."<<endl;
        }
        attempt--;
        if (attempt==0){
            cout << "You ran out of options. Try again"<<endl;
            cout << "Guess number:"<<" "<< Rand_num<<endl;
        }
    }
}

