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

void Ingrediente::set_disponibile(bool _disponibile){
	disponibile = _disponibile;
}

bool Ingrediente::get_disponibile(){
	return disponibile;
} 

set<Allergene> Ingrediente::get_allergeni (){
	return nodeAllergeni;
}

bool Ingrediente::operator < (const Ingrediente& _ingrediente)const{
	bool tmp;
	tmp=(id_ingrediente < _ingrediente.id_ingrediente);
	return tmp;
}

ostream& operator << (ostream& os, const Ingrediente& ingrediente){
	set<Allergene>::iterator iter;
	os << ingrediente.nome << " " << ingrediente.id_ingrediente << " ";
	if (ingrediente.disponibile == true){
		os << "Disponibile ";
	} else {
		os << "Non disponibile ";
	}
	if (ingrediente.surgelato == true){
		os << "Surgelato ";
	} else {
		os << "Non surgelato ";
	}
	for(iter = ingrediente.nodeAllergeni.begin(); iter != ingrediente.nodeAllergeni.end(); iter++){
		os << *iter;
	}
	return os;
}

void test_Ingrediente(){
	Ingrediente ingrediente("Acqua", 0000, true, false);
	ingrediente.add_allergene(ANIDRIDE_SOLFOROSA);
	cout << ingrediente << endl;
	ingrediente.set_disponibile(false);
	bool disp;
	disp = ingrediente.get_disponibile();
	cout << ingrediente << endl;
}
