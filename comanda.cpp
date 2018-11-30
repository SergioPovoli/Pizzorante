#include "pizzorante.h"


Comanda::Comanda(int _quantita, string nota, Prodotto* _prodotto, Cameriere* _camereire, Tavolo* _tavolo):Ordine(_quantita, nota,_prodotto){
    cameriere= _camereire;
    tavolo=_tavolo;
    tavolo->inserisci_comanda(this);
    set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
		sub_totale = sub_totale + (*iter).get_sub_totale();
	}
}

void Comanda::modifica_tavolo(Tavolo* t){
    tavolo->rimuouvicomanda(this);
    tavolo=t;
    tavolo->inserisci_comanda(this);
}
void Comanda::modifica_cameriere(Cameriere* c){
    cameriere=c;
}

float Comanda::aggiorna_sub_totale() {
	set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
		sub_totale = sub_totale + (*iter).get_sub_totale();
	}
	return sub_totale;
}

void Comanda::add_prodotti_comanda(int _q, string _n, Prodotto* _p){
	add_prodotti(_q, _n, _p);
	sub_totale = aggiorna_sub_totale();
}

void Comanda::remove_prodotti_comanda(int _q, string _n, Prodotto* _p){
	remove_prodotti(_q, _n, _p);
	sub_totale = aggiorna_sub_totale();
}

float Comanda::get_sub_totale() const{
	return sub_totale;
}

ostream& operator <<(ostream& os, Comanda& _comanda){
    os<<"----Comanda"<<_comanda.get_id_ordine()<<"-----"<<endl;
    os<< "Data:"<< _comanda.get_data()<<endl;
    set<RigaOrdine>::iterator iter;
    for(iter=_comanda.get_begin_prodotti();iter!=_comanda.get_end_prodotti();iter++){
        cout<<*iter;
    }
    os << "Totale: Euro " << _comanda.sub_totale << endl;
    return os;
}
