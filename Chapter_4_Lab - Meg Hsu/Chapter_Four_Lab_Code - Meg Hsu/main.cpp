//
//  main.cpp
//  Chapter_Four_Lab_Code - Meg Hsu
//
//  Created by Meg Hsu on 6/27/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.
//

#include <iostream>
#include <iomanip>

int get_value(std::string name){
    while(true){
        std::cout << "\nPlease enter a measurement for " << name << ": ";
        int value;
        std::cin >> value;
        if (value <=0){
            std::cout << value << " is not a valid measurement for " << name << ".";
            std::cout << " Please enter a positive number.\n";
        }
        else {
            return value;
        }
    }
    
}



int main(){
    
    std::cout << "This program is used to calculate the body fat of someone. Is the person in question a male or female? ";
    std::string gender;
    double bweight, wrist, waist, hip, forearm, A1, A2, A3, A4, A5, B, Bf, Bfpercent;
    std::cin >> gender;
    
    if (gender == "female" or gender == "Female"){
        std::cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- wrist measurement (at fullest point)\n- waist measurement (at navel)\n- hip measurement (at fullest point)\n- forearm measurement (at fullest point)\n";
        
        //std::cin >> bweight >> wrist >> waist >> hip >> forearm;
        bweight = get_value("bweight");
        wrist = get_value("wrist");
        waist = get_value("waist");
        hip = get_value("hip");
        forearm = get_value("forearm");
    }
        
        A1 = (bweight * 0.732) + 8.987;
        A2 = wrist/3.14;
        A3 = waist * 0.157;
        A4 = hip * 0.249;
        A5 = forearm * 0.434;
        B = A1 + A2 - A3 - A4 + A5;
        Bf = bweight - B;
        Bfpercent = (Bf * 100)/bweight;
        std::cout << "The total body fat percentage from the values given is " << Bfpercent << ".\n";
    
    if (gender == "male" or gender == "Male"){
        
        std::cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- wrist measurement (at fullest point)\n";

//        std::cin >> bweight >> wrist;

        bweight = get_value("bweight");
        wrist = get_value("wrist");
    }
        
        A1 = (bweight * 1.082) + 9.42;
        A2 = wrist * 4.15;
        B = A1 - A2;
        Bf = bweight - B;
        Bfpercent = (Bf * 100)/bweight;
        std::cout << "The total body fat percentage from the values given is " << Bfpercent << ".\n";
    }

    
    
//    std::cout << "\nWould you like to run this program again? (y/n) ";
//    std::string ans;
//    std::cin >> ans;
//    if (ans == "y" or ans == "Y"){
//        std::cout << " \n";
//        // \n used for formatting purposes
//        return main(); }
//    if (ans == "n" or ans == "N"){
//        return 0;}
    
//}
