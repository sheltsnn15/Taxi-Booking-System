

/*
 * File:   Drivers.h
 * Author: Shelton Ngwenya
 *
 * Created on 15 March 2021, 19:46
 */

#ifndef DRIVERS_H
#define DRIVERS_H

#include "Person.h"
#include "Report.h"

#include <iostream>
using namespace std;

class Drivers: virtual public Person, virtual public Report {
public:
    Drivers (){};
    Drivers(string, string, string, string, double, string, string, bool);
    virtual ~Drivers();
    void printDriverDetails();
    bool checkDriversAvail(bool);

    void setDriverIsAvail(bool driverIsAvail) {
        this->driverIsAvail = driverIsAvail;
    }
    
    string getIdNum() const {
        return idNum;
    }
    
    void setIdNum(string idNum) {
        this->idNum = idNum;
    }

    bool getIsDriverIsAvail() const {
        return driverIsAvail;
    }

    string getLicenseType() const {
        return licenseType;
    }

    double getKmDriven() const {
        return kmDriven;
    }

    void setKmDriven(double kmDriven) {
        this->kmDriven = kmDriven;
    }

    double getDriverTotalRev() const {
        return driverTotalRev;
    }

    void setDriverTotalRev(double driverTotalRev) {
        this->driverTotalRev += driverTotalRev;
    }


protected:
    string idNum, startDate;
    string licenseType;
    double kmDriven, driverTotalRev = 0;
    bool driverIsAvail;

};

#endif /* DRIVERS_H */

