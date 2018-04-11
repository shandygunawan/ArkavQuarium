#include "Food.h"

ULL Food::numProduced = 0;

Food::Food() : MovingObject(-1,-1) {
	// dummy
}

Food::Food(double _x, double _y) : MovingObject(_x,_y){
	idFood = numProduced;
	Food::numProduced++;
}

bool Food::operator==(const Food& other){
	return (this->idFood == other.idFood);
}

ULL Food::getId(){
	return idFood;
}

void Food::setNumProduced(ULL entry) {
	numProduced = entry;
}

ULL Food::getNumProduced(){
	return numProduced;
}

void Food::descend(LinkedList<Food>& listFood){
	if(isBottom() == false){
		MovingObject::descend(FOOD_SPEED);
	}
	else if(getY() >= SCREEN_HEIGHT-BOTTOM_OFFSET){
		int idx = listFood.find(*this);
		Food toDel;
		toDel = listFood.get(idx);
		listFood.remove(toDel);
	}
}