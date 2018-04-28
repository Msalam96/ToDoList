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
	/**Generic() - default constructor, calls addInstruction and sets taskType to G
	 */
	Generic();
	/**Generic() - Overloaded constructor that is called when LOAD Command is called. 
		       Function that is called using istream, since the file to be loaded 
		       is in a specific format it goes character by character in order to 
		       determine which specific character is which. When a "|" is found 
		       it means that a new piece of a Task is found in the line.
	 *@param string	line	[in]	Line read from file
	 */
	Generic(std::string line);

	void printList();
	void detailedPrint() {printList();};
	std::string printtoFile();
};

#endif
