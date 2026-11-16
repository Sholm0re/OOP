#ifndef REFRIGERATOR_HPP
#define REFRIGERATOR_HPP

class Refrigerator {
private:
    bool Power;           // Стан живлення (увімкн./вимкн.)
    double CurrentTemp;   // Поточна температура, °C
    double TargetTemp;    // Задана (цільова) температура (-25 ... 0 °C)
    double AmbientTemp;   // Температура навколишнього середовища, °C
    bool DoorOpen;        // Стан дверці (true - відчинена, false - зачинена)
    bool Alarm;           // Сигнал аварійного стану (увімкн./вимкн.)
    double CoolingTime;   // Останній розрахований час охолодження, хв

public:
    // Конструктор за замовчуванням
    Refrigerator(double ambient = 22.0);

    // Основні методи згідно з варіантом
    void TurnOn();
    void TurnOff();
    void SetTargetTemp(double newTemp);
    void OpenDoor();
    void CloseDoor();

    // Методи отримання значень властивостей (Getters)
    bool GetPower() const { return Power; }
    double GetCurrentTemp() const { return CurrentTemp; }
    double GetTargetTemp() const { return TargetTemp; }
    double GetAmbientTemp() const { return AmbientTemp; }
    bool GetDoorOpen() const { return DoorOpen; }
    bool GetAlarm() const { return Alarm; }
    double GetCoolingTime() const { return CoolingTime; }
};

#endif