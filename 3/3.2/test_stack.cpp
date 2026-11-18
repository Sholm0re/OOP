#include <iostream>
#include <iomanip>
#include <windows.h>
#include "stack.hpp"

using namespace std;

void RunMenu(Stack& st) {
    int choice = -1;

    while (choice != 0) {
        st.Print();
        cout << "Оберіть дію:\n";
        cout << "1 - Додати новий елемент\n";
        cout << "2 - Видалити елемент\n";
        cout << "3 - Знайти суму елементів\n";
        cout << "4 - Вивести стек на екран\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double val;
                cout << "Введіть дійсне число: ";
                cin >> val;
                if (st.Push(val)) {
                    cout << "Елемент додано.\n";
                }
                break;
            }
            case 2: {
                double removed;
                if (st.Pop(removed)) {
                    cout << "Видалено елемент: " << removed << "\n";
                }
                break;
            }
            case 3:
                cout << fixed << setprecision(2);
                cout << "Сума елементів стеку: " << st.Sum() << "\n";
                break;
            case 4:
                st.Print();
                break;
            case 0:
                cout << "Роботу завершено.\n";
                break;
            default:
                cout << "Невірний пункт меню!\n";
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int ctorChoice;
    cout << "Оберіть конструктор для створення стеку:\n";
    cout << "1 - За замовчуванням (порожній стек)\n";
    cout << "2 - З 1 аргументом (вносить одне задане значення)\n";
    cout << "3 - З 2 аргументами (заповнює з дійсного масиву)\n";
    cout << "4 - З 3 аргументами (вносить значення задану кількість разів)\n";
    cout << "5 - Копіювання (на основі тестового стеку)\n";
    cout << "Ваш вибір: ";
    cin >> ctorChoice;

    if (ctorChoice == 2) {
        double val;
        cout << "Введіть початкове значення: ";
        cin >> val;
        Stack st(val);
        RunMenu(st);
    } else if (ctorChoice == 3) {
        int n;
        cout << "Введіть кількість елементів у масиві: ";
        cin >> n;
        double* arr = new double[n];
        for (int i = 0; i < n; ++i) {
            cout << "Елемент [" << i << "]: ";
            cin >> arr[i];
        }
        Stack st(n, arr);
        delete[] arr;
        RunMenu(st);
    } else if (ctorChoice == 4) {
        int cap, count;
        double val;
        cout << "Введіть місткість стеку (1-й аргумент): ";
        cin >> cap;
        cout << "Введіть значення елемента (2-й аргумент): ";
        cin >> val;
        cout << "Введіть кількість повторень (3-й аргумент): ";
        cin >> count;
        Stack st(cap, val, count);
        RunMenu(st);
    } else if (ctorChoice == 5) {
        double sampleArr[] = {1.5, 2.5, 3.0};
        Stack sample(3, sampleArr);
        Stack st(sample);
        RunMenu(st);
    } else {
        Stack st;
        RunMenu(st);
    }

    return 0;
}