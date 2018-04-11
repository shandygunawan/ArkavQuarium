#ifndef SNAIL_H
#define SNAIL_H

#include "GlobalLib.h"
#include "LinkedList.h"
#include "MovingObject.h"
#include "Coin.h"

class Aquarium;

class Snail : public MovingObject {
private:
	bool direction;
	static ULL numProduced;
	ULL id;
public:
	Snail(); //ctor
	Snail(double);
	// Siput hanya terletak di dasar kolam

	/* Setter */
	void setDirection(bool);
	static void setNumProduced(ULL);

	/* Getter */
	bool getDirection();
	ULL getId();
	static ULL getNumProduced();

	/* operator Overloading */
	bool operator==(Snail&);

	/* METHOD */
	Coin searchCoin(LinkedList<Coin>&);
	// Siput mencari letak koin yang ada di dasar
	// Jika tidak ada koin di dasar, siput bergerak ke arah koin yang lebih dekat dengan dasar
	// Jika tidak ada koin di akuarium, siput diam
	// Return fungsi adalah posisi koin terdekat

	void getToCoin(LinkedList<Coin>&);
	// mengatur pergerakan siput untuk mendapatkan koin
	// Siput hanya bisa bergerak ke kiri atau kanan

	void takeCoin(Coin&, LinkedList<Coin>&);
	// Siput mengambil koin yang terletak pada posisi yang sama dengan siput

};

#endif
