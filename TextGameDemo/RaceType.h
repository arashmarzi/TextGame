#include <iostream>
using namespace std;

class RaceType {
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
	RaceType();
	RaceType(int _race);
private:
	Race race;
};

RaceType::RaceType(){}
RaceType::RaceType(int _race) {
	race = (Race)_race;
}