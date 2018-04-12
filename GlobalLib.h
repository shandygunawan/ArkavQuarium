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
const double SPEED_COIN = 0.3;
const double SPEED_FOOD = 0.5;
const double SPEED_SNAIL = 0.2;
const double SPEED_FISH = 100;

//OFFSET
const int OFFSET_TOP = 20;
const int OFFSET_BOTTOM = 80;
const int OFFSET_LEFT = 20;
const int OFFSET_RIGHT = 20;

//RADIUS
const double RADIUS_INPUT = 15.0;
const double RADIUS_EAT = 10.0;
const double RADIUS_TAKE = 10.0;
const double RADIUS_MOVE = 5.0;

//HARGA
const int PRICE_GUPPY = 20;
const int PRICE_PIRANHA = 50;
const int PRICE_EGG = 500;
const int PRICE_FOOD = 2;

//TIME
const int TIME_MAX_FULL = 2000;
const int TIME_MAX_HUNGRY = 3000;

//CONST
const double EPSILON = 1e-6;
const char* const FONT_NAME = "OpenSans-Regular.ttf";

//RESOLUTION
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;


#endif
