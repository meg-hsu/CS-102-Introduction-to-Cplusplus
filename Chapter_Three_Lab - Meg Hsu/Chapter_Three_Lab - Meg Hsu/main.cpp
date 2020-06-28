//
//  main.cpp
//  Chapter_Three_Lab_Code - Meg Hsu
//
//  Created by Meg Hsu on 6/22/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.
//

// Program Name: Chapter Three Lab (Credit Card Interest)
// Author: Meg Hsu
// Date: 26 June 2020
// Description: This program is used to calculate the interest on a credit card using information provided by the person using this program.


#include <iostream>
#include <iomanip>
 //iomanip for formatting purposes


//Function Name: main
//Purpose: Entry of program
//Parameter: n/a
//Return Code: returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.
int main() {
    double netBalance;
    int days1;
    int days2;
    double payment;
    std::cout << "Please enter the net balance here: ";
    std::cin >> netBalance;
    std::cout << "\nPlease enter the number of days in the billing cycle: " ;
    std::cin >> days1;
    std::cout << "\nPlease enter the number of days payment is made before billing cycle: ";
    std::cin >> days2;
    std::cout << "\nPlease enter the amount of payment: ";
    std::cin >> payment;
   
    double average_dbalance;
    average_dbalance = (netBalance*days1-payment*days2)/days1;
    
    std::cout << "\nThe average daily balance is $" << std::fixed << std::setprecision(2) << average_dbalance << ".\n";
  //std::fixed and std::setprecision(2) to make sure the program outputs a number with two decimals so it's easy to understand that the output is money
    
    double interest;
    std::cout << "\nPlease enter the interest rate here: ";
    std::cin >> interest;
    std::cout << "\nThe total amount of interest is $" << std::fixed << std::setprecision(2) << average_dbalance*interest << ".\n" ;
    
    
// The following code is used to ask the user if they want to use the program again. If not, the program ends.
    std::cout << "\nWould you like to run this program again? (y/n) ";
    std::string ans;
    std::cin >> ans;
    if (ans == "y" or ans == "Y"){
        std::cout << " \n";
        // \n used for formatting purposes
        return main(); }
    if (ans == "n" or ans == "N"){
        std::cout << " \n";
        return 0;}
    
    return 0;
}
