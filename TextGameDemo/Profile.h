#include <iostream>
#include <string>
#include "RaceType.h"
#include "Inventory.h"

class Profile {
public:
	Profile(string _name, int _level, RaceType _race);
	void deathOfCharacter();
	void isCharacterAlive();
	void incrementCurrentHealth(int incrHealth);
	void decrementCurrentHealth(int decrHealth);
	void incrementMaxHealth(int incrHealth);
	void decrementMaxHealth(int decrHealth);
	bool ItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	const string& getName() const;
	void setName(const string &name);
	const int& getLevel() const;
	void setLevel(const int &name);
	const int& getAttack() const;
	void setAttack(const int &attack);
	const int& getDefence() const;
	void setDefence(const int &defence);
	const int& getAgility() const;
	void setAgility(const int &agility);
	const RaceType& getRace() const;
	void setRace(const int &_race);
	const double& getCurrentHealth() const;
	void setCurrentHealth(const int &currentHealth);
	const double& getMaxHealth() const;
	void setMaxHealth(const double &maxHealth);
	const bool& getIsAlive() const;
	void setIsAlive(const bool &isAlive);
	//void updateStatsByEnemy(const EnemyProfile &enemy);

protected:
	string name;
	int level;
	int attack;
	int defence;
	int agility;
	RaceType race;
	vector<RaceType> affinity;
	double currentHealth;
	double maxHealth;
	bool isAlive;
};

class CharacterProfile : public Profile {
public:
	CharacterProfile(string _name, int _level, RaceType _race);
	void incrementLevel();
	void incrementMaxExperience();
	void incrementCurrentExperience(double incrExperience);
	//bool isItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	//void updateStatsByEnemy(const EnemyProfile &enemy);
	const double& getCurrentExperience() const;
	void setCurrentExperience(const double &currentExperience);
	const double& getMaxExperience() const;
	void setMaxExperience(const double &maxExperience);	
	void addItemToInventory(Item &item);
	const CharacterInventory& getInventory() const;
private:
	double currentExperience;
	double maxExperience;
	CharacterInventory characterInventory;

	friend ostream& operator<<(ostream &os, const CharacterProfile &characterProfile);
};

class EnemyProfile : public Profile{
public:
	EnemyProfile(string _name, int _level, RaceType _race);
	//bool isItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	//void updateStatsByCharacter(const CharacterProfile &character);
	void addItemToInventory(Item &item);
	const EnemyInventory& getInventory() const;
private:
	EnemyInventory enemyInventory;

	friend ostream& operator<<(ostream &os, const EnemyProfile &enemyProfile);
};

Profile::Profile(string _name, int _level, RaceType _race) : name(_name), level(_level), race(_race), attack(10), defence(10), agility(10), isAlive(true) {
	maxHealth = level*10;
	currentHealth = maxHealth;
}

/*Character dies*/
void Profile::deathOfCharacter() {
	cout << name << ", you have unfortunately died...what a pity;" << endl
		<< "though you managed to reach level " << level << "!" << endl;
}

/*Check if character is alive*/
void Profile::isCharacterAlive() {
	if (currentHealth == 0) {
		isAlive = false;
		deathOfCharacter();
	}
}

/*Increment character current health*/
void Profile::incrementCurrentHealth(int incrHealth) {
	if (currentHealth < maxHealth) {
		if (currentHealth + incrHealth < maxHealth) {
			currentHealth += incrHealth;
		} else if (currentHealth + incrHealth >= maxHealth) {
			currentHealth = maxHealth;
		}
	}
}

/*Decrement character current health*/
void Profile::decrementCurrentHealth(int decrHealth) {
	if (currentHealth > 0) {
		if (currentHealth - decrHealth > 0) {
			currentHealth -= decrHealth;
		} else if (currentHealth - decrHealth <= 0) {
			currentHealth = 0;
			deathOfCharacter();
		}
	}
}

/*Increment character max health*/
void Profile::incrementMaxHealth(int incrHealth) {
	maxHealth += incrHealth;
}

/*Decrement character max health*/
void Profile::decrementMaxHealth(int decrHealth) {
	if (maxHealth > 0) {
		if (maxHealth - decrHealth > 0) {
			maxHealth -= decrHealth;
		} else if (maxHealth - decrHealth <= 0) {
			maxHealth = 0;
			currentHealth = 0;
			isAlive = false;
		}
	}
}

const string& Profile::getName() const {
	return name;
}

void Profile::setName(const string &name){
	this->name = name;
}

const int& Profile::getLevel() const{
	return level;
}

void Profile::setLevel(const int &level){
	this->level = level;
}

const int& Profile::getAttack() const{
	return attack;
}

void Profile::setAttack(const int &attack){
	this->attack = attack;
}

const int& Profile::getDefence() const{
	return defence;
}

void Profile::setDefence(const int &defence){
	this->defence = defence;
}

const int& Profile::getAgility() const{
	return agility;
}

void Profile::setAgility(const int &agility){
	this->agility = agility;
}

const RaceType& Profile::getRace() const {
	return race;
}

void Profile::setRace(const int &_race){
	this->race = _race;
}

const double& Profile::getCurrentHealth() const{
	return currentHealth;
}

void Profile::setCurrentHealth(const int &currentHealth){
	this->currentHealth = currentHealth;
}

const double& Profile::getMaxHealth() const{
	return maxHealth;
}

void Profile::setMaxHealth(const double &maxHealth){
	this->maxHealth = maxHealth;
}

const bool& Profile::getIsAlive() const{
	return isAlive;
}

void Profile::setIsAlive(const bool &isAlive){
	this->isAlive = isAlive;
}

CharacterProfile::CharacterProfile(string _name, int _level, RaceType _race) : 
	Profile(_name, _level, _race), currentExperience(0) {
		maxExperience = 10.25 * level;
}

/*Increment character level*/
void CharacterProfile::incrementLevel() {
	level += 1;
}

/*Increment character max experience*/
void CharacterProfile::incrementMaxExperience() {
	maxExperience *= 10.25;
}

/*Increment character current experience*/
void CharacterProfile::incrementCurrentExperience(double incrExperience) {
	if (currentExperience + incrExperience < maxExperience) {
		currentExperience += incrExperience;
	} else if (currentExperience + incrExperience > maxExperience) {
		currentExperience = (currentExperience + incrExperience) - maxExperience ;
		incrementLevel();
		incrementMaxExperience();
	}
}

/*Perform stat update to attack, defence, and agility based on item*/
void CharacterProfile::updateStatsByItem(const Item &item, bool doAdd){
	if(doAdd == true){ // add stat bonus
		attack += item.getAttack();
		defence += item.getDefence();
		agility += item.getAgility();
	} else if(doAdd == false){
		attack -= item.getAttack();
		defence -= item.getDefence();
		agility -= item.getAgility();
	}
}

const double& CharacterProfile::getCurrentExperience() const{
	return currentExperience;
}

void CharacterProfile::setCurrentExperience(const double &currentExperience) {
	this->currentExperience = currentExperience;
}

const double& CharacterProfile::getMaxExperience() const {
	return maxExperience;
}

void CharacterProfile::setMaxExperience(const double &maxExperience) {
	this->maxExperience = maxExperience;
}

void CharacterProfile::addItemToInventory(Item &item){
	characterInventory.addItem(item);
}

/*Return Character's inventory*/
const CharacterInventory& CharacterProfile::getInventory() const{
	return characterInventory;
}

EnemyProfile::EnemyProfile(string _name, int _level, RaceType _race) : Profile(_name, _level, _race) {
}

/*Perform stat update to attack, defence, and agility based on item*/
void EnemyProfile::updateStatsByItem(const Item &item, bool doAdd){
	if(doAdd == true){ // add stat bonus
		attack += item.getAttack();
		defence += item.getDefence();
		agility += item.getAgility();
	} else if(doAdd == false){
		attack -= item.getAttack();
		defence -= item.getDefence();
		agility -= item.getAgility();
	}
}

void EnemyProfile::addItemToInventory(Item &item){
	enemyInventory.addItem(item);
}

/*Return Enemy's inventory*/
const EnemyInventory& EnemyProfile::getInventory() const{
	return enemyInventory;
}

ostream& operator<<(ostream &os, const EnemyProfile &enemyProfile){
	os << "--" << enemyProfile.getName() << "-----" << endl;
	os << "Level: " << enemyProfile.getLevel() << endl;
	os << "Attack: " << enemyProfile.getAttack() << endl;
	os << "Defence: " << enemyProfile.getDefence() << endl;
	os << "Agility: " << enemyProfile.getAgility() << endl;
	os << "Race: " << enemyProfile.getRace() << endl;
	os << "Current Health: " << enemyProfile.getCurrentHealth() << endl;
	os << "Max Health: " << enemyProfile.getMaxHealth() << endl;
	os << "Alive?: " << enemyProfile.getIsAlive() << endl << endl;
	os << "Inventory: " << endl;
	os << enemyProfile.getInventory();

	return os;
}

ostream& operator<<(ostream &os, const CharacterProfile &characterProfile){
	os << "--" << characterProfile.getName() << "-----" << endl;
	os << "Level: " << characterProfile.getLevel() << endl;
	os << "Attack: " << characterProfile.getAttack() << endl;
	os << "Defence: " << characterProfile.getDefence() << endl;
	os << "Agility: " << characterProfile.getAgility() << endl;
	os << "Race: " << characterProfile.getRace() << endl;
	os << "Current Health: " << characterProfile.getCurrentHealth() << endl;
	os << "Max Health: " << characterProfile.getMaxHealth() << endl;
	os << "Current Experience: " << characterProfile.getCurrentExperience() << endl;
	os << "Max Experience: " << characterProfile.getMaxExperience() << endl;
	os << "Alive?: " << characterProfile.getIsAlive() << endl << endl;
	os << "Inventory: " << endl;
	os << characterProfile.getInventory();
	return os;
}

