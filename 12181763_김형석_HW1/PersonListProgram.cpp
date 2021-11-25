#include "Person.h"

int main() {
    Job job1("Engineer", 10000);
    Job job2("Professor", 20000);
    Job job3(job2);
    cout << "Job 1 info" << endl;
    job1.display();
    cout << "Job 2 info" << endl;
    job2.display();
    cout << "Job 3 info" << endl;
    job3.display();


    //job3 º¯°æ
    int new_salary = 0;
    cout << "Enter the new salary for job3 : ";
    cin >> new_salary;
    job3.setSalary(new_salary);
    cout << endl;


    Person person1(28, "Seo", job1);
    Person person2(20, "John", job2);
    Person person3(30, "James", job3);

    Person dummy_person(person2);
    dummy_person.setName("None");
    dummy_person.setAge(1);

    //Show people information
    person1.display();
    person2.display();
    person3.display();
    dummy_person.display();

    return 0;
}