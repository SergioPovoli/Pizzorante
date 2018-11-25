#include "pizzorante.h"


Responsabile::Responsabile(string _nome, string _cognome, int _num_matricola):Persona(_nome,_cognome){
    num_matricola=_num_matricola;
}

ostream& operator <<(ostream& os, Responsabile &_responsabile){
    os<<_responsabile.get_nome()<<" "<<_responsabile.get_cognome()<<endl;
    os<<_responsabile.num_matricola<<endl;
    return os;
}

void test_responsabile(){
    Responsabile r("Giacomo","Planke",185790);
    cout << r;
}
