/*
* Item.h
*
*  Created on: Oct 28, 2013
*      Author: Arash
*/

#ifndef ITEM_H_
#define ITEM_H_
#include "stdafx.h"
#include "ItemType.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>
#include <istream>
#include <map>
#include <algorithm>
using namespace std;

class Item {

public:
	Item();
	Item(string _name, string _description, int _attack,
		int _defence, int _agility, ItemType type);
	Item(const Item &item);
	const string& getDescription() const;
	void setDescription(const string &description);
	const string& getName() const;
	void setName(const string &name);
	const int& getAgility() const;
	void setAgility(const int &agility);
	const int& getAttack() const;
	void setAttack(const int &attack);
	const int& getDefence() const;
	void setDefence(const int &defence);
	const ItemType& getType() const;
	void setType(const int type);

	friend bool operator==(const Item &item, const Item &other);
	friend ostream& operator<<(ostream &os, const Item &_item);
private:
	string name;
	string description;
	int attack;
	int defence;
	int agility;
	ItemType type;
};

Item::Item(){

}

Item::Item(string _name, string _description, int _attack,
		   int _defence, int _agility, ItemType _type) :
name(_name), description(_description), attack(_attack), defence(
	_defence), agility(_agility), type(_type) {
}

Item::Item(const Item &_item) :name(_item.name), description(_item.description), attack(_item.attack), defence(
	_item.defence), agility(_item.agility), type(_item.type) {
}

const string& Item::getDescription() const{
	return description;
}

void Item::setDescription(const string &description) {
	this->description = description;
}

const string& Item::getName() const {
	return name;
}

void Item::setName(const string &name) {
	this->name = name;
}

const int& Item::getAgility() const{
	return agility;
}

void Item::setAgility(const int &agility) {
	this->agility = agility;
}

const int& Item::getAttack() const{
	return attack;
}

void Item::setAttack(const int &attack) {
	this->attack = attack;
}

const int& Item::getDefence() const {
	return defence;
}

void Item::setDefence(const int &defence) {
	this->defence = defence;
}

const ItemType& Item::getType() const {
	return type;
}

void Item::setType(const int _type) {
	this->type.setType(_type);
}

bool operator==(const Item &item, const Item &other){
	if(	item.getName() == other.getName() &&
		item.getDescription() == other.getDescription() &&
		item.getAttack() == other.getAttack() &&
		item.getDefence() == other.getDefence() &&
		item.getAgility() == other.getAgility() && 
		item.getType() == other.getType()) {
			return true;
	}
	return false;
}

ostream& operator<<(ostream &os, const Item &_item){
	os << left << setw(15) << _item.getName() << setw(45) << _item.getDescription() 
		<< setw(5) << _item.getAttack() << setw(5) << _item.getDefence() 
		<< setw(5) << _item.getAgility() << setw(5) << _item.getType() << endl;
	return os;
}

#endif /* ITEM_H_ */
