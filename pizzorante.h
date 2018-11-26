#ifndef __PIZZORANTE_H__
#define __PIZZORANTE_H__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <map>
using namespace std;

//  ALLERGENE
typedef enum Allergene{
	GLUTINE,
	CROSTACEI,
	UOVA,
	PESCE,
	ARACHIDI,
	LATTE,
	FRUTTA_A_GUSCIO,
	SEDANO,
	SENAPE,
	SEMI_DI_SESAMO,
	ANIDRIDE_SOLFOROSA,
	LUPINI,
	MOLLUSCHI
}Allergene;

// INGREDIENTE
class Ingrediente {
	private:
		string nome;
		int id_ingrediente;
		bool disponibile;
		bool surgelato;
		set<Allergene> allergeni;
	public:
		Ingrediente(string _nome, int _id_ingrediente, bool _disponibile, bool _surgelato);
		void add_allergene (Allergene _allergene);
		void set_disponibile(bool _disponibile);
		bool get_disponibile()const;
        set<Allergene>::iterator get_allergeni_end ()const;
        set<Allergene>::iterator get_allergeni_begin ()const;
		bool operator < (const Ingrediente& _ingrediente)const;
		friend ostream& operator << (ostream& os, const Ingrediente& ingrediente) ;
};

void test_Ingrediente();
ostream& operator << (ostream& os, const Ingrediente& ingrediente) ;

// DATA
class Data {
private:
    unsigned int anno,mese,giorno,ora,minuto,secondi;
public:
    Data();
    Data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi);
    friend ostream& operator << (ostream& os,const Data& _data);
    bool operator <(const Data& _data)const;
};

ostream& operator << (ostream& os, const Data& _data);
void test_data();

//REPARTO
typedef enum Reparto{
	PIZZERIA,
	RISTORANTE,
	BAR
}Reparto;

// PRODOTTO
class Prodotto{
	private:
		string nome;
		Reparto reparto;
		float costo;
		bool disponibile;
		set<Ingrediente *> ingredienti;
        set<Allergene> allergeni;
	public:
		Prodotto(string _nome, Reparto _reparto, float _costo);
		void set_ingredienti( Ingrediente* _ingredienti);
	//	void set_allergeni(Ingrediente _ingrediente);
		bool get_disponibile()const;
		float get_costo()const;
		bool operator < (const Prodotto& _prodotto)const;
		friend ostream& operator << (ostream& os, const Prodotto& _prodotto);
};


ostream& operator << (ostream& os, const Prodotto& _prodotto);
void test_Prodotto();

// ORDINE

class Ordine{
	private:
		int id_ordine;
		float sub_totale;
		set<Prodotto*> prodotti;
		Data data;
	public:
		Ordine(int _id_ordine);
		void add_prodotti(Prodotto* _prodotto);
		float get_sub_totale()const;
		friend ostream& operator << (ostream& os, const Ordine& _ordine);
};

ostream& operator << (ostream& os, const Ordine& _ordine);
void test_Ordine();

// PERSONA
class Persona{
private:
    string nome;
    string cognome;
public:
    Persona(string _nome, string _cognome);
    string get_nome()const;
    string get_cognome()const    ;
    
    friend ostream& operator << (ostream& os, const Persona& _persona);

};

ostream& operator << (ostream& os, const Persona& _persona);
void test_persona();


// CLIENTE

class Cliente: public Persona{
private:
    string numero_tel;
    
public:
    Cliente(string _nome, string _cognome, string _numero_tel);
   friend ostream& operator <<(ostream& os, const Cliente& _cliente);
};

ostream& operator <<(ostream& os, const Cliente& _cliente);

void test_cliente();

//RESPONSABILE

class Responsabile: public Persona{
private:
    int num_matricola;
public:
    Responsabile(string _nome, string _cognome, int _num_matricola);
    friend ostream& operator <<(ostream& os, Responsabile &_responsabile);
    
};

void test_responsabile();

ostream& operator <<(ostream& os, Responsabile &_responsabile);

//CAMERIERE

class Cameriere: public Persona{
private:
    int num_matricola;
public:
    Cameriere(string _nome, string _cognome, int _num_matricola);
    friend ostream& operator <<(ostream& os, Cameriere& _cameriere);
};
ostream& operator <<(ostream& os, Cameriere& _cameriere);
void test_cameriere();

// PRENOTAZIONE

class Tavolo; //Avviso della presenza di una classe Tavolo che andrò ad implementare successivamente

class Prenotazione{
private:
    int num_posti;
    Cliente cliente;
    Responsabile* responsabile;
    Data prenotatoil;
    Data prenotatoper;
    Tavolo* tavolo;
public:
    Prenotazione(string _nomecli, string _cognomecli, string _numerocli, int _num_posti, Responsabile* _resposnabile, unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondo, Tavolo* _tavolo);
    friend ostream& operator << (ostream& os, Prenotazione& _prenotazione);
    bool operator < (const Prenotazione& _prenotazione)const;
};

ostream& operator << (ostream& os, Prenotazione& _prenotazione);
void test_prenotazione();

//POSIZIONE
typedef enum Posizione{
    SALA1,
    SALA2,
    VERANDA
}Posizione;

// TAVOLO
class Tavolo{
private:
    int numero;
    int num_posti;
    Posizione posizione;
    bool occupato;
    bool prenotato;
    set<Prenotazione*> prenotazioni;
public:
    Tavolo(int _numero, int _num_posti, Posizione _posizione, bool _occupato=false, bool _prenotato=false);
    bool get_prenotato()const;
    bool get_occupato()const;
    int get_numero()const;
    void set_occupato(bool _occupato);
    void set_prenotato(bool _prenotato);
    void inserisci_prenotazione(Prenotazione* _prenotazione);
    void cancella_prenotazioni();
    void stampa_listaprenotazioni();
    void rimuoviprenotazione(Prenotazione* _prenotazione);
    
    friend ostream& operator <<(ostream& os, Tavolo& _tavolo);
};

ostream& operator <<(ostream& os, Tavolo& _tavolo);

void test_tavolo();

// CONSEGNA

class Consegna{
private:
    string via;
    int numero;
    string citta;
    int cap;
    Cliente cliente;
public:
    Consegna(string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel);
    
    friend ostream& operator <<(ostream& os, Consegna& _consegna);
};

void test_consegna();
ostream& operator <<(ostream& os, Consegna& _consegna);

//TAKE AWAY
class TakeAway: public Ordine {
	private:
		Data data;
		Cliente cliente;
		Responsabile* responsabile;
	public:
		
};
#endif
