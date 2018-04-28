/***************************************************************
Title:			Shopping.cpp
Author:			Mohammed Salam
Date Created:		3/29/2018
Class:			Spring 2018, CSCI 235-03, Mon - Wed 7:00pm-8:15 pm
Professor:		Aarsh Vora
Purpose:		Assignment #2
Description:		Cpp file for Shopping specific functions 
***************************************************************/

#include "Shopping.h"

using namespace std;
Shopping::Shopping() {
	addInstructions();
	cout << "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" << endl;
	string item;
	bool flag = true;
	do {
		cout << "> ";
		getline(cin, item);
		string s = item;
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		if (s == "DONE") {
			flag = false;
		} else {
			shoppingList.push_back(item);
		}
	} while (flag == true);

	settaskType("S");
}

Shopping::Shopping (string line) {
	string str = "";
	int i = 0;
	while (line.size() != 0) {
		if (line[0] == '|' || line.size() == 1) {
			if(line.size() == 1) {
				str += line[0];
			} 
			if (i == 0) {
				++i;
				taskType_ = "Shopping";
			} else if (i == 1) {
				++i;
				Date date(str);
				deadline_ = date;
			} else if (i == 2) {
				++i;
				description_ = str;
			} else {
				string temp = str;
				shoppingList.push_back(temp);
			}

			line.erase(line.begin());
			str = "";
		} else {
			str += line[0];
			line.erase(line.begin());
		}
	}
}

void Shopping::pushItem(string item) {
	shoppingList.push_back(item);
}

void Shopping::printList() {
	cout << deadline().getDate() + " - [Shopping] " + description(); 

}

void Shopping::detailedPrint() {
	printList();
	cout << endl;
	cout << '\t' << "Items:" << endl;
	for (unsigned int i = 0; i < shoppingList.size(); ++i) {
		cout << '\t' << shoppingList[i] << endl;
	} 
}

string Shopping::printtoFile() {
	string s = taskType() + "|" + deadline().getDate() + "|" + description() + "|";
	for (unsigned int i = 0; i < shoppingList.size(); ++i) {
		s += shoppingList[i] + "|";
	}
	return s;
}
