#include <iostream>
#include <string>
#include <ostream>
#include <vector>
using namespace std;

class RaceType {
	enum Race {
		HUMAN, // 0
		IMMORTAL, // 1
		ELF, // 2
		GOBLIN, // 3
		INTERNETTROLL, // 4
		INSECTOID, // 5
		MAMMAL, // 6
		AQUATIC, // 7
		AERIAL, // 8
		DRAGON // 9
	};

public:
	RaceType();
	RaceType(int _race);
	const int& getRace() const;
	void setRace(const int &_race);
	vector<RaceType> getRaceAffinity();

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

vector<RaceType> RaceType::getRaceAffinity(){

	vector<RaceType> affinity;

	switch(race){
	case 0:
		affinity.push_back(RaceType(5)); // insectoid
		affinity.push_back(RaceType(6)); // mammal
		break;
	case 1:
		affinity.push_back(RaceType(0)); // human
		affinity.push_back(RaceType(2)); // elf
		affinity.push_back(RaceType(3)); // goblin
		affinity.push_back(RaceType(4)); // internet troll
		affinity.push_back(RaceType(5)); // insectoid
		affinity.push_back(RaceType(6)); // mammal
		affinity.push_back(RaceType(7)); // aquatic
		affinity.push_back(RaceType(8)); // aerial
		affinity.push_back(RaceType(9)); // dragon
		break;
	case 2:
	    affinity.push_back(RaceType(0)); // human
		affinity.push_back(RaceType(7)); // goblin
		affinity.push_back(RaceType(6)); // mammal
		break;
	case 3:
		affinity.push_back(RaceType(4)); // internet troll
		break;
	case 4:
		affinity.push_back(RaceType(0)); // human
		affinity.push_back(RaceType(1)); // immortal
		affinity.push_back(RaceType(2)); // elf
		affinity.push_back(RaceType(5)); // insectoid
		affinity.push_back(RaceType(6)); // mammal
		affinity.push_back(RaceType(7)); // aquatic
		affinity.push_back(RaceType(8)); // aerial
		affinity.push_back(RaceType(9)); // dragon
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		affinity.push_back(RaceType(0)); // human
		affinity.push_back(RaceType(4)); // insectoid
		affinity.push_back(RaceType(6)); // mammal
		break;
	case 9:
		affinity.push_back(RaceType(0)); // human
		affinity.push_back(RaceType(5)); // insectoid
		affinity.push_back(RaceType(6)); // mammal
		affinity.push_back(RaceType(7)); // aquatic
		affinity.push_back(RaceType(8)); // aerial
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
