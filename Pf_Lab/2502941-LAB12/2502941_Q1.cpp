#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;
    int array[size];
    cout << "Enter the element of "<<size << " in the array: "<<endl;
    for (int i = 0 ; i < size ;  i++){
        cin >> array[i];
    }
    for (int i = 0 ; i < size ; i++){
        cout << array[i]<<" ";
    }
    cout << endl;
    int *ptr = array;
    for (int i = 0 ; i < size ; i++){
        for (int j = 0 ; j <size ; j++){
            if (*(ptr+j)>*(ptr+j+1)){
                int sorting = *(ptr + j );
                *(ptr + j ) = * (ptr + j + 1);
                *(ptr + j + 1) = sorting;
            }
        }
    }
    cout << "Sorted element: "<<endl;
    for (int i = 0 ; i < size ; i++){
        cout << *(ptr+i)<< " ";
    }
}