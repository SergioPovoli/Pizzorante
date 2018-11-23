#ifndef __PIZZORANTE_H__
#define __PIZZORANTE_H__

#include <iostream>
#include <string>
#include <set>
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

typedef enum Reparto{
	PIZZERIA,
	RISTORANTE,
	BAR
}Reparto;

class Prodotto{
	private:
		Reparto reparto;
		float costo;
		bool disponibile;
		set<Ingrediente> ingredienti;
		set<Allergene> allergeni;
	public:
		Prodotto(Reparto _reparto, float _costo);
		void set_disponibile(bool _disponibile);
		void set_ingredienti(const Ingrediente _ingredienti);
	//	void set_allergeni(Ingrediente _ingrediente);
};

#endif

