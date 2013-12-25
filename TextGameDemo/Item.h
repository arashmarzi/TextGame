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
	Item(string _name, string _description, double _attack,
		double _defence, double _agility, ItemType type);
	Item(const Item &item);
	const string& getDescription() const;
	void setDescription(const string &description);
	const string& getName() const;
	void setName(const string &name);
	const double& getAgility() const;
	void setAgility(const double &agility);
	const double& getAttack() const;
	void setAttack(const double &attack);
	const double& getDefence() const;
	void setDefence(const double &defence);
	const int& getType() const;
	void setType(const int type);

	friend bool operator==(const Item &item, const Item &other);
	friend ostream& operator<<(ostream &os, const Item &item);
	friend istream& operator>>(istream &is, Item &item);
private:
	string name;
	string description;
	double attack;
	double defence;
	double agility;
	ItemType type;
};

Item::Item(){

}

Item::Item(string _name, string _description, double _attack,
		   double _defence, double _agility, ItemType _type) :
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

const double& Item::getAgility() const{
	return agility;
}

void Item::setAgility(const double &agility) {
	this->agility = agility;
}

const double& Item::getAttack() const{
	return attack;
}

void Item::setAttack(const double &attack) {
	this->attack = attack;
}

const double& Item::getDefence() const {
	return defence;
}

void Item::setDefence(const double &defence) {
	this->defence = defence;
}

const int& Item::getType() const {
	return type.getType();
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
	os << left << setw(10) << _item.getName() << setw(15) << _item.getDescription() << setw(10) << _item.getAttack() << setw(10) << _item.getDefence() << setw(10) << _item.getAgility() << setw(10) << _item.getType() << endl;
	return os;
}

istream& operator>>(istream &is, Item &_item){
	//must rework input reading from file
	int intType;
	is >> setw(10) >> _item.name;
	is.ignore();
	is >> setw(15) >>_item.description;
	is.ignore();
	is >> _item.attack;
	is >> _item.defence;
	is >> _item.agility;
	is >> intType; 
	_item.setType(intType);

	return is;
}
#endif /* ITEM_H_ */
