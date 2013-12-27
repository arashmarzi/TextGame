#include <iostream>
#include "RaceType.h"
#include "Inventory.h"

class Profile {
public:
	Profile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth);
	Profile(string _name);
	void deathOfCharacter();
	void isCharacterAlive();
	void incrementCurrentHealth(int incrHealth);
	void decrementCurrentHealth(int decrHealth);
	void incrementMaxHealth(int incrHealth);
	void decrementMaxHealth(int decrHealth);
	bool ItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	void updateStatsByEnemy(const EnemyProfile &enemy);

protected:
	string name;
	int level;
	int attack;
	int defence;
	int agility;
	RaceType race;
	double currentHealth;
	double maxHealth;
	bool isAlive;
};

class CharacterProfile: public Profile {
public:
	CharacterProfile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth);
	CharacterProfile(string _name);
	void incrementLevel();
	void incrementMaxExperience();
	void incrementCurrentExperience(int incrExperience);
	//bool ItemUsable(const Item &item); // based on race
	void updateStatsByItem(const Item &item, bool doAdd);
	//void updateStatsByEnemy(const EnemyProfile &enemy); // based on race
	CharacterInventory getInventory();
private:
	double currentExperience;
	double maxExperience;
	CharacterInventory characterInventory;
};

class EnemyProfile : public Profile {
public:
	EnemyProfile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth);
	EnemyProfile(string _name);
	bool ItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	void updateStatsByEnemy(const EnemyProfile &enemy);
	EnemyInventory getInventory();
private:
	EnemyInventory enemyInventory;
};

/*Constructor for specific profile*/
Profile::Profile(string _name, int _level, RaceType _race, double _currentHealth,
				 double _maxHealth) :
name(_name), level(_level), race(_race), currentHealth(
	_currentHealth), maxHealth(_maxHealth), isAlive(true) {

}


/*Constructor for default profile*/
Profile::Profile(string _name, int _level, RaceType _race) :
	name(_name), level(_level), race(_race), maxHealth(100), currentHealth(
	100), isAlive(true) {

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

/*Specific character profile, use to create storyline characters*/
CharacterProfile::CharacterProfile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth) :
	Profile(_name, _level, _race, _currentHealth, _maxHealth), currentExperience(0), isAlive(true) {
		maxExperience = 10.25 * level;
		maxHealth = level * 10;
}

/*Default character profile, used to create protagonist*/
CharacterProfile::CharacterProfile(string _name) : Profile(_name, 5, 100, 100, 0) {
		maxExperience = 10.25 * level;
		maxHealth = level * 10;
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
void CharacterProfile::incrementCurrentExperience(int incrExperience) {
	if (currentExperience + incrExperience < maxExperience) {
		currentExperience += incrExperience;
	} else if (currentExperience + incrExperience >= maxExperience) {
		currentExperience %= maxExperience;
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

/*Return Character's inventory*/
CharacterInventory CharacterProfile::getInventory(){
	return characterInventory;
}

/*Specific enemy profile, use to create storyline characters*/
EnemyProfile::EnemyProfile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth) :
	Profile(_name, _level, _race, _currentHealth, _maxHealth), isAlive(true) {
}

/*Default enemy profile, used to create antagonists*/
EnemyProfile::EnemyProfile(string _name) :
	name(_name), level(5), currentHealth(100), maxHealth(100), isAlive(true) {
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

/*Return Enemy's inventory*/
// must adjust return type
EnemyInventory EnemyInventory::getInventory(){
	return enemyInventory;
}