#ifndef COMPLEX_H				// ������� "Complex.h"�� �ߺ� ���ǵǴ� ���� ����
#define COMPLEX_H

class Complex
{
public:				// ���� ������ public
	Complex(double = 0, double = 0);				// �⺻ ������(default argument�� ������ ����), private data member�� ������ 2���� double�� ������ �Է¹���

	void setReal(double);				// private data member�� real�� ���� ����(set�Լ�)
	void setImagin(double);				// private data member�� imagin�� ���� ����(set�Լ�)

	double getReal() const;				// private data member�� real�� ���� ������, const�Լ�, ��ȯ�� double(get�Լ�)
	double getImagin() const;				// private data member�� imagin�� ���� ������, const�Լ�,  ��ȯ�� double(get�Լ�)

	void addComplex(const Complex&);				// �� ���� Complex ��ü�� ���ϱ� ������ ������ �Լ�
	void subComplex(const Complex&);				// �� ���� Complex ��ü�� ���� ������ ���� �� �Լ�

	void printComplex1(const Complex* const, const Complex&, const Complex* const, const char[]) const;				// (real, imaginary)�������� ���Ҽ� ���, const�Լ�, �ּ� Ư���� ����(��� �Ű��������� const�� ������)->�Լ� ���� ��� ���� ������ �Ұ�����!
	void printComplex2(const Complex* const, const Complex&, const Complex* const, const char[]) const;				// real + (imaginary)i�������� ���Ҽ� ���, const�Լ�, �ּ� Ư���� ����(��� �Ű��������� const�� ������)->�Լ� ���� ��� ���� ������ �Ұ�����!
private:				// ���� ������ private
	double real;				// ���Ҽ��� �Ǽ� ���� ������ double�� private data memeber
	double imagin;				// ���Ҽ��� ��� ���� ������ double�� private data member
};

#endif