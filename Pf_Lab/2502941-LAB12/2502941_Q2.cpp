#include <iostream>
#include <string>
using namespace std;
int vowelcount(string Vowels){
    int count = 0 ;
    char* ptr = &Vowels[0];
    for (int i = 0 ; ptr[i]!='\0';i++){
        if (ptr[i] == 'A'||ptr[i] =='a'||ptr[i] =='E'||ptr[i] =='e'||ptr[i] =='I'||ptr[i] =='i'||ptr[i] =='O'
        ||ptr[i] =='o'||ptr[i] =='U'||ptr[i] =='u'){
            count++;
        }
    }
    return count;
}
int main(){
    string words;
    cout << "Enter the sentences: "<<endl;
    getline(cin , words);
    cout << "Number of vowels: "<< vowelcount(words);
    return 0;
}