#define _USE_MATH_DEFINES				// PI(원주율)을 사용하기 위해 사용

#include <cmath>
using std::pow;				// 특정수의 n제곱을 반환하는 함수

#include "Circle.h"				// Circle 클래스가 선언되어 있는 "Circle.h"를 포함

Circle::Circle(double r)
{
	std::cout << "Call Circle class constructor" << std::endl;				// 생성자 문장 출력
	setRadius(r);				// radius설정
	setArea(radius);				// area계산 후 설정
}

void Circle::setRadius(double r)
{
	if (r > 0)				// r이 0보다 큰 경우
		radius = r;				// radius에 r을 대입
	else
	{
		std::cout << "radius should be greater than zero!(radius is set to 1)" << std::endl;				// 에러 문구 출력
		radius = 1.0;				// radius에 1.0을 대입
	}				// r이 0보다 작거나 같은 경우 1로 설정
}

double Circle::getRadius() const
{
	return radius;				// radius 반환
}

void Circle::setArea(double r)
{
	area = pow(radius, 2) * M_PI;				// area 설정, M_PI(=PI), radius^2 * PI
}

double Circle::getArea() const
{
	return area;				// area 반환
}

void Circle::print() const
{
	std::cout << "Circle's radius : " << getRadius() << std::endl;				// radius 출력
}

Circle::~Circle()
{
	std::cout << "Call Circle class destructor" << std::endl;				// 소멸자 문장 출력
}