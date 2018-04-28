#include "Event.h"

using namespace std;
Event::Event() {
	addInstructions();
	cout << "Where is this event taking place?" << endl << "> ";
	getline(cin, location_);
	cout << "When is this event taking place?" << endl << "> ";
	getline(cin, time_);
	settaskType("E");
}

Event::Event(string line) {
	string str = "";
	int i = 0;
	while (line.size() != 0) {
		if (line[0] == '|' || line.size() == 1) {
			if(line.size() == 1) {
				str += line[0];
			} 
			if (i == 0) {
				++i;
				taskType_ = "Event";
			} else if (i == 1) {
				++i;
				Date date(str);
				deadline_ = date;
			} else if (i == 2) {
				++i;
				description_ = str;
			} else if (i == 3) {
				++i;
				location_ = str;
			} else {
				time_ = str;
			}
			line.erase(line.begin());
			str = "";
		} else {
			str += line[0];
			line.erase(line.begin());
		}
	}
}

void Event::printList() {
	cout << deadline().getDate() << " - [Event] " << description();
}

void Event::detailedPrint() {
	printList();
	cout << endl;
	cout << '\t' << "Location:" << endl << '\t' << location() << endl;
	cout << '\t' << "Time:" << endl << '\t' << time();
}

string Event::printtoFile() {
	string s = taskType() + "|" + deadline().getDate() + "|" + description() + "|" + location() + "|" + time();
	return s;
}
