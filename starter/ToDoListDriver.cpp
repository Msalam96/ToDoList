#include "ToDoListDriver.h"


void addTask(SortedTaskList* tasks) {
	bool flag = true;
	cout << "What type of task is this? [G: Generic, S: Shopping, E:Event, H: Homework]" << endl;
	do {
		cout << "> ";
		string type;
		cin >> type;
		transform(type.begin(), type.end(), type.begin(), ::toupper);
		if (type == "G") {
			Generic* generic = new Generic;
			tasks->insert(generic);
			flag = false;
		} else if (type == "S") {
			Shopping* shopping = new Shopping;
			tasks->insert(shopping);
			flag = false;
		} else if (type == "E") {
			Event* event = new Event;
			tasks->insert(event);	
			flag = false;
		} else if (type == "H") {
			Homework* homework = new Homework;
			tasks->insert(homework);
			flag = false;
		} else {
			cout << "Unknown Command (" << type << "). Try Again.\n";
		}
	} while (flag == true);
		cout << "Task added successfully." << endl;
}

void printTask(SortedTaskList* tasks) {
	if (tasks->empty()) {
		cout << "You have no outstanding tasks!" << endl;
	} else {
		tasks->print(false);
	}
}

void printDetailed(SortedTaskList* tasks) {
	if (tasks->empty()) {
		cout << "You have no outstanding tasks!" << endl;
	} else {
		tasks->detailedPrint();
	}
}


void removeTask(SortedTaskList* tasks) {
	bool flag = true;
	if (tasks->empty()) {
		cout << "You have no outstanding tasks!" << endl;
	} else {
		cout << "Which task would you like to remove?" << endl << "> "; 
		do {
			string s;
			getline(cin, s);
			int pos = stoi(s);
			if (pos > tasks->incSize() || pos < 0) {
				cout << "You have entered an invalid task number, try again!" << endl;
			} else {
				tasks->remove(pos);
				cout << "Task removed successfully." << endl;
				flag = false;
			}
		} while (flag == true);
	}		
}

void completeTask(SortedTaskList* tasks) {
	if (tasks->empty()) {
		cout << "You have no outstanding tasks!" << endl;
	} else {
		cout << "Which task would you like to complete?" << endl << "> ";	
		string s;
		getline(cin, s);
		int pos = stoi(s);
		if (pos > tasks->incSize() || pos < 0) {
			cout << "You have entered an invalid task number!" << endl;
			return;
		}
		tasks->getNode(pos)->data->complete();
	}
	cout << "Task marked complete successfully!" << endl;
}

void printCompleted(SortedTaskList* tasks) {
	if (tasks->comSize() == 0) {
		cout << "You have no completed tasks!" << endl;
	} else {
		tasks->print(true);
	}
}

void saveTask(SortedTaskList* tasks) {
	if (tasks->empty()) {
		cout << "You have no outstanding tasks!" << endl;
		return;
	} else {
		ofstream outFile; 
		cout << "Where would you like to save your oustanding tasks?" << endl << "> ";
		string fileName;
		getline(cin, fileName);
		outFile.open(fileName, ios::out);
		for(int i = 1; i <= tasks->incSize(); ++i) {
			Node* newNode = tasks->getNode(i);
			outFile << *(newNode->data) << endl;
	
		}
		outFile.close();
		cout << "Tasks saved successfully!" << endl;
	}
}

void loadTask(SortedTaskList* tasks) {
	string line;
	string fileName;

	cout << "What file would you like to load outstanding tasks from?" << endl << "> ";
	getline(cin, fileName);
	ifstream inFile;
	inFile.open(fileName);

	while (getline(inFile, line)) {
		if (line[0] == 'G') {
			Generic* task = new Generic(line);
			tasks->insert(task);
		} else if (line[0] == 'S') {
			Shopping* task = new Shopping(line);
			tasks->insert(task);
		} else if (line[0] == 'E') {
			Event* task = new Event(line);
			tasks->insert(task);
		} else if (line[0] == 'H') {
			Homework* task = new Homework(line);
			tasks->insert(task);
		}
	}
	inFile.close();
	cout << "Tasks loaded successfully!" << endl;
}
