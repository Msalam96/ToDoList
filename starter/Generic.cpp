/***************************************************************
Title:			Generic.cpp
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	Defines functions of the Generic Class. Only tricky
				part here was the overloaded constructor which takes in 
				a single line from a file and breaks it up piece by piece
				to a temp string. The string will determine where we are
				currently at in the file. This will be called in the LOAD function
				as a new Task will be created and the the private members will be 
				set accordingly. 
***************************************************************/

#include "Generic.h"

using namespace std;
Generic::Generic() {
	addInstructions();
	settaskType("G");
}

void Generic::printList() {
	cout << deadline().getDate() + " - " + description();
}

Generic::Generic(string line) {
	string str = "";
	int i = 0;
	while (line.size() != 0) {
		if (line[0] == '|' || line.size() == 1) {
			if(line.size() == 1) {
				str += line[0];
			} 
			if (i == 0) {
				++i;
				taskType_ = "Generic";
			} else if (i == 1) {
				++i;
				Date date(str);
				deadline_ = date;
			} else {
				description_ = str;
			}
			line.erase(line.begin());
			str = "";
		} else {
			str += line[0];
			line.erase(line.begin());
		}
	}
}

string Generic::printtoFile() {
	string s = taskType() + "|" + deadline().getDate() + "|" + description();
	return s;
}
