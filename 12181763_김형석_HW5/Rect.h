#ifndef RECT_H				// ���� ��ó����(preprocessor wrappers)
#define RECT_H

#include "Shape.h"				// ��ӹ޴� �⺻(�θ�) Ŭ���� Shape�� �ִ� "Shape.h"�� ����

class Rect : public Shape				// Rect Ŭ����, Shape Ŭ������ public ���
{
public:
	Rect(double, double);				// ������, �Ű������� double���� ����
	void setWidth(double);				// width�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� double
	void setHeight(double);				// height�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� double
	double getWidth() const;				// width�� �������� �Լ�, const �Լ�, ��ȯ�� double
	double getHeight() const;				// height�� �������� �Լ�, const �Լ�, ��ȯ�� double
	void setArea(double, double);				// area�� �����ϴ� �Լ�, �Ű������� double�� 2���� ����, ��ȯ�� void
	virtual double getArea() const;				// ���� �Լ� ���, area�� �������� �Լ�, ��ȯ�� double, const �Լ�
	virtual void print() const;				// ���� �Լ� ���, ����ϴ� �Լ�, ��ȯ�� void, const �Լ�
	~Rect();				// �Ҹ���
private:
	double width;				// private data member, double��
	double height;				// private data member, double��
	double area;				// private data member, double��
};

#endif