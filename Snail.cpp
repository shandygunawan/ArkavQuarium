#include "Snail.h"

extern ULL Money;
ULL Snail::numProduced = 0;

Snail::Snail() : MovingObject(SCREEN_WIDTH/2,SCREEN_HEIGHT-OFFSET_BOTTOM) {
	direction = true;
}

Snail::Snail(double locX) : MovingObject(locX,SCREEN_HEIGHT-OFFSET_BOTTOM){
	direction = true;
	id = numProduced;
	numProduced++;
}

void Snail::setDirection(bool dir){
	direction = dir;
}

void Snail::setNumProduced(ULL num){
	numProduced = num;
}

bool Snail::getDirection(){
	return direction;
}

ULL Snail::getId(){
	return id;
}

ULL Snail::getNumProduced(){
	return numProduced;
}

bool Snail::operator==(Snail& other){
	return(this->id == other.getId());
}

Coin Snail::searchCoin(LinkedList<Coin>& listCoin){
	Coin dummy, minimum;

	// Search coin yang terletak paling dekat ke dasar
	// Bandingkan berdasarkan posisi Y saja (makin besar makin ke dasar)
	for(int i = 0 ; i<=listCoin.getSize(); i++){
		dummy = listCoin.get(i);
		if(minimum.getY() <= dummy.getY()){
			minimum = dummy;
		}
	}
	
	return minimum;
}

void Snail::getToCoin(LinkedList<Coin>& listCoin){
	Coin toGet;
	// bergerak jika hanya ada koin di dalam akuarium
	if(listCoin.isEmpty() == false){
		// ambil posisi koin terdekat
		
		toGet = searchCoin(listCoin);


		// cek posisi koin (kiri/kanan)
		if( toGet.getX() > getX() ) { // posisi koin di sebelah kanan siput
			direction = true;

			// cek jika posisi koin <= radius
			if( abs(toGet.getX() - getX()) <= RADIUS_EAT && abs(toGet.getY() - getY()) <= RADIUS_EAT) {
				takeCoin(toGet, listCoin);
			}
			else{
				moveRight(SPEED_SNAIL);
			}
		}
		else { // posisi koin di sebelah kiri siput
			direction = false;

			// cek jika posisi koin <= radius
			if( abs(getX() - toGet.getX()) <= RADIUS_EAT && abs(getY() - toGet.getY()) <= RADIUS_EAT ) {
				takeCoin(toGet, listCoin);
			}
			else{
				moveLeft(SPEED_SNAIL);
			}	
		}	
	}
	
}

void Snail::takeCoin(Coin& toDel, LinkedList<Coin>& listCoin) {
	Money += toDel.getValue();
	listCoin.remove(toDel);
}
