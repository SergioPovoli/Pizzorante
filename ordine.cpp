#include "pizzorante.h"

Ordine::Ordine(int _id_ordine)/*:data()*/{
	id_ordine = _id_ordine;
	
}

void Ordine::add_prodotti(Prodotto _prodotto){
	prodotti.insert(_prodotto);
	set<Prodotto>::iterator iter;
	for(iter = prodotti.begin(); iter != prodotti.end(); iter++){
		sub_totale = sub_totale + (*iter).get_costo();
	}
}

float Ordine::get_sub_totale()const{
	return sub_totale;
}

ostream& operator << (ostream& os, const Ordine& _ordine){
	set<Prodotto>::iterator iter;
	os<< _ordine.id_ordine << "Sub Totale " << _ordine.sub_totale << "Euro" << endl;
	for (iter = _ordine.prodotti.begin(); iter != _ordine.prodotti.end(); iter++){
		os << (*iter) << endl;
	}
	os << _ordine.data;
	return os;
}

void test_Ordine(){
/*	Ordine o(2301);
	Prodotto p("Acqua", BAR, 3);
	Ingrediente i("H20", 0000, true, false);
	Ingrediente i2("Bicchiere", 1, true, false);
//	p.set_ingredienti(i);
//	p.set_ingredienti(i2);
	Prodotto p1("Pane", RISTORANTE, 3);
	Ingrediente i3("Farina", 1023, true, false);
	Ingrediente i4("Lievito", 1, true, true);
	p.set_ingredienti(i3);
	p.set_ingredienti(i4);
	o.add_prodotti(p);
	o.add_prodotti(p1);
	cout << o;
	float tot;
	tot = o.get_sub_totale();*/
}
