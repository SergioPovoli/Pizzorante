#include "pizzorante.h"

Tavolo::Tavolo(int _prova){
    prova=_prova;
}

ostream& operator <<(ostream& os, Tavolo& _tavolo){
    os<<_tavolo.prova<<endl;
    return os;
}
