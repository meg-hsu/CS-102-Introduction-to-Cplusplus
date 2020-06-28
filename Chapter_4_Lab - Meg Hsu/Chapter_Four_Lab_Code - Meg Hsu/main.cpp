//
//  main.cpp
//  Chapter_Four_Lab_Code - Meg Hsu
//
//  Created by Meg Hsu on 6/27/20.
//  Copyright © 2020 Meg Hsu. All rights reserved.
//

#include <iostream>
#include <iomanip>


int main() {
    
    std::cout << "This program is used to calculate the body fat of someone. Is the person in question a male or female? ";
    std::string gender;
    std::cin >> gender;
    double bweight, wrist, waist, hip, forearm, A1, A2, A3, A4, A5, B, Bf, Bfpercent;
    
    if (gender == "female" or gender == "Female"){
        std::cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- wrist measurement (at fullest point)\n- waist measurement (at navel)\n- hip measurement (at fullest point)\n- forearm measurement (at fullest point)\n";
        
        std::cin >> bweight >> wrist >> waist >> hip >> forearm;
        
        if (bweight < 0){
            std::cout << bweight << " isn't a proper measurement. Would you like to input another? (y/n) ";
                std::string ans;
                std::cin >> ans;
                if (ans == "y" or ans == "Y"){
                    std::cout << "Please enter a positive value for body weight: ";
                    std::cin >> bweight;
                    std::cout << "\n";
                }
                if (ans == "n" or ans == "N"){
                    return 0;}
        }
        
         if (wrist < 0){
             std::cout << wrist << " isn't a proper measurement. Would you like to input another value? (y/n) ";
                 std::string ans;
                 std::cin >> ans;
                 if (ans == "y" or ans == "Y"){
                     std::cout << "Please enter a positive value for the wrist measurement: ";
                     std::cin >> wrist;
                     std::cout << "\n";
                     }
                 if (ans == "n" or ans == "N"){
                     return 0;}
         }
        
            if (waist < 0){
                std::cout << waist << " isn't a proper measurement. Would you like to input another value? (y/n) ";
                    std::string ans;
                    std::cin >> ans;
                    if (ans == "y" or ans == "Y"){
                        std::cout << "Please enter a positive value for the waist measurement: ";
                        std::cin >> waist;
                        std::cout << "\n";
                        }
                    if (ans == "n" or ans == "N"){
                        return 0;}
            }
        
            if (hip < 0){
                std::cout << hip << " isn't a proper measurement. Would you like to input another value? (y/n) ";
                    std::string ans;
                    std::cin >> ans;
                    if (ans == "y" or ans == "Y"){
                        std::cout << "Please enter a positive value for the hip measurement: ";
                        std::cin >> hip;
                        std::cout << "\n";
                    }
                    if (ans == "n" or ans == "N"){
                        return 0;}
            }
        
            if (forearm < 0){
                std::cout << forearm << " isn't a proper measurement. Would you like to input another value? (y/n) ";
                    std::string ans;
                    std::cin >> ans;
                    if (ans == "y" or ans == "Y"){
                        std::cout << "Please enter a positive value for the forearm measurement: ";
                        std::cin >> forearm;
                        std::cout << "\n";
                        }
                    if (ans == "n" or ans == "N"){
                        return 0;}
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
         }
            

    if (gender == "male" or gender == "Male"){
        std::cout << "Please enter the following measurements of the person in question, with each value seperated by a space:\n- body weight \n- wrist measurement (at fullest point)\n";
        
           std::cin >> bweight >> wrist;
           if (bweight < 0){
               std::cout << bweight << " isn't a proper measurement. Would you like to input another? (y/n) ";
                   std::string ans;
                   std::cin >> ans;
                   if (ans == "y" or ans == "Y"){
                       std::cout << "Please enter a positive value for body weight: ";
                       std::cin >> bweight;
                       std::cout << "\n";
                   }
                   if (ans == "n" or ans == "N"){
                       return 0;}
           }
        
            if (wrist < 0){
                std::cout << wrist << " isn't a proper measurement. Would you like to input another value? (y/n) ";
                    std::string ans;
                    std::cin >> ans;
                    if (ans == "y" or ans == "Y"){
                        std::cout << "Please enter a positive value for the wrist measurement: ";
                        std::cin >> wrist;
                        std::cout << "\n";
                        }
                    if (ans == "n" or ans == "N"){
                        return 0;}
            }
            
                A1 = (bweight * 1.082) + 94.42;
                A2 = wrist * 4.15;
                B = A1 - A2;
                Bf = bweight - B;
                Bfpercent = (Bf * 100)/bweight;
                std::cout << "The total body fat percentage from the values given is " << Bfpercent << ".\n";
            }

    
   
    std::cout << "\nWould you like to run this program again? (y/n) ";
    std::string ans;
    std::cin >> ans;
    if (ans == "y" or ans == "Y"){
        std::cout << " \n";
        // \n used for formatting purposes
        return main(); }
    if (ans == "n" or ans == "N"){
        return 0;}
    
}
