	#ifndef AQUARIUM_H
#define AQUARIUM_H

#include <bits/stdc++.h>
#include <unistd.h>
#include "GlobalLib.h"
#include "LinkedList.h"
#include "Food.h"
#include "Fish.h"
#include "Guppy.h"
#include "Piranha.h"
#include "Snail.h"
#include "Coin.h"

using namespace std;

class Aquarium{
	public :
		static LinkedList<Coin> listCoin; 		//LinkedList coin
		static LinkedList<Guppy> listGuppy; 	//LinkedList Guppy
		static LinkedList<Piranha> listPiranha;	//LinkedList piranha
		static LinkedList<Food> listFood; 		//LinkedList food
		static LinkedList<Snail> listSnail; 	//LinkedList Snail
	
		//ctor aquarium tanpa parameter
		Aquarium();
		
		//fungsi untuk menambah Objek kedalam linked list
		static void addCoin(Coin&); //menambah Coin ke dalam LinkedList<Coin>
		static void addGuppy(Guppy&); //menambah Fish ke dalam LinkedList<Guppy>
		static void addPiranha(Piranha&); //menambah Fish ke dalam LinkedList<Piranha>
		static void addFood(Food&); //menambah Fish ke dalam LinkedList<Food>
		static void addSnail(Snail&);
		
		//fungsi untuk menghapus sebuah objek dari linked list,
		static void delCoin(Coin&); //menghapus objek Coin dari LinkedList<Coin>
		static void delGuppy(Guppy&); //menghapus objek Fish dari LinkedList<Fish>
		static void delPiranha(Piranha&); //menghapus objek Fish dari LinkedList<Fish>
		static void delFood(Food&); //menghapus objek Food dari LinkedList<Food>
		static void delSnail(Snail&);
		
		
		//getter LinkedList<objek>
		static LinkedList<Coin> getListCoin(); //getter LinkedList<Coin>
		static LinkedList<Guppy> getListGuppy(); //getter LinkedList<Guppy>
		static LinkedList<Piranha> getListPiranha(); //getter LinkedList<Piranha>
		static LinkedList<Food> getListFood(); //getter LinkedList<Food>
		static LinkedList<Snail> getListSnail();
		
		//static Buy Object
		static void buyGuppy();
		static void buyPiranha();
		static void buyEgg();
		static void buyFood(double, double);

		//fungsi untuk mengubah(mengupdate) posisi semua objek dalam LinkedList atau posisi Snail
		static void moveCoin();  //fungsi untuk mengubah(mengupdate) posisi semua objek Coin dalam LinkedList<Coin>
		static void moveGuppy(double time);  //fungsi untuk mengubah(mengupdate) posisi semua objek Fish dalam LinkedList<Guppy>
		static void movePiranha(double time);  //fungsi untuk mengubah(mengupdate) posisi semua objek Fish dalam LinkedList<Piranha>
		static void moveFood();  //fungsi untuk mengubah(mengupdate) posisi semua objek Food dalam LinkedList<Food>
		static void moveSnail();  //fungsi untuk mengubah(mengupdate) posisi objek snail

		//setter dan getter money
		void increaseMoney(double);  //setter money
		void decreaseMoney(double);
		double getMoney(); //getter money

		//friend 
		friend class Fish;
		friend class Guppy;
		friend class Piranha;
		friend class Coin;
		friend class Snail;
		friend class Food;
};

#endif