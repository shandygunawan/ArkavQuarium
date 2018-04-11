#include "Aquarium.h"

using namespace std;

extern ULL Money;
extern int Egg;

LinkedList<Coin> Aquarium::listCoin; 		//LinkedList coin
LinkedList<Guppy> Aquarium::listGuppy; 		//LinkedList guppy
LinkedList<Piranha> Aquarium::listPiranha; 		//LinkedList fish
LinkedList<Food> Aquarium::listFood; 		//LinkedList food
LinkedList<Snail> Aquarium::listSnail; 					//Snail

//ctor aquarium tanpa parameter
Aquarium::Aquarium(){
	// Money = 0;
	Snail siput(SCREEN_WIDTH/2);
	addSnail(siput);
}

//fungsi untuk menambah Objek kedalam linked list
void Aquarium::addCoin(Coin& koin){
	listCoin.add(koin);
}

void Aquarium::addGuppy(Guppy& GuppyFish){
	listGuppy.add(GuppyFish);
}

void Aquarium::addPiranha(Piranha& PiranhaFish){
	listPiranha.add(PiranhaFish);
}

void Aquarium::addFood(Food& food){
	listFood.add(food);
}

void Aquarium::addSnail(Snail& siput) {
	listSnail.add(siput);
}


	
//fungsi untuk menghapus sebuah objek dari linked list,
void Aquarium::delCoin(Coin& koin){
	listCoin.remove(koin);
}
void Aquarium::delGuppy(Guppy& GuppyFish){
	listGuppy.remove(GuppyFish);
}
void Aquarium::delPiranha(Piranha& PiranhaFish){
	listPiranha.remove(PiranhaFish);
}
void Aquarium::delFood(Food& food){
	listFood.remove(food);
}
void Aquarium::delSnail(Snail& siput){
	listSnail.remove(siput);
}


//getter LinkedList<objek>
LinkedList<Coin> Aquarium::getListCoin(){
	return listCoin;
}
LinkedList<Guppy> Aquarium::getListGuppy(){
	return listGuppy;
}
LinkedList<Piranha> Aquarium::getListPiranha(){
	return listPiranha;
}
LinkedList<Food> Aquarium::getListFood(){
	return listFood;
}
LinkedList<Snail> Aquarium::getListSnail(){
	return listSnail;
}

void Aquarium::buyGuppy(){
	
	if(Money >= HARGA_IKAN){
		int x = rand()%SCREEN_WIDTH;
		int y = rand()%(SCREEN_HEIGHT-BOTTOM_OFFSET);
		Guppy newGuppy((double)x, (double)y);
		addGuppy(newGuppy);
		Money -= HARGA_IKAN;
	}
}

void Aquarium::buyPiranha(){
	if(Money >= HARGA_PIRANHA){
		int x = rand()%(SCREEN_WIDTH);
	    int y = rand()%(SCREEN_HEIGHT-BOTTOM_OFFSET);
	    Piranha newPiranha(x,y);
	    addPiranha(newPiranha);
	    Money -= HARGA_PIRANHA;
	}
}

void Aquarium::buyEgg(){
	if(Money >= HARGA_TELUR){
		Egg++;
		Money -= HARGA_TELUR;
	}
}

void Aquarium::buyFood(double locX, double locY){
	if(Money >= HARGA_MAKANAN){
		Food newFood(locX,locY);
		addFood(newFood);
		Money -= HARGA_MAKANAN;
	}
}

void Aquarium::moveCoin(){
	if(listCoin.isEmpty() == false){
        Coin* dummyCoin;
        for(int i = 1; i <= listCoin.getSize(); i++){
            dummyCoin = &(listCoin.get(i));
            dummyCoin->descend();
        }
    }
}
void Aquarium::moveGuppy(double time){
	int size = listGuppy.getSize();
	Guppy* dummyGuppy;
	for(int i = 1; i <= size; i ++){
		dummyGuppy = &(listGuppy.get(i));
		dummyGuppy->decreaseCountdown();
		dummyGuppy->decreaseCoinCountdown(listCoin);
	}
	for (int i = 1; i<=size; i++){
		dummyGuppy = &(listGuppy.get(i));
		dummyGuppy->moveToFood(time, listFood, listGuppy);
	}
}

void Aquarium::movePiranha(double time){
	int size = listPiranha.getSize();
	Piranha* dummyPiranha;

	for(int i = 1; i <= size; i++){
		dummyPiranha = &(listPiranha.get(i));
		dummyPiranha->decreaseCountdown();		
	}

	for (int i = 1; i<=size; i++){
		dummyPiranha = &(listPiranha.get(i));
		dummyPiranha->moveToFood(time, listGuppy, listCoin, listPiranha);
	}
	
}

void Aquarium::moveFood(){
	if(listFood.isEmpty() == false){
        Food* dummyFood;
        for(int i = 1; i <= listFood.getSize(); i++){
            dummyFood = &(listFood.get(i));
            dummyFood->descend(listFood);
        }
    }
}
void Aquarium::moveSnail(){
	if(listSnail.isEmpty() == false){
		Snail* dummySnail;
		for(int i = 1; i <= listSnail.getSize(); i++){
			dummySnail = &(listSnail.get(i));
			dummySnail->getToCoin(listCoin);
		}
	}
}

// //setter dan getter money
// void Aquarium::increaseMoney(double amount){
// 	Money += amount;
// }
// void Aquarium::decreaseMoney(double amount){
// 	Money -= amount;
// }
// double Aquarium::getMoney(){
// 	return Money;
// }
