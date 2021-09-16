#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Calculator
{
public:
	Calculator(void)
	{
		cout << "Please enter a formula :\n";
	}

	double add(double num1, double num2)
	{
		return num1 + num2;
	}

	double sub(double num1, double num2)
	{
		return num1 - num2;
	}

	double mul(double num1, double num2)
	{
		return num1 * num2;
	}

	double div(double num1, double num2)
	{
		return num1 / num2;
	}
};

int main(void)
{
	double input_num1, input_num2, result;
	char oper;

	Calculator doCalculation;

	cin >> input_num1;
	cin >> oper;
	cin >> input_num2;
	
	switch (oper)
	{
	case '+':
		result = doCalculation.add(input_num1, input_num2);
		break;
	case '-':
		result = doCalculation.sub(input_num1, input_num2);
		break;
	case '*':
		result = doCalculation.mul(input_num1, input_num2);
		break;
	case '/':
		result = doCalculation.div(input_num1, input_num2);
		break;
	default:
		cout << "�ùٸ� �����ڸ� �Է��ϼ���!" << endl;
		break;
	}

	cout << "Result : " << result << endl;

	return 0;
}