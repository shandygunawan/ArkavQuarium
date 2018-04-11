#ifndef GUPPY_H
#define GUPPY_H

#include <cmath>
#include "LinkedList.h"
#include "Coin.h"
#include "Fish.h"
#include "CoinProducer.h"

/* MULTIPLE INHERITANCE */
class Guppy : public Fish, public CoinProducer, public MovingObject {
public:
	Guppy(); //ctor dummy
	Guppy(double, double);

	//Getter
	int getTahapPertumbuhan();
	int getCoinCountdown();
	int getFoodCount();

	/* METHOD */
	void grow();//fungsi untuk menambahkan tahap pertumbuhan guppy
	void produceCoinGuppy(LinkedList<Coin>&);//fungsi untuk memproduksi coin sesuai dengan tahap pertumbuhan guppy
	Food searchFood(LinkedList<Food>&);//method untuk mencari makanan terdekat
	void decreaseCoinCountdown(LinkedList<Coin>&); // fungsi untuk mengurangi countdown coin
	void moveToFood(double time, LinkedList<Food>& listFood,LinkedList<Guppy>&); //method overload move to food

	//Operator
	Guppy& operator=(Guppy&);
	bool operator==(Guppy&);

private:
	int tahapPertumbuhan;//attribut tahap pertumbuhan ikan
	int foodCount;//total food yang dimakan oleh guppy
	int coinCountdown; //waktu untuk pengeluaran coin
};


#endif
