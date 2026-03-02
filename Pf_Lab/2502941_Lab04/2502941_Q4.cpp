#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter a number:";
    cin >> x;
    int division1=x / 10;
    int multiplication1= x - (division1 * 10);
    int add1= division1 + multiplication1;
    cout << "First add:-" << " "<< add1<<endl;
    int division2 = add1/10;
    int multiplication2= add1 - ( division2 * 10);
    int add2= division2 + multiplication2;
    cout << "Second add:-" << " "<< add2<<endl;
    return 0;




}