#include "pizzorante.h"

Delivery::Delivery(int _q, string _n, Prodotto* _p, 
		unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi,
		Responsabile *resp, string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel) : 
		data_consegna(_anno, _mese, _giorno, _ora, _minuto, _secondi),
		responsabile (resp), Ordine(_q, _n, _p), 
		consegna(_via, _citta, _numero, _cap, _nome, _cognome, _num_tel){
			set<RigaOrdine>::iterator iter;
			sub_totale = 0;
			for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
				sub_totale = sub_totale + (*iter).get_sub_totale();
			}
}

Data Delivery::get_data_consegna() const{
	return data_consegna;
}

Responsabile* Delivery::get_responsabile() const{
	return responsabile;
}

void Delivery::set_responsabile(Responsabile* _resp){
	responsabile = _resp;
}

void Delivery::set_data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi){
	data_consegna = Data(_anno, _mese, _giorno, _ora, _minuto, _secondi);
}

float Delivery::aggiorna_sub_totale() {
	set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
		sub_totale = sub_totale + (*iter).get_sub_totale();
	}
	return sub_totale;
}

void Delivery::add_prodotti_delivery(int _q, string _n, Prodotto* _p){
	add_prodotti(_q, _n, _p);
	sub_totale = aggiorna_sub_totale();
}

void Delivery::remove_prodotti_delivery(int _q, string _n, Prodotto* _p){
	remove_prodotti(_q, _n, _p);
	sub_totale = aggiorna_sub_totale();
}

float Delivery::get_sub_totale() const{
	return sub_totale;
}

ostream& operator << (ostream& os, Delivery& d){
	os <<"Ordine " << d.get_id_ordine() << endl;
	set<RigaOrdine>::iterator iter;
	for (iter = d.get_begin_prodotti(); iter != d.get_end_prodotti(); iter++){
		os << *(iter) << endl;
	}
	os << "Del" << d.get_data() << endl;
	os <<"Operatore: " << *(d.responsabile) << endl;
	os << "Totale: Euro " << d.sub_totale << endl;
	os <<"Consegna prevista: " << d.get_data_consegna() << endl;
	os << "Presso " << d.consegna << endl;
    return os;
}

Consegna Delivery::get_consegna() const{
	return consegna;
}

void Delivery::set_consegna(string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel){
	consegna = Consegna(_via, _citta, _numero, _cap, _nome, _cognome, _num_tel);
}

void test_delivery(){
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
	Delivery deli(7, "Frizzante", &p, 2018, 16, 32, 14,63, 12, &r, "Fermi", "Trento", 191, 38123, "Buffa", "Irene", "3334448969");
	cout << deli << endl;
	deli.add_prodotti_delivery(9, "Ben cotto", &p1); 
	cout << deli << endl;
	Data cons;
	cons = deli.get_data_consegna();
	cout <<"DATA " << cons << endl;
	Responsabile* resp;
	resp = deli.get_responsabile();
	cout << "RESP " << *resp << endl;
	Responsabile r1("Gino","Gioppi",666999);
	deli.set_responsabile(&r1);
	cout << deli << endl;
	deli.set_data(2019,1,1,0,0,0);
	cout << deli << endl;
	deli.remove_prodotti_delivery(7, "Frizzante", &p);
	cout << deli << endl;
	float tot;
	tot = deli.get_sub_totale();
	cout << "TOT " << tot << endl;
	Consegna via = deli.get_consegna();
	//via = ;
	cout << "Consegna " << via <<endl ;
	deli.set_consegna("Via Verdi", "Tenna", 1, 38070, "Maria", "Del Bepi", "0471653248");
	cout << deli;
}
