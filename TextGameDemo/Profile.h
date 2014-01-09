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
	const double& getAttack() const;
	void setAttack(const double &attack);
	const double& getDefence() const;
	void setDefence(const double &defence);
	const double& getAgility() const;
	void setAgility(const double &agility);
	const RaceType& getRace() const;
	void setRace(const int &_race);
	const double& getCurrentHealth() const;
	void setCurrentHealth(const int &currentHealth);
	const double& getMaxHealth() const;
	void setMaxHealth(const double &maxHealth);
	const bool& getIsAlive() const;
	void setIsAlive(const bool &isAlive);
	const vector<RaceType>& getRaceAffinity() const;
	void setRaceAffinity(const vector<RaceType> &affinity);
	//void updateStatsByEnemy(const EnemyProfile &enemy);

protected:
	string name;
	int level;
	double attack;
	double defence;
	double agility;
	RaceType race;
	vector<RaceType> affinity;
	double currentHealth;
	double maxHealth;
	bool isAlive;
};
class EnemyProfile;
class CharacterProfile : public Profile {
public:
	CharacterProfile(string _name, int _level, RaceType _race);
	void incrementLevel();
	void incrementMaxExperience();
	void incrementCurrentExperience(double incrExperience);
	//bool isItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	void addStatsByEnemy(const EnemyProfile &enemy);
	void removeStatsByEnemy();
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
	void addStatsByCharacter(const CharacterProfile &character);
	void removeStatsByCharacter();
	void addItemToInventory(Item &item);
	const EnemyInventory& getInventory() const;
private:
	EnemyInventory enemyInventory;

	friend ostream& operator<<(ostream &os, const EnemyProfile &enemyProfile);
};

Profile::Profile(string _name, int _level, RaceType _race) : name(_name), level(_level), race(_race), attack(10), defence(10), agility(10), isAlive(true) {
	maxHealth = level*10;
	currentHealth = maxHealth;
	affinity = race.getRaceAffinity();
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

const double& Profile::getAttack() const{
	return attack;
}

void Profile::setAttack(const double &attack){
	this->attack = attack;
}

const double& Profile::getDefence() const{
	return defence;
}

void Profile::setDefence(const double &defence){
	this->defence = defence;
}

const double& Profile::getAgility() const{
	return agility;
}

void Profile::setAgility(const double &agility){
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

const vector<RaceType>& Profile::getRaceAffinity() const{
	return affinity;
}

void Profile::setRaceAffinity(const vector<RaceType> &affinity){
	this->affinity = affinity;
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

/*Perform stat update to attack, defence, and agility based on enemy race type*/
void CharacterProfile::addStatsByEnemy(const EnemyProfile &enemy){
	bool isUpdated = false;
	for(int i = 0; i < affinity.size() && !isUpdated; i++){
		if(enemy.getRace().getRace() == affinity.at(i).getRace()){
			isUpdated = true;
			attack *= 1.25;
			defence *= 1.25;
			agility *= 1.25;
		}
	}
}

void CharacterProfile::removeStatsByEnemy(){
	attack = attack / 1.25;
	defence = defence / 1.25;
	agility = agility / 1.25;
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

/*Perform stat update to attack, defence, and agility based on enemy race type*/
void EnemyProfile::addStatsByCharacter(const CharacterProfile &enemy){
	bool isUpdated = false;
	for(int i = 0; i < affinity.size() && !isUpdated; i++){
		if(enemy.getRace().getRace() == affinity.at(i).getRace()){
			isUpdated = true;
			attack *= 1.25;
			defence *= 1.25;
			agility *= 1.25;
		}
	}
}

void EnemyProfile::removeStatsByCharacter(){
	attack = attack / 1.25;
	defence = defence / 1.25;
	agility = agility / 1.25;
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

