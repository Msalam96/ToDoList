/***************************************************************
Title:			Shopping.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	
***************************************************************/

#ifndef SHOPPING_H
#define SHOPPING_H

#include <vector>
#include "Task.h"

class Shopping : public Task {
public:
	Shopping();
	Shopping(string line);
	~Shopping () {};

	void pushItem(string item);

	void printList();
	void detailedPrint();
	string printtoFile();
	

private:
	vector<string> shoppingList;
};
#endif
