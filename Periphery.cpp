#include <iostream>

#include "Periphery.h"

using namespace std;

Periphery* Periphery::periphery = nullptr;

Periphery::Periphery() {
    size = 0;
    devices = new Device*[size];
}

Periphery::~Periphery() {
    size = 0;
    delete []devices;
}

std::ostream &operator<<(std::ostream &os, const Periphery &periphery) {
    os << "Size is " << periphery.size << endl;
    for (int i = 0; i < periphery.size; ++i) {
        os << *periphery.devices[i] << endl;
    }
    return os;
}

int Periphery::getSize() const {
    return size;
}


Device **Periphery::getDevices() const {
    return devices;
}

Periphery &Periphery::add(Device &device) {
    this->size++;
    Device **copy = new Device*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->devices[i];
    }
    this->devices = new Device*[this->size];
    for (int j = 0; j < this->size - 1; ++j) {
        this->devices[j] = copy[j];
    }
    this->devices[size - 1] = &device;
    return *this;
}

Periphery &Periphery::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Ошибка, неверный индекс массива" << endl;
    } else {
        int k = 0;
        Device **copy = new Device*[this->size];
        for (int i = 0; i < this->size; ++i) {
            if (i != index) {
                copy[k] = this->devices[i];
            }
        }
        this->size--;
    }
    return *this;
}
