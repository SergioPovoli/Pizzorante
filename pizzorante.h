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
		void remove_allergene (Allergene _allergene);
		void set_surgelato(bool _surgelato);
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
        //set<Allergene> allergeni;
	public:
		Prodotto(string _nome, Reparto _reparto, float _costo);
	//	Prodotto (Prodotto& _p);
		void set_ingredienti( Ingrediente* _ingredienti);
		void remove_ingrediente (Ingrediente* _ingrediente);
	//	void set_allergeni(Ingrediente _ingrediente);
		bool get_disponibile()const;
		float get_costo()const;
		void set_costo(float _c);
		bool operator < (const Prodotto& _prodotto)const;
		friend ostream& operator << (ostream& os, const Prodotto& _prodotto);
};


ostream& operator << (ostream& os, const Prodotto& _prodotto);
void test_Prodotto();

// RIGA ORDINE

class RigaOrdine{
	private:
		int quantita;
		string nota;
		Prodotto* prodotto;
		float sub_totale;
	public:
		RigaOrdine(int _q, string _n, Prodotto* _p);
		float get_sub_totale()const ;
		string get_nota()const;
		void set_quantita(int _q);
		void set_nota(string _n);
		friend ostream& operator << (ostream& os, const RigaOrdine& _ro);
		bool operator < (const RigaOrdine& _ro) const;
};

ostream& operator << (ostream& os, const RigaOrdine& _ro);
void test_riga_ordine();

// ORDINE
class Tavolo;

class Ordine{
	private:
        static int id_ordine;
	//	float sub_totale;
		RigaOrdine riga;
		set<RigaOrdine> prodotti; 
		Data data; 
	public:
		Ordine(int _q, string _n, Prodotto* _p);
        ~Ordine();
		void add_prodotti(int _q, string _n, Prodotto* _p);
		void remove_prodotti(int _q, string _n, Prodotto* _p);
	//	float get_sub_totale()const;
	//	void set_sub_totale(float _tot);
		set<RigaOrdine>::iterator get_begin_prodotti();
		set<RigaOrdine>::iterator get_end_prodotti();
		Data get_data() const;
		int get_id_ordine() const;
		friend ostream& operator << (ostream& os, const Ordine& _ordine);
        bool operator <( Ordine& _ordine);
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
    string get_cognome()const;
    void set_nome(string _nome);
    void set_cognome(string _cognome);
    
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
    ~Cliente();
    void modifica_nome(string _nome);
    void modifica_cognome (string _cognome);
    void modifica_numero_tel(string _numero_tel);
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
    void modifica_num_matricola(int _num_matricola);
    void modifica_nome(string _nome);
    void modifica_cognome(string _cognome);
    
};

void test_responsabile();
void stampa_responsabile(Responsabile& resp);
ostream& operator <<(ostream& os, Responsabile &_responsabile);

//CAMERIERE

class Cameriere: public Persona{
private:
    int num_matricola;
public:
    Cameriere(string _nome, string _cognome, int _num_matricola);
    friend ostream& operator <<(ostream& os, Cameriere& _cameriere);
    void modifica_num_matricola(int _num_matricola);
    void modifica_nome(string _nome);
    void modifica_cognome(string _cognome);
};
ostream& operator <<(ostream& os, Cameriere& _cameriere);
void test_cameriere();
void stampa_cameriere(Cameriere &c);

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
    void modifica_num_posti(int _num_posti);
    void modifica_cliente(string _nome,string _cognome, string _nume_tel);
    void modifica_responsabile(Responsabile* r1);
    void modifica_prenotatoper(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondo);
    void modifica_tavolo(Tavolo *t);
    
    friend ostream& operator << (ostream& os, Prenotazione& _prenotazione);
    bool operator < (const Prenotazione& _prenotazione)const;
    
};

ostream& operator << (ostream& os, Prenotazione& _prenotazione);
void test_prenotazione();
void stampa_prenotazione(Prenotazione &p);


//POSIZIONE
typedef enum Posizione{
    SALA1,
    SALA2,
    VERANDA
}Posizione;

class Comanda;

// TAVOLO
class Tavolo{
private:
    int numero;
    int num_posti;
    Posizione posizione;
    bool occupato;
    bool prenotato;
    set<Prenotazione*> prenotazioni;
    set<Comanda*> comande;
    float subtotale_tavolo;
public:
    Tavolo(int _numero, int _num_posti, Posizione _posizione, bool _occupato=false, bool _prenotato=false);
    bool get_prenotato()const;
    bool get_occupato()const;
    int get_numero()const;
    void set_occupato(bool _occupato);
    void set_prenotato(bool _prenotato);
    void inserisci_comanda(Comanda* _comanda);
    void paga();
    void rimuouvicomanda(Comanda* _comanda);
    void stampacomande();
    void inserisci_prenotazione(Prenotazione* _prenotazione);
    void cancella_prenotazioni();
    void stampa_listaprenotazioni();
    void rimuoviprenotazione(Prenotazione* _prenotazione);
    float aggiorana_subtotale();
    
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
    void modifica_via(string _via);
    void modifica_numero(int _numero);
    void modifica_citta(string _citta);
    void modifica_cap(int _cap);
    void modifica_cliente(string _nome, string _cognome, string _numero);
    friend ostream& operator <<(ostream& os, Consegna& _consegna);
};

void test_consegna();
ostream& operator <<(ostream& os, Consegna& _consegna);
void stampa_consegna(Consegna& con);


//COMANDA
class Comanda: public Ordine{
private:
    Cameriere* cameriere;
    Tavolo* tavolo;
    float sub_totale;
public:
    Comanda(int _quantita, string nota, Prodotto* _prodotto, Cameriere* _camereire, Tavolo* _tavolo);
    void modifica_tavolo(Tavolo* t);
    void modifica_cameriere(Cameriere* c);
    float aggiorna_sub_totale() ;
    void add_prodotti_comanda(int _q, string _n, Prodotto* _p);
    void remove_prodotti_comanda(int _q, string _n, Prodotto* _p);
    float get_sub_totale() const;
    bool operator <(Comanda& _ordine);
    friend ostream& operator <<(ostream& os, Comanda& _comanda);
};
ostream& operator <<(ostream& os, Comanda& _comanda);


//TAKE AWAY
class TakeAway: public Ordine {
	private:
		Data data_consegna;
		Responsabile* responsabile;
		float sub_totale;
	public:
		TakeAway(int _q, string _n, Prodotto* _p, unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi, Responsabile *resp);
		Data get_data_consegna() const;
		Responsabile* get_responsabile() const;
		void set_responsabile(Responsabile* _resp);
		void set_data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi);
		float aggiorna_sub_totale() ;
		void add_prodotti_take(int _q, string _n, Prodotto* _p);
		void remove_prodotti_take(int _q, string _n, Prodotto* _p);
		float get_sub_totale() const;
		friend ostream& operator << (ostream& os,  TakeAway& ta );
};

ostream& operator << (ostream& os, const TakeAway& ta );
void test_takeAway();

//DELIVERY
class Delivery:public Ordine {
	private:
		Data data_consegna;
		Responsabile* responsabile;
		float sub_totale;
		Consegna consegna;
	public:
		Delivery(int _q, string _n, Prodotto* _p, unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi, Responsabile *resp, string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel);
		Data get_data_consegna() const;
		Responsabile* get_responsabile() const;
		void set_responsabile(Responsabile* _resp);
		void set_data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi);
		float aggiorna_sub_totale();
		void add_prodotti_delivery(int _q, string _n, Prodotto* _p);
		void remove_prodotti_delivery(int _q, string _n, Prodotto* _p);
		float get_sub_totale() const;
		Consegna get_consegna() const;
		void set_consegna(string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel);
		friend ostream& operator << (ostream& os, Delivery& d);
};

ostream& operator << (ostream& os, const Delivery& d);
void test_delivery();

#endif
