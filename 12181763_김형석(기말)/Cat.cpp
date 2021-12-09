#include "Cat.h"

void Cat::printStatus()
{
	cout << "Cat information" << endl;
	cout << "[Breed of Cat] : " << getBreed() << endl;
	cout << "[Status]\n";
	cout << "Name : " << getName() << " Age : " << getAge() << endl;
	cout << "Happiness : " << getHappiness() << " Sickness : " << getSickness() << endl << endl;
}

Cat::Cat(int inAge, string inName, int inSick, int inHap, string inBreed) : Animal(inAge, inName, inSick, inHap)
{
	setBreed(inBreed);
}

Cat::~Cat()
{
	cout << Animal::getName() << " said : Good bye!" << endl;
}

void Cat::Play()
{
	cout << Animal::getName() << " playing in the house!!\n"
		<< "Happiness +5 Sickness +3\n\n";
	
	setSickness(getSickness() + 3);
}

void Cat::Sleep()
{
	cout << Animal::getName() << " is sleeping on a my bed...Zzzzzz\n"
		<< "Happiness +3 Sickness -4\n\n";
	setHappiness(getHappiness() + 3);
	setSickness(getSickness() - 4);
}

void Cat::Eat()
{
	cout << Animal::getName() << "is eat the cat food!!\n"
		<< "Happiness +10 Sickness -2\n\n";
	setHappiness(getHappiness() + 10);
	setSickness(getSickness() - 2);

}

void Cat::setBreed(string inBreed)
{
	int breedLen = inBreed.length();
	if (breedLen <= 30)
		breedOfCat = inBreed;
	else
	{
		cout << "breedOfCat은 30자 이하여야 합니다." << endl;
		breedOfCat = inBreed.substr(0, 30);
	}
}

const string Cat::getBreed() const
{
	return breedOfCat;
}

istream& operator>>(istream& input, Cat& inCat)
{
	int inAge, inSick, inHap;
	string inName, inBreed;

	cout << "Dog information" << endl;
	cout << "Age : ";
	input >> inAge;
	cout << "Name : ";
	input >> inName;
	cout << "Sickness : ";
	input >> inSick;
	cout << "Happiness : ";
	input >> inHap;
	cout << "Breed of cat : ";
	input >> inBreed;

	inCat.setAge(inAge);
	inCat.setName(inName);
	inCat.setSickness(inSick);
	inCat.setHappiness(inHap);
	inCat.setBreed(inBreed);

	return input;
}

ostream& operator<<(ostream& output, Cat& inCat)
{
	inCat.printStatus();

	return output;
}