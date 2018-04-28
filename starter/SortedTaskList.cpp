#include "SortedTaskList.h"

void SortedTaskList::insert(Task* data) {
	Node* temp = NULL;

	if(head == NULL || (head->data->deadline() > data->deadline())) {
		temp = new Node;
		temp->data = data;
		temp->next = head;
		head = temp;
		delete temp;
		++size_;
		return;
	}

	temp = head;

	while (temp->next != NULL && (data->deadline() > temp->next->data->deadline())) {
		temp = temp->next;
	}

	Node* temp2 = new Node;
	temp2->data = data;
	temp2->next = temp->next;
	temp->next = temp2;
	++size_;
	delete temp2;
}


void SortedTaskList::remove(int pos) {
	if (head == NULL) {
		return;
	} else {
		if (pos == 1) {
			Node* curr = getNode(1);
			Node* prev = getPrev(1);
			if (prev == NULL) {
				head = curr->next;
			} else {
				curr->next = prev->next;
			}
			curr->next = NULL;
			delete curr;
		} else if(pos+1 > incSize()) {
			Node* curr = getNode(pos);
			Node* prev = getPrev(pos);
			prev->next = NULL;
			delete curr;
		} else {
			Node* curr = getNode(pos);
			Node* prev = getPrev(pos);
			Node* temp = curr->next;
			prev->next = temp;
			curr->next = NULL;
			delete curr;
		}
		--size_;
	}
}

bool SortedTaskList::empty() {
	if (incSize() == 0) {
		return true;
	} else {
		return false;
	}
}

void SortedTaskList::print(bool flag) {
	Node* temp = new Node;
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
	delete temp;
}

void SortedTaskList::detailedPrint() {
	Node* temp = new Node;
	temp = head;
	int i = 1;
	while (temp != NULL) {
		cout << i << ". ";
		temp->data->detailedPrint();
		cout << endl;
		temp = temp->next;
		++i;
	}
	delete temp;
}

int SortedTaskList::incSize() const {
	Node* temp = new Node;
	temp = head;
	int i = 0;
	while (temp != NULL) {
		if(temp->data->status() == false) {
			++i;
		}
		temp = temp->next;
	}
	delete temp;
	return i;
}

int SortedTaskList::comSize() const {
	Node* temp = new Node;
	temp = head;
	int i = 0;
	while (temp != NULL) {
		if(temp->data->status() == true) {
			++i;
		}
		temp = temp->next;
	}
	delete temp;
	return i;
}

Node* SortedTaskList::getNode(int pos) const {
	Node* temp = head;
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

Node* SortedTaskList::getPrev(int pos) const {
	Node* temp = head;
	Node* prev = NULL;

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