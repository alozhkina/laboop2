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
		printf("\n��������, ������ ������� ������������� ������. �� ����� ���������� � 1\n");
		Mr = 1;
	}
	else
		Mr = rad;
};

Circle::~Circle() {
	printf("\n�� ���������� � ����������� ������ Circle\n");
};

void Circle::WhereAmI() const {
	printf("\n�� ���������� � ������ Circle\n");
};

void Circle::WhereAmIpupu() const {
	printf("\n�� ���������� � ������ Circle\n");
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
		printf("\n��������, ������ ������� ������������� ������.\n");
	}
	else Mr += x;
};