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
	printf("\nВы находитесь в деструкторе класса Shape\n"); 
};

void Shape::WhereAmI() const {
	printf("\nВы находитесь в классе Shape\n");
};

void Shape::WhereAmIpupu() const {
	printf("\nВы находитесь в классе Shape\n");
};

void Shape::inflate(int x) {

};