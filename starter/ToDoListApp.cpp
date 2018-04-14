#include <iostream> 
#include <algorithm>

#include "ToDoListApp.h"

using namespace std; 
void ToDoListApp::run() {

	//NOTE: we are using out/in streams from the class level, not cin/cout
	//      directly. All your functions should do this.
	out << "Welcome to your To-Do List! You may begin to enter commands.";
	out << endl;

	string command;
	do {
		out << "> ";
		getline(in, command);

		//Convert entire command to uppercase for easy compares
		transform(command.begin(), command.end(), command.begin(), ::toupper);

		if (command == "PRINT") {
			executeCommandPrint();
		} else if (command == "DETAILED") {
			executeCommandPrint(false, true);
		} else if (command == "COMPLETED") {
			executeCommandPrint(true);
		} else if (command == "ADD") {
			executeCommandAddTask();
		} else if (command == "REMOVE") {
			executeCommandRemoveTask();
		} else if (command == "COMPLETE") {
			executeCommandCompleteTask();
		} else if (command == "SAVE") {
			executeCommandSave();
		} else if (command == "LOAD") {
			executeCommandLoad();
		} else if (command == "EXIT") {
			out << "Thank you for using To-Do List!\n";
			break;
		} else {
			out << "Unknown Command (" << command << "). Try Again.\n";
		}
		//out << "\n";
	} while (true);
}

void ToDoListApp::executeCommandPrint(bool completed, bool detailed){
	if (completed == false && detailed == false) {
		printTask(tasks);
	} else if (completed == false && detailed == true) {
		printDetailed(tasks);
	} else if (completed == true && detailed == false) {
		printCompleted(tasks);
	}
}

void ToDoListApp::executeCommandAddTask(){
	addTask(tasks);
}

void ToDoListApp::executeCommandRemoveTask(){
	removeTask(tasks);
}

void ToDoListApp::executeCommandCompleteTask() {
	completeTask(tasks);
}

void ToDoListApp::executeCommandSave(){
	saveTask(tasks);
}

void ToDoListApp::executeCommandLoad() {
	loadTask(tasks);
}
