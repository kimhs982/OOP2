#ifndef TIME_H				// ������� "Time.h"�� �ߺ� ���ǵǴ� ���� ����
#define TIME_H

class Time
{
public:
	Time(int = 1, int = 0, int = 0, int = 0);				// Time Ŭ������ �⺻������(default argument�� ������ ����), private data member�� ������ 4���� int�� ������ �Է¹���

	void setTime(int, int, int, int);				// private data member���� �����ϴ� set�Լ����� ��� ��� ó��
	void setDay(int);				// private data member�� day�� ���� ����(set�Լ�)
	void setHour(int);				// private data member�� hour�� ���� ����(set�Լ�)
	void setMinute(int);				// private data member�� minute�� ���� ����(set�Լ�)
	void setSecond(int);				// private data member�� second�� ���� ����(set�Լ�)

	int getDay() const;				// private data member�� day�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
	int getHour() const;				// private data member�� hour�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
	int getMinute() const;				// private data member�� minute�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)
	int getSecond() const;				// private data member�� second�� ���� ������, const�Լ�, ��ȯ�� int(get�Լ�)

	void printUniversal() const;				// 24�ð� �������� �ð��� ����ϴ� �Լ�, const�Լ�, ��ȯ���� �Ű������� ��� void
	void printStandard() const;				// 12�ð� �������� "AM" �� "PM"���� ���� �ð��� ����ϴ� �Լ�, const�Լ�, ��ȯ���� �Ű������� ��� void

	void tick();				// Time ��ü�� �Էµ� �ð��� 1�ʾ� ������Ű�� �Լ�, ��ȯ���� �Ű������� ��� void
private:
	int day;				// ���� ������ int�� private data member 
	int hour;				// �ø� ������ int�� private data member 
	int minute;				// ���� ������ int�� private data member 
	int second;				// �ʸ� ������ int�� private data member 
};

#endif