#include <string>
#include <map>
using namespace std;

class ItemType {

	enum Type { WEAPON, MODIFIER, ARMOR };

public:
	ItemType();
	ItemType(int _type);
	const int getType() const;
	void setType(const int &_type);
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