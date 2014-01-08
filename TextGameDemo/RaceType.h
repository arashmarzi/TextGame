#include <iostream>
#include <string>
#include <ostream>
#include <vector>
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
	RaceType();
	RaceType(int _race);
	const int& getRace() const;
	void setRace(const int &_race);
	vector<RaceType::Race> getRaceAffinity();

	friend ostream& operator<<(ostream &os, const RaceType &raceType);
private:
	Race race;
};

RaceType::RaceType(){}

RaceType::RaceType(int _race) {
	race = (Race)_race;
}

const int& RaceType::getRace() const {
	return (int)race;
}

void RaceType::setRace(const int &_race) {
	switch(_race){
	case 0:
		race = HUMAN;
		break;
	case 1:
		race = IMMORTAL;
		break;
	case 2:
		race = ELF;
		break;
	case 3:
		race = GOBLIN;
		break;
	case 4:
		race = INTERNETTROLL;
		break;
	case 5:
		race = INSECTOID;
		break;
	case 6:
		race = MAMMAL;
		break;
	case 7:
		race = AQUATIC;
		break;
	case 8:
		race = AERIAL;
		break;
	case 9:
		race = DRAGON;
		break;
	}
}

vector<RaceType::Race> RaceType::getRaceAffinity(){

	vector<RaceType::Race> affinity;

	switch(race){
	case 0:
		affinity.push_back(Race::HUMAN);
		affinity.push_back(Race::IMMORTAL);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;

	}

	return affinity;
}

ostream& operator<<(ostream &os, const RaceType &_raceType){
	if(_raceType.getRace() == 0){
		os << "Human";
	} else if(_raceType.getRace() == 1){
		os << "Immortal";
	} else if(_raceType.getRace() == 2){
		os << "Elf";	
	} else if(_raceType.getRace() == 3){
		os << "Goblin";	
	} else if(_raceType.getRace() == 4){
		os << "Internet Troll";	
	} else if(_raceType.getRace() == 5){
		os << "Insectoid";	
	} else if(_raceType.getRace() == 6){
		os << "Mammal";	
	} else if(_raceType.getRace() == 7){
		os << "Aquatic";	
	} else if(_raceType.getRace() == 8){
		os << "Aerial";	
	} else if(_raceType.getRace() == 9){
		os << "Dragon";	
	} else{
		os << "None";
	}

	return os;
}
