#ifndef TP_GRAPHICPAD_H
#define TP_GRAPHICPAD_H


#include "Device.h"

class GraphicPad : public Device {
public:
    void writeToFile(ostream &file) override;
    void readFromFile(istream &file) override;

    string getFilename() override;

    void toConsole() override;

    friend ostream &operator<<(ostream &os, const GraphicPad &gp);
    friend istream &operator>>(istream &in, GraphicPad &gp);
};


#endif //TP_GRAPHICPAD_H
