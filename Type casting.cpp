
#include <iostream>
#include <cstdint>
using namespace std;

class Person
{
public:
    virtual void display()
    {
        cout << "Person details" << endl;
    }

    virtual ~Person() {}
};

class Student : public Person
{
public:
    void display() override
    {
        cout << "Student Result System" << endl;
    }

    void showResult()
    {
        cout << "Student result is displayed." << endl;
    }
};

class Teacher : public Person
{
public:
    void display() override
    {
        cout << "Teacher details" << endl;
    }
};

int main()
{
    // 1. Implicit Casting
    int marks = 85;
    float totalMarks = marks;
    cout << "Implicit Casting: " << totalMarks << endl;

    // 2. Explicit Casting
    float percentage = 87.65;
    int p = (int)percentage;
    cout << "Explicit Casting: " << p << endl;

    // 3. static_cast
    int obtained = 425, total = 500;
    float result = static_cast<float>(obtained) / total * 100;
    cout << "Student Percentage: " << result << "%" << endl;

    // 4. dynamic_cast
    Person *p1 = new Student();
    Person *p2 = new Teacher();

    Student *s1 = dynamic_cast<Student*>(p1);

    if (s1 != NULL)
        s1->showResult();

    Student *s2 = dynamic_cast<Student*>(p2);

    if (s2 == NULL)
        cout << "Teacher cannot be cast to Student." << endl;

    delete p1;
    delete p2;

    // 5. const_cast
    int fee = 5000;
    const int *cp = &fee;
    int *fp = const_cast<int*>(cp);
    *fp = 6000;

    cout << "Updated College Fee: " << fee << endl;

    // 6. reinterpret_cast
    int studentID = 65;
    int *idPtr = &studentID;

    uintptr_t address = reinterpret_cast<uintptr_t>(idPtr);
    cout << "Student ID variable address: " << address << endl;

    char *ch = reinterpret_cast<char*>(idPtr);
    cout << "Reinterpreted value: " << *ch << endl;

    return 0;
}
