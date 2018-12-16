#ifndef TP_SCANNER_H
#define TP_SCANNER_H

#include <string>
#include <ostream>
#include "Device.h"

using namespace std;

class Scanner : public Device {
private:
    string scanningArea;
public:
    friend ostream &operator<<(ostream &os, const Scanner &scanner);

    Scanner(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat,
            const string &scanningArea);

    const string &getScanningArea() const;

    void setScanningArea(const string &scanningArea);

    virtual ~Scanner();

};


#endif //TP_SCANNER_H
