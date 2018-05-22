/***************************************************************
Title:			List.hxx
Author:			Mohammed Salam
Date Created:	3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:	List class header fiel and function definitions. This is the current
			    version of this class that i will be using in order to have something
			    for the deadline. I was too far into my code till i realized that this list
			    is not abstract, so it should not be templated. However when i tried to remove
			    the template it seemed to have broke my code. For now this is what i will submit
			    for the friday deadline, until I figure out how to fix it completely.
***************************************************************/
#ifndef SORTEDTASKLIST_H
#define SORTEDTASKLIST_H

#include "Task.h"
#include "Generic.h"
#include "Shopping.h"
#include "Event.h"
#include "Homework.h"
#include "Comparator.h"
#include <cstdlib>

struct Node {
	Task* data;
	Node* next;
};

class SortedTaskList {
public:
	/**SortedTaskList() - default constructor
	 */
	SortedTaskList() {head = NULL, size_ = 0;};

	/**~SortedTaskList() - default destructor
	 */
	~SortedTaskList() {delete head;};

	/**insert() - Inserts a node into the Sorted Linked List of Tasks. The node will
				  contain the Task that either is loaded from a file or the user inputs
				  themself.
	 *@param	Task* 	data	[in]	pointer to Task user inserts
	 */
	void insert(Task* data);

	/**remove() - Removes a node in the Sorted Linked List in the nth position as inputed
				  by the user. This will only remove tasks that are marked incomplete. 
	 *@param	int 	pos 	[in]	position of the node to remove
	 */
	void remove(int pos);

	/**empty() - Checks to see if there is any incomplete tasks in the list.
	 *@return - true if no incomplete tasks in list, false otherwise
	 */
	bool empty();

	/**print() - Print item in the linked list that match the bool parameter inserted.
	 *@param	bool 	flag 	[in]	boolean value matching tasks's completion status
	 */
	void print(bool flag);

	/**detailedPrint() - Loop through the linked list and calls the detailed print of each
						 incomplete tasks.
	 */
	void detailedPrint();

	/**size() - Returns size of linked list.
	 *@return - size of linked list
	 */
	int size() const {return size_;};

	/**size() - Returns number of incomplete tasks in the linked list.
	 *@return - number of incomplete tasks in the linked list.
	 */
	int incSize() const;

	/**size() - Returns number of complete tasks in the linked list.
	 *@return - number of complete tasks in the linked list.
	 */
	int comSize() const;

	/**getNode() - returns the Node in the position prompted by the user.
	 *@param 	int 	pos 	[in]	position of the Node
	 *@return - Node in nth position
	 */
	Node* getNode(int pos) const;

	/**getNode() - returns the Node in the previous position prompted by the user.
	 *@param 	int 	pos 	[in]	position of the Node
	 *@return - Node in n-1 position
	 */
	Node* getPrev(int pos) const;

private:
	Node* head;
	int size_;
};


#endif
