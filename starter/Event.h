#ifndef EVENT_H
#define EVENT_H

#include "Task.h"

class Event : public Task {
public:
	Event();
	Event(string line);
	~Event() {};
	
	string location() {return location_;};
	string time() {return time_;};

	void printList();
	void detailedPrint();
	string printtoFile();

private:
	string location_, time_;
};

#endif