#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Complex.h"				// Complex 클래스가 정의되어 있는 헤더파일 "Complex.h"를 포함

int main()
{
	double a, b, c, d;				// 각각의 복소수에 입력할 double형 변수 선언

	cout << "--복소수 더하기--" << endl;

	cout << "첫 번째 복소수(실수 부분, 허수 부분) : ";
	cin >> a >> b;				// 첫 번째 복소수의 실수 부분과 허수 부분을 입력받음
	Complex com1(a, b);				// 첫 번째 Complex 객체 com1

	cout << "두 번째 복소수(실수 부분, 허수 부분) : ";
	cin >> c >> d;				// 두 번째 복소수의 실수 부분과 허수 부분을 입력받음
	Complex com2(c, d);				// 두 번째 Complex 객체 com2
	cout << endl;

	com1.addComplex(com2);				// Complex 객체 com1과 com2의 더하기 연산

	cout << "--복소수 빼기--" << endl;

	cout << "첫 번째 복소수(실수 부분, 허수 부분) : ";
	cin >> a >> b;				// 첫 번째 복소수의 실수 부분과 허수 부분을 입력받음
	Complex com3(a, b);				// 첫 번째 Complex 객체 com3, 객체의 재정의를 방지하기 위하여 다른 객체 com3를 생성

	cout << "두 번째 복소수(실수 부분, 허수 부분) : ";
	cin >> c >> d;				// 두 번째 복소수의 실수 부분과 허수 부분을 입력받음
	Complex com4(c, d);				// 두 번째 Complex 객체 com2, 객체의 재정의를 방지하기 위하여 다른 객체 com4를 생성
	cout << endl;
	
	// com1과 com2의 이름을 그대로 사용하려면 동적 할당(new)을 사용하여 객체를 생성하고 재정의 전에 delete로 메모리 공간을 해제해야함

	com3.subComplex(com4);				// Complex 객체 com3과 com4의 더하기 연산

	return 0;
}