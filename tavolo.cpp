#include "pizzorante.h"

Tavolo::Tavolo(int _numero, int _num_posti, Posizione _posizione, bool _occupato, bool _prenotato){
    numero=_numero;
    num_posti=_num_posti;
    posizione=_posizione;
    occupato=_occupato;
    prenotato=_prenotato;
}

bool Tavolo::get_prenotato()const{
    return prenotato;
}
bool Tavolo::get_occupato()const{
    return occupato;
}
void Tavolo::set_occupato(bool _occupato){
    occupato=_occupato;
}
void Tavolo::set_prenotato(bool _prenotato){
    prenotato=_prenotato;
}
void Tavolo::inserisci_prenotazione(Prenotazione* _prenotazione){
    prenotazioni.insert(_prenotazione);
}
void Tavolo::cancella_prenotazioni(){
    prenotazioni.clear();
}

void Tavolo::stampa_listaprenotazioni(){
    set<Prenotazione*>::iterator iter;
    for(iter=prenotazioni.begin();iter!=prenotazioni.end();++iter){
        cout<<"Lista prenotazioni:"<<endl<<(*(*iter))<<"--------"<<endl;
    }
}

void Tavolo::rimuoviprenotazione(Prenotazione* _prenotazione){
    set<Prenotazione*>::iterator iter;
    iter=prenotazioni.find(_prenotazione);
    prenotazioni.erase(iter);
}

int Tavolo::get_numero()const{
    return numero;
}

ostream& operator <<(ostream& os, Tavolo& _tavolo){
    os<<"------Tavolo: "<<_tavolo.numero<<"------"<<endl;
    switch(_tavolo.posizione){
        case 0: os<<"SALA1 "<<endl; break;
        case 1: os<<"SALA2 "<<endl; break;
        case 2: os<<"VERANDA "<<endl; break;
    }
    os<<"Numero Posti: "<<_tavolo.num_posti;
    if(_tavolo.occupato==true && _tavolo.prenotato==false){
        os<<"Stato: Occupato "<<endl;
    }else if (_tavolo.prenotato==true && _tavolo.occupato==false){
        os<<"Stato: Prenotato "<<endl;
    }else{
        os<<"Stato: Libero "<<endl;
    }
    os<<"Prenotazioni: "<<endl;
    set<Prenotazione*>::iterator iter1;
    for(iter1=_tavolo.prenotazioni.begin();iter1!=_tavolo.prenotazioni.end();++iter1){
        os<<**iter1<<" | ";
    }
    
    return os;
}


void test_tavolo(){
    Tavolo t(15,2,SALA1,0,1);
    Responsabile r("Marco","Garbari",69);
    Prenotazione p("Sergio","Povoli","3490754511",2,&r,2018,30,11,8,30,0,&t);
    t.inserisci_prenotazione(&p);
    cout<<t<<endl<<endl;
    Prenotazione p1("Riccardo","Ricci","3490754511",5,&r,2018,30,11,10,30,0,&t);
    t.inserisci_prenotazione(&p1);
    cout<<t<<endl<<endl;
    t.rimuoviprenotazione(&p1);
    cout<<t<<endl<<endl;
    t.cancella_prenotazioni();
    cout<<t<<endl<<endl;
}
