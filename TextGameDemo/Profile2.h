#include <iostream>
#include "RaceType.h"
#include "Inventory.h"

class Profile {
public:
	Profile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth);
	Profile(string _name, int _level, RaceType _race);
	Profile(string _name);
	void deathOfCharacter();
	void isCharacterAlive();
	void incrementCurrentHealth(int incrHealth);
	void decrementCurrentHealth(int decrHealth);
	void incrementMaxHealth(int incrHealth);
	void decrementMaxHealth(int decrHealth);
	bool ItemUsable(const Item &item);
	void updateStatsByItem(const Item &item, bool doAdd);
	//void updateStatsByEnemy(const EnemyProfile &enemy);

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

Profile::Profile(string _name, int _level, RaceType _race, double _currentHealth, double _maxHealth) : name(_name), level(_level), race(_race), currentHealth(_currentHealth), maxHealth(_maxHealth){}

Profile::Profile(string _name, int _level, RaceType _race) : name(_name), level(_level), race(_race), currentHealth(50), maxHealth(50) {}

Profile::Profile(string _name) : name(_name), level(5), race(0), currentHealth(50), maxHealth(50) {}

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

