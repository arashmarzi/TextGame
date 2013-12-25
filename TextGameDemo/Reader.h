#include "Item.h"
#include <iostream>
#include <fstream>
#include <vector>
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

	while(inFile >> item){
		itemVector.push_back(item);
	}
	return itemVector;
}
