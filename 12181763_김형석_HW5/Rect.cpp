#include "Rect.h"				// Rect Ŭ������ ����Ǿ� �ִ� "Rect.h"�� ����

Rect::Rect(double w, double h)
{
	std::cout << "Call Rect class constructor" << std::endl;				// ������ ���� ���
	setWidth(w);				// width ����
	setHeight(h);				// height ����
	setArea(width, height);				// area ��� �� ����
}

void Rect::setWidth(double w)
{
	if (w > 0)				// w�� 0���� ū ���
		width = w;				// width�� w�� ����
	else
	{
		std::cout << "width should be greater than zero!(width is set to 1)" << std::endl;				// ���� ���� ���
		width = 1.0;				// width�� 1.0�� ����
	}				// w�� 0���� �۰ų� ���� ��� 1�� ����
}

void Rect::setHeight(double h)
{
	if (h > 0)				// h�� 0���� ū ���
		height = h;				// height�� h�� ����
	else
	{
		std::cout << "height should be greater than zero!(height is set to 1)" << std::endl;				// ���� ���� ���
		height = 1.0;				// height�� 1.0�� ����
	}
}

double Rect::getWidth() const
{
	return width;				// width ��ȯ
}

double Rect::getHeight() const
{
	return height;				// height ��ȯ
}

void Rect::setArea(double w, double h)
{
	area = w * h;				// area ����, w*h
}

double Rect::getArea() const
{
	return area;				// area ��ȯ
}

void Rect::print() const
{
	std::cout << "Rect's width : " << getWidth() << ", height : " << getHeight() << std::endl;				// width�� height�� ���
}

Rect::~Rect()
{
	std::cout << "Call Rect class destructor" << std::endl;				// �Ҹ��� ���� ���
}