#ifndef TP_DEVICE_H
#define TP_DEVICE_H

#include <string>
#include <ostream>

using namespace std;

class Device {
private:
    string producer;
    int cost;
    string color;
    string interfaces;
    string maxFormat;
public:

    virtual void writeToFile(ostream &file);

    const string &getProducer() const;

    Device(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat);

    const string &getMaxFormat() const;

    void setMaxFormat(const string &maxFormat);

    virtual ~Device();

    void setProducer(const string &producer);

    int getCost() const;

    void setCost(int cost);

    const string &getColor() const;

    void setColor(const string &color);

    const string &getInterfaces() const;

    void setInterfaces(const string &interfaces);

    friend ostream &operator<<(ostream &os, const Device &device);

};


#endif //TP_DEVICE_H
