#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;				// 표준 에러 출력 스트림 cerr

#include <cstring>
using std::strcpy;
using std::strcat;
using std::strlen;

#include <cstdlib>
using std::exit;				// 프로그램 종료 함수 exit(0) : 정상 or exit(1) : 비정상

#include "myString.h"

myString::myString(int inLength) : length(inLength)				// 생성자, member intializer로 private data member lenth 초기화
{
	str = new char[length];				// char형 포인터 str에 lenth만큼의 char형 배열 동적할당
}

myString::myString(const myString& inMyString)				// 복사 생성자
{
	this->length = inMyString.length;				// 복사될 객체의 length에 복사할 객체 inMyString의 length를 대입
	str = new char[this->length];				// 복사될 객체의 char형 포인터 str에 length만큼 char형 배열 동적할당
	strcpy(this->str, inMyString.str);				// 복사될 객체의 str에 복사할 객체의 str을 복사
}

myString::~myString()				// 소멸자
{
	delete[] str;				// 동적 할당한 str의 메모리 공간 해제
}

void myString::setString(int inLength, char* inStr)				// 이미 생성된 객체의 stting을 수정하여 대입하는 함수 setString
{
	if (length != inLength)				// length가 매개변수로 받아온 inLength과 다른 경우
	{
		delete[] str;				// str에 미리 동적할당된 메모리 공간을 해제
		length = inLength;				// length에 매개변수로 받아온 inLength를 대입
		str = new char[length];				// str에 새롭게 메모리 동적할당
	}

	strcpy(str, inStr);				// str에 inStr을 복사
}

myString myString::operator+(myString& inMyString)				// (+)연산자 오버로딩, myString객체 + myString객체
{
	myString temp(this->length + inMyString.length - 1);				// 임시 객체 temp생성, 왼쪽 피연산자의 length + 오른쪽 피연산자의 length - 1(둘 다 '\0'가 포함된 길이이기 때문에)를 생성자의 인수로 전달
	strcpy(temp.str, this->str);				// temp의 str에 왼쪽 피연산자의 str을 복사, '\0'문자까지 복사됨
	strcat(temp.str, inMyString.str);				// temp의 str의 '\0'문자부터 오른쪽 피연산자의 str을 복사, '\0'문자까지 복사됨
	return temp;				// 임시 객체 temp를 call by value로 반환
}

void myString::operator=(myString& inMyString)				// (=)연산자 오버로딩, myString객체 = myString객체
{
	setString(inMyString.length, inMyString.str);				// setString함수 호출, 오른쪽 피연산자의 length와 str을 인자로 넘겨줌
}

bool myString::operator==(myString& inMyString)				// (==)연산자 오버로딩, myString객체 == myString객체
{
	if (this->length == inMyString.length)				// 왼쪽 피연산자와 오른쪽 피연산자의 length를 비교
	{
		for (int i = 0; i < this->length - 1; i++)				// for문, i=0부터 i=length--2까지 i를 1씩 증가시키며 반복
			if (this->str[i] != inMyString.str[i])				// 왼쪽 피연산자의 str과 오른쪽 피연산자의 str 중 원소가 하나라도 다를 경우
				return false;
		return true;
	}
	else
		return false;
}

bool myString::operator!=(myString& inMyString)				// (!=)연산자 오버로딩, myString객체 != myString객체
{
	return !(*this == inMyString);				// (==)연산자 오버로딩의 결과에 not을 붙여 반환
}

char myString::operator[](int inIndex)				// ([])연산자 오버로딩, myString객체[index]
{
	if ((inIndex < 0) || (inIndex > this->length - 2))				// inIndex가 배열의 index 범위를 벗어난 경우
	{
		cerr << "Error index; " << inIndex << " out of range" << endl;				// cerr함수를 통해 에러 메세지 출력
		exit(1);				// 프로그램 비정상 종료 표시
	}
	else
	{
		return str[inIndex];				// str의 inIndex번째 index에 해당하는 배열 원소 반환
	}
}

void myString::printString()				// 객체의 length와 str을 출력하는 함수
{
	cout << "This string's length : " << length << endl;
	cout << "This string is : " << str << endl;
}

ostream& operator<<(ostream& output, const myString& inMyString)				// (<<)연산자 오버로딩, cout << myString 객체
{
	output << "myString : " << inMyString.str << endl;				// inMyString의 str을 출력
	return output;				// output(=cout)을 call by reference로 반환
}

istream& operator>>(istream& input, myString& inMyString)				// (>>)연산자 오버로딩, cin >> myString 객체
{
	char* temp = new char[50];				// temp에 inMyString의 50만큼 char형 배열 동적할당
	input >> temp;				// char형 포인터 배열 temp에 문자열 입력
	inMyString.setString(strlen(temp) + 1, temp);				// 문자열 temp의 길이 + 1('\0'문자 포함)과 문자열 temp를 setString 함수의 인수로 전달
	delete[] temp;				// temp에 동적할당한 메모리 공간 해제
	return input;				// input(=cin)을 call by reference로 반환
}