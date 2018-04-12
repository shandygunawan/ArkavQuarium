#include "Piranha.h"

Piranha::Piranha() : MovingObject(0,0){
	
} 

Piranha::Piranha(double locX, double locY) : MovingObject(locX, locY){

}

/* METHOD */
void Piranha::eat(Guppy& eatenGuppy, LinkedList<Guppy>& listGuppy, LinkedList<Coin>& listCoin){
	listGuppy.remove(eatenGuppy);
	produceCoinPiranha(eatenGuppy, listCoin);
	fullCountdown = TIME_MAX_FULL;
	hungerCountdown = TIME_MAX_HUNGRY;
	full = true;
}

void Piranha::produceCoinPiranha(Guppy& eatenGuppy, LinkedList<Coin>& listCoin){
	int value = PRICE_GUPPY * (eatenGuppy.getTahapPertumbuhan() +1);
	Coin koin(value, getX(), getY());
	produceCoin(koin,listCoin);
}

void Piranha::searchGuppy(Guppy& GuppyLock, LinkedList<Guppy>& listGuppy){
	double distance,min;
	Guppy gtemp;
	GuppyLock = listGuppy.get(0);

	min = sqrt(pow(GuppyLock.getX() - this->getX(),2) + pow(GuppyLock.getY() - this->getY(),2));

	for(int i=1; i<=listGuppy.getSize();i++ ){
		gtemp = listGuppy.get(i);
		distance= sqrt(pow(gtemp.getX() - this->getX(),2) + pow(gtemp.getY() - this->getY(),2));
		if( min> distance){
			min = distance;
			GuppyLock = gtemp;
		}
	}
}

void Piranha::moveToFood(double time, LinkedList<Guppy>& listGuppy, LinkedList<Coin>& listCoin, LinkedList<Piranha>& listPiranha){
	
	if(isAlive()){
		Guppy Guppylock;
		if(listGuppy.isEmpty() == false){ // ada guppy dalam akuarium
			if(!full){ 
				searchGuppy(Guppylock, listGuppy);
		
				double Guppy_x = Guppylock.getX();
				double Guppy_y = Guppylock.getY();
				double piranha_x = this->getX();
				double piranha_y = this->getY();
				double dx = Guppy_x - piranha_x ;
				double dy = piranha_y - Guppy_y;
				double sudut=0;


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
				
				if(Guppy_x < piranha_x){ // gerak ke kiri
					direction = false;
				}
				else{
					direction = true; // gerak ke kanan
				}

				if(abs(Guppy_x - piranha_x) <= RADIUS_EAT && abs(Guppy_y - piranha_y) <= RADIUS_EAT ){
					eat(Guppylock, listGuppy,listCoin);
				}
				else{
					moveXby(this->direction, SPEED_FISH,sudut,time);
					moveYby(SPEED_FISH,sudut,time);	
				}	

			}
			else { //piranha kenyang
				if (this->hungerCountdown==TIME_MAX_HUNGRY-1){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;
				}
				double dx = this->dest_x - this->getX();
				double dy = this->getY() - this->dest_y;
				double sudut = 0;
				if(dx <= RADIUS_MOVE && dy <= RADIUS_MOVE){
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
				moveXby(this->direction, SPEED_FISH,sudut,time);
				moveYby(SPEED_FISH,sudut,time);
			}
		}
		else { // tidak ada makanan di akuarium
			if (this->hungerCountdown==TIME_MAX_HUNGRY-1){
					double randx = (rand()%SCREEN_WIDTH);
					double randy = (rand()%SCREEN_HEIGHT);
					this->dest_x = randx;
					this->dest_y = randy;
				}
				double dx = this->dest_x - this->getX();
				double dy = this->getY() - this->dest_y;
				double sudut = 0;
				if(dx <= RADIUS_MOVE && dy <= RADIUS_MOVE){
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
				moveXby(this->direction, SPEED_FISH,sudut,time);
				moveYby(SPEED_FISH,sudut,time);
		}
		
	}
	else{ // piranha mati
		listPiranha.remove(*this);
	}
}

Piranha& Piranha::operator=(Piranha& a){
	this->setX(a.getX());
	this->setY(a.getY());
	this->id = a.id;
	this->full=a.full;
	this->direction = a.direction;
	this->hungerCountdown = a.hungerCountdown;
	this->fullCountdown = a.fullCountdown;
	return *this;
}

bool Piranha::operator==(Piranha& a){
	return ((this->id == a.id) ?  true : false);

}
