#ifndef REFRIGERATOR_HPP
#define REFRIGERATOR_HPP

class Refrigerator {
private:
    bool Power;           
    double CurrentTemp;   
    double TargetTemp;    
    double AmbientTemp;   
    bool DoorOpen;        
    bool Alarm;           
    double CoolingTime;   

public:
    
    Refrigerator();

    
    Refrigerator(double ambient, double target, bool power = false);

    
    Refrigerator(const Refrigerator& other);

    
    ~Refrigerator();

    
    void TurnOn();
    void TurnOff();
    void SetTargetTemp(double newTemp);
    void OpenDoor();
    void CloseDoor();

    
    bool GetPower() const { return Power; }
    double GetCurrentTemp() const { return CurrentTemp; }
    double GetTargetTemp() const { return TargetTemp; }
    double GetAmbientTemp() const { return AmbientTemp; }
    bool GetDoorOpen() const { return DoorOpen; }
    bool GetAlarm() const { return Alarm; }
    double GetCoolingTime() const { return CoolingTime; }
};

#endif