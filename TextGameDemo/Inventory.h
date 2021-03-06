/*
* CharacterInventory.h
*
*  Created on: Oct 28, 2013
*      Author: Arash
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Item.h"
#include "Reader.h"
using namespace std;

class Inventory {
public:
	static vector<Item> itemDatabase;
	virtual void addItem(Item item)=0;
	virtual Item removeItem(Item item)=0;
	Item getItem(const Item &item);

protected:
	vector<Item> itemList;
};

class CharacterInventory: public Inventory {
public:
	CharacterInventory();
	void addItem(Item item);
	Item removeItem(Item item);
private:
	static const int MAXCHARACTERINVENTORYSIZE = 10;

	friend ostream& operator<<(ostream &os, const CharacterInventory &_characterInventory);
};

class EnemyInventory: public Inventory {
public:
	EnemyInventory();
	void addItem(Item item);
	Item removeItem(Item item);
private:
	static const int MAXENEMYINVENTORYSIZE = 3;

	friend ostream& operator<<(ostream &os, const EnemyInventory &_enemyInventory);
};

Item Inventory::getItem(const Item &item){
	vector<Item>::iterator posIter = find(itemList.begin(), itemList.end(), item);
	return *posIter;
}

vector<Item> Inventory::itemDatabase = Reader::readItemsFromFile("items.txt");

CharacterInventory::CharacterInventory(){
	//Reader reader;
	//itemDatabase = reader.readItemsFromFile("items.txt");
}

void CharacterInventory::addItem(Item item) {
	if(itemList.size() < MAXCHARACTERINVENTORYSIZE){
		itemList.push_back(item);
	}
}

Item CharacterInventory::removeItem(Item item) {
	vector<Item>::iterator posIter = find(itemList.begin(), itemList.end(), item);
	Item itemToRemove(*posIter);
	itemList.erase(posIter);
	return itemToRemove;
}

EnemyInventory::EnemyInventory(){
}

void EnemyInventory::addItem(Item item){
	if(itemList.size() < MAXENEMYINVENTORYSIZE) {
		itemList.push_back(item);
	}
}

Item EnemyInventory::removeItem(Item item){
	vector<Item>::iterator posIter = find(itemList.begin(), itemList.end(), item);
	Item itemToRemove(*posIter);
	itemList.erase(posIter);
	return itemToRemove;
}

ostream& operator<<(ostream &os, const CharacterInventory &_characterInventory){
	os << left << setw(15) << "Name" << setw(45) << "Description" << setw(10) << "Attack" << setw(10) << "Defence" << setw(10) << "Agility" << setw(10) << "Type" << endl;
	for(vector<Item>::const_iterator iter = _characterInventory.itemList.cbegin(); iter != _characterInventory.itemList.end(); iter++){
		os << *iter << endl;
	}

	return os;
}

ostream& operator<<(ostream &os, const EnemyInventory &_enemyInventory){
	os << left << setw(15) << "Name" << setw(45) << "Description" << setw(10) << "Attack" << setw(10) << "Defence" << setw(10) << "Agility" << setw(10) << "Type" << endl;
	for(vector<Item>::const_iterator iter = _enemyInventory.itemList.cbegin(); iter != _enemyInventory.itemList.end(); iter++){
		os << *iter << endl;
	}

	return os;
}