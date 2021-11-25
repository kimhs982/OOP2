#include "Person.h"
#include <iomanip>

int Person::count = 0;      //Q1

Person::Person(const int age, const char* name, const Job& job) :myJob(job) {
    setAge(age);
    setName(name);
    increaseCount();
}

Person::Person(const Person& copy) : myJob(copy.getMyJob()){
    setAge(copy.getAge());
    setName(copy.getName());
    increaseCount();
    //Q2
}

Person::~Person() {
    delete[] name;
    name = NULL;
}

void Person::setAge(const int age) {
    if (age > 0)
        this->age = age;
    else
        this->age = 1;
    //Q3
}

void Person::setName(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    //Q3
}

const int Person::getAge() const { return age; }
const char* Person::getName() const { return name; }
const Job Person::getMyJob() const { return myJob; }

void Person::display() {
    cout << setw(40) << setfill('=') << " " << endl;
    cout << "Current person count : " << count << endl;
    cout << "Age : " << '\t' << getAge() << endl;
    cout << "Name : " << '\t' << getName() << endl;
    cout << "Myjob " << endl;
    myJob.display();
    cout << setw(40) << setfill('=') << " ";
    cout << endl;
}

void Person::increaseCount() {
    count++;
}