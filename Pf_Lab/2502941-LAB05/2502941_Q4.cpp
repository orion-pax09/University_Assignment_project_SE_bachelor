#include <iostream>
#include <climits>
using namespace std;

int main() {
    int x = INT_MAX;
    int y=INT_MIN
    cout << x << endl;

    x = x + 1;  
    y= y-1       // Overflow occurs here
    cout << x;
    cout << y;          // Output: -2147483648 (wraps around)
}