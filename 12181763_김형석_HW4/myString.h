#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class myString
{
	friend ostream& operator<<(ostream&, const myString&);				// ������(<<) �����ε�, �����Լ��� ����
	friend istream& operator>>(istream&, myString&);				// ������(>>) �����ε�, �����Լ��� ����
private:
	char* str;				// ���ڿ��� ������ char�� ������, private data member
	int length;				// '\0'�� ������ ���ڿ��� ���̸� ������ int�� ����, private data member
public:
	myString(int);				// ������, �Ű����� int�� ����
	myString(const myString&);				// ���� ������, �Ű����� myString ��ü�� const reference��
	~myString();				// �Ҹ���
	// set function
	void setString(int, char*);				// �̹� ������ myString ��ü�� string�� �����Ͽ� ����, �Ű����� int�� ���� & char�� ������(���ڿ�)
	// concatenate
	myString operator+(myString&);				// ������(+) �����ε�, ����Լ�
	// copy
	void operator=(myString&);				// ������(=) �����ε�, ����Լ�
	// comparison
	bool operator==(myString&);				// ������(==) �����ε�, ����Լ�
	bool operator!=(myString&);				// ������(!=) �����ε�, ����Լ�
	// index-based approaching
	char operator[](int);					// ������([]) �����ε�, ����Լ�
	void printString();				// myString ��ü�� private data member length�� str�� ����ϴ� �Լ�
};