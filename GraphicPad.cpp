#include <iostream>
#include "GraphicPad.h"

void GraphicPad::writeToFile(ostream &file) {
    file << "graphicPad" << endl;
    Device::writeToFile(file);
}

void GraphicPad::readFromFile(istream &file) {
    Device::readFromFile(file);
}

istream &operator>>(istream &in, GraphicPad &gp) {
    in >> static_cast<Device &>(gp);
    return in;
}

ostream &operator<<(ostream &os, const GraphicPad &gp) {
    os << "Графический планшет - " << static_cast<const Device &>(gp);
    return os;
}

void GraphicPad::toConsole() {
    cout << *this;
}
