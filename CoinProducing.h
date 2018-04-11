#ifndef COINPRODUCING_H
#define COINPRODUCING_H

#include "Coin.h"
#include "LinkedList.h"
/* ABSTRACT BASE CLASS */

class CoinProducing {
public:
	virtual void produceCoin(Coin&, LinkedList<Coin>&)=0;
	
};

#endif