#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Calculator
{
public:
	Calculator(double class_num1, double class_num2)
	{
		setNumber(class_num1, class_num2);
	}

	void setNumber(double class_num1, double class_num2)
	{
		num1 = class_num1;
		num2 = class_num2;
	}

	double add()
	{
		return num1 + num2;
	}

	double sub()
	{
		return num1 - num2;
	}

	double mul()
	{
		return num1 * num2;
	}

	double div()
	{
		return num1 / num2;
	}
private:
	double num1, num2;
};

int main(void)
{
	double input_num1, input_num2, result;
	char oper;

	cout << "Please enter a formula :\n";

	cin >> input_num1;
	cin >> oper;
	cin >> input_num2;

	Calculator doCalculation(input_num1, input_num2);
	
	// switch������ break�� ������� ������ �������� ��찡 �ߺ� ����ȴ�!!
	switch (oper)
	{
	case '+':
		result = doCalculation.add();
		break;
	case '-':
		result = doCalculation.sub();
		break;
	case '*':
		result = doCalculation.mul();
		break;
	case '/':
		result = doCalculation.div();
		break;
	default:
		cout << "�ùٸ� �����ڸ� �Է��ϼ���!" << endl;
		break;
	}

	cout << "Result : " << result << endl;

	return 0;
}