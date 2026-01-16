#include <iostream>
#include <thread> // Для пауз (sleep)
#include <chrono> // Для времени
#include <cstdlib> // Для генерации случайных чисел (симуляция датчика)
#include <ctime>

// Симуляция функции задержки (аналог delay)
void delay_ms(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Класс для виртуального датчика
class VirtualSensor {
public:
    float readTemperature() {
        // Возвращает случайное число от 20.0 до 30.0
        return 20.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    }
};

int main() {
    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));
    
    VirtualSensor mySensor;
    bool ledState = false;

    std::cout << "--- Запуск виртуального устройства ---" << std::endl;

    while (true) {
        // 1. Симуляция работы датчика
        float temp = mySensor.readTemperature();
        
        // 2. Логика светодиода (переключение)
        ledState = !ledState;

        // 3. Вывод статуса в консоль (Виртуальный дисплей/Светодиод)
        std::cout << "[Сенсор]: " << temp << " C  |  ";
        
        if (ledState) {
            std::cout << "[LED]: ВКЛ (*)" << std::endl;
        } else {
            std::cout << "[LED]: ВЫКЛ ( )" << std::endl;
        }

        // Задержка 1 секунда
        delay_ms(1000);
    }

    return 0;
}