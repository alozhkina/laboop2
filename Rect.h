#pragma once
#include "Shape.h"
class Rect : public Shape {
	int mtop, mbotton, mleft, mright;
public:
	Rect();
	Rect(int top, int botton, int left, int right, COLOR c);
	Rect(const Rect& other);
	void Normalsize();
	~Rect();
	void WhereAmI() const;
	void WhereAmIpupu() const;
	void GetAll(int& left, int& right, int& top, int& botton) const;
	void inflate(int);
};
