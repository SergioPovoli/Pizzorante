#include "pizzorante.h"

Persona:: Persona(string _nome, string _cognome){
    nome=_nome;
    cognome=_cognome;
}

/*ostream& operator << (ostream& os, const Persona& _persona){
    os<<_persona.nome<<" "<<_persona.cognome;
    return os;
}*/

ostream& Persona::operator << (ostream& os)const{
    os<<nome<<" "<<cognome;
    return os;
}
void test_persona(){
    Persona p("Irene","Buffa");
    cout << p;
}
