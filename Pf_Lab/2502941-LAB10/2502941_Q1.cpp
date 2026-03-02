#include <iostream>
using namespace std;
int main(){
    int array[5][5];
    cout << "Enter the number: "<<endl;
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            cin >> array[i][j];
        }
    }
    cout << "You entered: "<<endl;
    for ( int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            cout << array[i][j]<< " ";
        }
        cout << endl;
    }
    int n;
    cout << "Enter the number: "<<endl;
    cin >> n;
    for ( int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            array[i][j]+=n;
       }
    }
    cout << "Calculation performed: "<<endl;
    for ( int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            cout << array[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "Displaying addition of two matrix"<<endl;
    for ( int i = 0 ; i < 5 ; i++){
        for ( int j = 0 ; j < 5 ; j ++){
            array[i][j] += array[i][j];
            cout << array[i][j]<< " ";
        }
        cout << endl;
    }
}
