#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;				// true & false를 직접 출력(반대 : noboolalpha)

#include "Vector.h"

int main()
{
	int inputDim;				// 입력할 차원을 저장할 int형 변수
	cout << "벡터의 차원을 입력하세요(>=2) : ";
	cin >> inputDim;
	Vector vec1(inputDim), vec2(inputDim), vec3(inputDim);				// 3개의 Vector 객체 vec1, vec2, vec3 생성

	cout << "vec1" << endl;
	cin >> vec1;				// stream extraction 연산자(>>) 오버로딩

	cout << "\nvec2" << endl;
	cin >> vec2;				// stream extraction 연산자(>>) 오버로딩

	cout << "+ 연산자 오버로딩 결과" << endl;
	vec3 = vec1 + vec2;				// 더하기 연산자(+), 대입 연산자(=) 오버로딩
	cout << vec3;				// stream extraction 연산자(>>) 오버로딩

	cout << "- 연산자 오버로딩 결과" << endl;
	vec3 = vec1 - vec2;				// 빼기 연산자(-), 대입 연산자(=) 오버로딩
	cout << vec3;

	cout << "* 연산자 오버로딩 결과" << endl;
	vec3 = vec1 * vec2;				// 곱하기 연산자(*), 대입 연산자(=) 오버로딩
	cout << vec3;

	cout << "== 연산자 오버로딩 결과" << endl;
	cout << boolalpha << (vec1 == vec2) << endl;				// ==연산자 오버로딩

	cout << "!= 연산자 오버로딩 결과" << endl;
	cout << (vec1 != vec2) << endl;				// !=연산자 오버로딩

	return 0;
}