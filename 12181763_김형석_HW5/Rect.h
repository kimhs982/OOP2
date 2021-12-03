#ifndef RECT_H				// 포함 전처리기(preprocessor wrappers)
#define RECT_H

#include "Shape.h"				// 상속받는 기본(부모) 클래스 Shape가 있는 "Shape.h"를 포함

class Rect : public Shape				// Rect 클래스, Shape 클래스를 public 상속
{
public:
	Rect(double, double);				// 생성자, 매개변수로 double형을 받음
	void setWidth(double);				// width를 설정하는 함수, 매개변수로 double형을 받음, 반환형 double
	void setHeight(double);				// height를 설정하는 함수, 매개변수로 double형을 받음, 반환형 double
	double getWidth() const;				// width를 가져오는 함수, const 함수, 반환형 double
	double getHeight() const;				// height를 가져오는 함수, const 함수, 반환형 double
	void setArea(double, double);				// area를 설정하는 함수, 매개변수로 double형 2개를 받음, 반환형 void
	virtual double getArea() const;				// 가상 함수 명시, area를 가져오는 함수, 반환형 double, const 함수
	virtual void print() const;				// 가상 함수 명시, 출력하는 함수, 반환형 void, const 함수
	~Rect();				// 소멸자
private:
	double width;				// private data member, double형
	double height;				// private data member, double형
	double area;				// private data member, double형
};

#endif