#include "queue.hpp"
#include <iostream>
#include <iomanip>

Queue::Queue() : Array(), checkpoint(0), count(0) {
    std::cout << "[Queue: конструктор за замовчуванням]\n";
}

Queue::Queue(int maxSize, int checkpointPos) : Array(maxSize), count(0) {
    if (checkpointPos >= 0 && checkpointPos < size) {
        checkpoint = checkpointPos;
    } else {
        checkpoint = 0;
    }
    std::cout << "[Queue: конструктор ініціалізації (контрольна точка = " << checkpoint << ")]\n";
}

Queue::Queue(const Queue& other) : Array(other), checkpoint(other.checkpoint), count(other.count) {
    std::cout << "[Queue: конструктор копіювання]\n";
}

Queue::~Queue() {
    std::cout << "[Queue: деструктор]\n";
}

bool Queue::Enqueue(double value) {
    if (count >= size) {
        std::cout << "Помилка: черга заповнена (досягнуто максимальний розмір сховища)!\n";
        return false;
    }
    data[count++] = value;
    return true;
}

bool Queue::ReadCheckpoint(double& value) const {
    if (checkpoint < 0 || checkpoint >= count) {
        return false;
    }
    value = data[checkpoint];
    return true;
}

bool Queue::ReadBack(double& value) const {
    if (count <= 0) {
        return false;
    }
    value = data[count - 1];
    return true;
}

bool Queue::SetCheckpoint(int newPos) {
    if (newPos < 0 || newPos >= size) {
        std::cout << "Помилка: позиція контрольної точки має бути в межах [0 .. " << size - 1 << "]!\n";
        return false;
    }
    checkpoint = newPos;
    return true;
}

bool Queue::Resize(int newSize) {
    if (!Array::Resize(newSize)) {
        return false;
    }
    if (count > size) {
        count = size;
    }
    if (checkpoint >= size) {
        checkpoint = size - 1;
    }
    return true;
}

void Queue::Print() const {
    std::cout << "\n--- СТАН ЧЕРГИ (Queue : Array) ---\n";
    std::cout << "Розмір сховища (size):     " << size << "\n";
    std::cout << "Елементів у черзі (count): " << count << "\n";
    std::cout << "Контрольна точка (індекс): " << checkpoint << "\n";
    std::cout << std::fixed << std::setprecision(2);
    if (count == 0) {
        std::cout << "Вміст: [порожня]\n";
    } else {
        std::cout << "Вміст (початок -> кінець): ";
        for (int i = 0; i < count; ++i) {
            std::cout << data[i];
            if (i == checkpoint) std::cout << "[КТ]";
            if (i < count - 1) std::cout << " -> ";
        }
        std::cout << "\n";
    }
    std::cout << "----------------------------------\n";
}