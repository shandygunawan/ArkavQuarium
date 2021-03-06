#include "GlobalLib.h"
#include "Fish.h"
#include "cmath"
#include "Guppy.h"

using namespace std;

ULL Fish::jumlahIkan = 0; //inisialisasi elemen statik

Fish::Fish(){
	jumlahIkan++;
	id = jumlahIkan;
	full = true;
	direction = true;
	hungerCountdown = TIME_MAX_HUNGRY;
	fullCountdown = TIME_MAX_FULL;
	dest_y = 0;
	dest_x = 0;
}

//Getter
ULL Fish::getJumlahIkan(){
	return jumlahIkan;
}
ULL Fish::getId(){
	return id;
}
bool Fish::getFull(){
	return full;
}
bool Fish::getDirection(){
	return direction;
}
int Fish::getHungerCountdown(){
	return hungerCountdown;
}
int Fish::getFullCountdown(){
	return fullCountdown;
}


//setter
void Fish::setId(ULL entry){
	id = entry;
}
void Fish::setFull(bool entry){
	full = entry;
}
void Fish::setDirection(bool entry){
	direction = entry;
}
void Fish::setHungerCountdown(int entry){
	hungerCountdown = entry;
}
void Fish::setFullCountdown(int entry){
	fullCountdown = entry;
}

//Method

void Fish::eat(Food& eatenFood, LinkedList<Food>& listFood){
	listFood.remove(eatenFood);
	full = true;
	fullCountdown=TIME_MAX_FULL;
	hungerCountdown=TIME_MAX_HUNGRY;
}	

void Fish::decreaseCountdown(){
	if(full){
		fullCountdown--;
		if(fullCountdown==0){
			full=false;
		}
	}
	else{
		if(hungerCountdown!=0){
			hungerCountdown--;
		}
	}
}

bool Fish::isAlive(){
	return (hungerCountdown>0);
}