#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class myString
{
	friend ostream& operator<<(ostream&, const myString&);				// 연산자(<<) 오버로딩, 전역함수만 가능
	friend istream& operator>>(istream&, myString&);				// 연산자(>>) 오버로딩, 전역함수만 가능
private:
	char* str;				// 문자열을 저장할 char형 포인터, private data member
	int length;				// '\0'을 포함한 문자열의 길이를 저장할 int형 변수, private data member
public:
	myString(int);				// 생성자, 매개변수 int형 변수
	myString(const myString&);				// 복사 생성자, 매개변수 myString 객체의 const reference형
	~myString();				// 소멸자
	// set function
	void setString(int, char*);				// 이미 생성된 myString 객체의 string을 수정하여 대입, 매개변수 int형 변수 & char형 포인터(문자열)
	// concatenate
	myString operator+(myString&);				// 연산자(+) 오버로딩, 멤버함수
	// copy
	void operator=(myString&);				// 연산자(=) 오버로딩, 멤버함수
	// comparison
	bool operator==(myString&);				// 연산자(==) 오버로딩, 멤버함수
	bool operator!=(myString&);				// 연산자(!=) 오버로딩, 멤버함수
	// index-based approaching
	char operator[](int);					// 연산자([]) 오버로딩, 멤버함수
	void printString();				// myString 객체의 private data member length와 str을 출력하는 함수
};