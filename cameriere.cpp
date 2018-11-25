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
