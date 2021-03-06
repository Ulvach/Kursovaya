#include <iostream>
#include <fstream>

#include "Periphery.h"

#include "MFU.h"
#include "Printer.h"
#include "Scanner.h"
#include "GraphicPad.h"

using namespace std;

Periphery* Periphery::periphery = nullptr;

Periphery::Periphery() {
    size = 0;
    devices = new Device*[size];
}

Periphery::~Periphery() {
    size = 0;
    delete []devices;
}

std::ostream &operator<<(std::ostream &os, const Periphery &periphery) {
    os << "Всего: " << periphery.size << endl;
    for (int i = 0; i < periphery.size; ++i) {
        periphery.devices[i]->toConsole();
        cout << endl;
    }
    return os;
}

int Periphery::getSize() const {
    return size;
}


Device **Periphery::getDevices() const {
    return devices;
}

Periphery &Periphery::add(Device &device) {
    this->size++;
    Device **copy = new Device*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->devices[i];
    }
    this->devices = new Device*[this->size];
    for (int j = 0; j < this->size - 1; ++j) {
        this->devices[j] = copy[j];
    }
    this->devices[size - 1] = &device;
    return *this;
}

Periphery &Periphery::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Ошибка, неверный индекс массива" << endl;
    } else {
        int k = 0;
        Device **copy = new Device*[this->size-1];
        for (int i = 0; i < this->size; ++i) {
            if (i != index) {
                copy[k] = this->devices[i];
                k++;
            }
        }
        this->size--;
        this->devices = new Device*[this->size];
        for (int j = 0; j < this->size; ++j) {
            this->devices[j] = copy[j];
        }
    }
    return *this;
}

void Periphery::writeToFile() {
    const string files[] = {
            "mfu.txt", "scanner.txt", "printer.txt", "graphicPad.txt"
    };
    const int length = 4;
    for (int j = 0; j < 4; ++j) {
        ofstream file;
        int count = 0;
        file.open(files[j], ios_base::out);
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                count++;
            }
        }
        file << count << endl;
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                devices[i]->writeToFile(file);
                file << endl;
            }
        }
        file.close();
    }
}

void Periphery::readFromFile() {
    const string files[] = {
            "mfu.txt", "scanner.txt", "printer.txt", "graphicPad.txt"
    };
    for (int j = 0; j < 4; ++j) {
        ifstream is;
        is.open(files[j], ios_base::in);
        int size;
        is >> size;
        for (int i = 0; i < size; ++i) {
           string currentDevice;
           is >> currentDevice;
           if (currentDevice == "mfu") {
               MFU *mfu = new MFU();
               mfu->readFromFile(is);
               this->add(*mfu);
           }
           if (currentDevice == "printer") {
               Printer *p = new Printer();
               p->readFromFile(is);
               this->add(*p);
           }
           if (currentDevice == "scanner") {
               Scanner *sc = new Scanner();
               sc->readFromFile(is);
               this->add(*sc);
           }
           if (currentDevice == "graphicPad") {
               GraphicPad *gp = new GraphicPad();
               gp->readFromFile(is);
               this->add(*gp);
           }
        }
        is.close();
    }
}
