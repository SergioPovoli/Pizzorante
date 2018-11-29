#include "pizzorante.h"

Prodotto::Prodotto(string _nome, Reparto _reparto, float _costo){
	reparto = _reparto;
	costo = _costo;
	nome = _nome;
}

/*Prodotto::Prodotto (Prodotto& _p){
	set<Ingrediente *>::iterator iter;
	reparto = _p.reparto;
	costo = _p.costo;
	nome = _p.nome;
	disponibile = _p.disponibile;
	for (iter = ingredienti.begin(); iter != ingredienti.end(); iter++){
		_p.ingredienti.insert(*iter);
	}
}*/

void Prodotto::set_ingredienti( Ingrediente* _ingredienti){
	set<Ingrediente *>::iterator iiter;
	set<Allergene>::iterator aiter;
    
	ingredienti.insert(_ingredienti);
    
   /* for(iiter=ingredienti.begin();iiter!=ingredienti.end();++iiter){
        for(aiter=_ingredienti->get_allergeni_begin();aiter!=_ingredienti->get_allergeni_end();++aiter){
            allergeni.insert((*aiter));
        }
    }
    */
    disponibile=true;
    for(iiter=ingredienti.begin();iiter!=ingredienti.end();++iiter)
        if(!(*iiter)->get_disponibile())
        {
            disponibile=false;
            break;
        }
}

bool Prodotto::get_disponibile()const{
	return disponibile;
}

float Prodotto::get_costo()const{
	return costo;
}

void Prodotto::set_costo(float _c){
	costo = _c;
}

bool Prodotto::operator < (const Prodotto& _prodotto)const{
	return (nome < _prodotto.nome);
}

ostream& operator << (ostream& os, const Prodotto& _prodotto){
	set<Ingrediente *>::iterator iiter;
	set<Allergene>::iterator aiter;
    os<< "- "<<_prodotto.nome<<" -"<<endl;
	os << _prodotto.costo << " Euro "<< endl << "Reparto: ";
	switch(_prodotto.reparto){
		case PIZZERIA: os << "Pizzeria" << endl; break;
		case RISTORANTE: os << "Ristorante" << endl; break;
		case BAR: os << "Bar" << endl; break;
		default: os<< "Errore" << endl;
	}
	if (_prodotto.disponibile == true){
		os << "Disponibile ";
	} else {
		os << "Non disponibile ";
	}
	os << endl;
    
    os<<"- Composto da: -" << endl<<endl;
	for (iiter = _prodotto.ingredienti.begin(); iiter != _prodotto.ingredienti.end(); ++iiter){
		os << *(*iiter);
	}
   /* os << endl<< "Allergeni Totali: " << endl;
	for (aiter = _prodotto.allergeni.begin(); aiter != _prodotto.allergeni.end(); ++aiter){
		switch(*aiter){
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
	}*/
	os << endl;
	return os;
}

void test_Prodotto(){
	Prodotto p("Acqua", BAR, 1);
	Ingrediente i("h2o", 0000, false, false);
	i.add_allergene(GLUTINE);
	i.add_allergene(MOLLUSCHI);
	Ingrediente i2("Bicchiere", 1, true, false);
	p.set_ingredienti(&i);
	p.set_ingredienti(&i2);
	cout << p;
}
