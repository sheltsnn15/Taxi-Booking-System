
/* 
 * File:   Fare.cpp
 * Author: Shelton Ngwenya
 * 
 * Created on 15 March 2021, 19:46
 */

#include "Fare.h"

#include <iostream>
using namespace std;

void Fare::calcFare() {//method to get journey length then calculate fare cost
    do {//loop to check if input is valid 
        cout << "\t\tWhat is the expected journey length in kilometres: ";
        cin >> journeyLength;
        validInput = isDouble(journeyLength);
        if (!validInput) {//if not display error message
            cout << "\n\t\tPlease try again\n" << endl;
        } else {//else, continue and calc fare cost
            fareCost = (journeyLength * kmCharge) + callOutCharge;
            cout << "\t\tFare Cost = E" << fareCost << endl;
            fareCost;
        }
    } while (!validInput);

}


