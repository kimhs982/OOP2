#ifndef COMPLEX_H				// 헤더파일 "Complex.h"가 중복 정의되는 것을 방지
#define COMPLEX_H

class Complex
{
public:				// 접근 지정자 public
	Complex(double = 0, double = 0);				// 기본 생성자(default argument를 가지고 있음), private data member에 저장할 2개의 double형 변수를 입력받음

	void setReal(double);				// private data member인 real의 값을 설정(set함수)
	void setImagin(double);				// private data member인 imagin의 값을 설정(set함수)

	double getReal() const;				// private data member인 real의 값을 가져옴, const함수, 반환형 double(get함수)
	double getImagin() const;				// private data member인 imagin의 값을 가져옴, const함수,  반환형 double(get함수)

	void addComplex(const Complex&);				// 두 개의 Complex 객체의 더하기 연산을 수행할 함수
	void subComplex(const Complex&);				// 두 개의 Complex 객체의 빼기 연산을 수행 할 함수

	void printComplex1(const Complex* const, const Complex&, const Complex* const, const char[]) const;				// (real, imaginary)형식으로 복소수 출력, const함수, 최소 특권의 원리(모든 매개변수에도 const가 지정됨)->함수 내의 모든 값의 변경이 불가능함!
	void printComplex2(const Complex* const, const Complex&, const Complex* const, const char[]) const;				// real + (imaginary)i형식으로 복소수 출력, const함수, 최소 특권의 원리(모든 매개변수에도 const가 지정됨)->함수 내의 모든 값의 변경이 불가능함!
private:				// 접근 지정자 private
	double real;				// 복소수의 실수 값을 저장할 double형 private data memeber
	double imagin;				// 복소수의 허수 값을 저장할 double형 private data member
};

#endif