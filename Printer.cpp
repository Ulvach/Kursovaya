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
    os << static_cast<const Device &>(scanner) << " Цвет печати: " << scanner.printingColor << " Скорость печати: "
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
