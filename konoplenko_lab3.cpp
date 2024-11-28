#include <iostream>
#include <string>

using namespace std;

// Перелік типів двигунів
enum class EngineType { Petrol, Diesel, Electric };

// Перелік типів автомобілів
enum class CarType { Sedan, SUV, Hatchback };

// Клас Engine
class Engine {
private:
    unsigned horsepower;
    EngineType type;

public:
    // Конструктор за замовчуванням
    Engine() : horsepower(0), type(EngineType::Petrol) {}

    // Конструктор з параметрами
    Engine(unsigned hp, EngineType t) : horsepower(hp), type(t) {}

    // Метод для виведення інформації про двигун
    void showDetails() const {
        cout << "Engine Details:" << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Type: " << getType() << endl;
    }

    // Геттер для типу двигуна
    string getType() const {
        switch (type) {
            case EngineType::Petrol: return "Petrol";
            case EngineType::Diesel: return "Diesel";
            case EngineType::Electric: return "Electric";
            default: return "Unknown";
        }
    }
};

// Клас Car
class Car {
private:
    string model;
    int year;
    CarType type;
    Engine engine;

public:
    // Конструктор за замовчуванням
    Car() : model("Unknown"), year(1985), type(CarType::Sedan), engine() {}

    // Конструктор з параметрами
    Car(string m, int y, CarType t, unsigned hp, EngineType et)
        : model(m), type(t), engine(hp, et) {
        setYear(y);
    }

    // Геттер для моделі
    string getModel() const {
        return model;
    }

    // Сеттер для моделі
    void setModel(const string& m) {
        model = m;
    }

    // Геттер для року
    int getYear() const {
        return year;
    }

    // Сеттер для року з перевіркою
    void setYear(int y) {
        if (y > 1985) {
            year = y;
        } else {
            cout << "Invalid year. Setting default value (1985)." << endl;
            year = 1985;
        }
    }

    // Геттер для типу автомобіля
    string getType() const {
        switch (type) {
            case CarType::Sedan: return "Sedan";
            case CarType::SUV: return "SUV";
            case CarType::Hatchback: return "Hatchback";
            default: return "Unknown";
        }
    }

    // Метод для відображення деталей автомобіля
    void showDetails() const {
        cout << "Car Details:" << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Type: " << getType() << endl;
        engine.showDetails();
    }
};

int main() {
    // Створення об'єктів з використанням різних конструкторів
    Car car1; // Конструктор за замовчуванням
    Car car2("Toyota Camry", 2020, CarType::Sedan, 200, EngineType::Petrol); // Конструктор з параметрами
    Car car3("Tesla Model S", 2022, CarType::Hatchback, 500, EngineType::Electric);

    // Виведення деталей автомобілів
    car1.showDetails();
    cout << endl;

    car2.showDetails();
    cout << endl;

    car3.showDetails();
    cout << endl;

    // Демонстрація роботи геттерів і сетерів
    car1.setModel("Honda Civic");
    car1.setYear(1980); // Некоректний рік
    car1.setYear(1995); // Коректний рік

    cout << "Updated Car 1 Details:" << endl;
    car1.showDetails();

    return 0;
}
