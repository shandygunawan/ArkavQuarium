#ifndef COIN_H
#define COIN_H

#include "GlobalLib.h"
#include "MovingObject.h"

// Sebuah kelas untuk merepresentasikan koin
class Coin : public MovingObject {
private:
	static ULL numProduced;//Jumlah koin keseluruhan yang telah diproduce dalam game
	ULL idKoin;//Nomor identifikasi idKoin
	int value; // menampung nilai koin

public:
	Coin(); //default ctor
	Coin(int, double, double); //User defined ctor, parameter sebagai value koin
	bool operator==(const Coin&); //operator overloading

	/* SETTER & GETTER */
	ULL getIdKoin();
	int getValue();
	void setValue(int);
	static ULL getNumProduced();
	static void setNumProduced(ULL);
	void descend();
};

#endif
