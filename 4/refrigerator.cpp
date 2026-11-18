#include "refrigerator.hpp"
#include <cmath>

Refrigerator::Refrigerator(double ambient) {
    AmbientTemp = ambient;
    Power = false;
    CurrentTemp = AmbientTemp;
    TargetTemp = -5.0;
    DoorOpen = false;
    Alarm = false;
    CoolingTime = 0.0;
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


Refrigerator& Refrigerator::operator=(double newTemp) {
    SetTargetTemp(newTemp);
    return *this;
}


Refrigerator& operator<<(Refrigerator& fridge, bool open) {
    if (open) {
        fridge.OpenDoor();
    } else {
        fridge.CloseDoor();
    }
    return fridge;
}