/***************************************************************
Title:			Date.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	The header file for the class function. This class
				contains the key components of a date (month, day, year)
				and how the compiler cin, couts, and compares two different
				dates. This will be used in order to compare the deadline
				of two different tasks in order to sort them. Since the deadline
				the user inputs will be cin'd as a string, the private members
				are all strings instead of ints. 
***************************************************************/
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;
class Date {
public:
	/** Date() - default constructor
	  */
	Date() {};

	/** Date() - overloaded constructor, sets deadline date when LOAD command 
				 is called. Since we can assume the user will input the date in
				 MM/DD/YYYY format, we break down that string using substrings 
				 and save the MM part to month, the DD part to day, and the YYYY 
				 part to year.
	 *@param - string 	deadline	[in]	Task deadline
	 *@return - a string, date's deadline
	 */
	Date(string deadline);

	/** getDate() - returns date in MM/DD/YYYY format.
	 *@return - a string, date format.
	 */
	string getDate() const;

	/** operator>> - istream operator to cin a date correctly using getline. Breaks down
					 the date to assign it to the corresponding private member by tracking
					 the "/" character in dates.
	 *@param -	istream 	in 		[in]	input stream
	 *@param -	Date 		date 	[in] 	Task date
	 *@return - in, istream for date class
	 */
	friend istream& operator>>(istream& in, Date& date);

	/** operator<< - ostream operator, outputs date in MM/DD/YYYY format.
	 *@param -	ostream 	out 	[in]	output stream
	 *@param -	Date 		date 	[in] 	Task date
	 *@return - out, ostream for date class
	 */
	friend ostream& operator<<(ostream& out, const Date& date);

	/** operator== - comparator operator for Date class, checks to see if 
					 two dates are the same by comparing their years, months,
					 then dates in that respective order.
	 *@param -	Date 		lhs 	[in]	first date in comparison
	 *@param -	Date 		rhs 	[in] 	second date in comparison
	 *@return - true if dates are equal, false otherwise.
	 */
	friend bool operator==(const Date& lhs, const Date& rhs);

	/** operator > - comparator operator for Date class, compares
					 two dates then checks to see which date is bigger
					 by comparing their years, months, then dates in that
					 respective order.
	 *@param -	Date 		lhs 	[in]	first date in comparison
	 *@param -	Date 		rhs 	[in] 	second date in comparison
	 *@return - true if lhs(first date) is greater, false if rhs(second date)
	 			is greater.
	 */
	friend bool operator >(const Date& lhs, const Date& rhs);

private:
	string month, day, year;
};
#endif