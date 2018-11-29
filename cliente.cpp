#include "pizzorante.h"

Cliente::Cliente(string _nome, string _cognome, string _numero_tel):Persona(_nome,_cognome){
    numero_tel=_numero_tel;
}

Cliente::~Cliente(){
    cout<<"Distrutto";
}

void Cliente::modifica_nome(string _nome){
	set_nome(_nome);
}

void Cliente::modifica_cognome (string _cognome){
	set_cognome(_cognome);
}

void Cliente::modifica_numero_tel(string _numero_tel){
	numero_tel = _numero_tel;
}

ostream& operator <<(ostream& os, const Cliente& _cliente){
    os<<_cliente.get_nome()<<" "<<_cliente.get_cognome()<<endl;
    os<<_cliente.numero_tel<<endl;
    return os;
}

void test_cliente(){
    Cliente c("Nicola","Fiorello","3490754511");
    cout << c;
}
