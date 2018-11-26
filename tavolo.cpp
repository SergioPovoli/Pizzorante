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
    return num_posti;
}
