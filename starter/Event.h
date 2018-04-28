#ifndef EVENT_H
#define EVENT_H

#include "Task.h"

class Event : public Task {
public:
	/**Event() - default constructor, calls addInstruction, asks user for Events 
		     location and time and sets taskType to E.
	 */
	Event();
	Event(std::string line);
	~Event() {};
	
	/**location() - getter for Event specific Task class location_ variable.
	 *@return - string, Event Tasks's location
         */
	std::string location() {return location_;};
	
	/**subject() - getter for Event specific Task class time_ variable.
	 *@return - string, Event Tasks's time.
         */
	std::string time() {return time_;};

	void printList();
	void detailedPrint();
	std::string printtoFile();

private:
	std::string location_, time_;
};

#endif
