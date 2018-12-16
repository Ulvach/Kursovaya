#include "Device.h"

const string &Device::getProducer() const {
    return producer;
}

void Device::setProducer(const string &producer) {
    Device::producer = producer;
}

int Device::getCost() const {
    return cost;
}

void Device::setCost(int cost) {
    Device::cost = cost;
}

const string &Device::getColor() const {
    return color;
}

void Device::setColor(const string &color) {
    Device::color = color;
}

const string &Device::getInterfaces() const {
    return interfaces;
}

void Device::setInterfaces(const string &interfaces) {
    Device::interfaces = interfaces;
}

Device::~Device() {
    color = "";
    producer = "";
    cost = 0;
    color = "";
    interfaces = "";
}

const string &Device::getMaxFormat() const {
    return maxFormat;
}

void Device::setMaxFormat(const string &maxFormat) {
    Device::maxFormat = maxFormat;
}

Device::Device(const string &producer, int cost, const string &color, const string &interfaces, const string &maxFormat)
        : producer(producer), cost(cost), color(color), interfaces(interfaces), maxFormat(maxFormat) {}

ostream &operator<<(ostream &os, const Device &device) {
    os << "Изготовитель: " << device.producer << " цена: " << device.cost << " цвет: " << device.color << " интерфейсы: "
       << device.interfaces << " максимальный формат: " << device.maxFormat;
    return os;
}

void Device::writeToFile(ostream &file) {
    file << producer << endl << cost << endl << color << endl << interfaces << endl << maxFormat << endl;
}
