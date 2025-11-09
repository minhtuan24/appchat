// g++ -std=c++17 src/oop2.cpp -o oop2

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    float score;

public:
    void input();

    void display()
    {
        cout << "Ten: " << name << ", Tuoi: " << age << ", Diem: " << score << endl;
    }

    bool isPass()
    {
        return score >= 5;
    }
};
