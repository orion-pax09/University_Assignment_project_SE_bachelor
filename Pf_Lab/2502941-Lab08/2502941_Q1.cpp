#include <iostream>
using namespace std;
void showchoices()
{
cout << "======Enter the problem choices======"<<endl;
}
int problem1(int a,int b){
return a+b;
}
int problem2(int a, int b){
return a*b;
}
int problem3(int a, int b){
if(a>b){
return a-b;
}
else{

return b-a;
}
}
int main(){
int choices;
int num1;
int num2;
cout << "Enter the number 1:"<<endl;
cin >> num1;
cout << "Enter the number 2:"<<endl;
cin>>num2;
showchoices();

cin >> choices;

if (choices <1||choices >3){
cout << "Invalid. Enter the choice btween 1,2, and 3"<<endl;
}
else if(choices ==1){
cout << "You chose problem 1 so it is addition problem:"<< " "<< problem1(num1,num2)<<endl;
}
else if(choices ==2){

cout << "You chose problem 1 so it is multiplication problem:"<< " "<< problem2(num1,num2)<<endl;
}
else if(choices ==3){
cout << "You chose problem 1 so it is subtraction problem:"<< " "<< problem3(num1,num2)<<endl;
}
else{
cout << "Enter 1,2,3"<<endl;
}
return 0;
}