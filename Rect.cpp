#include "Rect.h"
#include <iostream>

Rect::Rect(): Shape(BLACK) {
	mtop = mbotton = mleft = mright = 0;
};

Rect::Rect(int top, int botton, int left, int right, COLOR c) : Shape(c) {
	mtop = top;
	mbotton = botton;
	mleft = left;
	mright = right;

	Normalsize();
};

Rect::Rect(const Rect& r)
{
	mbotton = r.mbotton;
	mtop = r.mtop;
	mleft = r.mleft;
	mright = r.mright;
	Normalsize();

	printf("\nRect::constructor copy\n");
}

void Rect::Normalsize()
{
	if (mtop < mbotton)
	{
		int tmp = mbotton;
		mbotton = mtop;
		mtop = tmp;
	}

	if (mleft > mright)
	{
		int tmp = mleft;
		mleft = mright;
		mright = tmp;
	}

};

Rect::~Rect() {
	printf("\nВы находитесь в деструкторе класса Rect\n");

};

void Rect::WhereAmI() const {
	printf("\nВы находитесь в классе Rect\n");
};

void Rect::WhereAmIpupu() const {
	printf("\nВы находитесь в классе Rect\n");
};

void Rect::GetAll(int& left, int& right, int& top, int& botton) const {
	if ((mleft > mright) || (mbotton > mtop)) {
		printf("\nRect Constructor:неправильно введены параметры\n");
	} //здесь const поэтому вместо normalsize
	left = mleft;
	right = mright;
	top = mtop;
	botton = mbotton;
};

void Rect::inflate(int x) {
	mtop += x;
	mbotton -= x;
	mleft -= x;
	mright += x;

	Normalsize();
};