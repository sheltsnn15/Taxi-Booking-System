

/* 
 * File:   Drivers.cpp
 * Author: Shelton Ngwenya
 * 
 * Created on 15 March 2021, 19:46
 */

#include "Drivers.h"
#include <iomanip>
#include <iostream>

using namespace std;

Drivers::Drivers(string dID, string dName, string dAddress, string dPhoneNum, double dKmDriven,
        string dStartDate, string dlicense, bool dIsAvail) {//constructor
    idNum = dID;
    name = dName;
    address = dAddress;
    phoneNum = dPhoneNum;
    startDate = dStartDate;
    licenseType = dlicense;
    kmDriven = dKmDriven;
    driverIsAvail = dIsAvail;
    driverTotalRev = 0;
}



Drivers::~Drivers() {//destructor
}

void Drivers::printDriverDetails() {//method to print driver details
    cout << "\t" << left << setw(14) << setfill(' ') << idNum
            << left << setw(19) << setfill(' ') << name
            << left << setw(28) << setfill(' ') << address
            << left << setw(16) << setfill(' ') << phoneNum
            << left << setw(15) << setfill(' ') << kmDriven
            << left << setw(16) << setfill(' ') << startDate
            << left << setw(17) << setfill(' ') << licenseType
            << left << setw(17) << setfill(' ') << driverIsAvail << boolalpha  
            << "E" << left << setw(12) << setfill(' ') << driverTotalRev << "\n";
}

bool Drivers::checkDriversAvail(bool isAvailable) {//method to check if driver is available
    if (isAvailable != true) {//if not, display error message
        cout << "\n\t\tError: Driver is not available." << endl;
        return false;
    }
    return true;
}
    