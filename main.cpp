#include <iostream>

#include "Periphery.h"

using namespace std;

int main() {
    Periphery *perephery = Periphery::getInstance();

    cout << *perephery << endl;

    return 0;
}