#define _USE_MATH_DEFINES				// PI(������)�� ����ϱ� ���� ���

#include <cmath>
using std::pow;				// Ư������ n������ ��ȯ�ϴ� �Լ�

#include "Circle.h"				// Circle Ŭ������ ����Ǿ� �ִ� "Circle.h"�� ����

Circle::Circle(double r)
{
	std::cout << "Call Circle class constructor" << std::endl;				// ������ ���� ���
	setRadius(r);				// radius����
	setArea(radius);				// area��� �� ����
}

void Circle::setRadius(double r)
{
	if (r > 0)				// r�� 0���� ū ���
		radius = r;				// radius�� r�� ����
	else
	{
		std::cout << "radius should be greater than zero!(radius is set to 1)" << std::endl;				// ���� ���� ���
		radius = 1.0;				// radius�� 1.0�� ����
	}				// r�� 0���� �۰ų� ���� ��� 1�� ����
}

double Circle::getRadius() const
{
	return radius;				// radius ��ȯ
}

void Circle::setArea(double r)
{
	area = pow(radius, 2) * M_PI;				// area ����, M_PI(=PI), radius^2 * PI
}

double Circle::getArea() const
{
	return area;				// area ��ȯ
}

void Circle::print() const
{
	std::cout << "Circle's radius : " << getRadius() << std::endl;				// radius ���
}

Circle::~Circle()
{
	std::cout << "Call Circle class destructor" << std::endl;				// �Ҹ��� ���� ���
}