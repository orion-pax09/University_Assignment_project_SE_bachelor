#include <iostream>
using namespace std;
int main(){
char letter;
cout <<"Enter the letter alphabets:";
cin >> letter;
switch (letter){
case  'A':
case 'a':
case 'E':
case 'e':
case 'I':
case 'i':
case 'O':
case 'o':
case 'U':
case 'u':
cout << "it is vowel"<<endl;
break;
case 'B':
case 'b':
case 'C':
case 'c':
case 'D':
case 'd':
case 'F':
case 'f':
case 'J':
case 'j':
case 'K':
case 'k':
case 'L':
case 'l':
case 'M':
case 'm':
case 'N':
case 'n':
case 'P':
case 'p':
case 'Q':
case 'q':
case 'R':
case 'r':
case 'S':
case 's':
case 'T':
case 't':
case 'V':
case 'v':
case 'W':
case 'w':
case 'X':
case 'x':
case 'Y':
case 'y':
case 'Z':
case 'z':
cout << "it is consonant"<<endl;
break;
default:
cout << "Invalid Input"<<endl;

}
}
