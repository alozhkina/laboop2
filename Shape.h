#pragma once
enum COLOR { RED, GREEN, YELLOW, BLUE, BLACK, PINK };

class Shape {
	COLOR m_color;
public:
	Shape();
	Shape(COLOR c);
    virtual ~Shape();
	void WhereAmI() const;
	virtual void WhereAmIpupu() const;
	virtual void inflate(int);

};