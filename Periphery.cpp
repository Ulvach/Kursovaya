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
    cout << "Size is " << periphery.size << endl;
    return os;
}
