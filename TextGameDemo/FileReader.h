#include <iostream>
#include <fstream>
using namespace std;

class FileReader {
public:
	FileReader();
	vector<Item> readItemsFromFile(const string fileName);
private:
};

FileReader::FileReader(){
}

vector<Item> FileReader::readItemsFromFile(const string fileName){
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
	//IType type;

	Item item;
	vector<Item> itemVector;

	while(inFile >> item){
		itemVector.push_back(item);		
	}
	return itemVector;
}
