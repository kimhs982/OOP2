#include <iomanip>
using std::setw;

#include "Vector.h"

int Vector::dim = 0;				// static data member�� 0���� �ʱ�ȭ

Vector::Vector(int inDim)
{
	dim = inDim;				// dim�� �Ű������� ���� inDim�� ����
	vec = new int[dim];				// ������ ũ�⸸ŭ �����Ҵ�, vec�� ����
	temp = new int[dim];				// ������ ũ�⸸ŭ �����Ҵ�, temp�� ����

	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		vec[i] = 0;				// int�� ������ �迭 vec�� ���Ұ��� 0���� �ʱ�ȭ
		temp[i] = 0;				// int�� ������ �迭 temp�� ���Ұ��� 0���� �ʱ�ȭ
	}
}

Vector::~Vector()
{
	delete[] vec;				// int�� ������ �迭 vec�� �޸� ����
	delete[] temp;				// int�� ������ �迭 temp�� �޸� ����
}

Vector& Vector::operator=(const int* data)				// Vector ��ü1 = ������
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
		vec[i] = data[i];				// ��ü�� int�� ������ �迭 vec�� int�� ������ �迭 data�� ���� ����
	return *this;				// ��ü �ڽ��� ��ȯ
}

const int* Vector::operator+(const Vector& vec1)				// Vector ��ü1 + Vector ��ü
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
		temp[i] = vec[i] + vec1.vec[i];				// Vector ��ü1�� int�� ������ �迭 vec�� vec1�� int�� ������ �迭 vec1.vec�� ���Ͽ� �ӽ� ������ �迭 temp�� ����
	return temp;				// �ӽ� ������ �迭 temp�� ��ȯ
}

const int* Vector::operator-(const Vector& vec2)				// Vector ��ü1 - Vector ��ü
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
		temp[i] = vec[i] - vec2.vec[i];				// Vector ��ü1�� int�� ������ �迭 vec�� vec1�� int�� ������ �迭 vec1.vec�� ���� �ӽ� ������ �迭 temp�� ����
	return temp;				// �ӽ� ������ �迭 temp�� ��ȯ
}

const int* Vector::operator*(const Vector& vec3)				// Vector ��ü1 * Vector ��ü
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
		temp[i] = vec[i] * vec3.vec[i];				// Vector ��ü1�� int�� ������ �迭 vec�� vec1�� int�� ������ �迭 vec1.vec�� ���Ͽ� �ӽ� ������ �迭 temp�� ����
	return temp;				// �ӽ� ������ �迭 temp�� ��ȯ
}

bool Vector::operator==(const Vector& vec4)				// Vector ��ü1 == Vector ��ü
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		if (vec[i] != vec4.vec[i])				// Vector ��ü1�� ������ �迭 vec�� vec4�� ������ �迭 vec4.vec�� �������� ���Ͽ� �ϳ��� ���� �ٸ� ���
			return false;				// false�� ��ȯ
	}
	return true;				// ��� ���� ��� true�� ��ȯ
}

bool Vector::operator!=(const Vector& vec5)				// Vector ��ü1 != Vector ��ü
{
	for (int i = 0; i < dim; i++)				// for�ݺ���, i=0���� i=dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		if (vec[i] != vec5.vec[i])				// Vector ��ü1�� ������ �迭 vec�� vec4�� ������ �迭 vec4.vec�� �������� ���Ͽ� �ϳ��� ���� �ٸ� ���
			return true;				// true�� ��ȯ
	}
	return false;				// ��� ���� ��� false�� ��ȯ
}

ostream& operator<<(ostream& output, const Vector& vec6)				// cout << Vector ��ü
{
	output << "��" << setw(5) << vec6.vec[0] << " ��\n";				// ù��° ���� ���
	for (int i = 1; i < vec6.dim - 1; i++)				// for�ݺ���, i=1���� i=vec6/dim-2���� i�� 1�� ������Ű�鼭 �ݺ�
		output << "��" << setw(5) << vec6.vec[i] << " ��\n";				// �߰� ���� ���
	output << "��" << setw(5) << vec6.vec[vec6.dim - 1] << " ��\n";				// ������ ���� ���
	
	return output;				// cout�� ��ȯ
}

istream& operator>>(istream& input, const Vector& vec7)				// cin >> Vector ��ü
{
	for (int i = 0; i < vec7.dim; i++)				// for�ݺ���, i=0���� i=vec7.dim-1���� i�� 1�� ������Ű�鼭 �ݺ�
		input >> vec7.vec[i];				// �������� �Է�
	return input;				// cin�� ��ȯ
}