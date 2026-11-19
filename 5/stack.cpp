#include "stack.hpp"
#include <iostream>
#include <iomanip>

Stack::Stack() : Array(), depth(0) {
    std::cout << "[Stack: конструктор за замовчуванням]\n";
}

Stack::Stack(int maxDepth) : Array(maxDepth), depth(0) {
    std::cout << "[Stack: конструктор ініціалізації]\n";
}

Stack::Stack(const Stack& other) : Array(other), depth(other.depth) {
    std::cout << "[Stack: конструктор копіювання]\n";
}

Stack::~Stack() {
    std::cout << "[Stack: деструктор]\n";
}

bool Stack::Push(double value) {
    if (depth >= size) {
        std::cout << "Помилка: стек заповнений (досягнуто максимальний розмір сховища)!\n";
        return false;
    }
    data[depth++] = value;
    return true;
}

bool Stack::Pop(double& value) {
    if (depth <= 0) {
        std::cout << "Помилка: стек порожній!\n";
        return false;
    }
    value = data[--depth];
    return true;
}

bool Stack::Peek(double& value) const {
    if (depth <= 0) {
        return false;
    }
    value = data[depth - 1];
    return true;
}

bool Stack::Resize(int newSize) {
    if (!Array::Resize(newSize)) {
        return false;
    }
    if (depth > size) {
        depth = size;
    }
    return true;
}

void Stack::Print() const {
    std::cout << "\n--- СТАН СТЕКУ (Stack : Array) ---\n";
    std::cout << "Розмір сховища (size): " << size << "\n";
    std::cout << "Глибина стеку (depth): " << depth << "\n";
    std::cout << std::fixed << std::setprecision(2);
    if (depth == 0) {
        std::cout << "Елементи: [порожній]\n";
    } else {
        std::cout << "Елементи (знизу до вершини): ";
        for (int i = 0; i < depth; ++i) {
            std::cout << data[i] << (i < depth - 1 ? " | " : "");
        }
        std::cout << "  <-- вершина\n";
    }
    std::cout << "----------------------------------\n";
}