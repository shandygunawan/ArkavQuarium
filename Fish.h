#ifndef FISH_H
#define FISH_H

#include "GlobalLib.h"
#include "MovingObject.h"
#include "LinkedList.h"
#include "Food.h"

class Fish {
protected:
	static ULL jumlahIkan;//total dari ikan yang telah dikeluarkan pada akuarium
	ULL id;
	bool full; //true jika ikan dalam keadaan kenyang , false jika dalam keadaan lapar
	bool direction; //jika direction = true, maka ikan menghadap kanan
	int hungerCountdown; //countdown ketika ikan lapar. Jika nilai =0, maka ikan mati.
	int fullCountdown; // countdown ketika ikan dalam keadaan kenyang.Jika nilai =0 ikan berubah ke keadaan lapar
	const int maxFullTime = 2000; //nilai waktu maksimal keadaan kenyang
	const int maxHungerTime = 1000; //nilai waktu maksimal keadaan lapar
	double dest_x , dest_y;
	
public:
	Fish(); //dummy
	Fish(double, double); //ctor
	
	//Getter
	ULL getJumlahIkan();
	ULL getId();
	bool getFull();
	bool getDirection();
	int getHungerCountdown();
	int getFullCountdown();

	//setter
	void setId(ULL);
	void setFull(bool);
	void setDirection(bool);
	void setHungerCountdown(int);
	void setFullCountdown(int);
	
	//Method
	virtual void eat(Food&, LinkedList<Food>&); //method yang mendeskripsikan cara makan ikan
	void decreaseCountdown();//method untuk mengurangi countdown
	bool isAlive();//Method yang akan menreturn true jika ikan dalam keadaan hidup dan false jika ikan dalam keadaan false
	
	//Operator overloading
	// bool operator==(Fish&);
	// Fish& operator=(Fish&);
};

#endif
