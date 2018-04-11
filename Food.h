#ifndef FOOD_H
#define FOOD_H

#include "GlobalLib.h"
#include "LinkedList.h"
#include "MovingObject.h"

class Food : public MovingObject {
private:
	static ULL numProduced; // banyak koin yang sudah diproduksi dalam game
	ULL idFood;

public:
	Food(); // ctor
	Food(double, double); //ctor untuk lokasi X
	bool operator==(const Food&);

	/* SETTER & GETTER */
	ULL getId();
	static void setNumProduced(ULL);
	static ULL getNumProduced();

	/* METHOD */
	void descend(LinkedList<Food>&);
};

#endif
