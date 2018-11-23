#include "pizzorante.h"

Prodotto::Prodotto(Reparto _reparto, float _costo){
	reparto = _reparto;
	costo = _costo;
	
}

void Prodotto::set_disponibile(bool _disponibile){
	
}

void Prodotto::set_ingredienti(const Ingrediente _ingredienti){
	set<Ingrediente>::iterator iiter;
	set<Allergene>::iterator aiter;
	ingredienti.insert(_ingredienti);
	iiter = ingredienti.begin();
	disponibile = false;
	while (iiter != ingredienti.end() || disponibile == true){
		if (iiter->get_disponibile() == false){
			disponibile = false;
		}
		iiter++;
	}
/*	for (iiter = ingredienti.begin(); iiter != ingredienti.end(); iiter++){
		for (aiter = (iiter->get_allergeni()).begin(); aiter = (iiter->get_allergeni()).end(); aiter++){
			
		}
	}*/
}
