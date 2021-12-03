#include "Shape.h"
#include <iomanip>

int main() {
	Shape* shape1;				// Shape Ŭ���� ������ shape1
	Shape* shape2;				// Shape Ŭ���� ������ shape2
	Shape* shape3;				// Shape Ŭ���� ������ shape3

	Circle c(1.2);				// Circle Ŭ������ ��ü c ����, �����ڷ� 1.2�� �Ѱ���
	Square s(3.2);				// Square Ŭ������ ��ü s ����, �����ڷ� 3.2�� �Ѱ���
	Rect r(2.1, 3.4);				// Rect Ŭ������ ��ü r ����, �����ڷ� 2.1�� 3.4�� �Ѱ���

	shape1 = &c;				// �⺻ Ŭ������ ������(shape1)�� �Ļ� Ŭ������ ��ü(c)�� ����Ŵ
	shape2 = &s;				// �⺻ Ŭ������ ������(shape2)�� �Ļ� Ŭ������ ��ü(s)�� ����Ŵ
	shape3 = &r;				// �⺻ Ŭ������ ������(shape3)�� �Ļ� Ŭ������ ��ü(r)�� ����Ŵ

	shape1->print();				// Circle Ŭ������ print�Լ� ȣ��, ������
	shape2->print();				// Square Ŭ������ print�Լ� ȣ��, ������
	shape3->print();				// Rect Ŭ������ print�Լ� ȣ��, ������
	std::cout << std::fixed << std::setprecision(2);				// �Ҽ��� 2�ڸ����� ǥ��
	std::cout << "Area of shape1 : " << shape1->getArea() << std::endl;				// Circle Ŭ������ getArea�Լ� ȣ��, ������
	std::cout << "Area of shape2 : " << shape2->getArea() << std::endl;				// Square Ŭ������ getArea�Լ� ȣ��, ������
	std::cout << "Area of shape3 : " << shape3->getArea() << std::endl;				// Rect Ŭ������ getArea�Լ� ȣ��, ������


	return 0;
}