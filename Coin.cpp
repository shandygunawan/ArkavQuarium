#include "Coin.h"

ULL Coin::numProduced = 0;

Coin::Coin() : MovingObject(-1,-1) {
	// dummy
}

Coin::Coin(int val, double locX, double locY) : MovingObject(locX, locY) {
	value = val;
	Coin::numProduced++;
}

bool Coin::operator==(const Coin& other){
	return(idKoin == other.idKoin);
}

ULL Coin::getNumProduced() {
	return numProduced;
}

ULL Coin::getIdKoin() {
	return idKoin;
}

int Coin::getValue(){
	return value;
}

void Coin::setNumProduced(ULL num) {
	numProduced = num;
}

void Coin::setValue(int val){
	value = val;
}

void Coin::descend(){
	if(isBottom() == false){
		MovingObject::descend(SPEED_COIN);
	}
	else if(getY() > SCREEN_HEIGHT-OFFSET_BOTTOM){
		setY(SCREEN_HEIGHT-OFFSET_BOTTOM);
	}
}