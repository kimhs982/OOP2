#include "Shape.h"
#include <iomanip>

int main() {
	Shape* shape1;				// Shape 클래스 포인터 shape1
	Shape* shape2;				// Shape 클래스 포인터 shape2
	Shape* shape3;				// Shape 클래스 포인터 shape3

	Circle c(1.2);				// Circle 클래스의 객체 c 생성, 생성자로 1.2를 넘겨줌
	Square s(3.2);				// Square 클래스의 객체 s 생성, 생성자로 3.2를 넘겨줌
	Rect r(2.1, 3.4);				// Rect 클래스이 객체 r 생성, 생성자로 2.1과 3.4를 넘겨줌

	shape1 = &c;				// 기본 클래스의 포인터(shape1)가 파생 클래스의 객체(c)를 가리킴
	shape2 = &s;				// 기본 클래스의 포인터(shape2)가 파생 클래스의 객체(s)를 가리킴
	shape3 = &r;				// 기본 클래스의 포인터(shape3)가 파생 클래스의 객체(r)를 가리킴

	shape1->print();				// Circle 클래스의 print함수 호출, 다형성
	shape2->print();				// Square 클래스의 print함수 호출, 다형성
	shape3->print();				// Rect 클래스의 print함수 호출, 다형성
	std::cout << std::fixed << std::setprecision(2);				// 소수점 2자리까지 표시
	std::cout << "Area of shape1 : " << shape1->getArea() << std::endl;				// Circle 클래스의 getArea함수 호출, 다형성
	std::cout << "Area of shape2 : " << shape2->getArea() << std::endl;				// Square 클래스의 getArea함수 호출, 다형성
	std::cout << "Area of shape3 : " << shape3->getArea() << std::endl;				// Rect 클래스의 getArea함수 호출, 다형성


	return 0;
}