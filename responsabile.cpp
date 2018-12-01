#include "pizzorante.h"


Responsabile::Responsabile(string _nome, string _cognome, int _num_matricola):Persona(_nome,_cognome){
    num_matricola=_num_matricola;
}

ostream& operator <<(ostream& os, Responsabile &_responsabile){
    os<<_responsabile.get_nome()<<" "<<_responsabile.get_cognome()<<" | " ;
    os<<_responsabile.num_matricola<<" |"<<endl;
    return os;
}

void stampa_responsabile(Responsabile& resp){
    cout<<resp;
}

void Responsabile::modifica_num_matricola(int _num_matricola){
    num_matricola=_num_matricola;
}
void Responsabile::modifica_nome(string _nome){
    set_nome(_nome);
}
void Responsabile::modifica_cognome(string _cognome){
    set_cognome(_cognome);
}

void test_responsabile(){
    Responsabile c("Carlotta","Bressan",196739);
    cout<<c;
    c.modifica_nome("Ginevra");
    cout<<c;
    c.modifica_cognome("Endrighi");
    cout <<c;
    c.modifica_num_matricola(1234567);
    cout <<c;
}
