#ifndef TP_GRAPHICPAD_H
#define TP_GRAPHICPAD_H


#include "Device.h"

class GraphicPad : public Device {
public:
    void writeToFile(ostream &file) override;
};


#endif //TP_GRAPHICPAD_H
