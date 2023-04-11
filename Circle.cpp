#include "Circle.h"
#include <iostream>

Circle::Circle() {
	Mxcent = 0;
	Mycent = 0;
	Mr = 1;

};

Circle::Circle(int xc, int yc, double rad, COLOR c) : Shape(c) {
	Mxcent = xc;
	Mycent = yc;
	if (rad < 0) {
		printf("\nПростите, нельзя сделать отрицательный радиус. Он будет установлен в 1\n");
		Mr = 1;
	}
	else
		Mr = rad;
};

Circle::~Circle() {
	printf("\nВы находитесь в деструкторе класса Circle\n");
};

void Circle::WhereAmI() const {
	printf("\nВы находитесь в классе Circle\n");
};

void Circle::WhereAmIpupu() const {
	printf("\nВы находитесь в классе Circle\n");
};

Circle::Circle(const Rect &r) : Shape(r) {
	int left, right, top, botton;
	r.GetAll(left, right, top, botton);
	Mxcent = right - left;
	Mycent = top - botton;
	Mr = (top - botton) / 2.0;
};

void Circle::inflate(int x) {
	if ((Mr + x) < 0) {
		printf("\nПростите, нельзя сделать отрицательный радиус.\n");
	}
	else Mr += x;
};