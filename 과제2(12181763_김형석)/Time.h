#ifndef TIME_H				// 헤더파일 "Time.h"가 중복 정의되는 것을 방지
#define TIME_H

class Time
{
public:
	Time(int = 1, int = 0, int = 0, int = 0);				// Time 클래스의 기본생성자(default argument를 가지고 있음), private data member에 저장할 4개의 int형 변수를 입력받음

	void setTime(int, int, int, int);				// private data member들을 설정하는 set함수들을 모두 묶어서 처리
	void setDay(int);				// private data member인 day의 값을 설정(set함수)
	void setHour(int);				// private data member인 hour의 값을 설정(set함수)
	void setMinute(int);				// private data member인 minute의 값을 설정(set함수)
	void setSecond(int);				// private data member인 second의 값을 설정(set함수)

	int getDay() const;				// private data member인 day의 값을 가져옴, const함수, 반환형 int(get함수)
	int getHour() const;				// private data member인 hour의 값을 가져옴, const함수, 반환형 int(get함수)
	int getMinute() const;				// private data member인 minute의 값을 가져옴, const함수, 반환형 int(get함수)
	int getSecond() const;				// private data member인 second의 값을 가져옴, const함수, 반환형 int(get함수)

	void printUniversal() const;				// 24시간 기준으로 시간을 출력하는 함수, const함수, 반환형과 매개변수형 모두 void
	void printStandard() const;				// 12시간 기준으로 "AM" 과 "PM"으로 나눠 시간을 출력하는 함수, const함수, 반환형과 매개변수형 모두 void

	void tick();				// Time 객체에 입력된 시간을 1초씩 증가시키는 함수, 반환형과 매개변수형 모두 void
private:
	int day;				// 일을 저장할 int형 private data member 
	int hour;				// 시를 저장할 int형 private data member 
	int minute;				// 분을 저장할 int형 private data member 
	int second;				// 초를 저장할 int형 private data member 
};

#endif