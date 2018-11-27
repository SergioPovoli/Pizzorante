#include "pizzorante.h"

Prenotazione::Prenotazione(string _nomecli, string _cognomecli, string _numerocli, int _num_posti, Responsabile* _resposnabile, unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondo, Tavolo* _tavolo):cliente(_nomecli, _cognomecli, _numerocli){
    responsabile= _resposnabile;
    tavolo = _tavolo;
    num_posti = _num_posti;
    prenotatoil = Data();
    prenotatoper = Data(_anno, _mese, _giorno, _ora, _minuto, _secondo);
}

ostream& operator << (ostream& os, Prenotazione& _prenotazione){
    os<<"---- PRENOTAZIONE ----"<<endl;
    os<<"Cliente:"<<endl<<_prenotazione.cliente;
    os<<"Resposnabile della prenotazione:"<<endl<<(*_prenotazione.responsabile);
    os<<"La prenotazione è stata effettuata il"<<endl<<_prenotazione.prenotatoil;
    os<<"La prenotazione è per il"<<endl<<_prenotazione.prenotatoper;
    os<<"Il tavolo prenotato è il nuemro "<<(_prenotazione.tavolo->get_numero())<<"e terrà "<<_prenotazione.num_posti<<" posti"<<endl;
    os<<"----------------------"<<endl;
    
    return os;
}

bool Prenotazione::operator < (const Prenotazione& _prenotazione)const{
    return prenotatoper<_prenotazione.prenotatoper;
}

void stampa_prenotazione(Prenotazione &p){
    cout<<p;
}

void Prenotazione:: modifica_num_posti(int _num_posti){
    num_posti=_num_posti;
}

void Prenotazione::modifica_cliente(string _nome,string _cognome, string _nume_tel){
    Cliente c(_nome,_cognome,_nume_tel);
    cliente=c;
}

void Prenotazione::modifica_responsabile(Responsabile* r1){
    responsabile=r1;
}

void Prenotazione::modifica_prenotatoper(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondo){
    prenotatoper=Data(_anno, _mese, _giorno, _ora, _minuto, _secondo);
}

void Prenotazione::modifica_tavolo(Tavolo *t){
    tavolo=t;
}

void test_prenotazione(){
    Tavolo t(15,2,SALA1,0,1);
    Responsabile r("Marco","Garbari",69);
    Prenotazione p1("Sergio","Povoli","3490754511",2,&r,2018,30,11,8,30,0,&t);
    cout<< p1;
    p1.modifica_cliente("Mario", "Povoli", "3356020307");
    cout<<p1;
}
