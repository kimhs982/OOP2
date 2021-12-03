#include "Rect.h"				// Rect 클래스가 선언되어 있는 "Rect.h"를 포함

Rect::Rect(double w, double h)
{
	std::cout << "Call Rect class constructor" << std::endl;				// 생성자 문장 출력
	setWidth(w);				// width 설정
	setHeight(h);				// height 설정
	setArea(width, height);				// area 계산 후 설정
}

void Rect::setWidth(double w)
{
	if (w > 0)				// w가 0보다 큰 경우
		width = w;				// width에 w를 대입
	else
	{
		std::cout << "width should be greater than zero!(width is set to 1)" << std::endl;				// 에러 문구 출력
		width = 1.0;				// width에 1.0을 대입
	}				// w가 0보다 작거나 같은 경우 1로 설정
}

void Rect::setHeight(double h)
{
	if (h > 0)				// h가 0보다 큰 경우
		height = h;				// height에 h를 대입
	else
	{
		std::cout << "height should be greater than zero!(height is set to 1)" << std::endl;				// 에러 문구 출력
		height = 1.0;				// height에 1.0을 대입
	}
}

double Rect::getWidth() const
{
	return width;				// width 반환
}

double Rect::getHeight() const
{
	return height;				// height 반환
}

void Rect::setArea(double w, double h)
{
	area = w * h;				// area 설정, w*h
}

double Rect::getArea() const
{
	return area;				// area 반환
}

void Rect::print() const
{
	std::cout << "Rect's width : " << getWidth() << ", height : " << getHeight() << std::endl;				// width와 height를 출력
}

Rect::~Rect()
{
	std::cout << "Call Rect class destructor" << std::endl;				// 소멸자 문장 출력
}