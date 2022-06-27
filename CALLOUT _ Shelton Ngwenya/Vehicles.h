
/*
 * File:   Vehicles.h
 * Author: Shelton Ngwenya
 *
 * Created on 15 March 2021, 19:45
 */

#ifndef VEHICLES_H
#define VEHICLES_H

#include "Report.h"

#include <iostream>
using namespace std;

class Vehicles {
public:
    Vehicles (){};
    Vehicles(string, string, string, string, double, int, bool, bool);
    virtual ~Vehicles();
    
    bool checkVehiclesAvail(bool);
    bool wheelchairAccessible(bool, int);
    void printVehicleDetails();

    void setVehicleAvail(bool Avail) {
        isAvail = Avail;
    }

    string getRegistrationNum() const {
        return registrationNum;
    }

    void setRegistrationNum(string registrationNum) {
        this->registrationNum = registrationNum;
    }

    bool getVehicleIsAvail() const {
        return isAvail;
    }

    string getType() const {
        return type;
    }

    double getMileage() const {
        return mileage;
    }

    void setMileage(double mileage) {
        this->mileage = mileage;
    }

    double getVehicleTotalRev() const {
        return vehicleTotalRev;
    }

    void setVehicleTotalRev(double vehicleTotalRev) {
        this->vehicleTotalRev = vehicleTotalRev;
    }

    bool getIsWheelChair() const {
        return wheelChair;
    }


    
    

protected:
    string registrationNum, make, model, type;
    double mileage, vehicleTotalRev = 0;
    bool wheelChair;
    int capacity;
    bool isAvail;

};

#endif /* VEHICLES_H */

