#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Shape.h"

Shape::Shape() {
	m_color = RED;
};

Shape::Shape(COLOR c) {
	m_color = c;
};

Shape::~Shape() { 
	printf("\n�� ���������� � ����������� ������ Shape\n"); 
};

void Shape::WhereAmI() const {
	printf("\n�� ���������� � ������ Shape\n");
};

void Shape::WhereAmIpupu() const {
	printf("\n�� ���������� � ������ Shape\n");
};

void Shape::inflate(int x) {

};