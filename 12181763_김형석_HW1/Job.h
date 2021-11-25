#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Job {
private:
    char* job_name;
    int salary;         //Salary is must greater than 0

public:
    Job(const char*, const int);
    Job(const Job&);
    ~Job();
    //Set functions
    void setJobname(const char*);
    void setSalary(const int);

    //Get functions
    const char* getJobname() const;
    const int getSalary() const;

    //Display function
    void display();
};