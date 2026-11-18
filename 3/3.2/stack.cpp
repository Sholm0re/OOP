#include "stack.hpp"
#include <iostream>
#include <iomanip>


Stack::Stack() {
    capacity = 20;
    data = new double[capacity];
    top = -1;
    std::cout << "[Викликано конструктор за замовчуванням]\n";
}


Stack::Stack(double value) {
    capacity = 20;
    data = new double[capacity];
    top = -1;
    Push(value);
    std::cout << "[Викликано конструктор з 1 аргументом]\n";
}


Stack::Stack(int count, const double* arr) {
    if (count < 0) count = 0;
    capacity = (count > 20) ? count : 20;
    data = new double[capacity];
    top = -1;

    if (arr != nullptr) {
        for (int i = 0; i < count; ++i) {
            Push(arr[i]);
        }
    }
    std::cout << "[Викликано конструктор з 2 аргументами]\n";
}


Stack::Stack(int maxCapacity, double value, int count) {
    if (maxCapacity <= 0) maxCapacity = 20;
    if (count < 0) count = 0;
    if (count > maxCapacity) maxCapacity = count;

    capacity = maxCapacity;
    data = new double[capacity];
    top = -1;

    for (int i = 0; i < count; ++i) {
        Push(value);
    }
    std::cout << "[Викликано конструктор з 3 аргументами]\n";
}


Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new double[capacity];
    for (int i = 0; i <= top; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "[Викликано конструктор копіювання]\n";
}


Stack::~Stack() {
    delete[] data;
    std::cout << "[Викликано деструктор: пам'ять стеку звільнено]\n";
}


void Stack::Print() const {
    std::cout << "\n--- ПОТОЧНИЙ СТАН СТЕКУ ---\n";
    std::cout << "Вершина стеку (індекс top): " << top << "\n";
    std::cout << std::fixed << std::setprecision(2);
    if (top == -1) {
        std::cout << "Елементи: [порожній]\n";
    } else {
        std::cout << "Елементи: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << data[i] << (i < top ? " | " : "");
        }
        std::cout << "  <-- вершина\n";
    }
    std::cout << "---------------------------\n";
}

bool Stack::Push(double value) {
    if (top >= capacity - 1) {
        std::cout << "Помилка: стек переповнений!\n";
        return false;
    }
    data[++top] = value;
    return true;
}


bool Stack::Pop(double& removedValue) {
    if (top == -1) {
        std::cout << "Помилка: стек порожній, нічого видаляти!\n";
        return false;
    }
    removedValue = data[top--];
    return true;
}


double Stack::Sum() const {
    double total = 0.0;
    for (int i = 0; i <= top; ++i) {
        total += data[i];
    }
    return total;
}