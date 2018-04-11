#ifndef COINPRODUCER_H
#define COINPRODUCER_H

#include "Coin.h"
#include "LinkedList.h"
#include "CoinProducing.h"

class CoinProducer : public CoinProducing {
public:
	CoinProducer();
	void produceCoin(Coin&, LinkedList<Coin>&);
};

#endif