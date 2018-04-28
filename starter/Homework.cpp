#include "Homework.h"

using namespace std;
Homework::Homework() {
	addInstructions();
	cout << "What subject is this homework task for?" << endl << "> ";
	getline (cin, subject_);
	settaskType("H");
}

Homework::Homework(string line) {
	string str = "";
	int i = 0;
	while (line.size() != 0) {
		if (line[0] == '|' || line.size() == 1) {
			if(line.size() == 1) {
				str += line[0];
			} 
			if (i == 0) {
				++i;
				taskType_ = "Homework";
			} else if (i == 1) {
				++i;
				Date date(str);
				deadline_ = date;
			} else if (i == 2) {
				++i;
				description_ = str;
			} else {
				subject_ = str;
			}

			line.erase(line.begin());
			str = "";
		} else {
			str += line[0];
			line.erase(line.begin());
		}
	}
}

void Homework::printList() {
	cout << deadline().getDate() << " - [Homework] " << description();
}

void Homework::detailedPrint() {
	printList();
	cout << endl << '\t' << "Subject:" << endl << '\t' << subject();
}

string Homework::printtoFile() {
	string s = taskType() + "|" + description() + "|" + subject();
	return s;
}
