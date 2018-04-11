#ifndef MOV_H
#define MOV_H

#include "GlobalLib.h"

class MovingObject{
	private:
		double x;
		double y;
	public:
		// Ctor
		MovingObject(double, double);

		// Getter
		double getX();
		double getY();

		// Setter
		void setX(double);
		void setY(double);
		

		// Method
		// Mengecek apakah sudah di posisi paling atas
		bool isTop();

		// Mengecek apakah sudah di posisi paling bawah
		bool isBottom();

		// Mengecek apakah sudah di posisi paling kiri
		bool isLeftEdge();

		// Mengecek apakah sudah di posisi paling kanan
		bool isRightEdge();

		// Menambah X sebesar parameter 1, dan Y sebesar parameter 2
		void move(double, double);

		// Menambah Y sebesar parameter
		void ascend(double);

		// Menambah Y sebesar parameter
		virtual void descend(double);

		// Menambah X sebesar parameter
		void moveRight(double);

		// Menambah X sebesar parameter
		void moveLeft(double);

		// Bergerak diagonal kiri atas
		void moveTopLeft(double,double);

		// Bergerak diagonal kanan atas
		void moveTopRight(double, double);

		// Bergerak diagonal kiri bawah
		void moveBottomLeft(double, double);

		// Bergerak diagonal kanan bawah

		void moveBottomRight(double, double);

		// Bergerak sesuai sudut dan timeframe
		void moveXby(bool&, double, double, double);
		void moveYby(double, double, double);
};

#endif
