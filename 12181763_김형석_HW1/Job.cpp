#include "Job.h"

Job::Job(const char* j_name, const int _salary) {
    setJobname(j_name);
    setSalary(_salary);
}

Job::Job(const Job& copy) {
    setJobname(copy.getJobname());
    setSalary(copy.getSalary());
    //Q4
}

Job::~Job() {
    delete[] job_name;
    job_name = NULL;
}

void Job::setJobname(const char* j_name) {
    job_name = new char[strlen(j_name) + 1];
    strcpy(job_name, j_name);
    //Q5
}

void Job::setSalary(const int salary) {
    if (salary > 0)
        this->salary = salary;
    else
        this->salary = 1;
    //Q5
}

const char* Job::getJobname() const { return job_name; }

const int Job::getSalary()const { return salary; }

void Job::display() {
    cout << "Job name : " << job_name << endl;
    cout << "Salary : $" << salary << endl;
    cout << endl;
}