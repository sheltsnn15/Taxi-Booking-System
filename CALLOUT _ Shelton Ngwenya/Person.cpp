

/* 
 * File:   Person.cpp
 * Author: Shelton Ngwenya
 * 
 * Created on 12 March 2021, 14:43
 */

#include "Person.h"

#include <limits>
#include <iomanip>
#include <unistd.h>

#include <iostream>
using namespace std;

bool Person::isInt(int input) {//method to check if input is an int
    if (cin.fail()) {//if not clear input and display error message
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t\tError: Input is not a number" << endl;
        return false;
    }
    return true;
}

bool Person::isDouble(double input) {//method to check if input is an double
    if (cin.fail()) {//if not clear input and display error message
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t\tError: Input is not a number" << endl;
        return false;
    }
    return true;
}

bool Person::checkMenu(int input) {//method to check menu input
    if (input < 1 || input > 7) {//if input is greater than 7 or less than 1, display error message
        cout << "\t\tError: Input out of bounds" << endl;
        return false;
    }
    return true;
}

void Person::displayWelcome()//display welcome message
{
    cout << "\n\n\t\t________________________________________________________________________________\n"
            << "\t\t\t\t\tWelcome to CallOut Dispatch Services\n"
            << "\t\t________________________________________________________________________________\n\n";
}

int Person::menu() {//method to display menu and return user input

    bool isValid = true;
    int choice;

    do {//loop to check if input is valid

        cout << "\n\tWould you like to:" << endl
                << "\n\t1. Display all active fares" << endl
                << "\t2. Schedule fares" << endl
                << "\t3. Display all vehicle details" << endl
                << "\t4. Display all driver details" << endl
                << "\t5. Log return from scheduled fares" << endl
                << "\t6. Print daily report" << endl
                << "\t7. Exit" << endl
                << "\t> ";
        cin >> choice;//get users choice

        isValid = isInt(choice) && checkMenu(choice);// validation to check if input is int and is in bounds

        if (!isValid) {//if not display error
            cout << "\t\tPlease try again" << endl;
        } else {
            return choice;
        }

    } while (!isValid);
}

void Person::printVehiclesDriversHeadings(string s1, string s2, string s3, string s4,
        string s5, string s6, string s7, string s8, string s9) {//method to display Vehicles Drivers Headings
    cout << "\t" << left << setw(14) << setfill(' ') << s1
            << left << setw(19) << setfill(' ') << s2
            << left << setw(28) << setfill(' ') << s3
            << left << setw(16) << setfill(' ') << s4
            << left << setw(15) << setfill(' ') << s5
            << left << setw(16) << setfill(' ') << s6
            << left << setw(17) << setfill(' ') << s7
            << left << setw(17) << setfill(' ') << s8
            << left << setw(12) << setfill(' ') << s9 << endl;
}

bool Person::checkInputArrayIndex(unsigned short sizeOfArray, int input) {//method to check if user input is not out of bounds of array
    if (input > sizeOfArray || input < 0) {//if so, display error
        cout << "Error: Input is out of bounds";
        return false;
    }
    return true;
}

void Person::slightPause() {// method to make slight pause for better viewing
    for (int i = 0; i < 3; i++) {//display 3 dot per second 
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\b\b\b   \b\b\b";
}

void Person::printSeperator() {//method to display a case separator
    cout << "\n\t" << setw(120) << setfill('_') << "_" << "\n\n";
}






