#include "pizzorante.h"

Ingrediente::Ingrediente(string _nome, int _id_ingrediente, bool _disponibile, bool _surgelato){
	nome = _nome;
	id_ingrediente = _id_ingrediente;
	disponibile = _disponibile;
	surgelato = _surgelato;
	
}

void Ingrediente::add_allergene (Allergene _allergene){
	allergeni.insert(_allergene);
}

void Ingrediente::set_disponibile(bool _disponibile){
	disponibile = _disponibile;
}

bool Ingrediente::get_disponibile()const{
	return disponibile;
} 

set<Allergene> Ingrediente::get_allergeni (){
	set <Allergene>::iterator iter;
	set <Allergene> temp;
	for (iter = allergeni.begin(); iter != allergeni.end(); iter++){
		temp.insert(*iter);
	}
	return temp;
}

bool Ingrediente::operator < (const Ingrediente& _ingrediente)const{
	bool tmp;
	tmp=(id_ingrediente < _ingrediente.id_ingrediente);
	return tmp;
}

ostream& operator << (ostream& os, const Ingrediente& ingrediente){
	set<Allergene>::iterator iter;
    os << ingrediente.nome << " ID: " << ingrediente.id_ingrediente << " " <<endl;
	if (ingrediente.disponibile == true){
		os << "Disponibile "<<endl;
	} else {
        os << "Non disponibile "<<endl;
	}
	if (ingrediente.surgelato == true){
		os << "Surgelato"<<endl;
	} else {
		os << "Non surgelato "<<endl;
	}
	for(iter = ingrediente.allergeni.begin(); iter != ingrediente.allergeni.end(); iter++){
        switch(*iter){
            case 0: os<< "Glutine" <<endl; break;
            case 1: os<< "Crostacei" <<endl; break;
            case 2: os<< "Uova" <<endl; break;
            case 3: os<< "Pesce" <<endl; break;
            case 4: os<< "Arachidi" <<endl; break;
            case 5: os<< "Latte" <<endl; break;
            case 6: os<< "Frutta a Guscio" <<endl; break;
            case 7: os<< "Sedano" <<endl; break;
            case 8: os<< "Senape" <<endl; break;
            case 9: os<< "Semi di Sesamo" <<endl; break;
            case 10: os<< "Anidride Solforosa" <<endl; break;
            case 11: os<< "Lupini" <<endl; break;
            case 12: os<< "Molluschi" <<endl; break;
            default: os<< "Errore" << endl;
        }
    }
    os << endl;
	return os;
}

void test_Ingrediente(){
	Ingrediente ingrediente("Acqua", 0000, true, false);
	ingrediente.add_allergene(ANIDRIDE_SOLFOROSA);
	ingrediente.add_allergene(MOLLUSCHI);
	ingrediente.add_allergene(CROSTACEI);
	cout << ingrediente << endl;
	ingrediente.set_disponibile(false);
	bool disp;
	disp = ingrediente.get_disponibile();
	cout << ingrediente << endl;
	cout <<"Disonibile: "<<  disp << endl;
	// SBAGLIATO
	set<Allergene>::iterator iter;
	cout << "Allergeni: " << endl;
	for (iter = ingrediente.get_allergeni().begin(); iter != ingrediente.get_allergeni().end(); iter++ ){
		switch(*iter){
            case 0: cout<< "Glutine" <<endl; break;
            case 1: cout<< "Crostacei" <<endl; break;
            case 2: cout<< "Uova" <<endl; break;
            case 3: cout<< "Pesce" <<endl; break;
            case 4: cout<< "Arachidi" <<endl; break;
            case 5: cout<< "Latte" <<endl; break;
            case 6: cout<< "Frutta a Guscio" <<endl; break;
            case 7: cout<< "Sedano" <<endl; break;
            case 8: cout<< "Senape" <<endl; break;
            case 9: cout<< "Semi di Sesamo" <<endl; break;
            case 10: cout<< "Anidride Solforosa" <<endl; break;
            case 11: cout<< "Lupini" <<endl; break;
            case 12: cout<< "Molluschi" <<endl; break;
            default: cout<< "Errore" << endl;
        }
	}
}
