#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"				// Complex 클래스 선언이 있는 헤더파일 "Complex.h"를 포함

// 이항 범위 지정 연산자(binary scope resolution operator) :: 을 사용하여 Complex 클래스의 멤버 함수임을 알려줌

Complex::Complex(double realVal, double imaginVal)				// Complex 생성자, 2개의 double형 변수를 매개변수로 받음
{
	setReal(realVal);				// setReal함수를 통해 private data member인 real의 값을 설정
	setImagin(imaginVal);				// setImagin함수를 통해 private data member인 imagin의 값을 설정
}

void Complex::setReal(double inReal)				// private data member인 real의 값을 설정(set함수)
{
	real = inReal;
}

void Complex::setImagin(double inImagin)				// private data member인 imagin의 값을 설정(set함수)
{
	imagin = inImagin;
}

double Complex::getReal() const				// private data member인 real의 값을 가져옴, const함수, 반환형 double(get함수)
{
	return real;
}

double Complex::getImagin() const				// private data member인 imagin의 값을 가져옴, const함수,  반환형 double(get함수)
{
	return imagin;
}

void Complex::addComplex(const Complex& com)				// 두 개의 Complex 객체의 더하기 연산을 수행할 함수
{
	Complex* temp = new Complex;				// 더하기 연산 값을 저장할 임시 Complex 객체를 new로 heap 공간에 생성, temp포인터로 주소를 받음

	temp->setReal(this->getReal() + com.getReal());				// 실수(real number)부분 더하기 연산, this포인터는 멤버 함수를 실행한 객체 자신을 가리킴, set/get함수 사용
	temp->setImagin(this->getImagin() + com.getImagin());				// 허수(imaginary number)부분 더하기 연산, this포인터는 멤버 함수를 실행한 객체 자신을 가리킴, set/get함수 사용

	printComplex1(this, com, temp, " + ");				// (real, imaginary)형식으로 복소수 출력하는 printComplex1함수 호출
	printComplex2(this, com, temp, " + ");				// real + (imaginary)i형식으로 복소수 출력하는 printComplex2함수 호출
}

void Complex::subComplex(const Complex& com)				// 두 개의 Complex 객체의 빼기 연산을 수행 할 함수
{
	Complex* temp = new Complex;

	temp->setReal(this->getReal() - com.getReal());				// 실수(real number)부분 빼기 연산, this포인터는 멤버 함수를 실행한 객체 자신을 가리킴, set/get함수 사용
	temp->setImagin(this->getImagin() - com.getImagin());				// 허수(imaginary number)부분 빼기 연산, this포인터는 멤버 함수를 실행한 객체 자신을 가리킴, set/get함수 사용

	printComplex1(this, com, temp, " - ");				// (real, imaginary)형식으로 복소수 출력하는 printComplex1함수 호출
	printComplex2(this, com, temp, " - ");				// real + (imaginary)i형식으로 복소수 출력하는 printComplex2함수 호출
}

void Complex::printComplex1(const Complex* const com1, const Complex& com2, const Complex* const temp, const char oper[]) const				// (real, imaginary)형식으로 복소수 출력, const함수, 최소 특권의 원리(모든 매개변수에도 const가 지정됨)->함수 내의 모든 값의 변경이 불가능함!
{
	cout << "(" << com1->getReal() << ", " << com1->getImagin() << ")" << oper << "("				// 문자열로 연산자가 포함된 " + "또는 " - "를 받아옴
		<< com2.getReal() << ", " << com2.getImagin() << ") = (" << temp->getReal()
		<< ", " << temp->getImagin() << ")" << endl;
}

void Complex::printComplex2(const Complex* const com1, const Complex& com2, const Complex* const temp, const char oper[]) const				// real + (imaginary)i형식으로 복소수 출력, const함수, 최소 특권의 원리(모든 매개변수에도 const가 지정됨)->함수 내의 모든 값의 변경이 불가능함!
{
	cout << com1->getReal() << (com1->getImagin() >= 0 ? " + " : " ") << com1->getImagin() << "i";
	
	if (oper == " + ")
	{
		cout << (com2.getReal() >= 0 ? oper : " ") << com2.getReal() << (com2.getImagin() >= 0 ? " + " : " ") << com2.getImagin()
			<< "i = " << temp->getReal() << (temp->getImagin() >= 0 ? " + " : " ") << temp->getImagin() << "i" << endl << endl;
	}
	else
	{// 빼기 연산의 경우 두 번째 복소수의 부호에 따라서 출력 형태가 바껴야 하므로 if~else문으로 출력 형태 구분
		cout << (com2.getReal() <= 0 ? " + " : " ") << -(com2.getReal()) << (com2.getImagin() <= 0 ? " + " : " ") << -(com2.getImagin())
			<< "i = " << temp->getReal() << (temp->getImagin() >= 0 ? " + " : " ") << temp->getImagin() << "i" << endl << endl;
	}

	delete temp;				// addComplex와 subComplex에서 new를 통해 생성된 객체의 메모리 공간을 해제함
}