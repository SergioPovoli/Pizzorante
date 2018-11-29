#include "pizzorante.h"


Comanda::Comanda(int _quantita, string nota, Prodotto* _prodotto, Cameriere* _camereire, Tavolo* _tavolo):Ordine(_quantita, nota,_prodotto){
    cameriere= _camereire;
    tavolo=_tavolo;
    tavolo->inserisci_comanda(this);
    
}

void Comanda::modifica_tavolo(Tavolo* t){
    tavolo->rimuouvicomanda(this);
    tavolo=t;
    tavolo->inserisci_comanda(this);
}
void Comanda::modifica_cameriere(Cameriere* c){
    cameriere=c;
}

ostream& operator <<(ostream& os, Comanda& _comanda){
    os<<"----Comanda"<<_comanda.get_id_ordine()<<"-----"<<endl;
    os<< "Data:"<< _comanda.get_data()<<endl;
    set<RigaOrdine>::iterator iter;
    for(iter=_comanda.get_begin_prodotti();iter!=_comanda.get_end_prodotti();iter++){
        cout<<*iter;
    }
    return os;
}
