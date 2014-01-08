// TextGameDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Profile.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//CharacterInventory inventory;
	//Item item1("item1", "im an item", 10, 10, 10, 0);
	//inventory.addItem(item1);
	//Item getItem = inventory.getItem(item1);
	//cout << inventory;
	
	//CharacterInventory cInventory;
	//for(vector<Item>::iterator iter = cInventory.itemDatabase.begin(); iter != cInventory.itemDatabase.end(); iter++) {
	//	cout << *iter;
	//}

	//CharacterProfile hero((string)"Hero", 15, RaceType(0), 100, 100, 0, 100);
	//EnemyProfile enemy((string)"Villan", 99, RaceType(9), 100, 100);
	//cout << hero;
	//cout << enemy;

	/*CharacterProfile hero((string)"Hero", 20, RaceType(1));
	for(int i = 0; i < hero.getInventory().itemDatabase.size(); i++){
		hero.addItemToInventory(hero.getInventory().itemDatabase.at(i));
	}
	cout << hero;

	EnemyProfile enemy((string)"Enemy", 20, RaceType(3));
	for(int i = 0; i < enemy.getInventory().itemDatabase.size(); i++){
		enemy.addItemToInventory(enemy.getInventory().itemDatabase.at(i));
	}

	cout << endl << endl << enemy;*/

	CharacterProfile hero("Hero", 20, RaceType(0));
	vector<RaceType::Race> affinity;
	affinity = hero.getRaceAffinity();

	for(int i = 0; i < affinity.size(); i++){
		cout << affinity.at(i) << endl;
	}
}