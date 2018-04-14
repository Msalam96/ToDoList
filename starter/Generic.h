/***************************************************************
Title:			Generic.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	Header file for generic tasks. Mostly defines how to to print
				the list when PRINT command is called or DETAILED.
***************************************************************/

#ifndef GENERIC_H
#define GENERIC_H

#include "Task.h"

class Generic : public Task {
public:
	//Default constrcutor that will output the instructions when ADD command is called. Sets tasktype to G.
	Generic();
	//Overloaded constructor that is called when LOAD Command is called. function that is called using istream, 
	//since the file to be loaded is in a specific format t goes character by character in order to determine 
	//which specific character is which. When a "|" is found it means that a new piece of a Task is found in the line.
	Generic(string line);
	//prints list according to specs
	void printList();
	//detailed list for generic task types are the same as normal print, call printlist again	
	void detailedPrint() {printList();};
	//Outputs the task to a text file when SAVE command is called
	string printtoFile();
};

#endif