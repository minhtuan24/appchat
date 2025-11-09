#include "oop2.h"

void Student::input()
{
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap tuoi: ";
    cin >> age;
    cout << "Nhap diem: ";
    cin >> score;
    cin.ignore();
}

int main()
{
    Student s;
    s.input();
    s.display();
    cout << (s.isPass() ? "Dat" : "Khong dat") << endl;

    Student s2;
    s2.input();
    s2.display();
    cout << (s2.isPass() ? "Dat" : "Khong dat") << endl;
}
