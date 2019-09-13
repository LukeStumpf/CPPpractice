#include "pch.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

int main(int argc, char** argv)
{
	HashTable hashTable;
	string key = "";

	hashTable.AddItem("Paul", "Locha");
	hashTable.AddItem("Kim", "Iced Mocha");
	hashTable.AddItem("Emma", "Strawberry Smoothy");
	hashTable.AddItem("Annie", "Hot Chocolate");
	hashTable.AddItem("Sarah", "Passion Tea");
	hashTable.AddItem("Pepper", "Caramel Mocha");
	hashTable.AddItem("Mike", "Chai Tea");
	hashTable.AddItem("Steve", "Apple Cider");
	hashTable.AddItem("Bill", "Root Beer");
	hashTable.AddItem("Marie", "Skinny Latte");
	hashTable.AddItem("Susan", "Water");
	hashTable.AddItem("Joe", "Green Tea");

	hashTable.PrintIndexItems(2);

	while (key != "exit") {
		cout << "Remove: ";
		cin >> key;
		if (key != "exit")
			hashTable.RemoveItem(key);
	}

	hashTable.PrintIndexItems(2);

	return 0;
}

