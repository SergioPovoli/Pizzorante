#include "pizzorante.h"

int Ordine::id_ordine=0;

Ordine::Ordine(int _q, string _n, Prodotto* _p):riga(_q, _n, _p){
    prodotti.insert(riga);
    id_ordine++;
}

Ordine::~Ordine(){
    id_ordine--;
}

void Ordine::add_prodotti(RigaOrdine _prodotto){
	prodotti.insert(_prodotto);
/*	set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = prodotti.begin(); iter != prodotti.end(); iter++){
		sub_totale = sub_totale + (*iter)->get_sub_totale();
	}*/
}


/*float Ordine::get_sub_totale()const{
	return sub_totale;
}
*/
ostream& operator << (ostream& os, const Ordine& _ordine){
	set<RigaOrdine>::iterator iter;
	os<< _ordine.id_ordine << /*"Sub Totale " << _ordine.sub_totale << "Euro" << */endl;
	for (iter = _ordine.prodotti.begin(); iter != _ordine.prodotti.end(); iter++){
		os << *(iter) << endl;
	}
	os << _ordine.data;
	return os;
}

bool Ordine::operator <(Ordine& _ordine){
    return id_ordine<_ordine.id_ordine;
}

set<RigaOrdine>::iterator Ordine::get_begin_prodotti(){
	set<RigaOrdine>::iterator iter;
	iter = prodotti.begin();
	return iter;
}

set<RigaOrdine>::iterator Ordine::get_end_prodotti(){
	set<RigaOrdine>::iterator iter;
	iter = prodotti.end();
	return iter;
}
Data Ordine::get_data() const{
	return data;
}

int Ordine::get_id_ordine() const{
	return id_ordine;
}

void test_Ordine(){
    Prodotto p("Acqua", BAR, 3);
	Ingrediente i("H20", 0000, true, false);
	Ingrediente i2("Bicchiere", 1, true, false);
	p.set_ingredienti(&i);
	p.set_ingredienti(&i2);
	Ordine o(4, "Naturale", &p);
	Prodotto p1("Pane", RISTORANTE, 3);
	Ingrediente i3("Farina", 1023, true, false);
	Ingrediente i4("Lievito", 1, true, true);
	p1.set_ingredienti(&i3);
	p1.set_ingredienti(&i4);
	RigaOrdine ord(9, "Ben cotto", &p1);
	o.add_prodotti(ord);
	cout << o;
}
