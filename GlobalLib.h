#ifndef GLOBALLIB_H
#define GLOBALLIB_H
#include <bits/stdc++.h>
using namespace std;

/* TYPEDEF*/
typedef pair<int,int> Position;
typedef unsigned long long ULL;

// Global Var
extern ULL Money;
extern int Egg;
/* CONSTANTS*/

//SPEED
const double COIN_SPEED = 0.3;
const double FOOD_SPEED = 0.5;
const double SNAIL_SPEED = 0.2;
const double FISH_SPEED= 100;

//OFFSET
const int UP_OFFSET = 20;
const int BOTTOM_OFFSET = 80;
const int LEFT_OFFSET = 20;
const int RIGHT_OFFSET = 20;

//RADIUS
const double INPUT_RADIUS = 15.0;
const double RADIUS = 10.0;
const double TAKE_RADIUS = 10.0;

//HARGA
const int HARGA_IKAN = 20;
const int HARGA_PIRANHA = 50;
const int HARGA_TELUR = 1000;
const int HARGA_MAKANAN = 2;

//CONST
const double EPSILON = 1e-6;
const char* const FONT_NAME = "OpenSans-Regular.ttf";

//RESOLUTION
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;


#endif
