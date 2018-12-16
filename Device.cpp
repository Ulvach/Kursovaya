#include <iostream>

#include "Device.h"

using namespace std;

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

void Device::readFromFile(istream &file) {
    string producer;
    file >> producer;
    int cost;
    file >> cost;
    string color;
    file >> color;
    string interfaces;
    file >> interfaces;
    string maxFormat;
    file >> maxFormat;
    this->producer = producer;
    this->cost = cost;
    this->color = color;
    this->interfaces = interfaces;
    this->maxFormat = maxFormat;

}

istream &operator>>(istream &in, Device &device) {
    cout << "Введите изготовителя" << endl;
    string producer;
    in >> producer;
    cout << "Введите цену" << endl;
    int cost;
    in >> cost;
    cout << "Введите цвет" << endl;
    string color;
    in >> color;
    cout << "Введите интерфейсы" << endl;
    string interfaces;
    in >> interfaces;
    cout << "Введите максимальный формат" << endl;
    string maxFormat;
    in >> maxFormat;
    device.producer = producer;
    device.cost = cost;
    device.color = color;
    device.interfaces = interfaces;
    device.maxFormat = maxFormat;
    return in;
}

Device::Device() {}
