#include "Animal.h"

Animal::Animal(int inAge, string inName, int inSick, int inHap)
{
	setAge(inAge);
	setName(inName);
	setSickness(inSick);
	setHappiness(inHap);
}

Animal::Animal(Animal& copy)
{
	setAge(copy.getAge());
	setName(copy.getName());
	setSickness(copy.getSickness());
	setHappiness(copy.getHappiness());
}

Animal::~Animal() {}

void Animal::printStatus() {}

void Animal::setAge(int inAge)
{
	if (inAge > 0)
		Age = inAge;
	else
		Age = 1;
}

void Animal::setName(string inName)
{
	int nameLen = inName.length();
	if (nameLen <= 20)
		Name = inName;
	else
	{
		cout << "Name은 20자 이하여야 합니다." << endl;
		Name = inName.substr(0, 20);
	}
}

void Animal::setSickness(int inSick)
{
	if ((inSick >= 0) && (inSick <= 99))
		Sickness = inSick;
	else if (inSick > 99)
	{
		cout << getName() << " have to go to the animal hospital...!" << endl << endl;
		Sickness = 99;
	}
	else
		Sickness = 0;
}

void Animal::setHappiness(int inHap)
{
	if ((inHap > 0) && (inHap <= 100))
		Happiness = inHap;
	else if (inHap > 100)
	{
		Happiness = 100;
	}
	else
		Happiness = 1;
}

int Animal::getAge() const
{
	return Age;
}

const string Animal::getName() const
{
	return Name;
}

int Animal::getSickness() const
{
	return Sickness;
}

int Animal::getHappiness() const
{
	return Happiness;
}