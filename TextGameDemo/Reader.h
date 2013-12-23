#include <iostream>
#include <fstream>
#include "Item.h"
#include "Inventory.h"
#include "ItemType.h"
using namespace std;

class Reader {
public:
	Reader();
	vector<Item> readItemsFromFile(const string fileName);
private:
};

Reader::Reader(){
}

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

	while(inFile >> item){
		itemVector.push_back(item);		
	}
	return itemVector;
}
