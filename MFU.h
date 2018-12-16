#ifndef TP_MFU_H
#define TP_MFU_H

#include <ostream>
#include "Device.h"

class MFU : public Device {
private:
    int printingSpeed;
    string printingColor;
public:
    void writeToFile(ostream &file) override;

    MFU(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat,
        int printingSpeed, const string &printingColor, const string &scanningArea);

    virtual ~MFU();

    friend ostream &operator<<(ostream &os, const MFU &mfu);

    int getPrintingSpeed() const;

    void setPrintingSpeed(int printingSpeed);

    const string &getPrintingColor() const;

    void setPrintingColor(const string &printingColor);

    const string &getScanningArea() const;

    void setScanningArea(const string &scanningArea);

private:
    string scanningArea;
public:

};


#endif //TP_MFU_H
