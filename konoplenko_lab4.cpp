#include <iostream>
#include <string>

using namespace std;

// Базовий клас Vehicle
class Vehicle {
protected:
    string brand;
    int year;

public:
    // Конструктор з параметрами
    Vehicle(string b, int y) : brand(b), year(y) {}

    // Деструктор
    virtual ~Vehicle() {
        cout << "Destroying vehicle" << endl;
    }

    // Метод start
    virtual void start() const {
        cout << "Starting vehicle" << endl;
    }

    // Метод showDetails
    virtual void showDetails() const {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

// Похідний клас Car
class Car : public Vehicle {
private:
    string model;

public:
    // Конструктор з параметрами
    Car(string b, int y, string m) : Vehicle(b, y), model(m) {}

    // Деструктор
    ~Car() override {
        cout << "Destroying car" << endl;
    }

    // Метод start
    void start() const override {
        cout << "Starting car" << endl;
    }

    // Метод showDetails
    void showDetails() const override {
        Vehicle::showDetails();
        cout << "Model: " << model << endl;
    }
};

// Похідний клас Motorcycle
class Motorcycle : public Vehicle {
private:
    string type;

public:
    // Конструктор з параметрами
    Motorcycle(string b, int y, string t) : Vehicle(b, y), type(t) {}

    // Деструктор
    ~Motorcycle() override {
        cout << "Destroying motorcycle" << endl;
    }

    // Метод start
    void start() const override {
        cout << "Starting motorcycle" << endl;
    }

    // Метод showDetails
    void showDetails() const override {
        Vehicle::showDetails();
        cout << "Type: " << type << endl;
    }
};

int main() {
    // Створення об'єктів
    Car car("Toyota", 2020, "Camry");
    Motorcycle motorcycle("Yamaha", 2019, "Sport");

    // Виклик методів для Car
    car.start();
    car.showDetails();
    cout << endl;

    // Виклик методів для Motorcycle
    motorcycle.start();
    motorcycle.showDetails();
    cout << endl;

    // Деструктори викликаються автоматично
    return 0;
}

