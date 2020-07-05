//
//  main.cpp
//  Chapter_Five_Lab_Code
//
//  Created by Meg Hsu on 6/30/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.
//
// Program Name: Chapter Five Lab (Profit Maximization Calculator)
// Author: Meg Hsu
// Date: 3 July 2020
// Description: This program is used to calculate the amount of apartments that need to be rented out to make the maximum amount of profit.

#include <iostream>
#include <cmath>
using namespace std;

//Function Name: get_value
//Purpose: To make sure values used in the program are positive numbers
//Parameter: The name of the measurements used in this program
//Return Code: Returns a positive number. If the value used is negative, the program will make the user input a valid number.

int get_value(string name){
    while(true){
        cout << "Please enter a value for " << name << ": ";
        int value;
        cin >> value;
        if (value <=0){
            cout << value << " is not a valid measurement for " << name << ".";
            cout << " Please enter a positive number.\n\n";
        }
        else {
            return value;
        }
    }
}

//Function Name: main
//Purpose: Entry of program
//Parameter: n/a
//Return Code: returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.

int main() {
    int n_apartment;
    double rent, increase_in_rent, maintenance_cost, number_units;
    
    cout << "This program is used to calculate maximum profit when renting out apartment buildings using the given information. Please enter the following information:\n- number of apartments\n- initial amount of rent\n- the increase in rent that results in a vacant unit\n- cost of maintenance per apartment\n\n";
    
//The following code uses the funtion defined above to make sure the values used are positive.
    
    n_apartment = get_value("the number of apartments");
    rent = get_value("the amount of rent");
    increase_in_rent = get_value("the increase in rent that results in a vacant unit");
    maintenance_cost = get_value("the cost of maintenance");

//The code below consists of all the calculations to calculate the amount of apartments needed to make the most amount of money.
    
    number_units = (increase_in_rent*n_apartment+rent-maintenance_cost)/(2*increase_in_rent);
    
    cout << "\nThe number of units that need to be rented to make the most profit is " << round(number_units) << ".\n" ;

// The following code is used to ask the user if they want to use the program again. If not, the program ends.
    cout << "\nWould you like to run this program again? (y/n) ";
    string ans;
    cin >> ans;
    if (ans == "y" or ans == "Y"){
        cout << " \n";
        // \n used for formatting purposes
        return main(); }
    if (ans == "n" or ans == "N"){
        return 0;}
    
    return 0;
    
}
