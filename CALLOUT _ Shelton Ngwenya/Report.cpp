
/* 
 * File:   Report.cpp
 * Author: Shelton Ngwenya
 * 
 * Created on 15 March 2021, 19:46
 */

#include "Report.h"
#include <iomanip>

#include <iostream>
using namespace std;

Report::~Report() {
}

void Report::displayRevenue() {//method to display the total revenue generated from fares.
    cout << "\tTotal Revenue: E" << totalRevenue << endl;
}



