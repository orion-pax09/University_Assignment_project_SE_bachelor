#include <iostream>
using namespace std;
int main()

    {
        int value;
        int x;
        int result;
        cout <<"enter the number:";
        cin >> x;
        value= (x | 16) ;
        result= (value>>2)+1- ((x>>3)&1);
        cout<<"The reminder is:"<< " "<<result;
        return 0;

    }
