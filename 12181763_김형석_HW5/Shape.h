#include <iostream>

#include "Circle.h"
#include "Square.h"
#include "Rect.h"

#ifndef SHAPE_H				// 포함 전처리기(preprocessor wrapers)
#define SHAPE_H

class Shape				// 추상 기본 클래스 Shape
{
public:
	virtual double getArea() const = 0;				// 순수 가상함수 getArea, 반환형 double, const 함수
	virtual void print() const = 0;				// 순수 가상함수 print, 반환형 void, const 함수
};

#endif