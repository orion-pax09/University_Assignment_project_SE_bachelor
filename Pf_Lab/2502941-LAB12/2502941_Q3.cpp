#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    const char* month[]={"Jan","Feb","March","April","May","June","July",
    "Aug","Sept","Oct","Nov","Dec"};
    const char* days[] = {"Sun","Mon","Tue","Wed",
    "Thur","Friday","Saturday"};
    float* ptr = new float[n];
    for (int i = 0 ; i < n ; i++){
        cout << "Enter rainfall for day " << i + 1 << ": ";
        cin>>*(ptr + i );
    }
    int todayIndex = 4; 
    int date = 31;      
    int monthIndex = 2; 
    for (int i = 0; i < n; i++) {
        int dayIndex = (todayIndex - i + 7) % 7; 
        cout << *(days + dayIndex) << " " << date - i << " " <<endl
             << *(month + monthIndex) << " Rainfall: " <<endl
             << *(ptr + i) << " mm" << endl;
    }

    // Calculate average
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);
    }
    cout << "\nAverage Rainfall: " << sum / n << " mm" << endl;
    delete [] ptr;

}
