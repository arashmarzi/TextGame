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

	CharacterProfile hero((string)"Hero", 15, RaceType(0), 100, 100, 0, 100);
	EnemyProfile enemy((string)"Villan", 15, RaceType(9), 100, 100);
	cout << hero;
	cout << enemy;
}