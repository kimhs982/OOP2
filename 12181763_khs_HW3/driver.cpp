#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;				// true & false�� ���� ���(�ݴ� : noboolalpha)

#include "Vector.h"

int main()
{
	int inputDim;				// �Է��� ������ ������ int�� ����
	cout << "������ ������ �Է��ϼ���(>=2) : ";
	cin >> inputDim;
	Vector vec1(inputDim), vec2(inputDim), vec3(inputDim);				// 3���� Vector ��ü vec1, vec2, vec3 ����

	cout << "vec1" << endl;
	cin >> vec1;				// stream extraction ������(>>) �����ε�

	cout << "\nvec2" << endl;
	cin >> vec2;				// stream extraction ������(>>) �����ε�

	cout << "+ ������ �����ε� ���" << endl;
	vec3 = vec1 + vec2;				// ���ϱ� ������(+), ���� ������(=) �����ε�
	cout << vec3;				// stream extraction ������(>>) �����ε�

	cout << "- ������ �����ε� ���" << endl;
	vec3 = vec1 - vec2;				// ���� ������(-), ���� ������(=) �����ε�
	cout << vec3;

	cout << "* ������ �����ε� ���" << endl;
	vec3 = vec1 * vec2;				// ���ϱ� ������(*), ���� ������(=) �����ε�
	cout << vec3;

	cout << "== ������ �����ε� ���" << endl;
	cout << boolalpha << (vec1 == vec2) << endl;				// ==������ �����ε�

	cout << "!= ������ �����ε� ���" << endl;
	cout << (vec1 != vec2) << endl;				// !=������ �����ε�

	return 0;
}