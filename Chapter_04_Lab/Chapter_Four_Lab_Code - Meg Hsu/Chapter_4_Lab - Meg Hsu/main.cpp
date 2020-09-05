//
//  main.cpp
//  Chapter_Four_Lab_Code - Meg Hsu
//
//  Created by Meg Hsu on 6/27/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.

// Program Name: Chapter Four Lab (Body Fat Calculator)
// Author: Meg Hsu
// Date: 26 June 2020
// Description: This program is used to calculate the body fat of a person using information provided by the person using this program.

#include <iostream>
#include <iomanip>

using namespace::std;

//Function Name: get_value
//Purpose: To make sure values used in the program are positive numbers
//Parameter: The name of the measurements used in this program
//Return Code: Returns a positive number. If the value used is negative, the program will make the user input a valid number.

int get_value(string name){
    while(true){
        cout << "Please enter a measurement for " << name << ": ";
        int value;
        cin >> value;
        if (value <=0){
            cout << value << " is not a valid measurement for " << name << ".";
            cout << " Please enter a positive number.\n";
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

int main(){
    
    cout << "This program is used to calculate the body fat of someone. Is the person in question a male or female? ";
    string gender;
    double bweight, wrist, waist, hip, forearm, A1, A2, A3, A4, A5, B, Bf, Bfpercent;
    cin >> gender;
    
    if (gender == "female" or gender == "Female"){
        cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- wrist measurement (at fullest point)\n- waist measurement (at navel)\n- hip measurement (at fullest point)\n- forearm measurement (at fullest point)\n";
        
//the following code uses the funtion defined above to make sure the values used are positive.
        bweight = get_value("bweight");
        wrist = get_value("wrist");
        waist = get_value("waist");
        hip = get_value("hip");
        forearm = get_value("forearm");
  
//the code below consists of all the calculations to calculate the body fat percentage and also outputs the result.
        A1 = (bweight * 0.732) + 8.987;
        A2 = wrist/3.14;
        A3 = waist * 0.157;
        A4 = hip * 0.249;
        A5 = forearm * 0.434;
        B = A1 + A2 - A3 - A4 + A5;
        Bf = bweight - B;
        Bfpercent = (Bf * 100)/bweight;
        cout << "The total body fat percentage from the values given is " << Bfpercent << ".\n";
    }
    
    if (gender == "male" or gender == "Male"){
        cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- waist measurement (at navel)\n";

//the following code uses the funtion defined above to make sure the values used are positive.
        bweight = get_value("bweight");
        waist = get_value("waist");

//the code below consists of all the calculations to calculate the body fat percentage and also outputs the result.
        A1 = (bweight * 1.082) + 9.42;
        A2 = waist * 4.15;
        B = A1 - A2;
        Bf = bweight - B;
        Bfpercent = (Bf * 100)/bweight;
        cout << "The total body fat percentage from the values given is " << Bfpercent << ".\n";
    }
    
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
}
