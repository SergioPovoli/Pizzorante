#include "pizzorante.h"

Prodotto::Prodotto(string _nome, Reparto _reparto, float _costo){
	reparto = _reparto;
	costo = _costo;
	nome = _nome;
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
/*		if (iiter->get_disponibile() == false){
			disponibile = false;
		}
		iiter++;
	}
/*	for (iiter = ingredienti.begin(); iiter != ingredienti.end(); iiter++){
		for (aiter = (iiter->get_allergeni()).begin(); aiter = (iiter->get_allergeni()).end(); aiter++){
			
		}*/
	}
}

bool Prodotto::get_disponibile()const{
	return disponibile;
}

float Prodotto::get_costo()const{
	return costo;
}

bool Prodotto::operator < (const Prodotto& _prodotto)const{
	return (nome < _prodotto.nome);
}
