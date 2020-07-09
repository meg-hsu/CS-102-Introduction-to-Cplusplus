// Name: Midterm (Calculating Service Fees)
// Author: Meg Hsu
// Due Date: 8 July 2020
// Description: This is a program that allows you to calculate the amount of service fees charged each month using the initial amount of money in the bank account and the amount of checks used each week.

#include <iostream>
#include <iomanip>
using namespace std;

//Function Name: charge
//Purpose: The purpose of this function is determine whether the initial amount of money in the bank account is more or less than 300, which determines if there will be an additional fee.
//Parameter: n/a
//Return: 0 or 25. 0 being no amount of money charged as the amount of money in the account has more than or equal to $300 ad 25 if the amount of money in the acconut has less than $300.

double charge() {
	std::cout
			<< "Please enter the initial amount of money in your bank account: ";
	double value;
	std::cin >> value;
	if (value < 0) {
		std::cout
				<< "The amount of money entered as the initial amount indicates that your bank account has been overdrawn; please resolve this issue as soon as possible. \n"
						"As your account has less than $300.00, a $25.00 fee will be charged to your account.\n";
		return 25.00;
	} else if (value > 0 && value < 300) {
		cout
				<< "As your account has less than $300.00, a $25.00 fee will be charged to your account.\n"
				<< value - 25 << ".";
		return 25.00;
	} else if (value >= 300) {
		return 0.00;
	} else {
		return 0;
	}
}

//Function Name: amountchargedchargechecks
//Purpose: The purpose of this function is determine how much money is charged for the amount of checks used. The amount charged depends on the number of checks used.
//Parameter: n/a
//Return: The number returned is the amount of money charged for the number of checks used in the pertaining month.

double amountchargedchargechecks() {
	while (true) {
		std::cout
				<< "Please enter the amount of checks you have used this month: ";
		double value;
		std::cin >> value;
		if (value < 0) {
			std::cout << value << " is not a valid amount of checks.";
			std::cout << " Please enter zero or a positive number.\n";
		} else if (value >= 0 && value < 10) {
// no value = value * 1 because it's the same thing as itself
			return value;
		} else if (value >= 10 && value < 30) {
// value = value * .75 because checks are $.075 each when there are 10-29 checks
			value = value * .75;
			return value;
		} else if (value >= 30 && value < 50) {
// value = value * .50 because checks are $.075 each when there are 30-49 checks
			value = value * .5;
			return value;
		} else if (value >= 50) {
// value = value * .25 because checks are $.025 each when there are 50 or more checks
			value = value * .25;
			return value;
		}
	}
}

int main() {
	while (true) {
		double bankbalance, chargechecks;
		std::cout
				<< "This program is used to calculate service fees given the initial amount in a bank account and the number of checks used this month.\n";
		bankbalance = charge();
		chargechecks = amountchargedchargechecks();
// the following if/else if statements determine the output of the program based on if there is a low balance fee and if the user has used any checks.
		if (bankbalance == 0 && chargechecks > 0) {
            // bankbalance == 0 && chargechecks > 0 means the user has an account balance of $300 or more and has used some number of checks in the month calculated.
			std::cout
					<< "\nAs your account initially had at least $300 in it, the low balance fee does not apply. \n"
							"The amount of money charged for the number of checks you have used this month is $"
					<< fixed << showpoint << setprecision(2) << chargechecks << ", for a total of $"
					<< fixed << showpoint << setprecision(2) << chargechecks << " charged this month.";
		} else if (bankbalance == 25 && chargechecks > 0) {
            // bankbalance == 25 && chargechecks > 0 means the user has an account balance of less than $300 and has used some number of checks in the month calculated.
			std::cout
					<< "\nAs your account initially did not have at least $300.00 in it, a low balance fee of $25.00 will be charged. \n"
					   "The amount of money charged for the number of checks you have used this month is $"
					<< fixed << showpoint << setprecision(2) << chargechecks << ", for a total amount of $"
					<< fixed << showpoint << setprecision(2) << chargechecks + 25 << " charged this month.";
		} else if (bankbalance == 0 && chargechecks == 0) {
            // bankbalance == 0 && chargechecks > 0 means the user has an account balance of $300 or more and did not use any checks in the month calculated.
			std::cout
					<< "\nAs your account initially had at least $300.00 in it, the low balance fee does not apply. \n"
							"In addition, since no checks were used this month, there is no fee for them as well. \n"
							"In total, there are no service fees applicable this month.";
		} else if (bankbalance == 25 && chargechecks == 0) {
            // bankbalance == 25 && chargechecks > 0 means the user has an account balance of less than $300 and did not use any checks in the month calculated.
			std::cout
					<< "\nAs your account initially did not have at least $300.00 in it, a low balance fee of $25.00 will be charged. \n"
							"As no checks have been used this month, there will be no fees charged for them. \n"
							"The total amount charged this month is $25.00.";
		}

        //the following code is used to prompt the user if they want to run the program again.
		std::cout << "\n\nWould you like to run this program again? (y/n) ";
		std::string yesorno;
		std::cin >> yesorno;
		if (yesorno == "Y" or yesorno == "y") {
			std::cout << "\n";
		}
		if (yesorno == "N" or yesorno == "n") {
			break;
		}
	}
	return 0;
}
