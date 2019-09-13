#include "pch.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#pragma once

class HashTable {
private:
	static const int tableSize = 4;

	struct item {
		string m_key;
		string m_value;
		item *next;
	};

	item *table[tableSize];

public:
	HashTable();
	~HashTable();
	int Hash(string key);
	void AddItem(string key, string value);
	int GetNumIndexItems(int index);
	void PrintTable();
	void PrintIndexItems(int index);
	void FindValue(string key);
	void RemoveItem(string key);
};