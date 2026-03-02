#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int summatrix(int matrix[][3], int rows , int cols)
{
    int sum=0;
        for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            if (i==j){
                sum +=1;
            }
            else if (rows - 1 - i){
                sum +=1;
            }
            else if ( rows == cols & rows - 1 - i){
                sum +=1;
            }
        }        
    }
        return sum;
    }

int main(){
    int matrix[3][3];
    cout << "Enter the matrix: "<<endl;
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            cin >> matrix[i][j];
        }
    }
    cout << summatrix(matrix,3,3);
}