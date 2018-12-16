#ifndef TP_PRINTER_H
#define TP_PRINTER_H

#include <string>
#include <ostream>

#include "Device.h"

class Printer : public Device {
private:
    string printingColor;
    int printingSpeed;

public:
    void writeToFile(ostream &file) override;

    void readFromFile(istream &file) override;

    void toConsole() override;

    friend ostream &operator<<(ostream &os, const Printer &scanner);
    friend istream &operator>>(istream &is, Printer &printer);

    Printer();

    Printer(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat,
            const string &printingColor, int printingSpeed);

    const string &getPrintingColor() const;

    void setPrintingColor(const string &printingColor);

    int getPrintingSpeed() const;

    void setPrintingSpeed(int printingSpeed);

    virtual ~Printer();

};


#endif //TP_PRINTER_H
