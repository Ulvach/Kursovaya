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

Device::Device(const string &producer, int cost, const string &color, const string &interfaces) : producer(producer),
                                                                                                  cost(cost),
                                                                                                  color(color),
                                                                                                  interfaces(
                                                                                                          interfaces) {}

Device::~Device() {
    color = "";
    producer = "";
    cost = 0;
    color = "";
    interfaces = "";
}
