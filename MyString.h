#pragma once
class MyString
{
	char* m_pStr;	// 
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	const char* GetString() const;
	~MyString();
};
MyString cochet(const char* p, ...);