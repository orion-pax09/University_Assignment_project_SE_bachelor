#include <iostream>
using namespace std;
int main(){
int age;
char gender;
char transport;
cout<<"Enter the age:";
cin >> age;
cout << "Press (M) for male"<<endl;
cout << "Press (F) for female"<<endl;
cout << "Enter the gender:";
cin >> gender;
if (gender=='M'|| gender == 'm'){
if (age > 50){
cout << "You can cast your vote in your own city"<<endl;
}
   else{
cout << "Your voting center is out of town"<<endl;
}
}
 
if (gender=='F'|| gender=='f'){
cout<<"Does she have public transport?"<<endl;
cin >> transport;
if (transport == 'Y'|| transport =='y'){
cout << "Her age is:"<<" "<<age<<endl;
cout<<"Your voting center is out of town";

}
else{
cout << "Her age is:"<<" "<<age<<endl;
cout <<"You can cast your vote in your own city";
}

}
return 0;
}
