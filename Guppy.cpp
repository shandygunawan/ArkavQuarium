#include "Guppy.h"

Guppy::Guppy() : MovingObject(0,0) {
	
}

Guppy::Guppy(double locX, double locY) : MovingObject(locX, locY){
	tahapPertumbuhan = 1;
	foodCount = 0;
	coinCountdown=500;
} 

//Getter
int Guppy::getTahapPertumbuhan(){
	return tahapPertumbuhan;
}


int Guppy::getCoinCountdown(){
	return coinCountdown;
}

int Guppy::getFoodCount(){
	return foodCount;
}

/* METHOD */
void Guppy::grow(){
	if(tahapPertumbuhan<=3){
		if(foodCount>20){//*** PENTING : gatau musti berapa banyak bissa diubah lagi ***
			foodCount = 0;
			tahapPertumbuhan++;
		}
	}
}

//fungsi untuk menambahkan tahap pertumbuhan guppy
void Guppy::decreaseCoinCountdown(LinkedList<Coin>& listCoin){
	coinCountdown--;
	if (coinCountdown <=0){
		produceCoinGuppy(listCoin);
		coinCountdown =500;
	}
}

void Guppy::produceCoinGuppy(LinkedList<Coin>& listCoin){ 
	if(tahapPertumbuhan == 1){
		Coin koin(5,getX(),getY());
		produceCoin(koin,listCoin);
	}
	else if(tahapPertumbuhan==2){
		Coin koin(10,getX(),getY());
		produceCoin(koin,listCoin);
	}
	else{
		Coin koin(15,getX(),getY());
		produceCoin(koin,listCoin);
	}
}

Food Guppy::searchFood (LinkedList<Food>& listFood){
	double distance,min;
	Food* f,ftemp;
	f = &(listFood.get(0));

	min = sqrt(pow(f->getX() - this->getX(),2) + pow(f->getY() - this->getY(),2));

	for(int i=1; i<=listFood.getSize();i++ ){
		ftemp = listFood.get(i);
		distance= sqrt(pow(ftemp.getX() - this->getX(),2) + pow(ftemp.getY() - this->getY(),2));
		if( min > distance){
			min = distance;
			f = &ftemp;
		}
	}

	return *f;
}

void Guppy::moveToFood(double time, LinkedList<Food>& listFood,LinkedList<Guppy>& listGuppy){
	
	if(isAlive()){
		Food foodlock;
		if(listFood.isEmpty() == false){ // ada makanan di akuarium
			if(!full){
				foodlock = searchFood(listFood);
				double food_x = foodlock.getX();
				double food_y = foodlock.getY();
				double fish_x = this->getX();
				double fish_y = this->getY();
				double dx = food_x - fish_x;
				double dy = fish_y - food_y;
				double sudut = 0;
				if(dx>0 && dy>0){ //Kuadran 1
					sudut = -atan(abs(dy/dx));
				} 
				else if (dx <0 && dy>0){ //Kuadran 2
					sudut = M_PI+atan(abs(dy/dx));
				}
				else if (dx<0 && dy <0){ // Kuadran 3
					sudut = M_PI-atan(abs(dy/dx));
				} 
				else if (dx >0 && dy<0){ //Kuadran 4
					sudut = atan(abs(dy/dx));
				}
				
				if(abs(food_x - fish_x) <=RADIUS && abs(food_y - fish_y) <=RADIUS ){
					eat(foodlock, listFood);
					foodCount++;
					grow();
				}
				else{
					moveXby(this->direction, FISH_SPEED,sudut,time);
					moveYby(FISH_SPEED,sudut,time);
				}
			}
			else { // guppy kenyang
				if (this->hungerCountdown==maxHungerTime){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;
				}
				double dx = this->dest_x - this->getX();
				double dy = this->getY() - this->dest_y;
				double sudut = 0;
				if(dx <= RADIUS && dy <= RADIUS){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;	
				}

				if(dx>0 && dy>0){ //Kuadran 1
					sudut = -atan(abs(dy/dx));
				} 
				else if (dx <0 && dy>0){ //Kuadran 2
					sudut = M_PI+atan(abs(dy/dx));
				}
				else if (dx<0 && dy <0){ // Kuadran 3
					sudut = M_PI-atan(abs(dy/dx));
				} 
				else if (dx >0 && dy<0){ //Kuadran 4
					sudut = atan(abs(dy/dx));
				}
				moveXby(this->direction, FISH_SPEED,sudut,time);
				moveYby(FISH_SPEED,sudut,time);
			}
		}
		else { // tidak ada makanan di akuarium
			if (this->hungerCountdown==maxHungerTime){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;
				}
				double dx = this->dest_x - this->getX();
				double dy = this->getY() - this->dest_y;
				double sudut = 0;
				
				if(dx <= RADIUS && dy <= RADIUS){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;	
				}

				if(dx>0 && dy>0){ //Kuadran 1
					sudut = -atan(abs(dy/dx));
				} 
				else if (dx <0 && dy>0){ //Kuadran 2
					sudut = M_PI+atan(abs(dy/dx));
				}
				else if (dx<0 && dy <0){ // Kuadran 3
					sudut = M_PI-atan(abs(dy/dx));
				} 
				else if (dx >0 && dy<0){ //Kuadran 4
					sudut = atan(abs(dy/dx));
				}
				moveXby(this->direction, FISH_SPEED,sudut,time);
				moveYby(FISH_SPEED,sudut,time);
		}
	}
	else { // guppy mati
		listGuppy.remove(*this);
	}
}
	

Guppy& Guppy::operator=(Guppy& a){
	this->setX(a.getX());
	this->setY(a.getY());
	this->id = a.id;
	this->full=a.full;
	this->direction = a.direction;
	this->hungerCountdown = a.hungerCountdown;
	this->fullCountdown = a.fullCountdown;
	this-> tahapPertumbuhan = a.tahapPertumbuhan;
	this-> foodCount = a.foodCount;
	this->coinCountdown = a.coinCountdown;
	this->dest_y = a.dest_y;
	this->dest_x = a.dest_x;
	return *this;
}

bool Guppy::operator==(Guppy& a){
	return ((this->id == a.id) ?  true : false);
}