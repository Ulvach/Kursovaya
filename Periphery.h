#ifndef TP_PERIPHERY_H
#define TP_PERIPHERY_H


class Periphery {
private:
    static Periphery *periphery;
    Periphery() {}
    Periphery( const Periphery& );
    Periphery& operator=( Periphery& );
public:
    static Periphery* getInstance() {
        if(!periphery)
            periphery = new Periphery();
        return periphery;
    }
};


#endif //TP_PERIPHERY_H
