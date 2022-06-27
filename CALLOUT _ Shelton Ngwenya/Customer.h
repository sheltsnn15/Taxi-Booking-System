
/* 
 * File:   Customer.h
 * Author: Shelton Ngwenya
 *
 * Created on 12 March 2021, 14:39
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Drivers.h"
#include "Vehicles.h"
#include "Fare.h"
#include "Fare.h"

#include <iostream>
using namespace std;

class Customer: virtual public Person, virtual public Drivers, virtual public Vehicles, virtual public Fare, virtual public Report {
public:
    Customer (){};
    
    Customer(string, string, string, string, int, int, string, string, double, double);
    virtual ~Customer();
    void printCustomerDetails();
    void scheduleFare();
    bool checkArrayEmpty(string);

    int getWheelChairNum() const {
        return wheelChairNum;
    }

private:
    string source, destination;
    int travellerNum, wheelChairNum;

};

#endif /* CUSTOMER_H */

