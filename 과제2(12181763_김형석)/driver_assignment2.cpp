#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Time.h"				// Time 클래스가 선언되어 있는 헤더파일 "Time.h"를 포함

int main()
{
	int day, hour, minute, second, loop = 1;				// 일, 시, 분, 초, 반복 횟수를 입력 받을 int형 변수

	cout << "일, 시, 분, 초를 차례대로 입력하세요 : ";
	cin >> day >> hour >> minute >> second;				// 4개의 int형 변수에 일, 시, 분, 초를 순서대로 입력

	cout << "반복할 횟수를 입력하세요 : ";
	cin >> loop;				// int형 변수에 반복 횟수를 입력

	Time timeLoop(day, hour, minute, second);				// 입력 받은 int형 변수를 이용하여 객체 생성
	timeLoop.printStandard();				// 처음 설정한 값이 맞는지 확인하기 위해 출력

	for (int i = 0; i < loop; i++)				// for 반복문, i가 0부터 loop보다 작아질때 까지 1씩 증가하면서 반복
	{
		timeLoop.tick();				// 1초 증가시키는 member function 호출
		timeLoop.printStandard();				// 표준 형식으로 시간 출력
	}

	// printUniversal 멤버 함수로도 성립함을 확인가능!

	return 0;
}