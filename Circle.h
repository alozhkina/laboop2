#pragma once
#include "Shape.h"
#include "Rect.h"
class Circle : public Shape {
	int Mxcent, Mycent;
	double Mr;
public:
	Circle();
	Circle(int xc, int yc, double rad, COLOR c);
	Circle(const Rect& other);
	~Circle();
	void WhereAmI() const;
	void WhereAmIpupu() const;
	void inflate(int);
};
