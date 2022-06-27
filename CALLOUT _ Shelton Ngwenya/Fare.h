

/* 
 * File:   Fare.h
 * Author: Shelton Ngwenya
 *
 * Created on 15 March 2021, 19:46
 */
#include "Person.h"

#ifndef FARE_H
#define FARE_H

class Fare: virtual public Person {
public:
    void calcFare();
    void viewActiveFare();
    
    double getFareCost() const {
        return fareCost;
    }

    double getJourneyLength() const {
        return journeyLength;
    }

    
protected:
    double fareCost, journeyLength;
private:
    double kmCharge = 6.50;
    int callOutCharge = 5;
    bool validInput;
    
};

#endif /* FARE_H */

