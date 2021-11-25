#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"				// Complex Ŭ���� ������ �ִ� ������� "Complex.h"�� ����

// ���� ���� ���� ������(binary scope resolution operator) :: �� ����Ͽ� Complex Ŭ������ ��� �Լ����� �˷���

Complex::Complex(double realVal, double imaginVal)				// Complex ������, 2���� double�� ������ �Ű������� ����
{
	setReal(realVal);				// setReal�Լ��� ���� private data member�� real�� ���� ����
	setImagin(imaginVal);				// setImagin�Լ��� ���� private data member�� imagin�� ���� ����
}

void Complex::setReal(double inReal)				// private data member�� real�� ���� ����(set�Լ�)
{
	real = inReal;
}

void Complex::setImagin(double inImagin)				// private data member�� imagin�� ���� ����(set�Լ�)
{
	imagin = inImagin;
}

double Complex::getReal() const				// private data member�� real�� ���� ������, const�Լ�, ��ȯ�� double(get�Լ�)
{
	return real;
}

double Complex::getImagin() const				// private data member�� imagin�� ���� ������, const�Լ�,  ��ȯ�� double(get�Լ�)
{
	return imagin;
}

void Complex::addComplex(const Complex& com)				// �� ���� Complex ��ü�� ���ϱ� ������ ������ �Լ�
{
	Complex* temp = new Complex;				// ���ϱ� ���� ���� ������ �ӽ� Complex ��ü�� new�� heap ������ ����, temp�����ͷ� �ּҸ� ����

	temp->setReal(this->getReal() + com.getReal());				// �Ǽ�(real number)�κ� ���ϱ� ����, this�����ʹ� ��� �Լ��� ������ ��ü �ڽ��� ����Ŵ, set/get�Լ� ���
	temp->setImagin(this->getImagin() + com.getImagin());				// ���(imaginary number)�κ� ���ϱ� ����, this�����ʹ� ��� �Լ��� ������ ��ü �ڽ��� ����Ŵ, set/get�Լ� ���

	printComplex1(this, com, temp, " + ");				// (real, imaginary)�������� ���Ҽ� ����ϴ� printComplex1�Լ� ȣ��
	printComplex2(this, com, temp, " + ");				// real + (imaginary)i�������� ���Ҽ� ����ϴ� printComplex2�Լ� ȣ��
}

void Complex::subComplex(const Complex& com)				// �� ���� Complex ��ü�� ���� ������ ���� �� �Լ�
{
	Complex* temp = new Complex;

	temp->setReal(this->getReal() - com.getReal());				// �Ǽ�(real number)�κ� ���� ����, this�����ʹ� ��� �Լ��� ������ ��ü �ڽ��� ����Ŵ, set/get�Լ� ���
	temp->setImagin(this->getImagin() - com.getImagin());				// ���(imaginary number)�κ� ���� ����, this�����ʹ� ��� �Լ��� ������ ��ü �ڽ��� ����Ŵ, set/get�Լ� ���

	printComplex1(this, com, temp, " - ");				// (real, imaginary)�������� ���Ҽ� ����ϴ� printComplex1�Լ� ȣ��
	printComplex2(this, com, temp, " - ");				// real + (imaginary)i�������� ���Ҽ� ����ϴ� printComplex2�Լ� ȣ��
}

void Complex::printComplex1(const Complex* const com1, const Complex& com2, const Complex* const temp, const char oper[]) const				// (real, imaginary)�������� ���Ҽ� ���, const�Լ�, �ּ� Ư���� ����(��� �Ű��������� const�� ������)->�Լ� ���� ��� ���� ������ �Ұ�����!
{
	cout << "(" << com1->getReal() << ", " << com1->getImagin() << ")" << oper << "("				// ���ڿ��� �����ڰ� ���Ե� " + "�Ǵ� " - "�� �޾ƿ�
		<< com2.getReal() << ", " << com2.getImagin() << ") = (" << temp->getReal()
		<< ", " << temp->getImagin() << ")" << endl;
}

void Complex::printComplex2(const Complex* const com1, const Complex& com2, const Complex* const temp, const char oper[]) const				// real + (imaginary)i�������� ���Ҽ� ���, const�Լ�, �ּ� Ư���� ����(��� �Ű��������� const�� ������)->�Լ� ���� ��� ���� ������ �Ұ�����!
{
	cout << com1->getReal() << (com1->getImagin() >= 0 ? " + " : " ") << com1->getImagin() << "i";
	
	if (oper == " + ")
	{
		cout << (com2.getReal() >= 0 ? oper : " ") << com2.getReal() << (com2.getImagin() >= 0 ? " + " : " ") << com2.getImagin()
			<< "i = " << temp->getReal() << (temp->getImagin() >= 0 ? " + " : " ") << temp->getImagin() << "i" << endl << endl;
	}
	else
	{// ���� ������ ��� �� ��° ���Ҽ��� ��ȣ�� ���� ��� ���°� �ٲ��� �ϹǷ� if~else������ ��� ���� ����
		cout << (com2.getReal() <= 0 ? " + " : " ") << -(com2.getReal()) << (com2.getImagin() <= 0 ? " + " : " ") << -(com2.getImagin())
			<< "i = " << temp->getReal() << (temp->getImagin() >= 0 ? " + " : " ") << temp->getImagin() << "i" << endl << endl;
	}

	delete temp;				// addComplex�� subComplex���� new�� ���� ������ ��ü�� �޸� ������ ������
}