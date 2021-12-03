#include <cmath>
using std::pow;				// Ư������ n������ ��ȯ�ϴ� �Լ�

#include "Square.h"				// Square Ŭ������ ����Ǿ� �ִ� "Square.h"�� ����

Square::Square(double s)
{
	std::cout << "Call Square class constructor" << std::endl;				// ������ ���� ���
	setSide(s);				// side ����
	setArea(side);				// area ��� �� ����
}

void Square::setSide(double s)
{
	if (s > 0)				// s�� 0���� ū ���
		side = s;				// side�� s�� ����
	else
	{
		std::cout << "side should be greater than zero!(side is set to 1)" << std::endl;				// ���� ���� ���
		side = 1.0;				// side�� 1.0�� ����
	}				// s�� 0���� �۰ų� ���� ��� 1�� ����
}

double Square::getSide() const
{
	return side;				// side ��ȯ
}

void Square::setArea(double s)
{
	area = pow(side, 2);				// area ����, side^2
}

double Square::getArea() const
{
	return area;				// side ��ȯ
}

void Square::print() const
{
	std::cout << "Square's side : " << getSide() << std::endl;				// side ���
}

Square::~Square()
{
	std::cout << "Call Square class destructor" << std::endl;				// �Ҹ��� ���� ���
}