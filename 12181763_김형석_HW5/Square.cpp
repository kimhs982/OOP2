#include <cmath>
using std::pow;				// 특정수의 n제곱을 반환하는 함수

#include "Square.h"				// Square 클래스가 선언되어 있는 "Square.h"를 포함

Square::Square(double s)
{
	std::cout << "Call Square class constructor" << std::endl;				// 생성자 문장 출력
	setSide(s);				// side 설정
	setArea(side);				// area 계산 후 설정
}

void Square::setSide(double s)
{
	if (s > 0)				// s가 0보다 큰 경우
		side = s;				// side에 s를 대입
	else
	{
		std::cout << "side should be greater than zero!(side is set to 1)" << std::endl;				// 에러 문구 출력
		side = 1.0;				// side에 1.0을 대입
	}				// s가 0보다 작거나 같은 경우 1로 설정
}

double Square::getSide() const
{
	return side;				// side 반환
}

void Square::setArea(double s)
{
	area = pow(side, 2);				// area 설정, side^2
}

double Square::getArea() const
{
	return area;				// side 반환
}

void Square::print() const
{
	std::cout << "Square's side : " << getSide() << std::endl;				// side 출력
}

Square::~Square()
{
	std::cout << "Call Square class destructor" << std::endl;				// 소멸자 문장 출력
}