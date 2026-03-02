#include <iostream>
#include <string>
using namespace std;
int thestrLen(char string[]){
    int count=0;
    int array[100];
    for (int i = 0 ; string[i] != '\0' ; i++ ){
        if(string[i]!=' '){
            count++;
        }
       
    }
    return count;
}
int main(){
    char words[100];
    cout << "Enter the words: ";
    cin.getline(words,100);
    cout << "Total length of string is: " << thestrLen(words) <<endl;
}