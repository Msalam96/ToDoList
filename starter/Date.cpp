/***************************************************************
Title:			Date.cpp
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	Cpp file for the Date class, defines all non inline
				functions of the class. 
***************************************************************/
#include "Date.h"

using namespace std;
Date::Date(string deadline) {
	month = deadline.substr(0,2);
	day   = deadline.substr(3,2);
	year  = deadline.substr(6,4);
}

string Date::getDate() const {
	string date = month + "/" + day + "/" + year;
	return date;
}

istream& operator>>(istream& in, Date& date) {
	getline(in, date.month, '/');
	getline(in, date.day,   '/');
	getline(in, date.year);

	date.month.erase(std::remove(date.month.begin(), date.month.end(), '\n'), date.month.end());

	return in;
};

ostream& operator<<(ostream& out, const Date& date) {
	out << date.month << "/" << date.day << "/" << date.year;
	return out;
}

bool Date::operator==(const Date& rhs) {
	return ((year == rhs.year) && (month == rhs.month) && (day == rhs.day));
}

bool Date::operator >(const Date& rhs) {
	if (year < rhs.year) {
      return false;
    } 
    if (year == rhs.year) {
    	if (month < rhs.month) { 
          return false;
        } 
        else if (month == rhs.month) {
             if (day < rhs.day) {
                return false;
             }
        }
    }
    return true;
}
