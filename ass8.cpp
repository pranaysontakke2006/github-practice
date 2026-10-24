#include <iostream>
#include <string>

class IVehicle {
public:
    virtual void changeGear(int g) = 0;
    virtual void speedUp(int inc) = 0;
    virtual void applyBrakes(int dec) = 0;
    virtual void displayStatus() const = 0;
    virtual ~IVehicle() {}
};

class Car : public IVehicle {
private:
    std::string m_model;
    int m_gear;
    int m_speed;

public:
    Car(std::string model) : m_model(model), m_gear(1), m_speed(0) {}

    void changeGear(int g) override {
        if (g >= 1 && g <= 6) {
            m_gear = g;
            std::cout << "Car (" << m_model << ") shifted to gear " << m_gear << "\n";
        } else {
            std::cout << "Car (" << m_model << "): Bad gear selection!\n";
        }
    }

    void speedUp(int inc) override {
        m_speed += inc;
        std::cout << "Car (" << m_model << ") speeding up by " << inc << ". Speed is now " << m_speed << "\n";
    }

    void applyBrakes(int dec) override {
        m_speed = (m_speed - dec >= 0) ? (m_speed - dec) : 0;
        std::cout << "Car (" << m_model << ") braking by " << dec << ". Speed is now " << m_speed << "\n";
    }

    void displayStatus() const override {
        std::cout << "[Car] Model: " << m_model << " | Gear: " << m_gear << " | Speed: " << m_speed << "\n";
    }
};

class Bike : public IVehicle {
private:
    std::string m_model;
    int m_gear;
    int m_speed;

public:
    Bike(std::string model) : m_model(model), m_gear(0), m_speed(0) {}

    void changeGear(int g) override {
        if (g >= 0 && g <= 5) {
            m_gear = g;
            std::cout << "Bike (" << m_model << ") shifted to gear " << m_gear << "\n";
        } else {
            std::cout << "Bike (" << m_model << "): Bad gear selection!\n";
        }
    }

    void speedUp(int inc) override {
        m_speed += inc;
        std::cout << "Bike (" << m_model << ") speeding up by " << inc << ". Speed is now " << m_speed << "\n";
    }

    void applyBrakes(int dec) override {
        m_speed = (m_speed - dec >= 0) ? (m_speed - dec) : 0;
        std::cout << "Bike (" << m_model << ") braking by " << dec << ". Speed is now " << m_speed << "\n";
    }

    void displayStatus() const override {
        std::cout << "[Bike] Model: " << m_model << " | Gear: " << m_gear << " | Speed: " << m_speed << "\n";
    }
};

class Bicycle : public IVehicle {
private:
    std::string m_brand;
    int m_gear;
    int m_speed;

public:
    Bicycle(std::string brand) : m_brand(brand), m_gear(1), m_speed(0) {}

    void changeGear(int g) override {
        if (g >= 1 && g <= 3) {
            m_gear = g;
            std::cout << "Bicycle (" << m_brand << ") shifted to gear " << m_gear << "\n";
        } else {
            std::cout << "Bicycle (" << m_brand << "): Bad gear selection!\n";
        }
    }

    void speedUp(int inc) override {
        m_speed += inc;
        std::cout << "Bicycle (" << m_brand << ") pedaling faster by " << inc << ". Speed is now " << m_speed << "\n";
    }

    void applyBrakes(int dec) override {
        m_speed = (m_speed - dec >= 0) ? (m_speed - dec) : 0;
        std::cout << "Bicycle (" << m_brand << ") braking by " << dec << ". Speed is now " << m_speed << "\n";
    }

    void displayStatus() const override {
        std::cout << "[Bicycle] Brand: " << m_brand << " | Gear: " << m_gear << " | Speed: " << m_speed << "\n";
    }
};

int main() {
    IVehicle* myVehicles[3];
    myVehicles[0] = new Car("Hatchback");
    myVehicles[1] = new Bike("Cruiser");
    myVehicles[2] = new Bicycle("Mountain Bike");

    for (int i = 0; i < 3; ++i) {
        std::cout << "\n--------------------\n";
        myVehicles[i]->changeGear(2);
        myVehicles[i]->speedUp(15);
        myVehicles[i]->applyBrakes(5);
        myVehicles[i]->displayStatus();
    }

    for (int i = 0; i < 3; ++i) {
        delete myVehicles[i];
    }

    return 0;
}
