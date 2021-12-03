#ifndef SQUARE_H				// ���� ��ó����(preprocessor wrappers)
#define SQUARE_H

#include "Shape.h"				// ��ӹ޴� �⺻(�θ�) Ŭ���� Shape�� �ִ� "Shape.h"�� ����

class Square : public Shape				// Square Ŭ����, Shape Ŭ������ public ���
{
public:
	Square(double);				// ������, �Ű������� double���� ����
	void setSide(double);				// side�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� double
	double getSide() const;				// side�� �������� �Լ�, const �Լ�, ��ȯ�� double
	void setArea(double);				// area�� �����ϴ� �Լ�, �Ű������� double���� ����, ��ȯ�� void
	virtual double getArea() const;				// ���� �Լ� ���, area�� �������� �Լ�, ��ȯ�� double, const �Լ�
	virtual void print() const;				// ���� �Լ� ���, ����ϴ� �Լ�, ��ȯ�� void, const �Լ�
	~Square();				// �Ҹ���
private:
	double side;				// private data member, double��
	double area;				// private data member, double��
};

#endif