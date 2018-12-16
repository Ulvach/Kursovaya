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
    os << static_cast<const Device &>(scanner) << " Область сканирования: " << scanner.scanningArea;
    return os;
}

void Scanner::writeToFile(ostream &file) {
    file << "scanner" << endl;
    static_cast<Device &>(*this).writeToFile(file);
}


