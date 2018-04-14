/***************************************************************
Title:			Date.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	The header file for the Abstract Date Class Task.
				This file will contain the getters and setters of the
				basic task private members that all tasks shares, as well
				as pure virtual functions,
***************************************************************/

#ifndef TASK_H
#define TASK_H

#include "Date.h"

class Task {
public:
	/** Task() - default constructor
	  */
	Task();
	Task(string str, Date d);

	//Friend function that defines the output of tasks
	friend ostream& operator<<(ostream& out, Task& task);

	//copies data from current task into new task for the save function
	Task& operator=(const Task& rhs);

	//Virtual functions that will be defined in the specific task classes. As defined in the
	//Generic header file all tasks will print based off the specific specs given.
	virtual void printList() = 0;
	virtual void detailedPrint() = 0;
	virtual string printtoFile() = 0;

	//Instructions to be called in the default constructor when a new Task is added
	void addInstructions();

	//Getters for the private members of tasks
	string taskType() 	 {return taskType_;};
	string description() {return description_;};
	Date deadline()      {return deadline_;};
	bool status()        {return completed;};

	//Setters for the private members of tasks
	void settaskType(string str)	{taskType_ = str;};
	void setDescription(string str) {description_ = str;};
	void setDeadline(Date d) 		{deadline_ = d;};
	//Sets status of a task to complete
	void complete() 				{completed = true;};

protected: 
	string taskType_, description_;
	Date deadline_;
	bool completed;
};

#endif