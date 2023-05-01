#pragma once
class Point {
	int mx;
	int my;
public:
	Point();
	Point(int x, int y);
	Point(int x);
	Point& operator+=(const Point& p1);
	Point& operator+=(int val);

	friend Point& operator-=(Point& pt1, const Point& pt2);//необязательно
	friend Point& operator-=(Point& pt1, int val);

	Point operator+(const Point& p2) const;
	Point operator+(int num) const;
	friend Point operator+(int num, const Point& pt);

	friend Point operator-(const Point& p1, const Point& p2);
	friend Point operator-(const Point& p1, int val);

	Point operator-() const;
	Point operator+() const;

};

Point& operator-=(Point& pt1, const Point& pt2);
Point& operator-=(Point& pt1, int val);

Point operator+(int num, const Point& pt);

Point operator-(const Point& p1, const Point& p2);
Point operator-(const Point& p1, int val);

