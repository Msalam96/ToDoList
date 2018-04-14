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
#ifndef LIST_H
#define LIST_H

#include "Task.h"
#include "Generic.h"
#include "Shopping.h"
#include "Event.h"
#include "Homework.h"
#include <cstdlib>

template <typename T> 
struct Node {
	T* data;
	Node* next;
	Node* prev;
};

template <typename T>
class List {
public:
	List() {head = NULL, size_ = 0;};
	~List() {delete head;};

	//add datae to the front of the list
	void push_front(Task* data);
	//sorted insert based off the the tasks deadline, will insert apparoptely
	Node<Task>* sortedInsert(Node<Task>* head, Task* data);

	void remove(int pos);

	bool empty();

	//prints tasks in the list according to if they are complete are not
	void print(bool flag);
	//calls detailed print of a task
	void detailedPrint();

	int size() const {return size_;};
	int incSize() const;
	int comSize() const;

	Node<Task>* getHead() {return head;};
	Node<Task>* getNode(int pos) const;
	Node<Task>* getPrev(int pos) const;
private:
	Node<T>* head;
	int size_;
};

template <typename T> void List<T>::push_front(Task* data) {
	Node<T> *temp = new Node<T>;
	temp->data = data;
	temp->next = head;
	head = temp;
}

template <typename T> Node<Task>* List<T>::sortedInsert(Node<Task>* head,Task* data) {
	if (head == NULL || head->data->deadline() > data->deadline()) {
		push_front(data);
	} else if ((head->data->deadline() > data->deadline()) || (head->data->deadline() == data->deadline())) {
		Node<Task>* child = new Node<Task>;
		child->data = data;
		child->next = head;
		head->prev = child;
		head = child;
	} else {
		Node<Task>* current = head;
		while (current->next != NULL && ((data->deadline() > current->next->data->deadline()) 
							       || (data->deadline() == current->next->data->deadline()))) {
			current = current->next;
		}
		Node<Task>* child = new Node<Task>;
		child->data = data;
		child->next = current->next;
		child->prev = current;
		current->next = child;
	}
	++size_;
	return head;
}

template<typename T> void List<T>::remove(int pos) {
	if (head == NULL) {
		return;
	} else {
		if (pos == 1) {
			Node<Task>* curr = getNode(1);
			Node<Task>* prev = getPrev(1);
			if (prev == NULL) {
				head = curr->next;
			} else {
				curr->next = prev->next;
			}
			curr->next = NULL;
			delete curr;
		} else if(pos+1 > incSize()) {
			Node<Task>* curr = getNode(pos);
			Node<Task>* prev = getPrev(pos);
			prev->next = NULL;
			delete curr;
		} else {
			Node<Task>* curr = getNode(pos);
			Node<Task>* prev = getPrev(pos);
			Node<Task>* temp = curr->next;
			prev->next = temp;
			curr->next = NULL;
			delete curr;
		}
		--size_;
	}
}

template<typename T> bool List<T>::empty() {
	if (incSize() == 0) {
		return true;
	} else {
		return false;
	}
}

template<typename T> void List<T>::print(bool flag) {
	Node<Task>* temp = new Node<Task>;
	temp = head;
	int i = 1;
	while (temp != NULL) {
		if (flag == temp->data->status()) {
			cout << i << ". ";
			temp->data->printList();
			cout << endl;
			++i;
		}
		temp = temp->next;
	}
}

template<typename T> void List<T>::detailedPrint() {
	Node<Task>* temp = new Node<Task>;
	temp = head;
	int i = 1;
	while (temp != NULL) {
		cout << i << ". ";
		temp->data->detailedPrint();
		cout << endl;
		temp = temp->next;
		++i;
	}
}

template<typename T> int List<T>::incSize() const {
	Node<Task>* temp = new Node<Task>;
	temp = head;
	int i = 0;
	while (temp != NULL) {
		if(temp->data->status() == false) {
			++i;
		}
		temp = temp->next;
	}
	return i;
}

template<typename T> int List<T>::comSize() const {
	Node<Task>* temp = new Node<Task>;
	temp = head;
	int i = 0;
	while (temp != NULL) {
		if(temp->data->status() == true) {
			++i;
		}
		temp = temp->next;
	}
	return i;
}

template<typename T>Node<Task>* List<T>::getNode(int pos) const {
	if ((pos > size()-1) || (pos <= 0)) {
		cout << "error" << endl;
	}
	Node<Task>* temp = head;
	while (temp->data->status()) {
		temp = temp->next;
	}
	for (int i = 1; i < pos; ++i) {
		temp = temp->next;
		while(temp->data->status()) {
			temp = temp->next;
		}
	}

	return temp;
}

template<typename T>Node<Task>* List<T>::getPrev(int pos) const {
	Node<Task>* temp = head;
	Node<Task>* prev = NULL;

	while(temp->data->status()) {
		prev = temp;
		temp = temp->next;
	}

	for (int i = 1; i < pos; ++i) {
		prev = temp;
		temp = temp->next;
		while(temp->data->status()) {
			prev = temp;
			temp = temp->next;
		}
	}
	return prev;
}


#endif