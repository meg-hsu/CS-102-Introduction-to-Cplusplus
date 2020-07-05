#include <iostream>
#include<iomanip>
#include <time.h>
//using namespace std;

int twelvetotwentyfour(std::string name){
	int twelveh_hour, twelveh_minute, twelveh_second;
	std::string am_pm;
	std::cout << "This option converts time from 12-hour notation to 24-hour notation.\n"
				 "Please enter in the hour value for the time that will be converted: ";
	std::cin >> twelveh_hour;
	std::cout << "Please enter in the minute value for the time that will be converted: ";
	std::cin >> twelveh_minute;
	std::cout << "Please enter in the second value for the time that will be converted: ";
	std::cin >> twelveh_second;
	std::cout << "The time that has been input is " << twelveh_hour
			  << ":"  << twelveh_minute << ":"
			  << twelveh_second << ". Is it in AM or PM? ";
// << std::setfill('0') << std::setw(2)
	std::cin >> am_pm;
	if (am_pm == "am" or am_pm == "AM" or am_pm == "Am"){
		std::cout << "The time " << twelveh_hour << ":" << twelveh_minute << ":" <<
				twelveh_second << " " << am_pm << " in twelve hour format is " << twelveh_hour << ":" << twelveh_minute << ":" <<
				twelveh_second << " in twenty four hour format.";
	}
	if (am_pm == "pm" or am_pm == "PM" or am_pm == "Pm"){
		std::cout << "The time " << twelveh_hour << ":" << twelveh_minute << ":"
				<< twelveh_second << " " << am_pm
				<< " in twelve hour format is " << (twelveh_hour + 12) << ":"
				<< twelveh_minute << ":" << twelveh_second
				<< " in twenty four hour format.";
	}
	return 0;
}

int twentyfourtotwelve(std::string name){
	int twentyfourh_hour, twentyfourh_minute, twentyfourh_second;
	std::cout << "This option converts time from 12-hour notation to 24-hour notation.\n"
				 "Please enter in the hour value for the time that will be converted: ";
	std::cin >> twentyfourh_hour;
	std::cout << "Please enter in the minute value for the time that will be converted: ";
	std::cin >> twentyfourh_minute;
	std::cout << "Please enter in the second value for the time that will be converted: ";
	std::cin >> twentyfourh_second;
	// << std::setfill('0') << std::setw(2)
	if (twentyfourh_hour > 12) {
		std::cout << "The time " << twentyfourh_hour << ":" << twentyfourh_minute
				<< ":" << twentyfourh_second << " in twenty four hour format is "
				<< (twentyfourh_hour - 12) << ":" << twentyfourh_minute << ":"
				<< twentyfourh_second << " PM in twelve four hour format.";
	}
	if (twentyfourh_hour <= 12){
		std::cout << "The time " << twentyfourh_hour << ":" << twentyfourh_minute << ":"
				<< twentyfourh_second << " in twenty four hour format is " << (twentyfourh_hour - 12) << ":"
				<< twentyfourh_minute << ":" << twentyfourh_second
				<< " AM in twelve hour format.";
	}
	return 0;
}

int main() {
	std::cout
			<< "This program is used to convert time from 12-hour notation to 24-hour notation and "
					"vice versa. \nPlease enter select which option you would like to use:\n"
					"1. Convert from 12-hour notation to 24-hour notation\n"
					"2. Convert from 24-hour notation to 12-hour notation\n"
					"3. Quit program\n";
	std::cout << "Which select which option you would like to use: ";
	int answer;
	std::cin >> answer;
	if (answer == 1) {
		answer = twelvetotwentyfour("a");
	}
	if (answer == 2){
		answer = twentyfourtotwelve("a");
	}

	return 0;
}
