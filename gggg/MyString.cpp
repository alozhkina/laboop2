#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MyString.h"
#include "BD.h"
#include <iostream>

//MyString Constructor:: ïî óìîë÷àíèþ
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

MyString cochet(const char* p, ...) {//óêàçàòåëü íà ïåðâûé ýëåìåíò ìàññèâà
	int count = 0;
	const char** str = &p;// óêàçàòåëü íà ïåðâûé ýëåìåíò ýëåìåíòà ìàññèâà
	while (*str) {//óçíàëè ðàçìåð ñóììàðíûé ó ìàññèâà
		count += strlen(*str);
		str++;
	};
	if (count == 0) return MyString();
	char* buf = new char[count + 1];
	str = &p;
	buf[0] = 0;
	while (*str) {
		strcpy(buf + strlen(buf), *str);
		str++;
	};
	MyString ret(buf);
	delete[] buf;
	//std::cout << ret.GetString() << std::endl;
	return ret;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ïåðåãðóçêà =
MyString& MyString::operator =(const MyString& mon) {
	if (&mon == this) return *this;
	if (m_pStr) delete[] m_pStr;
	if (mon.m_pStr) {
		m_pStr = new char[strlen(mon.m_pStr) + 1];
		strcpy(m_pStr, mon.m_pStr);
	}
	else m_pStr = nullptr;
	return *this;
};

MyString& MyString::operator = (const char* str) {
	if (str != nullptr) {
		delete[] m_pStr;
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	return *this;
}

MyString& MyString::operator= (MyString&& mon) noexcept
{
	if (this != &mon)
	{
		delete[] m_pStr;
		m_pStr = mon.m_pStr;
		mon.m_pStr = 0;
		return *this;
	}
	return *this;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& out, const MyString& str) {
	out << str.m_pStr;
	return out;
};


/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


MyString MyString::operator +(const MyString& mon) const {
	return cochet(m_pStr, mon.m_pStr, 0);
};

MyString MyString::operator +=(const MyString& mon) {
	*this = *this + mon;
	return *this;
};

bool MyString::operator ==(MyString s) const {
	return (strcmp(s.GetString(), m_pStr) == 0);
};

bool MyString::operator ==(const char* s) const {
	return (strcmp(s, m_pStr) == 0);
};

MyString pereg(Sex sex) {
	switch (sex)
	{
	case Sex::MALE:
		return "Male";
		break;
	case Sex::FEMALE:
		return "Female";
		break;
	case Sex::IDK:
		return "None";
		break;
	}
};
