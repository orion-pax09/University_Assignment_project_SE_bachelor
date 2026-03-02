#include <iostream>
using namespace std;
void ctof( double &temp){
    temp = (temp * 9.0/5.0) +32;
}
void ktoc(double &temp){
    temp = (temp - 273.15);
}
void ftok(double &temp){
    temp = (temp - 32) * 5.0 / 9.0  + 273.15; 
}
    
int main(){
    
    int celsius;
    int farenheit;
    int kelvin;
    int choice;
    double temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;
    cout << "Enter the choice for following temperature: "<<endl;
    cout << "1. From centrigrade to farenheit: "<<endl;
    cout << "2. From kelvin to centigratde: "<<endl;
    cout << "3. From farenheit to kelvin: "<<endl;
    cin >> choice;
    switch(choice){
        case 1:
        ctof(temperature);
        cout << "Temperature from centigrade to farenheit: " <<  temperature;
        break;

        case 2:
        ktoc(temperature);
        cout << "Temperature from kelvin to centigrade: "<< temperature;
        break;

        case 3:
        ftok(temperature);
        cout << "Temperature from farenheit to centigrade: "<< temperature;
        break;

        default:
        cout << "invalid choice";
    }

    
}