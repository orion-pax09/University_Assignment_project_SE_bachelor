#include <iostream>
using namespace std;
void inputEnergyData(int energyData[6][2]){
    int energy_consumption;
    int avg_power;
    for (int i = 0 ; i < 6 ; i++){
        cout << "Enter energy consumption (KWh) for sector "<<i+1<<" : ";
        cin >> energyData[i][0];
        cout << "Enter average power demand (KW) for sector "<<i+1<<" : ";
        cin >> energyData[i][1];  
    }
}
void printcategories(int energyData[][2]){
    for (int i = 0 ; i < 6 ; i++){
        if (energyData[i][0] >= 0 && energyData[i][0]<=50 ){
            cout << "Sector "<<i+1 <<": Low consumption"<<endl;
        }
        else if (energyData[i][0] >= 50 && energyData[i][0]<=100){
            cout << "Sector "<<i+1 <<": Moderate consumption"<<endl;
        }
        else if (energyData[i][0]>100){
            cout << "Sector "<<i+1<<": High consumption"<<endl;
        }
    }
}
int findMaax(int energyData[][2], int &maximum_sector , int &maximum_value){
    maximum_value = 0 ;
    maximum_sector = 0;
    for (int i = 0 ; i <  6 ; i++){
        if (energyData[i][0] > maximum_value){
            maximum_value = energyData[i][0];
            maximum_sector = i+1;
        }
    }
    return maximum_sector,maximum_value;
}
int findMin( int energyData[][2] ,int &minimum_Sector , int &minimum_Value){
    minimum_Value = 1000;
    minimum_Sector = 0;
    for (int i = 0 ; i < 6 ; i++){
        if (energyData[i][0] < minimum_Value){
            minimum_Value = energyData[i][0];
            minimum_Sector = i+1;
        }
    }
    return minimum_Sector , minimum_Value;
}
void calculateTotal(int energyData[][2], int size , int &totalConsumption){
    totalConsumption = 0;
    for (int i = 0 ; i < size; i++){
        totalConsumption += energyData[i][0];   
    }
}
void Decision(int energyData[][2], int maxID , int minID){
    int highconsumptioncount = 0 ;
    bool max_value = false;
    int maxConsumption = energyData[maxID-1][0];
    for (int i = 0 ; i < 6 ; i++)
        {
        if (energyData[i-1][1] == maxID && energyData[i][1] >= 5){
        cout << "Increase power supply by 20% at Sector "<< maxID<<endl;
        }
        else if (energyData[i-1][1]== minID && energyData[i][1] <=5){
            cout << "Reduce Power supply by 10% at Sector "<< minID<<endl;
        }
    }
    for (int i = 0 ; i < 6 ; i++){
        if (energyData[i][0] > maxConsumption){
            highconsumptioncount++;
            if (energyData[i][1] >= 5){
                max_value = true;
            }
        }
        if (highconsumptioncount >=3 && max_value){
            cout << "Deploy backup generator to handle peak load"<<endl;
        }
    }
}
void calculatepriority(int energyData[][2], int priorityOrder[6]){
    for (int i = 0 ; i < 6 ; i++){
        priorityOrder[i] = i+1;
    }
    for (int i = 0 ; i< 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            int id1 = priorityOrder[j];
            int id2 = priorityOrder[j+1];
            if (energyData[id1 - 1 ][1]< energyData[id2 - 1][1]){
                int temp = priorityOrder[j];
                priorityOrder[j] = priorityOrder[j+1];
                priorityOrder [j+1] = temp;
            } 
        }
    }
}


int main(){
    int array[6][2];
    inputEnergyData(array);
    cout << "--- Energy Usage Classification ---"<<endl;
    printcategories(array);
    cout << "--- Analytics ---"<<endl;
    int maxsec , maxVal ;
    int minSec , minVal ;
    int total_energy;
    findMaax(array,maxsec , maxVal);
    cout << "Sector with Maximum Consumption: Sector "<< maxsec <<" ("<< maxVal << "KWh)"<<endl;
    findMin(array , minSec , minVal);
    cout << "Sector with Minimum Consumption: Sector "<< minSec <<" ("<< minVal << "KWh)"<<endl;
    calculateTotal(array , 6 , total_energy);
    cout<< "Total energy consumed: "<< total_energy<<"KWh"<<endl;
    cout << "--- Decision ---"<<endl;
    Decision(array , maxsec , minSec);
    cout << "--- Priority Order (Based on Average Power Demand) ---"<<endl;
    int priority_order[6];
    calculatepriority(array , priority_order);
    for (int i = 0 ; i < 6 ; i++){
        cout << i+1 <<" . sector "<<priority_order[i]<<endl;
    }
}
