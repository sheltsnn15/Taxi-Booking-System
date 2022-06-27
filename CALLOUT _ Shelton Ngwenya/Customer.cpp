
/* 
 * File:   Customer.cpp
 * Author:Shelton Ngwenya
 * 
 * Created on 12 March 2021, 14:39
 */

#include "Customer.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

Customer::Customer(string cusName, string cusPhoneNum, string cusSource, string cusDestination,
        int cusTravellerNum, int cusWheelChairNum, string driverIDNum, string vehicleRegNum, double cusJourneyLength, double cost) {//constructor 
    name = cusName;
    phoneNum = cusPhoneNum;
    source = cusSource;
    destination = cusDestination;
    travellerNum = cusTravellerNum;
    wheelChairNum = cusWheelChairNum;
    idNum = driverIDNum;
    registrationNum = vehicleRegNum;
    fareCost = cost;
    journeyLength = cusJourneyLength;

}

Customer::~Customer() {//destructor
}

void Customer::scheduleFare() {//method to schedule fare
    bool validateInt = true;

    cout << "\tEnter fare details.\n" << endl;
    cout << "\t\tName: ";
    cin.get();
    getline(cin, name);//get line input from user
    cout << "\t\tPhone Number (089-1234567): ";
    cin >> phoneNum;
    cout << "\t\tSource: ";
    cin.get();
    getline(cin, source);//get source address line input from user
    cout << "\t\tDestination: ";
    cin.get();
    getline(cin, destination);//get destination address line input from user

    do {
        cout << "\t\tNumber of people travelling: ";
        cin >> travellerNum;//get traveller number
        validateInt = isInt(travellerNum) && travellerNum > 0;//validate traveller number input is int and is greater than 0
        if (!validateInt) {//if not output error message
            cout << "\t\tPlease try again\n" << endl;
        }
    } while (!validateInt);

    do {
        cout << "\t\tNumber of people using a wheelchair: ";
        cin >> wheelChairNum;//get number of wheelChair 
        validateInt = isInt(wheelChairNum);//validate traveller number input is int 
        if (!validateInt) {//if not output error message
            cout << "\t\tPlease try again\n" << endl;
        }
    } while (!validateInt);
    
    calcFare();//calculate fare

    fflush(stdin);

}

bool Customer::checkArrayEmpty(string input) {//method to check if array is empty
    if (input == "") {//if it is, output message
        cout << "\n\t\tThat one is empty." << endl;
        return false;
    }
    return true;
}

void Customer::printCustomerDetails() {//method to display customer/fare details

    cout << "\tName: " << setw(27) << setfill(' ') << name
            << "Phone Number: " << setw(30) << setfill(' ') << phoneNum
            << "No. Travellers: " << setw(10) << setfill(' ') << travellerNum
            << "No. wheel chairs: " << setw(10) << setfill(' ') << wheelChairNum << "\n";

    cout << "\n\tSource: " << setw(40) << setfill(' ') << source
            << "Destination: " << setw(40) << setfill(' ') << destination
            << "Journey Length: " << setw(12) << setfill(' ') << journeyLength << left << "km" << "\n";

    cout << "\n\tDriver ID No.: " << setw(18) << setfill(' ') << idNum
            << "Vehicle Registration No.: " << setw(18) << setfill(' ') << registrationNum
            << "Travel cost: E" << setw(10) << setfill(' ') << fareCost << "\n\n";

}


