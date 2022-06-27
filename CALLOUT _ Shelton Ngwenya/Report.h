

/* 
 * File:   Report.h
 * Author: Shelton Ngwenya
 *
 * Created on 15 March 2021, 19:46
 */

#ifndef REPORT_H
#define REPORT_H

#include <iostream>
using namespace std;

class Report  {
public:
    Report() {
        totalRevenue = 0;
    };
    virtual ~Report();
    void displayRevenue();    

    void setTotalRevenue(double totalRevenue) {
        this->totalRevenue += totalRevenue;
    }
    
protected:
    double totalRevenue;

};

#endif /* REPORT_H */

