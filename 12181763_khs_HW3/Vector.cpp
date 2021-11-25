#include <iomanip>
using std::setw;

#include "Vector.h"

int Vector::dim = 0;				// static data member를 0으로 초기화

Vector::Vector(int inDim)
{
	dim = inDim;				// dim에 매개변수로 받은 inDim을 대입
	vec = new int[dim];				// 차원의 크기만큼 동적할당, vec에 연결
	temp = new int[dim];				// 차원의 크기만큼 동적할당, temp에 연결

	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
	{
		vec[i] = 0;				// int형 포인터 배열 vec의 원소값을 0으로 초기화
		temp[i] = 0;				// int형 포인터 배열 temp의 원소값을 0으로 초기화
	}
}

Vector::~Vector()
{
	delete[] vec;				// int형 포인터 배열 vec의 메모리 해제
	delete[] temp;				// int형 포인터 배열 temp의 메모리 해제
}

Vector& Vector::operator=(const int* data)				// Vector 객체1 = 포인터
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
		vec[i] = data[i];				// 객체의 int형 포인터 배열 vec에 int형 포인터 배열 data의 값을 복사
	return *this;				// 객체 자신을 반환
}

const int* Vector::operator+(const Vector& vec1)				// Vector 객체1 + Vector 객체
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
		temp[i] = vec[i] + vec1.vec[i];				// Vector 객체1의 int형 포인터 배열 vec과 vec1의 int형 포인터 배열 vec1.vec를 더하여 임시 포인터 배열 temp에 저장
	return temp;				// 임시 포인터 배열 temp를 반환
}

const int* Vector::operator-(const Vector& vec2)				// Vector 객체1 - Vector 객체
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
		temp[i] = vec[i] - vec2.vec[i];				// Vector 객체1의 int형 포인터 배열 vec과 vec1의 int형 포인터 배열 vec1.vec를 빼서 임시 포인터 배열 temp에 저장
	return temp;				// 임시 포인터 배열 temp를 반환
}

const int* Vector::operator*(const Vector& vec3)				// Vector 객체1 * Vector 객체
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
		temp[i] = vec[i] * vec3.vec[i];				// Vector 객체1의 int형 포인터 배열 vec과 vec1의 int형 포인터 배열 vec1.vec를 곱하여 임시 포인터 배열 temp에 저장
	return temp;				// 임시 포인터 배열 temp를 반환
}

bool Vector::operator==(const Vector& vec4)				// Vector 객체1 == Vector 객체
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
	{
		if (vec[i] != vec4.vec[i])				// Vector 객체1의 포인터 배열 vec과 vec4의 포인터 배열 vec4.vec을 차원별로 비교하여 하나라도 서로 다른 경우
			return false;				// false를 반환
	}
	return true;				// 모두 같은 경우 true를 반환
}

bool Vector::operator!=(const Vector& vec5)				// Vector 객체1 != Vector 객체
{
	for (int i = 0; i < dim; i++)				// for반복문, i=0부터 i=dim-1까지 i를 1씩 증가시키면서 반복
	{
		if (vec[i] != vec5.vec[i])				// Vector 객체1의 포인터 배열 vec과 vec4의 포인터 배열 vec4.vec을 차원별로 비교하여 하나라도 서로 다른 경우
			return true;				// true를 반환
	}
	return false;				// 모두 같은 경우 false를 반환
}

ostream& operator<<(ostream& output, const Vector& vec6)				// cout << Vector 객체
{
	output << "┌" << setw(5) << vec6.vec[0] << " ┐\n";				// 첫번째 차원 출력
	for (int i = 1; i < vec6.dim - 1; i++)				// for반복문, i=1부터 i=vec6/dim-2까지 i를 1씩 증가시키면서 반복
		output << "│" << setw(5) << vec6.vec[i] << " │\n";				// 중간 차원 출력
	output << "└" << setw(5) << vec6.vec[vec6.dim - 1] << " ┘\n";				// 마지막 차원 출력
	
	return output;				// cout을 반환
}

istream& operator>>(istream& input, const Vector& vec7)				// cin >> Vector 객체
{
	for (int i = 0; i < vec7.dim; i++)				// for반복문, i=0부터 i=vec7.dim-1까지 i를 1씩 증가시키면서 반복
		input >> vec7.vec[i];				// 차원별로 입력
	return input;				// cin을 반환
}