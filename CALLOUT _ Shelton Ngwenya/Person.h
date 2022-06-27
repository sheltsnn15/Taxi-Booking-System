

/*
 * File:   Person.h
 * Author: Shelton Ngwenya
 *
 * Created on 12 March 2021, 14:43
 */

#ifndef PERSON_H
#define PERSON_H

#include <iomanip>
#include <iostream>

using namespace std;

class Person {
public:
    int menu();
    bool isInt(int);
    bool isDouble(double);
    bool checkMenu(int);
    void displayWelcome();
    void printSeperator();
    void printVehiclesDriversHeadings(string, string, string, string, string, string, string, string, string);
    bool checkInputArrayIndex(unsigned short, int);
    
    void slightPause();
    void printHeading(string heading) {
        cout << "\n\t\t" << setw(33) << setfill('-') << "-" << "/" << heading << "/" << setw(33) << setfill('-') << "-" << "\n\n";
    }
    
protected:
    string name, phoneNum, address;
private:

};

#endif /* PERSON_H */

