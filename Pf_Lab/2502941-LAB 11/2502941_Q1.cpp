#include <iostream>
using namespace std;
void Darray(int matrix[][10], int rows , int cols){
int target;
cout << "Enter the target: ";
cin >> target;
bool found = false;
for (int i = 0 ; i < rows ; i++){
for (int j = 0 ; j < cols ; j++){
cout << matrix[i][j]<< " ";
}
cout << endl;
}
int rowS=0;
int Cols = 0;
for (int i = 0 ; i < rows ; i++){
for (int j = 0 ; j < cols ; j++){
if (matrix[i][j]==target){
rowS = i;
Cols = j;
cout << "Success! item exists as: " << rowS << " and " << Cols;
found = true;
return;
}
}
}
if (found==false){
cout << "Item does not exist";
}

}
int main (){
int matrix[10][10];
cout << "Enter the matrix: "<<endl;
for (int i = 0 ; i < 2 ; i++){
for (int j = 0 ; j < 2 ; j++){
cin >>  matrix[i][j];
}
}
Darray(matrix , 2 , 2);
return 0 ;
}
