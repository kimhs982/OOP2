#pragma once
#include <iostream>
using std::ostream;				// ostream Ŭ���� ���
using std::istream;				// istream Ŭ���� ���

class Vector				// Vector Ŭ����
{
public:
	Vector(int = 0);				// ������, int�� �Ű����� 1��, default��
	~Vector();				// �Ҹ���
	Vector& operator=(const int*);				// ���Կ�����(=) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
	const int* operator+(const Vector&);				// ����Լ�, ���ϱ⿬����(+) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
	const int* operator-(const Vector&);				// ����Լ�, ���⿬����(-) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
	const int* operator*(const Vector&);				// ����Լ�, ���ϱ⿬����(*) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
	bool operator==(const Vector&);				// ����Լ�, ������(==) �����ε�, bool�� �Ű����� 1��, ��ȯ�� bool
	bool operator!=(const Vector&);				// ����Լ�, ������(!=) �����ε�, bool�� �Ű����� 1��, ��ȯ�� bool
	friend ostream& operator<<(ostream&, const Vector&);				// friend �Լ�, �����Լ�, stream insertion ������(<<) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
	friend istream& operator>>(istream&, const Vector&);				// friend �Լ�, �����Լ�, stream extraction ������(>>) �����ε�, const int �������� �Ű����� 1��, ��ȯ�� Vector reference
private:
	static int dim;				// private data member, static(����) int�� ����, ������ ������ ����
	int* vec;				// private data member, int �����ͺ���, Vector ��ü�� �� ������ ���Ұ� ����
	int* temp;				// private data member, int �����ͺ���, �ӽ÷� ���Ұ� ����
};