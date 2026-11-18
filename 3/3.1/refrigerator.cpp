#include "refrigerator.hpp"
#include <cmath>
#include <iostream>


Refrigerator::Refrigerator() {
    AmbientTemp = 22.0;
    Power = false;
    CurrentTemp = AmbientTemp;
    TargetTemp = -5.0;
    DoorOpen = false;
    Alarm = false;
    CoolingTime = 0.0;
    std::cout << "[Викликано конструктор за замовчуванням]\n";
}


Refrigerator::Refrigerator(double ambient, double target, bool power) {
    AmbientTemp = ambient;
    if (target < -25.0) target = -25.0;
    if (target > 0.0) target = 0.0;
    TargetTemp = target;
    DoorOpen = false;
    Alarm = false;
    Power = power;

    if (Power) {
        double diff = AmbientTemp - TargetTemp;
        CoolingTime = (diff > 1.0) ? 24.0 * std::log(diff) : 0.0;
        CurrentTemp = TargetTemp;
    } else {
        CurrentTemp = AmbientTemp;
        CoolingTime = 0.0;
    }
    std::cout << "[Викликано конструктор ініціалізації]\n";
}


Refrigerator::Refrigerator(const Refrigerator& other) {
    Power = other.Power;
    CurrentTemp = other.CurrentTemp;
    TargetTemp = other.TargetTemp;
    AmbientTemp = other.AmbientTemp;
    DoorOpen = other.DoorOpen;
    Alarm = other.Alarm;
    CoolingTime = other.CoolingTime;
    std::cout << "[Викликано конструктор копіювання]\n";
}


Refrigerator::~Refrigerator() {
    std::cout << "[Викликано деструктор: об'єкт Refrigerator знищено]\n";
}

void Refrigerator::TurnOn() {
    Power = true;
    if (!DoorOpen) {
        double diff = AmbientTemp - TargetTemp;
        CoolingTime = (diff > 1.0) ? 24.0 * std::log(diff) : 0.0;
        CurrentTemp = TargetTemp;
        Alarm = false;
    } else {
        CurrentTemp = AmbientTemp;
        Alarm = true;
        CoolingTime = 0.0;
    }
}

void Refrigerator::TurnOff() {
    Power = false;
    Alarm = false;
    CurrentTemp = AmbientTemp;
    CoolingTime = 0.0;
}

void Refrigerator::SetTargetTemp(double newTemp) {
    
    if (newTemp < -25.0) newTemp = -25.0;
    if (newTemp > 0.0) newTemp = 0.0;
    TargetTemp = newTemp;

    if (Power) {
        if (!DoorOpen) {
            if (CurrentTemp > TargetTemp) {
                double diff = CurrentTemp - TargetTemp;
                CoolingTime = (diff > 1.0) ? 24.0 * std::log(diff) : 0.0;
            } else {
                CoolingTime = 0.0;
            }
            CurrentTemp = TargetTemp;
        } else {
            CurrentTemp = AmbientTemp;
            Alarm = true;
            CoolingTime = 0.0;
        }
    }
}

void Refrigerator::OpenDoor() {
    DoorOpen = true;
    if (CurrentTemp < AmbientTemp) {
        CurrentTemp += 0.05 * (AmbientTemp - CurrentTemp);
    }
}

void Refrigerator::CloseDoor() {
    DoorOpen = false;
    Alarm = false;
    if (Power) {
        double diff = AmbientTemp - TargetTemp;
        CoolingTime = (diff > 1.0) ? 24.0 * std::log(diff) : 0.0;
        CurrentTemp = TargetTemp;
    }
}