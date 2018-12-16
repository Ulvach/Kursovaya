#include <iostream>
#include <fstream>

#include "Periphery.h"
#include "Scanner.h"
#include "Printer.h"
#include "GraphicPad.h"
#include "MFU.h"

using namespace std;

const string FILENAME = "text.txt";

void printMenu() {
    cout << "0 - выход" << endl;
    cout << "1 - добавить устройство" << endl;
    cout << "2 - удалить устройство" << endl;
    cout << "3 - записать в файл" << endl;
    cout << "4 - прочитать из файла" << endl;
    cout << "5 - вывод устройств на экран" << endl;
}

int main() {

    setlocale(LC_ALL, "Russian");

    Periphery *perephery = Periphery::getInstance();

    bool isRunning = true;
    int mode;
    while (isRunning) {
        printMenu();
        cin >> mode;
        switch(mode) {
            case 0:
                isRunning = false;
                break;
            case 1:
                cout << "Выберите что хотите добавить" << endl;
                cout << "1 - принтер, 2 - МФУ, 3 - сканер, 4 - графический планшет" << endl;
                int selected;
                cin >> selected;
                if (selected == 1) {
                    Printer *p = new Printer();
                    cin >> *p;
                    Periphery::getInstance()->add(*p);
                }
                if (selected == 2) {
                    MFU *mfu = new MFU();
                    cin >> *mfu;
                    Periphery::getInstance()->add(*mfu);
                }
                if (selected == 3) {
                    Scanner *sc = new Scanner();
                    cin >> *sc;
                    Periphery::getInstance()->add(*sc);
                }
                if (selected == 4) {
                    GraphicPad *gp = new GraphicPad();
                    cin >> *gp;
                    Periphery::getInstance()->add(*gp);
                }
                break;
            case 2:
                cout << "Введите индекс удаляемого устройства" << endl;
                int removed;
                cin >> removed;
                Periphery::getInstance()->remove(removed);
                break;
            case 3:
                try {
                    ofstream file;
                    file.open(FILENAME, ios_base::out);
                    Periphery::getInstance()->writeToFile(file);
                    file.close();
                } catch (exception e) {
                    cout << "Не удается записать в файл" << e.what();
                }
                break;
            case 4:
                try {
                    ifstream file;
                    file.open(FILENAME, ios_base::in);
                    Periphery::getInstance()->readFromFile(file);
                    file.close();
                } catch (exception e) {
                    cout << "Не удается прочитать файл" << e.what();
                }
                break;
            case 5:
                cout << *Periphery::getInstance();
                break;

        }

    }

    return 0;
}