#include <iostream>
#include <iomanip>
#include <windows.h>
#include "refrigerator.hpp"

using namespace std;

void PrintState(const Refrigerator& fridge) {
    cout << "\n--- ПОТОЧНИЙ СТАН ХОЛОДИЛЬНИКА ---\n";
    cout << "Живлення:              " << (fridge.GetPower() ? "УВІМКНЕНО" : "ВИМКНЕНО") << "\n";
    cout << "Дверця:                " << (fridge.GetDoorOpen() ? "ВІДЧИНЕНА" : "ЗАЧИНЕНА") << "\n";
    cout << "Аварійний сигнал:      " << (fridge.GetAlarm() ? "УВІМКНЕНО (!)" : "ВИМКНЕНО") << "\n";
    cout << fixed << setprecision(2);
    cout << "Поточна температура:   " << fridge.GetCurrentTemp() << " °C\n";
    cout << "Задана температура:    " << fridge.GetTargetTemp() << " °C\n";
    cout << "Темп. середовища:      " << fridge.GetAmbientTemp() << " °C\n";
    cout << "Час охолодження (t):   " << fridge.GetCoolingTime() << " хв\n";
    cout << "----------------------------------\n";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Refrigerator myFridge(22.0); 
    int choice = -1;

    while (choice != 0) {
        PrintState(myFridge);
        cout << "Оберіть дію:\n";
        cout << "1 - Увімкнути холодильник\n";
        cout << "2 - Вимкнути холодильник\n";
        cout << "3 - Встановити цільову температуру (-25 ... 0 °C)\n";
        cout << "4 - Відчинити дверцю\n";
        cout << "5 - Зачинити дверцю\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                myFridge.TurnOn();
                break;
            case 2:
                myFridge.TurnOff();
                break;
            case 3: {
                double t;
                cout << "Введіть цільову температуру (-25 ... 0): ";
                cin >> t;
                myFridge.SetTargetTemp(t);
                break;
            }
            case 4:
                myFridge.OpenDoor();
                break;
            case 5:
                myFridge.CloseDoor();
                break;
            case 0:
                cout << "Роботу завершено.\n";
                break;
            default:
                cout << "Невірний пункт меню!\n";
        }
    }

    return 0;
}
