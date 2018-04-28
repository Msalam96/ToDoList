/***************************************************************
Title:			ToDolistDriver.h
Author:			Mohammed Salam
Date Created:		3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:		Since we were given a ToDoListDriver, i have implemented
			it in the sense that they will be called when a 
			specific command is called by the user. The function that is called
			by a specific command is clear cut. As are most of the functions. 
***************************************************************/
#ifndef TODOLISTDRIVER_H
#define TODOLISTDRIVER_H

#include <iostream>
#include <fstream>
#include "SortedTaskList.h"

using namespace std;

void addTask(SortedTaskList* tasks);
void printTask(SortedTaskList* tasks);
void printDetailed(SortedTaskList* tasks);
void printCompleted(SortedTaskList* tasks);
void removeTask(SortedTaskList* tasks);
void completeTask(SortedTaskList* tasks);
void saveTask(SortedTaskList* tasks);
void loadTask(SortedTaskList* tasks);

#endif
