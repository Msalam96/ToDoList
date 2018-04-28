/***************************************************************
Title:			Shopping.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	Header file for shopping task functions
***************************************************************/

#ifndef SHOPPING_H
#define SHOPPING_H

#include <vector>
#include "Task.h"

class Shopping : public Task {
public:
	/**Shopping() - default constructor, calls addInstruction and asks user which item
	 		they need for their shopping list. Sets tasktype_ to S.
     	 */	
	Shopping();

	Shopping(std::string line);
	~Shopping () {};

	/**pushItem() - adds items to the users Shopping List, 
	 *@param - string item 	[in]	Item to add to shopping list
     	 */	
	void pushItem(std::string item);

	void printList();
	void detailedPrint();
	std::string printtoFile();
	

private:
	std::vector<std::string> shoppingList;
};
#endif
