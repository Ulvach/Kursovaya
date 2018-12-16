#include <iostream>
#include <fstream>

#include "Periphery.h"
#include "Scanner.h"

using namespace std;

void menu () {

}

int main() {
    Periphery *perephery = Periphery::getInstance();


    ofstream file;
    file.open("text.txt", ios_base::out);
    Scanner *sc = new Scanner("ibm", 120, "red", "usb", "a4", "1200x100");
    sc->writeToFile(file);
    file.close();
    perephery->add(*sc);

    cout << *perephery << endl;
    menu();

    return 0;
}