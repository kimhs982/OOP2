#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;				// ǥ�� ���� ��� ��Ʈ�� cerr

#include <cstring>
using std::strcpy;
using std::strcat;
using std::strlen;

#include <cstdlib>
using std::exit;				// ���α׷� ���� �Լ� exit(0) : ���� or exit(1) : ������

#include "myString.h"

myString::myString(int inLength) : length(inLength)				// ������, member intializer�� private data member lenth �ʱ�ȭ
{
	str = new char[length];				// char�� ������ str�� lenth��ŭ�� char�� �迭 �����Ҵ�
}

myString::myString(const myString& inMyString)				// ���� ������
{
	this->length = inMyString.length;				// ����� ��ü�� length�� ������ ��ü inMyString�� length�� ����
	str = new char[this->length];				// ����� ��ü�� char�� ������ str�� length��ŭ char�� �迭 �����Ҵ�
	strcpy(this->str, inMyString.str);				// ����� ��ü�� str�� ������ ��ü�� str�� ����
}

myString::~myString()				// �Ҹ���
{
	delete[] str;				// ���� �Ҵ��� str�� �޸� ���� ����
}

void myString::setString(int inLength, char* inStr)				// �̹� ������ ��ü�� stting�� �����Ͽ� �����ϴ� �Լ� setString
{
	if (length != inLength)				// length�� �Ű������� �޾ƿ� inLength�� �ٸ� ���
	{
		delete[] str;				// str�� �̸� �����Ҵ�� �޸� ������ ����
		length = inLength;				// length�� �Ű������� �޾ƿ� inLength�� ����
		str = new char[length];				// str�� ���Ӱ� �޸� �����Ҵ�
	}

	strcpy(str, inStr);				// str�� inStr�� ����
}

myString myString::operator+(myString& inMyString)				// (+)������ �����ε�, myString��ü + myString��ü
{
	myString temp(this->length + inMyString.length - 1);				// �ӽ� ��ü temp����, ���� �ǿ������� length + ������ �ǿ������� length - 1(�� �� '\0'�� ���Ե� �����̱� ������)�� �������� �μ��� ����
	strcpy(temp.str, this->str);				// temp�� str�� ���� �ǿ������� str�� ����, '\0'���ڱ��� �����
	strcat(temp.str, inMyString.str);				// temp�� str�� '\0'���ں��� ������ �ǿ������� str�� ����, '\0'���ڱ��� �����
	return temp;				// �ӽ� ��ü temp�� call by value�� ��ȯ
}

void myString::operator=(myString& inMyString)				// (=)������ �����ε�, myString��ü = myString��ü
{
	setString(inMyString.length, inMyString.str);				// setString�Լ� ȣ��, ������ �ǿ������� length�� str�� ���ڷ� �Ѱ���
}

bool myString::operator==(myString& inMyString)				// (==)������ �����ε�, myString��ü == myString��ü
{
	if (this->length == inMyString.length)				// ���� �ǿ����ڿ� ������ �ǿ������� length�� ��
	{
		for (int i = 0; i < this->length - 1; i++)				// for��, i=0���� i=length--2���� i�� 1�� ������Ű�� �ݺ�
			if (this->str[i] != inMyString.str[i])				// ���� �ǿ������� str�� ������ �ǿ������� str �� ���Ұ� �ϳ��� �ٸ� ���
				return false;
		return true;
	}
	else
		return false;
}

bool myString::operator!=(myString& inMyString)				// (!=)������ �����ε�, myString��ü != myString��ü
{
	return !(*this == inMyString);				// (==)������ �����ε��� ����� not�� �ٿ� ��ȯ
}

char myString::operator[](int inIndex)				// ([])������ �����ε�, myString��ü[index]
{
	if ((inIndex < 0) || (inIndex > this->length - 2))				// inIndex�� �迭�� index ������ ��� ���
	{
		cerr << "Error index; " << inIndex << " out of range" << endl;				// cerr�Լ��� ���� ���� �޼��� ���
		exit(1);				// ���α׷� ������ ���� ǥ��
	}
	else
	{
		return str[inIndex];				// str�� inIndex��° index�� �ش��ϴ� �迭 ���� ��ȯ
	}
}

void myString::printString()				// ��ü�� length�� str�� ����ϴ� �Լ�
{
	cout << "This string's length : " << length << endl;
	cout << "This string is : " << str << endl;
}

ostream& operator<<(ostream& output, const myString& inMyString)				// (<<)������ �����ε�, cout << myString ��ü
{
	output << "myString : " << inMyString.str << endl;				// inMyString�� str�� ���
	return output;				// output(=cout)�� call by reference�� ��ȯ
}

istream& operator>>(istream& input, myString& inMyString)				// (>>)������ �����ε�, cin >> myString ��ü
{
	char* temp = new char[50];				// temp�� inMyString�� 50��ŭ char�� �迭 �����Ҵ�
	input >> temp;				// char�� ������ �迭 temp�� ���ڿ� �Է�
	inMyString.setString(strlen(temp) + 1, temp);				// ���ڿ� temp�� ���� + 1('\0'���� ����)�� ���ڿ� temp�� setString �Լ��� �μ��� ����
	delete[] temp;				// temp�� �����Ҵ��� �޸� ���� ����
	return input;				// input(=cin)�� call by reference�� ��ȯ
}