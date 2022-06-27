

/* 
 * File:   Vehicles.cpp
 * Author: Shelton Ngwenya
 * 
 * Created on 15 March 2021, 19:45
 */

#include "Vehicles.h"
#include <iomanip>
#include <iostream>
using namespace std;

Vehicles::Vehicles(string vType, string vRegNum, string vMake, string vModel,
        double vMileage, int vCapacity,  bool vWheelChair, bool vIsAvailable) {//constructor
    type = vType;
    registrationNum = vRegNum;
    make = vMake;
    model = vModel;
    mileage = vMileage;
    wheelChair = vWheelChair;
    capacity = vCapacity;
    isAvail = vIsAvailable;
    vehicleTotalRev = 0;
    
}

Vehicles::~Vehicles() {//destructor
}

void Vehicles::printVehicleDetails() {//method to display vehicle details
    cout << "\t" << left << setw(14) << setfill(' ') << type
            << left << setw(19) << setfill(' ') << registrationNum
            << left << setw(28) << setfill(' ') << make
            << left << setw(16) << setfill(' ') << model
            << left << setw(15) << setfill(' ') << mileage
            << left << setw(16) << setfill(' ') << capacity
            << left << setw(17) << setfill(' ') << wheelChair << boolalpha 
            << left << setw(17) << setfill(' ') << isAvail << boolalpha 
            << "E" << left << setw(12) << setfill(' ') << vehicleTotalRev << "\n";
}

bool Vehicles::checkVehiclesAvail(bool isAvailable) {//method to check if vehicle is available
    
    if (isAvailable != true) {//if not, display error message
        cout << "\t\t\nError: Vehicle is not available." << endl;
        return false;
    }
    return true;
}

bool Vehicles::wheelchairAccessible(bool vehicle, int wcNum) {//method to check if vehicle is wheel chair accessible
    if (vehicle == false && wcNum > 0) {
        cout <<"\n\t\tError: Vehicle is not wheel chair accessible." << endl;
        return false;
    }
    return true;
}
    
