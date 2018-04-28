#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "Task.h"

class Homework : public Task {
public:
	/**Homework() - default constructor, calls addInstruction and asks user which subject
			the homework is for. Sets tasktype_ to H.
     	 */	
	Homework();
	Homework(std::string line);
	~Homework() {};

	/**subject() - getter for Homework specic Task class subject_ variable.
	 *@return - string, Homework Tasks's subject.
     	 */
	std::string subject() {return subject_;};

	void printList();
	void detailedPrint();
	std::string printtoFile();

private:
	std::string subject_;
};
#endif
