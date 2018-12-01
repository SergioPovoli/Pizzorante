#include "pizzorante.h"

Consegna::Consegna(string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel):cliente(_nome,_cognome,_num_tel){
    via=_via;
    citta=_citta;
    numero =_numero;
    cap=_cap;
}

ostream& operator <<(ostream& os, Consegna& _consegna){
    os<<"---- Consegna ----"<<endl;
    os<< _consegna.cliente;
    os << _consegna.via<<" "<< _consegna.numero<<endl;
    os << _consegna.citta<<" "<< _consegna.cap<<endl;
    return os;
}

void stampa_consegna(Consegna& con){
    cout<<con;
}

void Consegna::modifica_via(string _via){
    via=_via;
}
void Consegna::modifica_numero(int _numero){
    numero=_numero;
}
void Consegna::modifica_citta(string _citta){
    citta=_citta;
}
void Consegna::modifica_cap(int _cap){
    cap=_cap;
}
void Consegna::modifica_cliente(string _nome, string _cognome, string _numero){
    Cliente c(_nome,_cognome,_numero);
    cliente=c;
}

void test_consegna(){
    Consegna c("Via Picarel", "Vezzano", 11, 38096, "Sergio", "Povoli", "3490754511");
    cout << c;
    c.modifica_cap(38123);
	cout << c << endl;
	c.modifica_citta("Trento");
	cout << c << endl;
	c.modifica_cliente("Anna", "Fait", "0461897645");
	cout << c << endl;
	c.modifica_numero(13);
	cout << c << endl;
	c.modifica_via("Matti");
	cout << c << endl; 
}
