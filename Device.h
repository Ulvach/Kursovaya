#ifndef TP_DEVICE_H
#define TP_DEVICE_H

#include <string>

using namespace std;

class Device {
private:
    string producer;
    int cost;
    string color;
    string interfaces;
public:
    const string &getProducer() const;

    Device(const string &producer, int cost, const string &color, const string &interfaces);
    virtual ~Device();

    void setProducer(const string &producer);

    int getCost() const;

    void setCost(int cost);

    const string &getColor() const;

    void setColor(const string &color);

    const string &getInterfaces() const;

    void setInterfaces(const string &interfaces);

};


#endif //TP_DEVICE_H
