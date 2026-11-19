#include <iostream>
#include <iomanip>
#include <windows.h>
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

void TestStack(Stack& st) {
    int choice = -1;
    while (choice != 0) {
        st.Print();
        cout << "Меню класу \"Стек\":\n";
        cout << "1 - Записати значення на вершину (Push)\n";
        cout << "2 - Вийняти значення вершини (Pop)\n";
        cout << "3 - Прочитати значення вершини без вийняття (Peek)\n";
        cout << "4 - Змінити розмір сховища (Resize - метод базового класу)\n";
        cout << "0 - Назад у головне меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double val;
                cout << "Введіть значення: ";
                cin >> val;
                if (st.Push(val)) cout << "Значення записано на вершину.\n";
                break;
            }
            case 2: {
                double val;
                if (st.Pop(val)) cout << "Вийнято значення вершини: " << val << "\n";
                break;
            }
            case 3: {
                double val;
                if (st.Peek(val)) cout << "Значення на вершині: " << val << "\n";
                else cout << "Стек порожній.\n";
                break;
            }
            case 4: {
                int newSize;
                cout << "Введіть новий розмір сховища: ";
                cin >> newSize;
                if (st.Resize(newSize)) cout << "Розмір змінено.\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "Невірний пункт меню!\n";
        }
    }
}

void TestQueue(Queue& q) {
    int choice = -1;
    while (choice != 0) {
        q.Print();
        cout << "Меню класу \"Черга\":\n";
        cout << "1 - Додати елемент у чергу (Enqueue)\n";
        cout << "2 - Прочитати значення з контрольної точки\n";
        cout << "3 - Прочитати значення з кінця черги\n";
        cout << "4 - Змінити позицію контрольної точки\n";
        cout << "5 - Змінити розмір сховища (Resize - метод базового класу)\n";
        cout << "0 - Назад у головне меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double val;
                cout << "Введіть значення: ";
                cin >> val;
                if (q.Enqueue(val)) cout << "Елемент додано в кінець черги.\n";
                break;
            }
            case 2: {
                double val;
                if (q.ReadCheckpoint(val)) {
                    cout << "Значення у контрольній точці [" << q.GetCheckpoint() << "]: " << val << "\n";
                } else {
                    cout << "Контрольна точка ще не заповнена елементом!\n";
                }
                break;
            }
            case 3: {
                double val;
                if (q.ReadBack(val)) cout << "Значення в кінці черги: " << val << "\n";
                else cout << "Черга порожня.\n";
                break;
            }
            case 4: {
                int pos;
                cout << "Введіть нову позицію контрольної точки (індекс від 0): ";
                cin >> pos;
                if (q.SetCheckpoint(pos)) cout << "Контрольну точку оновлено.\n";
                break;
            }
            case 5: {
                int newSize;
                cout << "Введіть новий розмір сховища: ";
                cin >> newSize;
                if (q.Resize(newSize)) cout << "Розмір змінено.\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "Невірний пункт меню!\n";
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int mainChoice = -1;
    while (mainChoice != 0) {
        cout << "\n=== ТЕСТУВАННЯ ІЄРАРХІЇ КЛАСІВ (Array -> Stack, Queue) ===\n";
        cout << "1 - Тестувати клас \"Стек\" (конструктор за замовчуванням)\n";
        cout << "2 - Тестувати клас \"Стек\" (конструктор ініціалізації та копіювання)\n";
        cout << "3 - Тестувати клас \"Черга\" (конструктор за замовчуванням)\n";
        cout << "4 - Тестувати клас \"Черга\" (конструктор ініціалізації та копіювання)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            Stack st;
            TestStack(st);
        } else if (mainChoice == 2) {
            int sz;
            cout << "Введіть розмір стеку: ";
            cin >> sz;
            Stack original(sz);
            original.Push(10.5);
            original.Push(20.5);
            cout << "\n--- Створення копії стеку через конструктор копіювання ---\n";
            Stack copySt(original);
            TestStack(copySt);
        } else if (mainChoice == 3) {
            Queue q;
            TestQueue(q);
        } else if (mainChoice == 4) {
            int sz, cp;
            cout << "Введіть розмір черги: ";
            cin >> sz;
            cout << "Введіть позицію контрольної точки (індекс): ";
            cin >> cp;
            Queue original(sz, cp);
            original.Enqueue(1.1);
            original.Enqueue(2.2);
            original.Enqueue(3.3);
            cout << "\n--- Створення копії черги через конструктор копіювання ---\n";
            Queue copyQ(original);
            TestQueue(copyQ);
        }
    }

    return 0;
}