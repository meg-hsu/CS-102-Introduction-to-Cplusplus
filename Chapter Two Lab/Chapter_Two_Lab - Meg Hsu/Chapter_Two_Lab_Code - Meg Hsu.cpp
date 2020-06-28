//
//  main.cpp
//  chapter two lab
//
//  Created by Meg Hsu on 6/17/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.
//


// Name: Meg Hsu
// Description: This is a program that allows you to convert seconds into hours, minutes, and seconds.
// Course: CS 102 - Introduction to Programming C++
// Due Date: 24 June 2020

#include <iostream>
#include<iomanip>

int main() {
//Function Name: main
//Purpose: Entry of program
//Parameter: n/a
//Return Code: returns zero or nonzero value which indicates if the program runs smoothly or if there are any problems.
    std::cout << "Please enter a positive number of seconds you would like converted into hours and minutes: ";
    int sec;
    int min;
    int hour;
    std:: cin >> sec;

//if number of seconds is less than zero
    if (sec < 0){
        std::cout << "This isn't a valid amount of time." ;
    }
    
//if seconds only (program autofills hours and minutes with 0)
    if (sec < 60 && sec >= 0){
        std::cout << "\nThere are 0 hours, 0 minutes, and "<< sec << (sec == 1 ? " second" : " seconds") << " in " << sec << (sec == 1 ? " second" : " seconds") << ", which can be written as\n" << "00:00:" << std::setfill('0') << std::setw(2) << sec << "." ;
        // (sec > 1 == " seconds" : " second") is used to choose between singular or plural form depending on the number given. This is used the same way with minutes and hours throughout the rest of the code.
        // std::setfill('0') and std::setw(2) are used for numbers less than 10. For example, if the output for seconds was 8, the program would display xx:xx:08 instead of xx:xx:8.
        }

    // minutes and seconds (program autofills hours with 0)
    if (3600 > sec && sec >= 60){
        min = sec/60;
        std::cout << "\nThere are 0 hours, " << min << (min > 1 ? " minutes" : " minute") << ", and " << sec-min*60 << (sec-min*60 == 1 ? " second" : " seconds") <<" in " << sec << (sec > 1 ? " seconds" : " second") << ", which can be written as\n" << "00:"<< std::setfill('0') << std::setw(2) << min << ":" << std::setfill('0') << std::setw(2) << sec-min*60 << ".";
        //(min > 1 ? " minutes" : " minute") / (sec-min*60 > 1 ? " seconds" : " second") is used again for grammar issues.
        //sec-min*60 is to identify the remaining seconds after the calculation for minutes has been done.
        //std::setfill('0') and std::setw(2) are used again but for both seconds and minutes.
    }
//hours, minutes, and seconds
    if (3600 <= sec){
        min = sec/60;
        hour = min/60;
        std::cout << "There" << (hour == 1 ? " is " : " are ") << hour << (hour > 1? " hours" : " hour") << ", " << min-hour*60 << (min-hour*60 == 1 ? " minute" : " minutes") << ", and " << sec-min*60 << (sec-min*60 == 1 ? " second" : " seconds") << " in " << sec << (sec > 1 ? " seconds" : " second") << ", which can be written as\n" << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << min-hour*60 << ":" << std::setfill('0') << std::setw(2) << sec-min*60 << ".";}
    //(hour == 1 ? " is " : " are ") is used here to determine whether or not the singular form (is) or plural form (are) should be used in the sentence produced.
    //sec-min*60 is used again here, and min-hour*60 is used as well for minutes.
    //all units of time (seconds, minutes, and hours) use std::setfill('0') and std::setw(2) for formatting purposes.
    //(hour > 1? " hours" : " hour") and variations of it with minutes and seconds are used to ensure that the program outputs the proper grammar based on the input given.
    
    
// the following code is used to ask the user if they want to use the program again. If not, the program ends.
std::cout << "\nWould you like to run this program again? (y/n) ";
    std::string ans;
    std::cin >> ans;
    if (ans == "y" or ans == "Y"){
        std::cout << " \n";
        // \n used for formatting purposes
        return main(); }
    if (ans == "n" or ans == "N"){
        return 0;}
   
return 0;
}
