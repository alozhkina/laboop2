#include"Point.h"

Point::Point() {
	mx = my = 0;
};

Point::Point(int x, int y) {
	mx = x;
	my = y;
};

Point::Point(int x) {
	mx = x;
	my = 0;
};
Point& Point:: operator+=(const Point& p1) {
	mx = mx + p1.mx;
	my = my + p1.my;
	return *this;
};

Point& Point::operator+=(int val) {
	mx = mx + val;
	my = my + val;
	return *this;
};

Point& operator-=(Point& pt1, int val) {
	pt1 = pt1 - val;
	return pt1;
};

Point& operator-=(Point& pt1, const Point& pt2) {
	pt1 = pt1 - pt2;
	return pt1;
};

Point Point::operator+(const Point& p1) const {

	Point tmp((mx + p1.mx), (my + p1.my));
	return tmp;
};
Point Point::operator+(int num) const {
	Point tmp((mx + num), (my + num));
	return tmp;
};
Point operator+(int num, const Point& pt) {
	Point tmp((pt.mx + num), (pt.my + num));
	return tmp;
};

Point operator-(const Point& p1, const Point& p2) {
	Point tmp((p1.mx - p2.mx), (p1.my - p2.my));
	return tmp;
};
Point operator-(const Point& p1, int val) {
	Point tmp((p1.mx - val), (p1.my - val));
	return tmp;
};

Point Point::operator-() const {
	return Point(-this->mx, -this->my);
};
Point Point::operator+() const {
	return Point(this->mx, this->my);
};
