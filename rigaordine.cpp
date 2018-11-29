#include "pizzorante.h"

RigaOrdine::RigaOrdine(int _q, string _n, Prodotto* _p):prodotto(_p){
	quantita = _q;
	nota = _n;
	sub_totale = quantita * prodotto->get_costo();
}

float RigaOrdine::get_sub_totale()const{
	return sub_totale;
}

string RigaOrdine::get_nota()const{
	return nota;
}

void RigaOrdine::set_quantita(int _q){
	quantita = _q;
	sub_totale = quantita * prodotto->get_costo();
}

void RigaOrdine::set_nota(string _n){
	nota = _n;		
}

bool RigaOrdine::operator < (const RigaOrdine& _ro) const{
	return ((&prodotto)<(&(_ro.prodotto)));
}

ostream& operator << (ostream& os, const RigaOrdine& _ro){
	os << "Prodotto: " <<  *(_ro.prodotto) << endl;
	os << "Quantita': " << _ro.quantita << endl;
	os << "Note: " << _ro.nota << endl;
	os << "Totale Prodotto: Euro " << _ro.sub_totale;
	os << endl;
	return os;
}

void test_riga_ordine(){
	Ingrediente ingrediente("Acqua", 0000, true, false);
	ingrediente.add_allergene(ANIDRIDE_SOLFOROSA);
	ingrediente.add_allergene(MOLLUSCHI);
	ingrediente.add_allergene(CROSTACEI);
	cout << ingrediente << endl;
	
	Ingrediente ingrediente2("Farina", 1023, true, false);
	ingrediente2.add_allergene(GLUTINE);
	ingrediente2.add_allergene(MOLLUSCHI);
	ingrediente2.add_allergene(CROSTACEI);
	cout << ingrediente2 << endl;
	
	Prodotto pane("Pane", RISTORANTE, 4);
	pane.set_ingredienti(&ingrediente);
	pane.set_ingredienti(&ingrediente2);
	cout << "Prodotto " << pane << endl;
	
	RigaOrdine ord(4, "Ben Cotto", &pane);
	cout << ord;
	float tot;
	tot = ord.get_sub_totale();
	cout << tot;
	string note;
	note = ord.get_nota();
	cout << note;
	cout << "==================================" << endl;
	ord.set_quantita(23);
	ord.set_nota("Integrale");
	cout << ord;
}
