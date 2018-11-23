#include "pizzorante.h"

Ingrediente::Ingrediente(string _nome, int _id_ingrediente, bool _disponibile, bool _surgelato/*, Allergene _allergene*/){
	nome = _nome;
	id_ingrediente = _id_ingrediente;
	disponibile = _disponibile;
	surgelato = _surgelato;
	//nodeAllergeni.insert(_allergene);
}

void Ingrediente::add_allergene (Allergene _allergene){
	nodeAllergeni.insert(_allergene);
}

void test_Ingrediente(){
	Ingrediente ingrediente("Acqua", 0000, 1, 0);
	ingrediente.add_allergene(ANIDRIDE_SOLFOROSA);
	
}
