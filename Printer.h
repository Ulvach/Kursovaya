#ifndef TP_SCANNER_H
#define TP_SCANNER_H

#include <string>
#include <ostream>

#include "Device.h"

using namespace std;

class Printer : public Device {
private:
    string printingColor;
    int printingSpeed;

public:
    friend ostream &operator<<(ostream &os, const Printer &scanner);

    Printer(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat,
            const string &printingColor, int printingSpeed);

    const string &getPrintingColor() const;

    void setPrintingColor(const string &printingColor);

    int getPrintingSpeed() const;

    void setPrintingSpeed(int printingSpeed);

    virtual ~Printer();

};


#endif //TP_SCANNER_H
