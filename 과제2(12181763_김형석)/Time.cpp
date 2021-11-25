#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>				// ǥ�� ������� <iomanip> ����
using std::setfill;				// setw�� Ȯ���� ������ ä������
using std::setw;				// ���� Ȯ��

#include "Time.h"				// Time Ŭ������ ����Ǿ� �ִ� ������� "Time.h"�� ����

// ���� ���� ���� ������(binary scope resolution operator) :: �� ����Ͽ� Complex Ŭ������ ��� �Լ����� �˷���

Time::Time(int dy, int hr, int min, int sec)				// Time ������, 4���� double�� ������ �Ű������� ����
{
	setTime(dy, hr, min, sec);				// private data member���� �����ϴ� set�Լ����� ��� ��� ó���ϴ� setTimeȣ��
}

void Time::setTime(int d, int h, int m, int s)				// private data member���� �����ϴ� set�Լ����� ��� ��� ó��
{
	setDay(d);
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setDay(int d)				// private data member�� day�� ���� ����(set�Լ�)
{
	day = (d >= 1 && d <= 31) ? d : 1;				// ��ȿ�� �˻�, 1�� 31������ ���� �Է�, �� �̿ܿ��� 1�� �Է�
}

void Time::setHour(int h)				// private data member�� hour�� ���� ����(set�Լ�)
{
	hour = (h >= 0 && h < 24) ? h : 0;				// ��ȿ�� �˻�, 0�� 59������ ���� �Է�, �� �̿ܿ��� 0�� �Է�
}

void Time::setMinute(int m)				// private data member�� minute�� ���� ����(set�Լ�)
{
	minute = (m >= 0 && m < 60) ? m : 0;				// ��ȿ�� �˻�, 0�� 59������ ���� �Է�, �� �̿ܿ��� 0�� �Է�
}

void Time::setSecond(int s)				// private data member�� second�� ���� ����(set�Լ�)
{
	second = (s >= 0 && s < 60) ? s : 0;				// ��ȿ�� �˻�, 0�� 59������ ���� �Է�, �� �̿ܿ��� 0�� �Է�
}

int Time::getDay() const				// private data member�� day�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
{
	return day;
}

int Time::getHour() const				// private data member�� hour�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
{
	return hour;
}

int Time::getMinute() const				// private data member�� minute�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
{
	return minute;
}

int Time::getSecond() const				// private data member�� second�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
{
	return second;
}

void Time::printUniversal() const				// 24�ð� �������� �ð��� ����ϴ� �Լ�, const�Լ�, ��ȯ���� �Ű������� ��� void
{
	cout << day << "�� " << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second << endl;
}

void Time::printStandard() const				// 12�ð� �������� "AM" �� "PM"���� ���� �ð��� ����ϴ� �Լ�, const�Լ�, ��ȯ���� �Ű������� ��� void
{
	cout << day << "��" << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"				// 24�ð��� 0�ÿ��� 12�� ���̷θ� ǥ���ϰ� "AM" �� "PM"���� �����Ͽ���.
		<< setfill('0') << setw(2) << minute << ":" << setw(2)
		<< second << (hour < 12 ? " AM" : " PM") << endl;
}

void Time::tick()				// Time ��ü�� �Էµ� �ð��� 1�ʾ� ������Ű�� �Լ�, ��ȯ���� �Ű������� ��� void
{
	if (getSecond() + 1 < 60)				// �ʰ� 60�̸� �϶�
	{
		setSecond(getSecond() + 1);				// 1�ʸ� ����
	}
	else if (getMinute() + 1 < 60)				// �ʰ� 60�̻�(60 �϶��� ����)�̰� ���� 60�̸� �϶�
	{
		setSecond(0);				// �ʸ� 0���� �ٲٰ�
		setMinute(getMinute() + 1);				// �п� 1�� ����
	}
	else if (getHour() + 1 < 24)				// �ʰ� 60�̻�(60 �϶��� ����)�̰� ���� 60�̻�(60 �϶��� ����)�̰� �ð� 24�̸� �϶�
	{
		setSecond(0);				// �ʸ� 0���� �ٲٰ�
		setMinute(0);				// ���� 0���� �ٲٰ�
		setHour(getHour() + 1);				// �ÿ� 1�� ����
	}
	else
	{// �ʰ� 60, ���� 60, �ð� 24 �϶�
		setSecond(0);				// �ʸ� 0���� �ٲٰ�
		setMinute(0);				// ���� 0���� �ٲٰ�
		setHour(0);				// �õ� 0���� �ٲٰ�
		setDay(getDay() + 1);				// �Ͽ� 1�� ����
	}
}