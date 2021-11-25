#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Time.h"				// Time Ŭ������ ����Ǿ� �ִ� ������� "Time.h"�� ����

int main()
{
	int day, hour, minute, second, loop = 1;				// ��, ��, ��, ��, �ݺ� Ƚ���� �Է� ���� int�� ����

	cout << "��, ��, ��, �ʸ� ���ʴ�� �Է��ϼ��� : ";
	cin >> day >> hour >> minute >> second;				// 4���� int�� ������ ��, ��, ��, �ʸ� ������� �Է�

	cout << "�ݺ��� Ƚ���� �Է��ϼ��� : ";
	cin >> loop;				// int�� ������ �ݺ� Ƚ���� �Է�

	Time timeLoop(day, hour, minute, second);				// �Է� ���� int�� ������ �̿��Ͽ� ��ü ����
	timeLoop.printStandard();				// ó�� ������ ���� �´��� Ȯ���ϱ� ���� ���

	for (int i = 0; i < loop; i++)				// for �ݺ���, i�� 0���� loop���� �۾����� ���� 1�� �����ϸ鼭 �ݺ�
	{
		timeLoop.tick();				// 1�� ������Ű�� member function ȣ��
		timeLoop.printStandard();				// ǥ�� �������� �ð� ���
	}

	// printUniversal ��� �Լ��ε� �������� Ȯ�ΰ���!

	return 0;
}