
/*
 * File:   CDSMain.cpp
 * Author: Shelton Ngwenya
 *
 * Created on 08 March 2021, 20:32
 */



#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cctype>


#include "Person.h"
#include "Customer.h"
#include "Vehicles.h"
#include "Drivers.h"
#include "Report.h"
#include "Fare.h"

using namespace std;

unsigned short arrayVehicles = 11, arrayDrivers = 6, arrayCustomers = 6;
bool validInput = true, addCus = true, selectedIsAvail = true, returnInfo = true;
char anotherCusChoice;
int arrayIndex, i = 0, x = 0;
double info;

/*
 *
 */

int main() {
    Person person; //create instance of person class
    Vehicles vehicle;//create instance of vehicles class
    Drivers driver;//create instance of driver class
    Customer cus;//create instance of customer class
    Report report;//create instance of report class

    Vehicles vehicles[arrayVehicles] = {//create an array of vehicle class
        Vehicles("Taxi", "12 C 4956", "Hyundai", "i30 Tourer", 65172, 4, true, true),
        Vehicles("Taxi", "14 C 89365", "Ford", "Mondeo", 33892, 4, true, true),
        Vehicles("Taxi", "15 C 46046", "VW", "Passat", 23897, 4, true, true),
        Vehicles("Taxi", "14 C 38492", "Nissan", "Primera", 29418, 4, true, true),
        Vehicles("Taxi", "10 C 99393", "Skoda", "Octavia", 89678, 4, true, true),
        Vehicles("Taxi", "15 C 2379", "Seat", "Toledo", 12812, 4, true, true),
        Vehicles("Bus", "10 C 37209", "Ace", "Cougar", 28786, 48, true, true),
        Vehicles("Bus", "11 C 882", "Daimler", "Fleetline", 68893, 48, false, true),
        Vehicles("Minibus", "14 C 23908", "Ford", "Transit", 18827, 16, true, true),
        Vehicles("Minibus", "10 C 831", "Fiat", "Ducato", 32986, 16, true, true),
        Vehicles("Minibus", "13 C 82677", "Mercedes-Benz", "Vario", 18567, 20, false, true)
    };

    Drivers drivers[arrayDrivers] = {//create an array of drivers class
        Drivers("1234567A", "Tom Daly", "14 Green St., Cork", "087-6543210", 23231, "12/08/2008", "B", true),
        Drivers("2345678B", "Anne O'Brien", "Beach View, Kinsale", "086-5432109", 11980, "09/12/2011", "D", true),
        Drivers("3456789B", "James Twomey", "14, French St., Cork", "085-4321098", 18414, "14/11/2010", "D1", true),
        Drivers("4567890C", "Mary O'Neill", "23 Castle Road, Youghal", "089-8765432", 12669, "11/02/2014", "B", true),
        Drivers("5678901D", "Brendan Brown", "98 Nuns Walk, Cork", "083-2109876", 23864, "01/04/2007", "D", true),
        Drivers("6789012E", "Vincent Coy", "Green Valley, Cobh", "087-8901234", 34196, "03/04/1998", "D1", true),
    };
    Customer customer[arrayCustomers]; //create an array of customer class

    person.displayWelcome(); //display welcome message

MENU://loop id jump
        switch (person.menu()) {//get program menu and get user input, execute program functions on commands

                /*execute command 1, 
                 * display active fares*/

            case 1: cout << "\n\tDisplaying all active fares";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Active Fares");
                

                for (unsigned short i = 0; i <= arrayCustomers - 1; i++) {//for loop to display active fares
                    if (customer[i].getIdNum() != "") {//if fare index id num is not empty, carry on with display
                        printf("%*d). ", 3, i);
                        customer[i].printCustomerDetails();
                    } else {//if fare index id num is empty, don't carry on with display(Print error message
                        cout << "\tIs empty. Enter 2nd Option and schedule fare.\n";
                    }

                }

                person.printSeperator();
                goto MENU;



                /*execute command 2, 
                 * Schedule fares*/

            case 2: cout << "\n\tScheduling fares";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Schedule Fares");

                do {//loop this statement while theres less than six fares

                    addCus = person.checkInputArrayIndex(arrayCustomers, i); //check if theres less than 6 fares
                    if (!addCus) {//if not
                        cout << "\n\tError:You can only order 6 fares" << endl; //output error message
                        person.printSeperator();
                        goto MENU;
                    }
                    else {
                        customer[i++].scheduleFare(); //schedule fare, increment the customer by one


                        cout << "\n\tDisplaying all driver details";
                        person.slightPause(); //execute a slight pause for better execution
                        cout << "\n\n";

                        person.printVehiclesDriversHeadings("ID No.", "Name", "Address", "Phone No.", "KMS Driven",
                                "Start Date", "License Type", "Is Available", "Revenue");

                        for (unsigned short i = 0; i <= arrayDrivers - 1; i++) {
                            printf("%*d). ", 3, i); //print the index and increment by one per driver
                            drivers[i].printDriverDetails();
                        }

                        do {
                            cout << "\n\tWhich driver would you like: ";
                            cin >> arrayIndex;
                            validInput = person.isInt(arrayIndex)
                                    && person.checkInputArrayIndex(arrayDrivers, arrayIndex)
                                    && driver.checkDriversAvail(drivers[arrayIndex].getIsDriverIsAvail());
                            if (!validInput) {
                                cout << "\n\t\tPlease try again\n" << endl;
                            } else {
                                cout << "\n";
                                person.printVehiclesDriversHeadings("ID No.", "Name", "Address", "Phone No.", "KMS Driven",
                                        "Start Date", "License Type", "Is Available", "Revenue");
                                drivers[arrayIndex].printDriverDetails();
                                drivers[arrayIndex].setDriverIsAvail(false);
                                customer[i - 1].setIdNum(drivers[arrayIndex].getIdNum());
                                report.setTotalRevenue(customer[i - 1].getFareCost());
                            }
                        } while (!validInput);

                        cout << "\n\tDisplaying all vehicle details"; //display all vehicle details
                        person.slightPause(); //execute a slight pause for better execution
                        cout << "\n\n";

                        person.printVehiclesDriversHeadings("Type", "Registration No.", "Make", "Model", "Mileage", "Capacity",
                                "Wheelchair", "Is Available", "Revenue");
                        for (unsigned short i = 0; i <= arrayVehicles - 1; i++) {//for loop to display vehicle details
                            printf("%*d). ", 3, i); //print the index and increment by one per vehicle
                            vehicles[i].printVehicleDetails(); //print vehicle details
                        }

                        do {
                            cout << "\n\tWhich vehicle would you like: "; //ask user which vehicle they would like
                            cin >> arrayIndex; //input its index
                            validInput = person.isInt(arrayIndex)
                                    && person.checkInputArrayIndex(arrayVehicles, arrayIndex)
                                    && vehicle.checkVehiclesAvail(vehicles[arrayIndex].getVehicleIsAvail()
                                    && vehicle.wheelchairAccessible(vehicles[arrayIndex].getIsWheelChair(), customer[i - 1].getWheelChairNum())); //validate user input

                            if (!validInput) {//if user input is not valid
                                cout << "\n\t\tPlease try again\n" << endl; //display error message
                            } else {//if user input is valid
                                cout << "\n";
                                person.printVehiclesDriversHeadings("Type", "Registration No.", "Make", "Model", "Mileage", "Capacity",
                                        "Wheelchair", "Is Available", "Revenue"); //if display information menu 
                                vehicles[arrayIndex].printVehicleDetails(); //print vehicle details according to index from user input
                                vehicles[arrayIndex].setVehicleAvail(false); //set vehicle index selected by user to unavailable
                                customer[i - 1].setRegistrationNum(vehicles[arrayIndex].getRegistrationNum()); //set vehicle registration num to customer array information
                                
                            }
                        } while (!validInput);
                        
                        person.printSeperator();
                        goto MENU;
                        
                    }
                } while (!addCus);


                /*execute command 3, 
                 * display vehicle details*/


            case 3: cout << "\n\tDisplaying all vehicle details";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Vehicle Details");

                person.printVehiclesDriversHeadings("Type", "Registration No.", "Make", "Model", "Mileage", "Capacity",
                        "Wheelchair", "Is Available", "Revenue");
                for (unsigned short i = 0; i <= arrayVehicles - 1; i++) {//loop through the array
                    vehicles[i].printVehicleDetails(); //display vehicle details
                }

                person.printSeperator();
                goto MENU;


                /*execute command 4, 
                 * display driver details*/


            case 4: cout << "\n\tDisplaying all driver details";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Driver Details");

                person.printVehiclesDriversHeadings("ID No.", "Name", "Address", "Phone No.", "KMS Driven",
                        "Start Date", "License Type", "Is Available", "Revenue");
                for (unsigned short i = 0; i <= arrayDrivers - 1; i++) {//loop through array
                    drivers[i].printDriverDetails(); //display driver details
                }

                person.printSeperator();
                goto MENU;


                /*execute command 5, 
                 * display and log return from scheduled fares
                 */


            case 5: cout << "\n\tLog return from scheduled fares";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Return Log");

                if (customer[0].getIdNum() == "" && customer[1].getIdNum() == "" && customer[2].getIdNum() == ""
                        && customer[3].getIdNum() == "" && customer[4].getIdNum() == "" && customer[5].getIdNum() == "") {//check if entire log is empty
                    cout << "\tEntire Log is empty" << "\n\n";
                    person.printSeperator();
                    goto MENU;
                } else {//if not carry on with logging in fare returns

                    for (unsigned short i = 0; i <= arrayCustomers - 1; i++) {//for loop to display active fares
                        if (customer[i].getIdNum() != "") {//if fare index id num is not empty, carry on with display
                            printf("%*d). ", 3, i);
                            customer[i].printCustomerDetails();
                            cout << "\n";
                        } else {//if fare index id num is empty, don't carry on with display(Print error message
                            cout << "\tIs empty. Enter 2nd Option and schedule fare.\n";
                        }
                    }

                    do {
                        cout << "\n\tWhich fare would you like to return: ";
                        cin >> arrayIndex;
                        validInput = person.isInt(arrayIndex)
                                && person.checkInputArrayIndex(arrayCustomers, arrayIndex)
                                && cus.checkArrayEmpty(customer[arrayIndex].getIdNum());
                        if (!validInput) {
                            cout << "\t\tPlease try again" << endl;
                        } else {

                            do {
                                cout << "\n\tEnter index of the driver that was assigned to this customer: ";
                                cin >> x;
                                returnInfo = person.isInt(x)
                                        && person.checkInputArrayIndex(arrayDrivers, x);
                                if (!returnInfo) {
                                    cout << "\t\tPlease try again" << endl;
                                } else {
                                    cout << "\n";
                                    person.printVehiclesDriversHeadings("ID No.", "Name", "Address", "Phone No.", "KMS Driven",
                                            "Start Date", "License Type", "Is Available", "Revenue");
                                    drivers[x].printDriverDetails();
                                    drivers[x].setDriverIsAvail(true);
                                    drivers[x].setKmDriven(drivers[x].getKmDriven() + customer[arrayIndex].getJourneyLength()); //calculate driver total km driven
                                    drivers[x].setDriverTotalRev((customer[arrayIndex].getJourneyLength() *6.50) + 5);

                                }
                            } while (!returnInfo);

                            do {
                                cout << "\n\tEnter index of the vehicle that was assigned to this customer: ";
                                cin >> x;
                                returnInfo = person.isInt(x)
                                        && person.checkInputArrayIndex(arrayVehicles, x);
                                if (!returnInfo) {
                                    cout << "\t\tPlease try again" << endl;
                                } else {
                                    cout << "\n";
                                    person.printVehiclesDriversHeadings("Type", "Registration No.", "Make", "Model", "Mileage", "Capacity",
                                            "Wheelchair", "Is Available", "Revenue"); //if display information menu 
                                    vehicles[x].printVehicleDetails(); //print vehicle details according to index from user input
                                    vehicles[x].setVehicleAvail(true);
                                    vehicles[x].setMileage(vehicles[x].getMileage() + customer[arrayIndex].getJourneyLength()); //calculate vehicle total mileage
                                    vehicles[x].setVehicleTotalRev((customer[arrayIndex].getJourneyLength()*6.50) + 5); // vehicle
                                }
                            } while (!returnInfo);


                            cout << "\n\tFare has been returned" << endl;
                        }
                    } while (!validInput);

                    person.printSeperator();
                    goto MENU;

                }




                /*execute command 6, 
                 * display and daily report
                 */


            case 6: cout << "\n\tPrinting daily report";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                person.printHeading("Daily Report");

                cout << "\n\tPrinting drivers daily report";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";

                person.printVehiclesDriversHeadings("ID No.", "Name", "Address", "Phone No.", "Total KMs",
                        "Start Date", "License Type", "Is Available", "Revenue");
                for (unsigned short i = 0; i <= arrayDrivers - 1; i++) {//loop through array
                    printf("%*d). ", 3, i); //print the index and increment by one per driver
                    drivers[i].printDriverDetails(); //display driver details
                }

                cout << "\n\n";

                cout << "\n\tPrinting vehicle daily report";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";

                person.printVehiclesDriversHeadings("Type", "Registration No.", "Make", "Model", "Total Mileage", "Capacity",
                        "Wheelchair", "Is Available", "Revenue");
                for (unsigned short i = 0; i <= arrayVehicles - 1; i++) {//loop through the array
                    printf("%*d). ", 3, i); //print the index and increment by one per driver
                    vehicles[i].printVehicleDetails(); //display vehicle details
                }

                cout << "\n\n";

                report.displayRevenue();

                person.printSeperator();
                goto MENU;


                /*execute command 7, 
                 * Close Program
                 */


            case 7: cout << "\n\tClosing Program";
                person.slightPause(); //execute a slight pause for better execution
                cout << "\n\n";
                exit(0);

        }

    return 0;
}

