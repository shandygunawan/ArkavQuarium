#ifndef PIRANHA_H
#define PIRANHA_H

#include <cmath>
#include "Fish.h"
#include "Guppy.h"
#include "LinkedList.h"
#include "CoinProducer.h"
#include "MovingObject.h"
/* MULTIPLE INHERITANCE */
class Piranha : public Fish, public CoinProducer, public MovingObject {
public:
	Piranha(); //ctor dummy
	Piranha(double, double);

	/* METHOD */
	void eat(Guppy& eatenGuppy, LinkedList<Guppy>& listGuppy, LinkedList<Coin>& listCoin); //method overloading, method untuk memakan guppy
	void produceCoinPiranha(Guppy&, LinkedList<Coin>&); //method override, method untuk menghasilkan coin berdasarkan harga ikan dan tahapan guppy
	void searchGuppy(Guppy&, LinkedList<Guppy>&);
	void moveToFood(double time, LinkedList<Guppy>&, LinkedList<Coin>&, LinkedList<Piranha>&);

	//Operator
	Piranha& operator=(Piranha&);
	bool operator==(Piranha&);
	
};

#endif
