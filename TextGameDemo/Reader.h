#include "Item.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

static class Reader {
public:
	static vector<Item> readItemsFromFile(const string fileName);
private:
};

vector<Item> Reader::readItemsFromFile(const string fileName){
	ifstream inFile;
	inFile.open(fileName.c_str(), ios::in);
	if(!inFile) {
		cerr << "Error: unable to open: " << fileName << endl;
		exit(EXIT_FAILURE);
	}

	string name;
	string description;
	double attack;
	double defence;
	double agility;
	ItemType type;

	Item item;
	vector<Item> itemVector;
	
	string line;
	int counter;

	// use find algorithm from string library

	while(getline(inFile, line)){ // read line from items.txt
		string::iterator iterBegin = line.begin(); // iterator pointing to beginning of attribute
		string::iterator iterCurrent = line.begin()++; // iterator pointing to current character
		while(iterCurrent != line.end()){ // while the current iterator has not reached the end of current string
			if(*iterCurrent == '/'){ // if the current iterator hits a backslash then everything from beginning iterator till 1 before current iterator is an attribute
				switch (counter) // determine the attribute
				{
				case 0: // name
				case 1: // description
				case 2: // attack
				case 3: // defence
				case 4: // agility
				case 5: // item type
				}
			}
		}
		
		itemVector.push_back(item);
	}
	return itemVector;
}
