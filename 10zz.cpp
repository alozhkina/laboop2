#include "10zz.h"
#include <iostream>

void Bin::Show() const {
	printf("В двоичном виде\n");
	printf("%d%d%d%d%d%d%d%d\n", mb7, mb6, mb5, mb4, mb3, mb2, mb1, mb0);
};

void Hex::Show() const {
	printf("В шестнадцатеричном виде\n");
	printf("%x%x\n", mx1, mx0);
};

void Oct::Show() const {
	printf("В восьмеричном виде\n");
	printf("%d%d%d\n", mo2, mo1, mo0);
};
void Dec::Show() const {
	printf("В десятичном виде\n");
	printf("%d\n", md0);
};
void Hex::ShowSmb(int val) const {
	switch (val) {
	case 0:
		printf("\n%x\n", mx1);
		break;
	case 1:
		printf("\n%x\n", mx0);
		break;
	default:
		std::cout << "Необходимо ввести 0 или 1" << std::endl;
		break;
	}
};
void Bin::ShowSmb(int val) const {
	switch (val) {
	case 0:
		printf("\n%d\n", mb7);
		break;
	case 1:
		printf("\n%d\n", mb6);
		break;
	case 2:
		printf("\n%d\n", mb5);
		break;
	case 3:
		printf("\n%d\n", mb4);
		break;
	case 4:
		printf("\n%d\n", mb3);
		break;
	case 5:
		printf("\n%d\n", mb2);
		break;
	case 6:
		printf("\n%d\n", mb1);
		break;
	case 7:
		printf("\n%d\n", mb0);
		break;
	default:
		std::cout << "Необходимо ввести 0, 1, 2, 3, 4, 5, 6, 7" << std::endl;
		break;
	}
};

void Oct::ShowSmb(int val) const {
	switch (val) {
	case 0:
		printf("\n%d\n", mo2);
		break;
	case 1:
		printf("\n%d\n", mo1);
		break;
	case 2:
		printf("\n%d\n", mo0);
		break;
	default:
		std::cout << "Необходимо ввести число 0, 1, 2" << std::endl;
		break;
	}
};

void Hex::Edit(int val, int z) {
	if ((val < 0) || (val > 1) || (z < 0) || (z > 15)) { printf("Неправильные значения\n"); }
	else {
		switch (val) {
		case 0:
			mx1 = z;
			break;
		case 1:
			mx0 = z;
			break;
		}
	}
};

void Bin::Edit(int val, int z) {
	if ((val < 0) || (val > 7) || (z < 0) || (z > 1)) { printf("Неправильные значения\n"); }
	else {
		switch (val) {
		case 0:
			mb7 = z;
			break;
		case 1:
			mb6 = z;
			break;
		case 2:
			mb5 = z;
			break;
		case 3:
			mb4 = z;
			break;
		case 4:
			mb3 = z;
			break;
		case 5:
			mb2 = z;
			break;
		case 6:
			mb1 = z;
			break;
		case 7:
			mb0 = z;
			break;
		};
	};
};

void Oct::Edit(int val, int z) {
	if ((val < 0) || (val > 2) || (z < 0) || (z > 7)) { printf("Неправильные значения\n"); }
	else {
		switch (val) {
		case 0:
			mo2 = z;
			break;
		case 1:
			mo1 = z;
			break;
		case 2:
			mo0 = z;
			break;
		}
	}
};


Byte::Byte(unsigned char val) {
	m_val = val;
}
