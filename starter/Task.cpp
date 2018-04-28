/***************************************************************
Title:			Task.cpp
Author:			Mohammed Salam
Date Created:		3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:		Cpp file for the Task class, defines all non inline
			functions of the class. 
***************************************************************/

#include "Task.h"

using namespace std;
Task::Task() {
	completed = false;
}

ostream& operator<<(ostream& out, Task& task) {
	out << task.printtoFile();
	return out;
}

Task& Task::operator=(const Task& rhs) {
	if (this != &rhs) {
		this->description_ = rhs.description_;
		this->deadline_ = rhs.deadline_;
		this->completed = rhs.completed;
	}
	return *this;
}

void Task::addInstructions() {
	cout << "What is the deadline for this task (MM/DD/YYYY format)?" << endl << "> ";
	cin >> deadline_;
	cout << "How would you describe this task?" << endl << "> ";
	getline(cin, description_);
}

