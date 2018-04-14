#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "Task.h"

class Homework : public Task {
public:
	Homework();
	Homework(string line);
	~Homework() {};

	string subject() {return subject_;};

	void printList();
	void detailedPrint();
	string printtoFile();

private:
	string subject_;
};
#endif
