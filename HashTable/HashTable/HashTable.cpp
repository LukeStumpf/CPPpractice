#include "pch.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
	for (int i = 0; i < tableSize; i++) {
		table[i] = new item;
		table[i]->m_key = "";
		table[i]->m_value = "";
		table[i]->next = NULL;
	}	
}

HashTable::~HashTable()
{
	item *ptr;
	for (int i = 0; i < tableSize; i++) {
		ptr = table[i];
		table[i] = table[i]->next;
		delete ptr;
	}
}

int HashTable::Hash(string key)
{
	int hashValue = 0;
	int length = key.length();

	for (int i = 0; i < length; i++) {
		hashValue = (hashValue + (int)key[i]) * 17;
	}

	int index = hashValue % tableSize;

	return index;
}

void HashTable::AddItem(string key, string value)
{
	int index = Hash(key);

	if (table[index]->m_key == "") {
		table[index]->m_key = key;
		table[index]->m_value = value;
	}
	else {
		item *ptr = table[index];
		item *n = new item;
		n->m_key = key;
		n->m_value = value;
		n->next = NULL;
		while (ptr->next) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int HashTable::GetNumIndexItems(int index)
{
	int count = 0;

	if (table[index]->m_key == "") {
		return count;
	}

	else {
		count++;
		item *ptr = table[index];
		while (ptr->next) {
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

void HashTable::PrintTable()
{
	int numItems;
	for (int i = 0; i < tableSize; i++) {
		numItems = GetNumIndexItems(i);
		cout << "----------------\n";
		cout << "index: " << i << endl;
		cout << table[i]->m_key << endl;
		cout << table[i]->m_value << endl;
		cout << "# of items: " << numItems << endl;
		cout << "----------------\n";
	}
}

void HashTable::PrintIndexItems(int index)
{
	item *ptr = table[index];

	if (ptr->m_key == "") {
		cout << "index " << index << " is empty" << endl;
	}
	else {
		cout << "index: " << index << " contains the following item" << endl;
		while (ptr) {
			cout << "----------------\n";
			cout << ptr->m_key << endl;
			cout << ptr->m_value << endl;
			cout << "----------------\n";
			ptr = ptr->next;
		}
	}
}

void HashTable::FindValue(string key) 
{
	int index = Hash(key);
	string value;

	item *ptr = table[index];
	while (ptr) {
		if (ptr->m_key == key) {
			cout << "Value: " <<  ptr->m_value << endl;
			return;
		}
		ptr = ptr->next;
	}
	cout << "No value present at specified key" << endl;
}

void HashTable::RemoveItem(string key)
{
	int index = Hash(key);

	item *delPtr;
	item *ptr1;
	item *ptr2;

	// Case 0 - bucket is empty
	if (table[index]->m_key == "") {
		cout << key << " was not found in the hash table." << endl;
	}

	// Case 1 - only 1 item is contained in bucket and that item has matching name
	else if (table[index]->m_key == key && !table[index]->next) {
		table[index]->m_key = "";
		table[index]->m_value = "";

		cout << key << " was removed from the hash table." << endl;
	}

	// Case 2 - match is located in the first item, but there are more items
	else if (table[index]->m_key == key && table[index]->next) {
		delPtr = table[index];
		table[index] = table[index]->next;
		delete delPtr;

		cout << key << " was removed from the hash table." << endl;
	}

	// Case 3 - bucket contains more than one item, but first item is not a match
	else {
		ptr1 = table[index]->next;
		ptr2 = table[index];

		while (ptr1 && ptr1->m_key != key) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		// Case 3.1 - no match
		if (!ptr1) {
			cout << "No value present at specified key" << endl;
		}
		// Case 3.2 match found
		else {
			delPtr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;

			delete delPtr;
			cout << key << " was removed from the hash table." << endl;
		}
	}
}
