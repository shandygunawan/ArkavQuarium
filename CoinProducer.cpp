#include "CoinProducer.h"

CoinProducer::CoinProducer() {

}

void CoinProducer::produceCoin(Coin& koin, LinkedList<Coin>& listCoin){
	listCoin.add(koin);
}