#include "array.hpp"
#include <iostream>

Array::Array() : size(5), data(new double[5]) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0.0;
    }
    std::cout << "[Array: конструктор за замовчуванням (розмір = " << size << ")]\n";
}

Array::Array(int initialSize) {
    size = (initialSize > 0) ? initialSize : 5;
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0.0;
    }
    std::cout << "[Array: конструктор ініціалізації (розмір = " << size << ")]\n";
}

Array::Array(const Array& other) : size(other.size), data(new double[other.size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "[Array: конструктор копіювання]\n";
}

Array::~Array() {
    delete[] data;
    std::cout << "[Array: деструктор (пам'ять сховища звільнено)]\n";
}

bool Array::Resize(int newSize) {
    if (newSize <= 0) {
        std::cout << "Помилка: некоректний новий розмір!\n";
        return false;
    }

    double* newData = new double[newSize];
    int copyCount = (newSize < size) ? newSize : size;

    for (int i = 0; i < copyCount; ++i) {
        newData[i] = data[i];
    }
    for (int i = copyCount; i < newSize; ++i) {
        newData[i] = 0.0;
    }

    delete[] data;
    data = newData;
    size = newSize;
    return true;
}