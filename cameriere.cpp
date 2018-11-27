#include "pizzorante.h"

Cameriere::Cameriere(string _nome, string _cognome, int _num_matricola):Persona(_nome,_cognome){
    num_matricola=_num_matricola;
}
ostream& operator <<(ostream& os, Cameriere& _cameriere){
    os<<_cameriere.get_nome()<<" "<<_cameriere.get_cognome()<<"MC:" ;
    os<<_cameriere.num_matricola<<endl;
    return os;
}
void test_cameriere(){
    Cameriere c("Daniele","Mattedi",1231);
    cout<<c;
}

void stampa_cameriere(Cameriere &c){
    cout<<c;
}

void Cameriere::modifica_num_matricola(int _num_matricola){
    num_matricola=_num_matricola;
}
void Cameriere::modifica_nome(string _nome){
    set_nome(_nome);
}
void Cameriere::modifica_cognome(string _cognome){
    set_cognome(_cognome);
}
