#pragma once
#include <iostream>

using namespace std;
class MyString
{
	char* m_pStr;	// 
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	const char* GetString() const;
	MyString& operator =(const MyString& mon);// вернется объект класса MyString, за счет & не придется коппировать, эффективная запись
	MyString& operator = (const char* str);
	MyString& operator =(MyString&& mon) noexcept;//надо сделать копию объекта, но копирование данных нежелательно - вместо копирования данных они просто перемещаются из одной копии объекта в другую
	~MyString();

	friend ostream& operator<<(ostream& out, const MyString& str);

	MyString operator+(const MyString& mon) const;
	MyString operator+=(const MyString& mon);

	bool operator ==(const char* s) const;
	bool operator ==(MyString s) const;

};
MyString cochet(const char* p, ...);
ostream& operator<<(ostream& out, const MyString& str);