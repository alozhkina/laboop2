#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MyString.h"
#include <iostream>

//MyString Constructor:: по умолчанию
MyString::MyString() {
	m_pStr = nullptr;
};
//MyString Constructor
MyString::MyString(const char* str)
{
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else m_pStr = nullptr;

};
//MyString Constructor copy
MyString::MyString(const MyString& str) {
	if (str.m_pStr) {
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy(m_pStr, str.m_pStr);
	}
	else m_pStr = nullptr;

};
//MyString Destructor
MyString::~MyString()
{
	delete[] m_pStr;

};

const char* MyString::GetString() const {
	if (m_pStr)
		return m_pStr;
	else
		return "GetString Error";
};

MyString cochet(const char* p, ...) {//указатель на первый элемент массива
	int count = 0;
	const char** str = &p;// указатель на первый элемент элемента массива
	while (*str) {//узнали размер суммарный у массива
		count += strlen(*str);
		str++;
	};
	if (count == 0) return MyString();
    char* buf = new char[count + 1];
	str = &p;
	buf[0] = 0;
	while (*str) {
		strcpy(buf+strlen(buf), *str);
		str++;
	};
	MyString ret(buf);
	delete[] buf;
	//std::cout << ret.GetString() << std::endl;
	return ret;
}