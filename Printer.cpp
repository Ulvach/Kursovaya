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
    os << static_cast<const Device &>(scanner) << " printingColor: " << scanner.printingColor << " printingSpeed: "
       << scanner.printingSpeed;
    return os;
}
