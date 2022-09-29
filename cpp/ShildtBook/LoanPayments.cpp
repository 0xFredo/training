/*
	Project 2-3
	Regular payments for a loan.

	formula: payment fee = InterestRate * (TotalAmount/PaymentsPerYear) 
						   --------------------------------------------
							1 - ((InterestRate / PaymentPerYear) + 1)pow(-PaymentPerYear*NumYears) 
*/

#include <iostream>
#include <cmath>

int main()
{
	double startingBalance;
	double interestRate;
	double paymentsPerYear;
	double numYears;
	double paymentResult;
	double numerator;
	double denominator;
	double base, exponent;

	std::cout << "Enter starting balance: ";
	std::cin >> startingBalance;

	std::cout << "Enter interest rate (i.e. 0.075, that is 7.5%): ";
	std::cin >> interestRate;

	std::cout << "Enter number of payments per year: ";
	std::cin >> paymentsPerYear;

	std::cout << "Enter number of years: ";
	std::cin >> numYears;

	numerator = interestRate * (startingBalance / paymentsPerYear);

	base = (interestRate / paymentsPerYear) + 1;
	exponent = -(paymentsPerYear * numYears);

	denominator = 1 - pow(base, exponent);

	paymentResult = numerator / denominator;

	std::cout << "Payment is " << paymentResult;

}