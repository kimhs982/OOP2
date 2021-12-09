#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    int Age;
    string Name;
    int Sickness;
    int Happiness;

public:
    Animal(int = 1, string = "None", int = 0, int = 50);
    Animal(Animal&);
    ~Animal();
    virtual void Eat()=0;               // 순수 가상함수로 변경
    virtual void Play()=0;              // 순수 가상함수로 변경
    virtual void Sleep()=0;             // 순수 가상함수로 변경


    void printStatus();

    //set함수, get 함수
    void setAge(int);
    void setName(string);
    void setSickness(int);
    void setHappiness(int);

    int getAge() const;
    const string getName() const;
    int getSickness() const;
    int getHappiness() const;

};