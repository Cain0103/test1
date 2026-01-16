#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

void delay_ms(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

class VirtualSensor {
public:
    float readTemperature() {
        return 20.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    }
};

int main() {
    std::srand(std::time(nullptr));
    
    VirtualSensor mySensor;
    bool ledState = false;

    std::cout << "--- Запуск виртуального устройства ---" << std::endl;

    while (true) {
        float temp = mySensor.readTemperature();
        
        ledState = !ledState;

        std::cout << "[Сенсор]: " << temp << " C  |  ";
        
        if (ledState) {
            std::cout << "[LED]: ВКЛ (*)" << std::endl;
        } else {
            std::cout << "[LED]: ВЫКЛ ( )" << std::endl;
        }

        delay_ms(1000);
    }

    return 0;
}
