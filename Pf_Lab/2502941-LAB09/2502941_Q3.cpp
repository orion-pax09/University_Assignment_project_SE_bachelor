#include <iostream> 
using namespace std;
float factorial( float x){
    int num = (int) x;
    float fact = 1.0 ;
    for (int i = 1 ; i <= num  ; i++){
        fact *= i;
    }
    return fact;
}
float formula (float item, int n){
    return ((item +1)*(item -1)/ (n*n + 1));
}
int main(){
    int Size;
    cout << "Enter the size of array: ";
    cin >> Size;
    if (Size<=7){
        cout << "Enter the size of array greater than at least 7"<<endl;
        return 0;
    }
    float* array = new float [Size];
    cout << "Enter the elements of array"<<endl;
    for (int i = 0 ; i < Size ; i++){
        cin >> array[i];
    }
    for (int i = 0 ; i < Size ; i++){
        cout << array[i]<<" ";
    }
    cout << endl;
    for (int i = 0  ; i <= Size ;i++){
        int value = (int) array[i];
        if (value% 2==0){
            array[i] =  factorial(array[i]);
        }
        else{
            array[i] = formula(array[i],Size);
        }
    }
     for (int i = 0  ; i <= Size ;i++){
        cout << array[i]<<" ";
     }
     cout << endl;

}