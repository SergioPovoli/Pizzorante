#include "pizzorante.h"

TakeAway::TakeAway(int _q, string _n, Prodotto* _p, unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, 
	unsigned int _minuto, unsigned int _secondi, Responsabile* resp): 
		data(_anno, _mese, _giorno, _ora, _minuto, _secondi),
		responsabile (resp), Ordine(_q, _n, _p){
	set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
		sub_totale = sub_totale + (*iter).get_sub_totale();
	}
}

Data TakeAway::get_data() const{
	return data;
}

Responsabile* TakeAway::get_responsabile() const{
	return responsabile;
}

void TakeAway::set_responsabile(Responsabile* _resp){
	responsabile = _resp;
}
		
void TakeAway::set_data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi){
/*	data.anno=_anno;
    data.mese=_mese;
    data.giorno=_giorno;
    data.ora=_ora;
    data.minuto=_minuto;
    data.secondi=_secondi;*/
}

float TakeAway::get_sub_totale() const{
	return sub_totale;
}

ostream& operator << (ostream& os, TakeAway& ta ){
	os <<"Ordine " << ta.get_id_ordine() << endl;
	set<RigaOrdine>::iterator iter;
	for (iter = ta.get_begin_prodotti(); iter != ta.get_end_prodotti(); iter++){
		os << *(iter) << endl;
	}
	os << "Del" << ta.get_data() << endl;
	os <<"Operatore: " << &(ta.responsabile) << endl;
	os << "Totale: Euro " << ta.sub_totale << endl;
	os <<"Consegna prevista: " << ta.get_data() << endl;
    return os;
}

void test_takeAway(){
	Prodotto p("Acqua", BAR, 3);
	Ingrediente i("H20", 0000, true, false);
	Ingrediente i2("Bicchiere", 1, true, false);
	p.set_ingredienti(&i);
	p.set_ingredienti(&i2);
	Prodotto p1("Pane", RISTORANTE, 3);
	Ingrediente i3("Farina", 1023, true, false);
	Ingrediente i4("Lievito", 1, true, true);
	p1.set_ingredienti(&i3);
	p1.set_ingredienti(&i4);
	RigaOrdine ord(9, "Ben cotto", &p1);
	Responsabile r("Giacomo","Planke",185790);
	TakeAway take(4, "Naturale", &p, 2018, 12, 1, 15, 34, 16, &r);
}
