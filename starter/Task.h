/***************************************************************
Title:			Date.h
Author:			Mohammed Salam
Date Created:		3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:		The header file for the Abstract Date Class Task.
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
	Task(std::string str, Date d);

	/**Operator<< - outstream operator function to output a Task to a file
			when LOAD function is called
	 *@param - istream out 		[in]	output stream
	 *@param - Task    Task 	[in] 	Task date
	 *@return - out, outstream containing the output for a Task
         */
	friend std::ostream& operator<<(std::ostream& out, Task& task);

	/**Operator = Copy assignment operator assigning data from another task
				  to current task. 
	 *@param - task  rhs 	[in]	Task to copy from
	 *@return - this, task rhs was copied into
         */	
	Task& operator=(const Task& rhs);

	/**printList() - Virtual function for specific tasks, when PRINT function 
	  		 is caled it will output the details of the specific tasks
	  	 	 according to the specs given to us.
         */
	virtual void printList() = 0;

	/**detailedPrint() - Virtual function for specific tasks, when DETAILED function 
	  		     is caled it will output the details of the specific tasks
	  		     according to the specs given to us.
         */
	virtual void detailedPrint() = 0;

	/**printtoFile() - Virtual function for specific tasks, when SAVE function is called
			   a Task will be outputted to a file according to the specs given to us.
			   This function will be used in the Task outstream operator.
	 *@return string to be saved into a file.
         */ 
	virtual std::string printtoFile() = 0;

	/**addInstructions() - function to be called by the constructors of each tasks. This will
			       ask the user to input the Tasks deadline and description.
	 */
	void addInstructions();

	/**taskType() - getter for Task class taskType_ variable.
	 *@return - string, Task's taskType_
     	 */
	std::string taskType() {return taskType_;};

	/**description() - getter for Task class description_ variable.
	 *@return - string, Task's description
     	 */
	std::string description() {return description_;};

	/**deadline() - getter for Task class deadline_ variable.
	 *@return - Date, Task's deadline
     	 */
	Date deadline() {return deadline_;};

	/**status() - getter for Task class complated_ variable.
	 *@return - true if Task is completed, false otherwise
     	 */
	bool status() {return completed;};

	/**settaskType() - setter for Task class taskType_ variable.
	 *@param - string str 	[in]	string to set taskType_ to
     	 */	
	void settaskType(std::string str) {taskType_ = str;};

	/**setDescription() - setter for Task class description_ variable.
	 *@param - string str 	[in]	string to set description_ to
    	 */	
	void setDescription(std::string str) {description_ = str;};

	/**setDeadline() - setter for Task class deadline_ variable.
	 *@param - Date	  d 	[in]	Dte to set deadline_ to
         */	
	void setDeadline(Date d) {deadline_ = d;};

	/**settaskType() - when COMPLETE function is called, sets status
			   of the task to Complete.
         */	
	void complete() {completed = true;};

protected: 
	std::string taskType_, description_;
	Date deadline_;
	bool completed;
};

#endif
