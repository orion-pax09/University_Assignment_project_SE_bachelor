#include <iostream>
#include <sstream>
#include <string>
using namespace std; 
int main(){
    string sentences;
    cout << "Enter the sentences: ";
    getline(cin , sentences);
    char words[100][100];
    int rows = 0 ; int column = 0;
    for (int i = 0 ; sentences[i]!='\0';i++){
        if (sentences[i]== ' '){
            words[rows][column]='\0';
            rows++;
            column=0;
        }
        else{
            words[rows][column] = sentences[i];
            column++;
        }
    }
    words[rows][column]='\0';
    for (int i = 0 ; i <= rows ; i++){
        cout << "Rows: "<<i << " = "<<words[i]<<endl;
    }
    return 0;
}