#include <string>
#include <map>
#include <ostream>
using namespace std;

class ItemType {

	enum Type { WEAPON, MODIFIER, ARMOR };

public:
	ItemType();
	ItemType(int _type);
	const int getType() const;
	void setType(const int &_type);

	friend ostream& operator<<(ostream &os, const ItemType &_itemType);
	friend bool operator==(const ItemType &itemType, const ItemType &other);
private:
	Type type;
};

ItemType::ItemType(){
}

ItemType::ItemType(int _type) {
	type = (Type)_type;
}

const int ItemType::getType() const {
	return (int)type;
}

void ItemType::setType(const int &_type) {
	switch(_type){
	case 0:
		type = WEAPON;
		break;
	case 1:
		type = MODIFIER;
		break;
	case 2:
		type = ARMOR;
		break;
	}
}

bool operator==(const ItemType &itemType, const ItemType &other){
	if(itemType.getType() == other.getType()){
		return true;
	}

	return false;
}

ostream& operator<<(ostream &os, const ItemType &_itemType){
	if(_itemType.getType() == 0){
		os << "Weapon";
	} else if(_itemType.getType() == 1){
		os << "Modifier";
	} else if(_itemType.getType() == 2){
		os << "Armour";	
	} else{
		os << "None";
	}

	return os;
}

