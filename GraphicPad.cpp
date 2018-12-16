#include "GraphicPad.h"

void GraphicPad::writeToFile(ostream &file) {
    file << "graphicPad" << endl;
    Device::writeToFile(file);
}
