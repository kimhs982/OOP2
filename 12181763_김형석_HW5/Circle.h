#ifndef CIRCLE_H				// ���� ��ó����(preprocessor wrappers)
#define CIRCLE_H

#include "Shape.h"				// ��ӹ޴� �⺻(�θ�) Ŭ���� Shape�� �ִ� "Shape.h"�� ����

class Circle : public Shape				// Circle Ŭ����, Shape Ŭ������ public ���
{
public:
	Circle(double);				// ������, �Ű������� double���� ����
	void setRadius(double);				// radius�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� double
	double getRadius() const;				// radius�� �������� �Լ�, const �Լ�, ��ȯ�� double
	void setArea(double);				// area�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� void
	virtual double getArea() const;				// ���� �Լ� ���, area�� �������� �Լ�, ��ȯ�� double, const �Լ�
	virtual void print() const;				// ���� �Լ� ���, ����ϴ� �Լ�, ��ȯ�� void, const �Լ�
	~Circle();				// �Ҹ���
private:
	double radius;				// private data member, double��
	double area;				// private data member, double��
};

#endif