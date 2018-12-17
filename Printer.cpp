#include <iostream>
#include "Printer.h"

Printer::Printer(const string &producer, int cost, const string &color, const string &interfaces,
                 const string &maxFormat, const string &printingColor, int printingSpeed) : Device(producer, cost,
                                                                                                   color, interfaces,
                                                                                                   maxFormat),
                                                                                            printingColor(
                                                                                                    printingColor),
                                                                                            printingSpeed(
                                                                                                    printingSpeed) {}

ostream &operator<<(ostream &os, const Printer &scanner) {
    os << "Принтер - " << static_cast<const Device &>(scanner) << " Цвет печати: " << scanner.printingColor << " Скорость печати: "
       << scanner.printingSpeed;
    return os;
}

const string &Printer::getPrintingColor() const {
    return printingColor;
}

void Printer::setPrintingColor(const string &printingColor) {
    Printer::printingColor = printingColor;
}

int Printer::getPrintingSpeed() const {
    return printingSpeed;
}

void Printer::setPrintingSpeed(int printingSpeed) {
    Printer::printingSpeed = printingSpeed;
}

Printer::~Printer() {
    printingSpeed = 0;
    printingColor = "";
}

void Printer::writeToFile(ostream &file) {
    file << "printer" << endl;
    Device::writeToFile(file);
    file << printingSpeed << endl;
    file << printingColor << endl;
}

void Printer::readFromFile(istream &file) {
    Device::readFromFile(file);
    int printingSpeed;
    string printingColor;
    file >> printingSpeed;
    file >> printingColor;
    this->printingColor = printingColor;
    this->printingSpeed = printingSpeed;
}

istream &operator>>(istream &in, Printer &printer) {
    in >> static_cast<Device &>(printer);
    int printingSpeed;
    string printingColor;
    cout << "Введите скорость печати" << endl;
    in >> printingSpeed;
    cout << "Введите цвет печати" << endl;
    in >> printingColor;
    printer.printingColor = printingColor;
    printer.printingSpeed = printingSpeed;
    return in;
}

Printer::Printer() {}

void Printer::toConsole() {
    cout << *this;
}

string Printer::getFilename() {
    return "printer.txt";
}
