#include <iostream>
using namespace std;
int main()
{
    int x;
    int variable;
    cout << "Enter a number:";
    cin >> x;
    variable = x;
    x = ( x << 1);
    cout << "Doubled:"<<" "<< x<<endl;
    x = (x + 10) ;
    cout <<"Added 10:"<<" "<< x <<endl;
    x = (x / 2);
    cout <<"Halved:"<<" "<< x<<endl;
    x= ( x - variable);
    cout <<"Subtracted 20:"<<" "<< x<<endl;
    cout << "Final number:"<< x <<endl;
    return 0;
    

}