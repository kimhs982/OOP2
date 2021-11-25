#pragma once
#include <iostream>
using std::ostream;				// ostream 클래스 사용
using std::istream;				// istream 클래스 사용

class Vector				// Vector 클래스
{
public:
	Vector(int = 0);				// 생성자, int형 매개변수 1개, default값
	~Vector();				// 소멸자
	Vector& operator=(const int*);				// 대입연산자(=) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
	const int* operator+(const Vector&);				// 멤버함수, 더하기연산자(+) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
	const int* operator-(const Vector&);				// 멤버함수, 빼기연산자(-) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
	const int* operator*(const Vector&);				// 멤버함수, 곱하기연산자(*) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
	bool operator==(const Vector&);				// 멤버함수, 연산자(==) 오버로딩, bool형 매개변수 1개, 반환형 bool
	bool operator!=(const Vector&);				// 멤버함수, 연산자(!=) 오버로딩, bool형 매개변수 1개, 반환형 bool
	friend ostream& operator<<(ostream&, const Vector&);				// friend 함수, 전역함수, stream insertion 연산자(<<) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
	friend istream& operator>>(istream&, const Vector&);				// friend 함수, 전역함수, stream extraction 연산자(>>) 오버로딩, const int 포인터형 매개변수 1개, 반환형 Vector reference
private:
	static int dim;				// private data member, static(정적) int형 변수, 벡터의 차원을 저장
	int* vec;				// private data member, int 포인터변수, Vector 객체의 각 차원의 원소값 저장
	int* temp;				// private data member, int 포인터변수, 임시로 원소값 저장
};