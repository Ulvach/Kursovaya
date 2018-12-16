#include <iostream>
#include "MFU.h"

MFU::MFU(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat,
         int printingSpeed, const string &printingColor, const string &scanningArea) : Device(producer, cost, color,
                                                                                              interfaces, maxFormat),
                                                                                       printingSpeed(printingSpeed),
                                                                                       printingColor(printingColor),
                                                                                       scanningArea(scanningArea) {}

int MFU::getPrintingSpeed() const {
    return printingSpeed;
}

void MFU::setPrintingSpeed(int printingSpeed) {
    MFU::printingSpeed = printingSpeed;
}

const string &MFU::getPrintingColor() const {
    return printingColor;
}

void MFU::setPrintingColor(const string &printingColor) {
    MFU::printingColor = printingColor;
}

const string &MFU::getScanningArea() const {
    return scanningArea;
}

void MFU::setScanningArea(const string &scanningArea) {
    MFU::scanningArea = scanningArea;
}

ostream &operator<<(ostream &os, const MFU &mfu) {
    os << static_cast<const Device &>(mfu) << " Скорость печати: " << mfu.printingSpeed << " Цвет печати: "
       << mfu.printingColor << " Область сканирования: " << mfu.scanningArea;
    return os;
}

MFU::~MFU() {
    printingSpeed = 0;
    printingColor = "";
    scanningArea = "";
}

void MFU::writeToFile(ostream &file) {
    file << "mfu" << endl;
    Device::writeToFile(file);
    file << printingSpeed << endl;
    file << printingColor << endl;
    file << scanningArea << endl;
}

istream &operator>>(istream &in, MFU &mfu) {
    in >> static_cast<Device &>(mfu);
    cout << "Введите скорость печати:" << endl;
    int printingSpeed;
    in >> printingSpeed;
    cout << "Введите цвет печати:" << endl;
    string printingColor;
    cin >> printingColor;
    cout << "Введите область сканирования:" << endl;
    string scanningArea;
    cin >> scanningArea;
    mfu.printingSpeed = printingSpeed;
    mfu.printingColor = printingColor;
    mfu.scanningArea = scanningArea;
    return in;
}

void MFU::readFromFile(istream &file) {
    Device::readFromFile(file);
    int printingSpeed;
    string printingColor;
    string scanningArea;
    file >> printingSpeed;
    file >> printingColor;
    file >> scanningArea;
    this->printingSpeed = printingSpeed;
    this->printingColor = printingColor;
    this->scanningArea = scanningArea;
}
