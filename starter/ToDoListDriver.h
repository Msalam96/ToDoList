/***************************************************************
Title:			ToDolistDriver.h
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	Since we were given a ToDoListDriver, i have implemented
				it in the sense that they will be called when a 
				specific command is called by the user. The function that is called
				by a specific command is clear cut. As are most of the functions. 
***************************************************************/
#ifndef TODOLISTDRIVER_H
#define TODOLISTDRIVER_H

#include <iostream>
#include <fstream>
#include "List.hxx"

using namespace std;

//Creates a new task according to the user and inserts it into the list
void addTask(List<Task>* tasks);
//Prints tasks that are not completed that are in the list
void printTask(List<Task>* tasks);
//Gives the specific details of not completed tasks in the list
void printDetailed(List<Task>* tasks);
//Prints completed tasks in the list.
void printCompleted(List<Task>* tasks);
//Removes tasks according to the users output.
void removeTask(List<Task>* tasks);
//Completes a task
void completeTask(List<Task>* tasks);
void saveTask(List<Task>* tasks);
void loadTask(List<Task>* tasks);

#endif