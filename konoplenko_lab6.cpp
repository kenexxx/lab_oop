#include <iostream>
#include <string>
using namespace std;

// 1. Абстрактний клас Vehicle
class Vehicle {
protected:
    string vehicleType;
    static int vehicleCount; // Статична змінна для підрахунку

public:
    Vehicle() {
        vehicleCount++;
    }
    virtual ~Vehicle() {}

    // Чисті віртуальні функції
    virtual void start() = 0;
    virtual string getFuelType() = 0;
    virtual int getSpeed() = 0;

    // Метод для відображення типу транспортного засобу
    void showVehicleType() {
        cout << "Тип транспортного засобу: " << vehicleType << endl;
    }

    // Статична функція для отримання кількості транспортних засобів
    static int getVehicleCount() {
        return vehicleCount;
    }
};

// Ініціалізація статичної змінної
int Vehicle::vehicleCount = 0;

// 2. Клас Car
class Car : public Vehicle {
private:
    string fuelType;
    int speed;

public:
    Car(string fuel, int spd) : fuelType(fuel), speed(spd) {
        vehicleType = "Car";
    }

    void start() override {
        cout << "Car запускається." << endl;
    }

    string getFuelType() override {
        return fuelType;
    }

    int getSpeed() override {
        return speed;
    }

    void showFuelInfo() {
        cout << "Тип палива для Car: " << fuelType << endl;
    }
};

// 3. Клас Bicycle
class Bicycle : public Vehicle {
private:
    int speed;

public:
    Bicycle(int spd) : speed(spd) {
        vehicleType = "Bicycle";
    }

    void start() override {
        cout << "Bicycle запускається." << endl;
    }

    string getFuelType() override {
        return "No fuel";
    }

    int getSpeed() override {
        return speed;
    }
};

// 4. Клас Motorcycle
class Motorcycle : public Vehicle {
private:
    string fuelType;
    int speed;

public:
    Motorcycle(string fuel, int spd) : fuelType(fuel), speed(spd) {
        vehicleType = "Motorcycle";
    }

    void start() override {
        cout << "Motorcycle запускається." << endl;
    }

    string getFuelType() override {
        return fuelType;
    }

    int getSpeed() override {
        return speed;
    }

    void showFuelInfo() {
        cout << "Тип палива для Motorcycle: " << fuelType << endl;
    }
};

// 5. Головна функція main
int main() {
    // Створення об'єктів
    Car car("Бензин", 120);
    Bicycle bicycle(25);
    Motorcycle motorcycle("Бензин", 100);

    // Використання вказівників на базовий клас
    Vehicle* vehicles[] = { &car, &bicycle, &motorcycle };

    for (Vehicle* v : vehicles) {
        v->start();
        v->showVehicleType();
        cout << "Тип палива: " << v->getFuelType() << endl;
        cout << "Швидкість: " << v->getSpeed() << " км/год" << endl;
        cout << "--------------------------" << endl;
    }

    // Підрахунок транспортних засобів
    cout << "Кількість створених транспортних засобів: " 
         << Vehicle::getVehicleCount() << endl;

    return 0;
}