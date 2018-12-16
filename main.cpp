#include <iostream>
#include <fstream>

#include "Periphery.h"
#include "Scanner.h"

using namespace std;

void menu () {

}

int main() {
    Periphery *perephery = Periphery::getInstance();

    cout << *perephery << endl;

    ofstream file;
    file.open("text.txt", ios_base::out);
    Scanner *sc = new Scanner("ibm", 120, "red", "usb", "a4", "1200x100");
    cout << *sc;
    sc->writeToFile(file);
    file.close();

    menu();

    return 0;
}