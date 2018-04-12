#include "MovingObject.h"
#include <math.h>

MovingObject::MovingObject(double a, double b){
	x = a;
	y = b;
}

// Getter
double MovingObject::getX(){
	return x;
}
double MovingObject::getY(){
	return y;
}

// Setter
void MovingObject::setX(double a){
	x = a;
}
void MovingObject::setY(double a){
	y = a;
}

// Method
// Mengecek apakah sudah di posisi paling atas
bool MovingObject::isTop(){
	return y == 0;
}

// Mengecek apakah sudah di posisi paling bawah
bool MovingObject::isBottom(){
	// Masih bingung
	return (y >= SCREEN_HEIGHT-OFFSET_BOTTOM);
}

// Mengecek apakah sudah di posisi paling kiri
bool MovingObject::isLeftEdge(){
	return (x <= 0);
}

// Mengecek apakah sudah di posisi paling kanan
bool MovingObject::isRightEdge(){
	return (x >= SCREEN_WIDTH);
}

// Menambah X sebesar parameter 1, dan Y sebesar parameter 2
void MovingObject::move(double dx, double dy){
	x += dx;
	y += dy;
}

// Menambah Y sebesar dy
void MovingObject::ascend(double dy){
	y -= dy;
}

// Menambah Y sebesar dy
void MovingObject::descend(double dy){
	y += dy;
}

// Menambah X sebesar 1
void MovingObject::moveRight(double dx){
	x += dx;
}

// Menambah X sebesar -1
void MovingObject::moveLeft(double dx){
	x -= dx;
}

// Bergerak diagonal kiri atas
void MovingObject::moveTopLeft(double dx,double dy){
	ascend(dy);
	moveLeft(dx);
}

// Bergerak diagonal kanan atas
void MovingObject::moveTopRight(double dx, double dy){
	ascend(dy);
	moveRight(dx);
}

// Bergerak diagonal kiri bawah
void MovingObject::moveBottomLeft(double dx, double dy){
	descend(dy);
	moveLeft(dx);
}

// Bergerak diagonal kanan bawah
void MovingObject::moveBottomRight(double dx, double dy){
	descend(dy);
	moveRight(dx);
}

// Bergerak sesuai sudut dan timeframe
void MovingObject::moveXby(bool& dir, double v, double a, double t){
	double dx = cos(a)*v*t;
	double move_outer = x + dx;

	if(move_outer < x){ //hadap kiri
		dir = false;
	}
	else {
		dir = true;
	}

	if(isRightEdge() == true && move_outer > SCREEN_WIDTH-OFFSET_RIGHT){

	}
	else if(isLeftEdge() == true && move_outer < OFFSET_LEFT){

	}
	else{
		x += dx;
	}

}
void MovingObject::moveYby(double v, double a, double t){
	double dy = sin(a)*v*t;	
	double move_outer = y+dy;

	if(isTop() == true && move_outer < 0){

	}
	else if(isBottom() == true && move_outer > SCREEN_HEIGHT-OFFSET_BOTTOM){

	}
	else {
		y+=dy;
	}
	
}
