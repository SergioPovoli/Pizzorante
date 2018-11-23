#ifndef __PIZZORANTE_H__
#define __PIZZORANTE_H__

#include <iostream>
#include <string>
#include <set>
#include <ctime>
#include <map>
using namespace std;

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

class Ingrediente {
	private:
		string nome;
		int id_ingrediente;
		bool disponibile;
		bool surgelato;
		set<Allergene> nodeAllergeni;
	public:
		Ingrediente(string _nome, int _id_ingrediente, bool _disponibile, bool _surgelato/*, Allergene _allergene*/);
		void add_allergene (Allergene _allergene);
		void set_disponibile(bool _disponibile);
		bool get_disponibile();
		set<Allergene> get_allergeni ();
		bool operator < (const Ingrediente& _ingrediente)const;
		friend ostream& operator << (ostream& os, const Ingrediente& ingrediente) ;
};

//bool operator < ( Ingrediente& _ingrediente1, Ingrediente& _ingrediente2) ;
void test_Ingrediente();
ostream& operator << (ostream& os, const Ingrediente& ingrediente) ;
class Data {
private:
    unsigned int anno,mese,giorno,ora,minuto,secondi;
public:
    Data();
    Data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi);
    friend ostream& operator << (ostream& os, Data& _data);
    bool operator <(const Data& _data)const;
};

ostream& operator << (ostream& os, Data& _data);
void test_data();
typedef enum Reparto{
	PIZZERIA,
	RISTORANTE,
	BAR
}Reparto;

class Prodotto{
	private:
		string nome;
		Reparto reparto;
		float costo;
		bool disponibile;
		set<Ingrediente> ingredienti;
		set<Allergene> allergeni;
	public:
		Prodotto(string _nome, Reparto _reparto, float _costo);
		void set_disponibile(bool _disponibile);
		void set_ingredienti(const Ingrediente _ingredienti);
	//	void set_allergeni(Ingrediente _ingrediente);
		bool get_disponibile();
		float get_costo();
		bool operator < (const Prodotto& _prodotto)const;
};

class Ordine{
	private:
		int id_ordine;
		float sub_totale;
		set<Prodotto> prodotti;
		
	public:
		Ordine(int _id_ordine);
		void add_prodotti(Prodotto _prodotto);
		void set_sub_totale(Prodotto _prodotto);
		float get_sub_totale();
};

#endif

