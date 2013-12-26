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
	int attributeNumber = 0;
	int attributeBegin = 0; // pointing to beginning of attribute		
	int backslashPosition = -1;

	while(getline(inFile, line)){ // read line from items.txt
		attributeNumber = 0;
		attributeBegin = 0;
		backslashPosition = line.find("/");
		while(backslashPosition > -1){
			switch(attributeNumber){
			case 0: // name
				name = line.substr(attributeBegin, backslashPosition);
				item.setName(name);
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
				backslashPosition = line.find("/", attributeBegin);
			case 1: // description
				description = line.substr(attributeBegin, backslashPosition-attributeBegin);
				item.setDescription(description);
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
				backslashPosition = line.find("/", attributeBegin);
			case 2: // attack
				attack = stoi(line.substr(attributeBegin, backslashPosition));
				item.setAttack(attack);
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
				backslashPosition = line.find("/", attributeBegin);
			case 3: // defence
				defence = stoi(line.substr(attributeBegin, backslashPosition));
				item.setDefence(defence);
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
				backslashPosition = line.find("/", attributeBegin);
			case 4: // agility
				agility = stoi(line.substr(attributeBegin, backslashPosition));
				item.setAgility(agility);
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
			case 5: // item type
				type = stoi(line.substr(attributeBegin));
				item.setType(type.getType());
				attributeBegin = backslashPosition + 1;
				attributeNumber++;
				backslashPosition = -1;
			}
		}

		itemVector.push_back(item);
	}
	return itemVector;
}
