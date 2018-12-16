#include <iostream>
#include "Scanner.h"

const string &Scanner::getScanningArea() const {
    return scanningArea;
}

void Scanner::setScanningArea(const string &scanningArea) {
    Scanner::scanningArea = scanningArea;
}

Scanner::Scanner(const string &producer, int cost, const string &color, const string &interfaces,
                 const string &maxFormat, const string &scanningArea) : Device(producer, cost, color, interfaces,
                                                                               maxFormat), scanningArea(scanningArea) {}

Scanner::~Scanner() {
    scanningArea = "";
}

ostream &operator<<(ostream &os, const Scanner &scanner) {
    os << "Сканер - "<< static_cast<const Device &>(scanner) << " Область сканирования: " << scanner.scanningArea;
    return os;
}

void Scanner::writeToFile(ostream &file) {
    file << "scanner" << endl;
    Device::writeToFile(file);
    file << scanningArea << endl;
}

istream &operator>>(istream &in, Scanner &scanner) {
    in >> static_cast<Device &>(scanner);
    cout << "Введите область сканирования" << endl;
    string scanningArea;
    in >> scanningArea;
    scanner.scanningArea = scanningArea;
    return in;
}

void Scanner::readFromFile(istream &file) {
    Device::readFromFile(file);
    string scanningArea;
    file >> scanningArea;
    this->scanningArea = scanningArea;
}

Scanner::Scanner() {}

void Scanner::toConsole() {
    cout << *this;
}


