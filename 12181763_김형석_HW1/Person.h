#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Job.h"

class Person {
private:
    int age;
    char* name;
    Job myJob;

public:
    static int count;  //Q1   

    //Constructors(user defined, copy constructor) and destructor
    Person(const int, const char*, const Job&);
    Person(const Person&);
    ~Person();

    //Set functions
    void setAge(const int);
    void setName(const char*);

    //Get functions
    const int getAge()const;
    const char* getName() const;
    const Job getMyJob() const;

    //Display function
    void display();

    //Count function
    static void increaseCount(); //Q1
};