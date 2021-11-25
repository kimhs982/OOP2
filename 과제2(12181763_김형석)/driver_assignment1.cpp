#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Complex.h"				// Complex Ŭ������ ���ǵǾ� �ִ� ������� "Complex.h"�� ����

int main()
{
	double a, b, c, d;				// ������ ���Ҽ��� �Է��� double�� ���� ����

	cout << "--���Ҽ� ���ϱ�--" << endl;

	cout << "ù ��° ���Ҽ�(�Ǽ� �κ�, ��� �κ�) : ";
	cin >> a >> b;				// ù ��° ���Ҽ��� �Ǽ� �κа� ��� �κ��� �Է¹���
	Complex com1(a, b);				// ù ��° Complex ��ü com1

	cout << "�� ��° ���Ҽ�(�Ǽ� �κ�, ��� �κ�) : ";
	cin >> c >> d;				// �� ��° ���Ҽ��� �Ǽ� �κа� ��� �κ��� �Է¹���
	Complex com2(c, d);				// �� ��° Complex ��ü com2
	cout << endl;

	com1.addComplex(com2);				// Complex ��ü com1�� com2�� ���ϱ� ����

	cout << "--���Ҽ� ����--" << endl;

	cout << "ù ��° ���Ҽ�(�Ǽ� �κ�, ��� �κ�) : ";
	cin >> a >> b;				// ù ��° ���Ҽ��� �Ǽ� �κа� ��� �κ��� �Է¹���
	Complex com3(a, b);				// ù ��° Complex ��ü com3, ��ü�� �����Ǹ� �����ϱ� ���Ͽ� �ٸ� ��ü com3�� ����

	cout << "�� ��° ���Ҽ�(�Ǽ� �κ�, ��� �κ�) : ";
	cin >> c >> d;				// �� ��° ���Ҽ��� �Ǽ� �κа� ��� �κ��� �Է¹���
	Complex com4(c, d);				// �� ��° Complex ��ü com2, ��ü�� �����Ǹ� �����ϱ� ���Ͽ� �ٸ� ��ü com4�� ����
	cout << endl;
	
	// com1�� com2�� �̸��� �״�� ����Ϸ��� ���� �Ҵ�(new)�� ����Ͽ� ��ü�� �����ϰ� ������ ���� delete�� �޸� ������ �����ؾ���

	com3.subComplex(com4);				// Complex ��ü com3�� com4�� ���ϱ� ����

	return 0;
}