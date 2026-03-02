#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    if (size < 0){
        cout << "Enter the size of array greater than 1: ";
        return 0;
    }
    int* array = new int [size];
    cout << "Enter the elements of array:"<<endl;
    for (int i = 0 ; i < size ;i++){
        cin >> array[i];
    }
    int max = array[0] ;
    int sec_max = -1 ;
    for (int i = 0 ; i <  size  ; i++){
        if (array[i]> max){
            sec_max = max ; 
            max = array[i];
        }
        else if(array[i]> sec_max && array[i] < max)
        {
            sec_max = array[i];
        }
    }
    for (int i = 0 ; i <  size  ; i++){
        cout << array[i]<<" ";
    }
    cout << endl;

    int* newarray= new int[size+1];
    int j = 0;
    int remaining = max - sec_max;
for (int i = 0 ; i < size ; i++){
    if (array[i]== max){
        newarray[j++] = remaining; 
        newarray[j++] = sec_max;
    }
    else{
        newarray[j++] = array[i];
    }
}
for (int  i = 0 ; i < size + 1 ; i++){
    cout << newarray[i]<<" ";
}
}