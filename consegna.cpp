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

void test_consegna(){
    Consegna c("Via Picarel", "Vezzano", 11, 38096, "Sergio", "Povoli", "3490754511");
    cout << c;
}
