#include <iostream>
using namespace std;
int main(){
    int arrayA[100][100];
    int rowsA;
    cout << "Enter the rows for matrix A: ";
    cin >> rowsA;
    int ColumnA;
    cout << "Enter the column for matrix A: ";
    cin >> ColumnA;
    cout << "Enter the matrix A: "<<endl;
    for (int i = 0 ; i < rowsA ; i++){
        for (int j = 0 ; j < ColumnA ; j++){
            cin >> arrayA[i][j];
        }
    }
    cout << "You entered the matrix A: "<<endl;
    for (int i = 0 ; i <  rowsA ; i++){
        for (int j = 0 ; j < ColumnA ; j++){
            cout << arrayA[i][j]<<" ";
        }
        cout << endl;
    }
    int arrayB[100][100];
    int rowsB;
    cout << "Enter the rows for matrix B: ";
    cin >> rowsB;
    int ColumnB;
    cout << "Enter the column for matrix B: ";
    cin >> ColumnB;
    cout << "Enter the matrix B: "<<endl;
    for (int i = 0 ; i < rowsB ; i++){
        for (int j = 0 ; j < ColumnB ; j++){
            cin>> arrayB[i][j];
        }
    }
    cout << "You entered the matrix B: "<<endl;
    for (int i = 0 ; i < rowsB ; i++){
        for (int j = 0 ; j < ColumnB ; j++){
            cout <<arrayB[i][j]<<" ";
        }
        cout << endl;
    }
    if (rowsA != ColumnB){
        cout << "Multiplication cross not possible"<<endl;
    }
    int arrayC[100][100];
    int sum = 0 ;
    for (int i = 0 ; i < rowsA ; i++){
        for (int j = 0 ; j < ColumnB ; j++){
            for (int k = 0 ; k < ColumnA ; k++){
                sum += arrayA[i][k]*arrayB[k][j];
            }
            arrayC[i][j]=sum;
            sum =0;
        }
    }
    for (int i = 0 ; i < rowsA ; i++){
        for (int j = 0 ; j < ColumnB ; j++){
            cout << arrayC[i][j]<<" ";
        }
        cout << endl;
    }
}