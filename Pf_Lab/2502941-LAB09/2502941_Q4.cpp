#include <iostream>
using namespace std;
bool checkVowels(char a){
    if (a == 'a'|| a == 'e'|| a == 'i'|| a == 'o'||a == 'u'){
        return true;
    }
    return false;
}
int main(){
    int n;
    cout << "Enter the size array: ";
    cin >> n;
    char array[n];
    if (n < 10){
        cout << "Invalid. Enter the size array greater than 10";
    }
    else{
        for ( int i = 0 ; i < n ; i++){
            cout << "Enter the character "<<i+1 << ": ";
            cin >> array[i];
        }
        cout << "Character array is: "<<endl;
        for ( int i = 0 ; i < n ; i++){
            cout<<array[i];
        }
        cout << endl;
        cout <<"Returned vowel array: "<<endl;
        for (int i = 0 ; i < n ; i++){
            if (checkVowels(array[i])==true){
                cout<<array[i];
            }
        }
        cout << endl;
        char searchcharacter;
        int count=0;
        cout << "Enter a character to search: ";
        cin >> searchcharacter;
        for (int a = 0 ; a < n ; a++){
            if (array[a]==searchcharacter){
                count++;
            }            
        }
        cout << "Character "<< searchcharacter << " repeated "<< count << " times. "<<endl;
        return 0;
    }
}