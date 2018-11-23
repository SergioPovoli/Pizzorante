#include "pizzorante.h"

Ordine::Ordine(int _id_ordine){
	id_ordine = _id_ordine;
}

void Ordine::add_prodotti(Prodotto _prodotto){
	prodotti.insert(_prodotto);
	set<Prodotto>::iterator iter;
	for(iter = prodotti.begin(); iter != prodotti.end(); iter++){
		sub_totale += (*iter).get_costo();
	}
}
		
void Ordine::set_sub_totale(Prodotto _prodotto){
	
}

float Ordine::get_sub_totale(){
	return sub_totale;
}
