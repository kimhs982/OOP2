#include <iostream>

#include "Circle.h"
#include "Square.h"
#include "Rect.h"

#ifndef SHAPE_H				// ���� ��ó����(preprocessor wrapers)
#define SHAPE_H

class Shape				// �߻� �⺻ Ŭ���� Shape
{
public:
	virtual double getArea() const = 0;				// ���� �����Լ� getArea, ��ȯ�� double, const �Լ�
	virtual void print() const = 0;				// ���� �����Լ� print, ��ȯ�� void, const �Լ�
};

#endif