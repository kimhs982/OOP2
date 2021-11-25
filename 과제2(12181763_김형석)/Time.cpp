#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>				// 표준 헤더파일 <iomanip> 포함
using std::setfill;				// setw로 확보된 공간에 채워넣음
using std::setw;				// 공간 확보

#include "Time.h"				// Time 클래스가 선언되어 있는 헤더파일 "Time.h"를 포함

// 이항 범위 지정 연산자(binary scope resolution operator) :: 을 사용하여 Complex 클래스의 멤버 함수임을 알려줌

Time::Time(int dy, int hr, int min, int sec)				// Time 생성자, 4개의 double형 변수를 매개변수로 받음
{
	setTime(dy, hr, min, sec);				// private data member들을 설정하는 set함수들을 모두 묶어서 처리하는 setTime호출
}

void Time::setTime(int d, int h, int m, int s)				// private data member들을 설정하는 set함수들을 모두 묶어서 처리
{
	setDay(d);
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setDay(int d)				// private data member인 day의 값을 설정(set함수)
{
	day = (d >= 1 && d <= 31) ? d : 1;				// 유효성 검사, 1과 31사이의 값만 입력, 그 이외에는 1을 입력
}

void Time::setHour(int h)				// private data member인 hour의 값을 설정(set함수)
{
	hour = (h >= 0 && h < 24) ? h : 0;				// 유효성 검사, 0과 59사이의 값만 입력, 그 이외에는 0을 입력
}

void Time::setMinute(int m)				// private data member인 minute의 값을 설정(set함수)
{
	minute = (m >= 0 && m < 60) ? m : 0;				// 유효성 검사, 0과 59사이의 값만 입력, 그 이외에는 0을 입력
}

void Time::setSecond(int s)				// private data member인 second의 값을 설정(set함수)
{
	second = (s >= 0 && s < 60) ? s : 0;				// 유효성 검사, 0과 59사이의 값만 입력, 그 이외에는 0을 입력
}

int Time::getDay() const				// private data member인 day의 값을 가져옴, const함수, 반환형 int(get함수)
{
	return day;
}

int Time::getHour() const				// private data member인 hour의 값을 가져옴, const함수, 반환형 int(get함수)
{
	return hour;
}

int Time::getMinute() const				// private data member인 minute의 값을 가져옴, const함수, 반환형 int(get함수)
{
	return minute;
}

int Time::getSecond() const				// private data member인 second의 값을 가져옴, const함수, 반환형 int(get함수)
{
	return second;
}

void Time::printUniversal() const				// 24시간 기준으로 시간을 출력하는 함수, const함수, 반환형과 매개변수형 모두 void
{
	cout << day << "일 " << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second << endl;
}

void Time::printStandard() const				// 12시간 기준으로 "AM" 과 "PM"으로 나눠 시간을 출력하는 함수, const함수, 반환형과 매개변수형 모두 void
{
	cout << day << "일" << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"				// 24시간을 0시에서 12시 사이로만 표현하고 "AM" 과 "PM"으로 구분하였다.
		<< setfill('0') << setw(2) << minute << ":" << setw(2)
		<< second << (hour < 12 ? " AM" : " PM") << endl;
}

void Time::tick()				// Time 객체에 입력된 시간을 1초씩 증가시키는 함수, 반환형과 매개변수형 모두 void
{
	if (getSecond() + 1 < 60)				// 초가 60미만 일때
	{
		setSecond(getSecond() + 1);				// 1초를 더함
	}
	else if (getMinute() + 1 < 60)				// 초가 60이상(60 일때와 동일)이고 분이 60미만 일때
	{
		setSecond(0);				// 초를 0으로 바꾸고
		setMinute(getMinute() + 1);				// 분에 1을 더함
	}
	else if (getHour() + 1 < 24)				// 초가 60이상(60 일때와 동일)이고 분이 60이상(60 일때와 동일)이고 시가 24미만 일때
	{
		setSecond(0);				// 초를 0으로 바꾸고
		setMinute(0);				// 분을 0으로 바꾸고
		setHour(getHour() + 1);				// 시에 1을 더함
	}
	else
	{// 초가 60, 분이 60, 시가 24 일때
		setSecond(0);				// 초를 0으로 바꾸고
		setMinute(0);				// 분을 0으로 바꾸고
		setHour(0);				// 시도 0으로 바꾸고
		setDay(getDay() + 1);				// 일에 1을 더함
	}
}