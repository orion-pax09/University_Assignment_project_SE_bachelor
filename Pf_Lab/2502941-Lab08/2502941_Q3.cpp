#include <iostream>
#include <iomanip>
using namespace std;
double Area_cylinder(double r, double h, double pi=3.14){
    return (2*pi * r * h) + (2*pi*r*r);
}
double Area_cube(double a){
    return 6*a*a;
}
double Area_sphere(double r,double pi = 3.14){
    return  4*pi*r*r;
}
int main(){
    double radius;
    cout << "Enter the radius:"<<endl;
    cin >> radius;
    double A;
    cout << "Enter the side of square:"<<endl;
    cin>>A;
    double height;
    cout << "Enter the height for cylinder:"<<endl;
    cin >> height;
    cout <<fixed<< setprecision(2) << "Area of cylinder: "<<Area_cylinder(radius,height)<<endl;
    cout <<fixed<< setprecision(3) << "Area of cube    : "<<Area_cube(A)<<endl;
    cout <<fixed<< setprecision(4) << "Area of sphere  : "<<Area_sphere(radius)<<endl;
}