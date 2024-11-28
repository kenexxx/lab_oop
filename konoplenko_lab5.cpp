#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Створення базового класу Vehicle
class Vehicle {
protected:
    string brand;

public:
    Vehicle(string br) : brand(br) {}
    virtual ~Vehicle() {}

    virtual void start() {
        cout << "Запуск транспортного засобу марки " << brand << endl;
    }
};

// 2. Клас GasolineCar
class GasolineCar : virtual public Vehicle {
protected:
    string fuelType;

public:
    GasolineCar(string br, string fuel) : Vehicle(br), fuelType(fuel) {}

    void start() override {
        cout << "Запуск автомобіля з двигуном внутрішнього згоряння (" 
             << fuelType << "), марка: " << brand << endl;
    }
};

// Клас ElectricCar
class ElectricCar : virtual public Vehicle {
protected:
    int batteryCapacity;

public:
    ElectricCar(string br, int battery) : Vehicle(br), batteryCapacity(battery) {}

    void start() override {
        cout << "Запуск електромобіля, марка: " << brand 
             << ", ємність акумулятора: " << batteryCapacity << " kWh" << endl;
    }
};

// 3. Клас HybridCar
class HybridCar : public GasolineCar, public ElectricCar {
public:
    HybridCar(string br, string fuel, int battery) 
        : Vehicle(br), GasolineCar(br, fuel), ElectricCar(br, battery) {}

    void start() override {
        cout << "Запуск гібридного автомобіля, марка: " << brand 
             << ", тип палива: " << fuelType 
             << ", ємність акумулятора: " << batteryCapacity << " kWh" << endl;
    }
};

// 4. Перетворення типів
void demonstrateCasting(HybridCar& hybridCar) {
    // Перетворення за допомогою static_cast
    Vehicle* vehiclePtr = static_cast<Vehicle*>(&hybridCar);
    vehiclePtr->start();

    GasolineCar* gasolinePtr = static_cast<GasolineCar*>(&hybridCar);
    gasolinePtr->start();

    ElectricCar* electricPtr = static_cast<ElectricCar*>(&hybridCar);
    electricPtr->start();

    // Перетворення за допомогою dynamic_cast
    if (Vehicle* dynamicVehicle = dynamic_cast<Vehicle*>(&hybridCar)) {
        dynamicVehicle->start();
    }

    if (GasolineCar* dynamicGasoline = dynamic_cast<GasolineCar*>(&hybridCar)) {
        dynamicGasoline->start();
    }

    if (ElectricCar* dynamicElectric = dynamic_cast<ElectricCar*>(&hybridCar)) {
        dynamicElectric->start();
    }
}

// 5. Динамічне зв’язування
void demonstrateDynamicBinding() {
    vector<Vehicle*> vehicles;

    GasolineCar gasolineCar("Toyota", "Бензин");
    ElectricCar electricCar("Tesla", 100);
    HybridCar hybridCar("Prius", "Бензин", 50);

    vehicles.push_back(&gasolineCar);
    vehicles.push_back(&electricCar);
    vehicles.push_back(&hybridCar);

    for (Vehicle* v : vehicles) {
        v->start();
    }
}

int main() {
    // Демонстрація роботи
    cout << "=== Перетворення типів ===" << endl;
    HybridCar hybrid("Prius", "Бензин", 50);
    demonstrateCasting(hybrid);

    cout << "\n=== Динамічне зв’язування ===" << endl;
    demonstrateDynamicBinding();

    return 0;
}
