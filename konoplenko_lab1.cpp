#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    float grade;

public:
    // Конструктор для ініціалізації полів
    Student(string n, int a, float g) : name(n), age(a), grade(g) {}

    // Метод для виводу інформації
    void displayInfo() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // Створення двох об’єктів класу Student
    Student student1("Alice", 20, 4.5);
    Student student2("Bob", 22, 4.2);

    // Виведення інформації про студентів
    student1.displayInfo();
    student2.displayInfo();

    return 0;
}
