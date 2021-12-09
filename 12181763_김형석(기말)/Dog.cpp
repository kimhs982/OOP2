#include "Dog.h"

void Dog::printStatus()
{
	cout << "Cat information" << endl;
	cout << "[Breed of Dog] : " << getBreed() << endl;
	cout << "[Status]\n";
	cout << "Name : " << getName() << " Age : " << getAge() << endl;
	cout << "Happiness : " << getHappiness() << " Sickness : " << getSickness() << endl << endl;
}

Dog::Dog(int inAge, string inName, int inSick, int inHap, string inBreed) : Animal(inAge, inName, inSick, inHap)
{
	setBreed(inBreed);
}

Dog::~Dog()
{
	cout << Animal::getName() << " said : Good bye!" << endl;
}

void Dog::Play()
{
	cout << Animal::getName() << " running in the front yard!!\n"
		<< "Happiness +10 Sickness +5\n\n";
	setHappiness(getHappiness() + 10);
	setSickness(getSickness() + 5);
}

void Dog::Sleep()
{
	cout << Animal::getName() << " is sleeping on a pet bed...Zzzzzz\n"
		<< "Happiness +2 Sickness -4\n\n";
	setHappiness(getHappiness() + 2);
	setSickness(getSickness() - 4);
}

void Dog::Eat()
{
	cout << Animal::getName() << "is eat the dog food!!\n"
		<< "Happiness +15 Sickness -4\n\n";
	setHappiness(getHappiness() + 15);
	setSickness(getSickness() + -4);
}

void Dog::setBreed(string inBreed)
{
	int breedLen = inBreed.length();
	if (breedLen <= 30)
		breedOfDog = inBreed;
	else
	{
		cout << "breedOfDog은 30자 이하여야 합니다." << endl;
		breedOfDog = inBreed.substr(0, 30);
	}
}

const string Dog::getBreed() const
{
	return breedOfDog;
}

istream& operator>>(istream& input, Dog& inDog)
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
	cout << "Breed of dog : ";
	input >> inBreed;

	inDog.setAge(inAge);
	inDog.setName(inName);
	inDog.setSickness(inSick);
	inDog.setHappiness(inHap);
	inDog.setBreed(inBreed);

	return input;
}

ostream& operator<<(ostream& output, Dog& inDog)
{
	inDog.printStatus();

	return output;
}