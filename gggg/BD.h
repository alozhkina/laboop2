#pragma once
#include "MyString.h"
#include <iostream>
//ñïèñêè èíèöèàëèçàöèè, îäíîçíà÷íîå äà äëÿ êîíñòàíò è ññûëîê
enum Sex { MALE = 1, FEMALE, IDK };
MyString pereg(Sex sex);
const int buf = 4;

class INF {
public:
	Sex sex;
	int age;
	MyString job;
	int salary;
	INF() : sex(Sex::IDK), age(0), job("undef"), salary(0) {};
	INF(Sex s, int a, MyString j, int sal) : sex(s), age(a), job(j), salary(sal) {};

	friend std::ostream& operator<<(std::ostream& out, const INF& form);

};

class Pair {
	MyString name;
	INF form;
public:
	Pair() : name("NoName") {}
	Pair(const MyString& n, const INF& f) : name(n), form(f) {}
	bool operator==(const char* k) const;
	MyString Key() { return name; };
	INF Gform() { return form; };
	friend class BD;
};

class BD {
	Pair** pp;//òàì âûõîäèò ÷òåíèå íåäîïóñòèìûõ çíà÷åíèé, îñòàâëÿþ **
	int cap;
	int kolvo;

	void Resize(int keyNum, bool flag);
public:
	BD() { cap = kolvo = 0; pp = nullptr; };
	BD(const BD& other);

	BD(BD&& bd);

	INF& operator [] (const MyString& key);
	friend std::ostream& operator<<(std::ostream& out, const BD& bd);

	void delet(const MyString& n);
	void Job() const;
	void Salary() const;
	void Age() const;
	void Sex() const;
	void Names() const;
	BD& operator=(const BD& bd);
	BD& operator = (BD&& other) noexcept;

	~BD() {
		for (int i = 0; i < kolvo; i++) {
			delete pp[i];
		}
		delete[] pp;
	}

};
