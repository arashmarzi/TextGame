/*
 * Profile.h
 *
 *  Created on: Oct 28, 2013
 *      Author: Arash
 */

#ifndef PROFILE_H_
#define PROFILE_H_
#include <iostream>
#include "Inventory.h"
using namespace std;

class Profile {
public:
	enum Race {
		HUMAN,
		IMMORTAL,
		ELF,
		GOBLIN,
		INTERNETTROLL,
		INSECTOID,
		MAMMAL,
		AQUATIC,
		AMPHIBIAN,
		AERIAL,
		DRAGON
	};

	/*Constructor for specific profile*/
	inline Profile(string _name, int _level, Race _race, double _currentHealth,
			double _maxHealth) :
			name(_name), level(_level), race(_race), currentHealth(
					_currentHealth), maxHealth(_maxHealth), isAlive(true) {

	}


	/*Constructor for default profile*/
	inline Profile(string _name, int _level, Race _race) :
			name(_name), level(_level), race(_race), maxHealth(100), currentHealth(
					100), isAlive(true) {

	}

	inline virtual ~Profile(){
	}

	/*Character dies*/
	inline void deathOfCharacter() {
		cout << name << ", you have unfortunately died...what a pity;" << endl
				<< "though you managed to reach level " << level << "!" << endl;
	}

	/*Check if character is alive*/
	inline void isCharacterAlive() {
		if (currentHealth == 0) {
			isAlive = false;
			deathOfCharacter();
		}
	}

	/*Increment character current health*/
	inline void incrementCurrentHealth(int incrHealth) {
		if (currentHealth < maxHealth) {
			if (currentHealth + incrHealth < maxHealth) {
				currentHealth += incrHealth;
			} else if (currentHealth + incrHealth >= maxHealth) {
				currentHealth = maxHealth;
			}
		}
	}

	/*Decrement character current health*/
	inline void decrementCurrentHealth(int decrHealth) {
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
	inline void incrementMaxHealth(int incrHealth) {
		maxHealth += incrHealth;
	}

	/*Decrement character max health*/
	inline void decrementMaxHealth(int decrHealth) {
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

	/*Return profile's inventory*/
	inline virtual Inventory getInventory();

private:
	string name;
	int level;
	Race race;
	double currentHealth;
	double maxHealth;
	bool isAlive;
};

class CharacterProfile: public Profile {
public:
	/*Specific character profile, use to create storyline characters*/
	inline CharacterProfile(string _name, int _level, Race _race, double _currentHealth, double _maxHealth) :
			Profile(_name, _level, _race, _currentHealth, _maxHealth), currentExperience(0), isAlive(true) {
		maxExperience = 10.25 * level;
		maxHealth = level * 10;
	}

	/*Default character profile, used to create protagonist*/
	inline CharacterProfile(string _name) :
			name(_name), level(5), currentHealth(100), maxHealth(100), currentExperience(
					0), isAlive(true) {
		maxExperience = 10.25 * level;
		maxHealth = level * 10;
	}

	/*Increment character level*/
	inline void incrementLevel() {
		level += 1;
	}

	/*Increment character max experience*/
	inline void incrementMaxExperience() {
		maxExperience *= 10.25;
	}

	/*Increment character current experience*/
	inline void incrementCurrentExperience(int incrExperience) {
		if (currentExperience + incrExperience < maxExperience) {
			currentExperience += incrExperience;
		} else if (currentExperience + incrExperience >= maxExperience) {
			currentExperience %= maxExperience;
			incrementLevel();
			incrementMaxExperience();
		}
	}

	/*Return Character's inventory*/
	// must adjust return type
	inline CharacterInventory getInventory(){
		return characterInventory;
	}

private:
	double currentExperience;
	double maxExperience;
	CharacterInventory characterInventory;
};

class EnemyProfile {
public:
	/*Return Enemy's inventory*/
	// must adjust return type
	inline EnemyInventory getInventory(){
			return enemyInventory;
		}

private:
	EnemyInventory enemyInventory;
};

#endif /* PROFILE_H_ */
