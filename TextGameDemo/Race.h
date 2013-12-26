#include <iostream>
#include "Item.h"
#include "Profile.h"
#include "Inventory.h"
using namespace std;

class RaceInterface {
	enum Race {
		HUMAN,
		IMMORTAL,
		ELF,
		GOBLIN,
		INTERNETTROLL,
		INSECTOID,
		MAMMAL,
		AQUATIC,
		AERIAL,
		DRAGON
	};

public:

	virtual bool isItemUsable(Item* item, int race) = 0;
	virtual void updateStatsByItem(Item* item, int race) = 0;
	virtual void updateStatsByEnemy(EnemyProfile* enemy, int race) = 0;
	virtual ~RaceInterface();
};

//HUMAN,
class Human: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {
		// iterator to vector element:
		vector<Race>::iterator iter;
		iter = find(item->getAffinity().begin(), item->getAffinity().end(), HUMAN);
		cout << "Item " << item->getName() << " ";
		if (*iter == HUMAN){
			cout << "can";
		} else {
			cout << "cannot";
		}

		cout << " by a human." << endl;
	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//	IMMORTAL
class Immortal: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//ELF
class Elf: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//	GOBLIN
class Goblin: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//INTERNETTROLL
class InternetTroll: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//	INSECTOID
class Insectoid: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//	MAMMAL
class Mammal: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

// AQUATIC
class Aquatic: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//		AERIAL
class Aerial: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};

//	DRAGON
class Dragon: public RaceInterface {
public:
	bool isItemUsable(const Item* item, int race) {

	}

	void updateStatsByItem(const Item* item, int race){

	}

	void updateStatsByEnemy(const EnemyProfile* enemy, int race) {

	}
};