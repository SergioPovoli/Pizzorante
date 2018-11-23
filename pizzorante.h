#ifndef __PIZZORANTE_H__
#define __PIZZORANTE_H__

#include <iostream>
#include <string>
#include <set>
#include <ctime>
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
		set<Allergene> NodeAllergeni;
	public:
};

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
#endif

