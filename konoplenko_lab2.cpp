#include <iostream>
#include <string>

using namespace std;

// Клас Engine
class Engine {
private:
    int horsepower;
    string type;

public:
    // Конструктор за замовчуванням
    Engine() : horsepower(0), type("Unknown") {}

    // Конструктор з параметрами
    Engine(int hp, string t) : horsepower(hp), type(t) {}

    // Метод для відображення інформації про двигун
    void showEngineDetails() const {
        cout << "Engine Details:" << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Type: " << type << endl;
    }
};

// Клас Car
class Car {
private:
    string model;
    int year;
    Engine engine;
    static int totalCars;

public:
    // Конструктор за замовчуванням
    Car() : model("Unknown"), year(0), engine() {
        totalCars++;
    }

    // Конструктор з параметрами
    Car(string m, int y, int hp, string t) : model(m), year(y), engine(hp, t) {
        totalCars++;
    }

    // Конструктор копіювання
    Car(const Car &c) : model(c.model), year(c.year), engine(c.engine) {
        totalCars++;
    }

    // Деструктор
    ~Car() {
        cout << "Car object (" << model << ") is destroyed." << endl;
        totalCars--;
    }

    // Метод start
    void start() const {
        cout << model << " is started." << endl;
    }

    // Метод stop
    void stop() const {
        cout << model << " is stopped." << endl;
    }

    // Метод для відображення деталей автомобіля
    void showDetails() const {
        cout << "Car Details:" << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        engine.showEngineDetails();
    }

    // Статичний метод для отримання кількості об'єктів
    static int getTotalCars() {
        return totalCars;
    }
};

// Ініціалізація статичного поля
int Car::totalCars = 0;

int main() {
    // Створення об'єктів
    Car car1; // Використання конструктора за замовчуванням
    Car car2("Toyota Camry", 2020, 200, "Gasoline"); // Використання конструктора з параметрами
    Car car3 = car2; // Використання конструктора копіювання

    // Виведення інформації про машини
    car1.showDetails();
    car2.showDetails();
    car3.showDetails();

    // Виклик методів start і stop
    car2.start();
    car2.stop();

    // Отримання загальної кількості об'єктів
    cout << "Total cars created: " << Car::getTotalCars() << endl;

    return 0;
}
