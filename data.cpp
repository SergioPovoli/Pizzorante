#include "pizzorante.h"

//DATA::COSTRUTTORE 0 PARAMETRI --> ORA DI ADESSO
Data::Data(){
    time_t now;
    now=time(0);
    tm *ltm=localtime(&now);
    secondi=ltm->tm_sec;
    minuto=ltm->tm_min;
    ora=ltm->tm_hour;
    giorno=ltm->tm_mday;
    mese=ltm->tm_mon+1;
    anno=ltm->tm_year +1900;

}
//DATA::COSTRUTTORE PARAMETRI
Data::Data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi){
    anno=_anno;
    mese=_mese;
    giorno=_giorno;
    ora=_ora;
    minuto=_minuto;
    secondi=_secondi;
}

//STAMPA DATA --> OPERATORE <<
ostream& operator << (ostream& os, Data& _data){
    if(_data.giorno<10){
        os<<"0"<<_data.giorno<<"/";
    }else{
        os<<_data.giorno<<"/";
    }
    
    if(_data.mese<10){
        os<<"0"<<_data.mese<<"/";
    }else{
        os<<_data.mese<<"/";
    }
    
    os<<_data.anno<<endl;
    
    if(_data.ora<10){
        os<<"0"<<_data.ora;
    }else{
        os<<_data.ora;
    }
    
    if(_data.minuto<10 && _data.secondi>10){
    os<<":0"<<_data.minuto<<":"<<_data.secondi<<endl;
    }else{
        if(_data.secondi>10 && _data.secondi<10){
        os<<":"<<_data.minuto<<":O"<<_data.secondi<<endl;
        }else{
            if(_data.minuto<10 && _data.secondi<10){
        os<<":0"<<_data.minuto<<":0"<<_data.secondi<<endl;
            }else{
                os<<":"<<_data.minuto<<":"<<_data.secondi<<endl;
            }
        }
    }
    return os;
}

//DATA::TEST DATA
void test_data(){
    Data d1;
    Data d2(2018,12,19,7,14,7);
    cout<<d1<<d2;
    if(d1<d2){
        cout<<"ok";
    }
}

//DATA:: OPERATOR <
bool Data::operator <(const Data& _data)const{
    if(anno<_data.anno){
        return true;
    }else{
        if(anno==_data.anno && mese<_data.mese){
            return true;
        }else{
            if(anno==_data.anno && mese==_data.mese && giorno<_data.giorno){
                return true;
            }else{
                if(anno==_data.anno && mese==_data.mese && giorno==_data.giorno && ora<_data.ora){
                    return true;
                }else{
                    if(anno==_data.anno && mese==_data.mese && giorno==_data.giorno && ora==_data.ora && minuto<_data.minuto){
                        return true;
                    }else{
                        if(anno==_data.anno && mese==_data.mese && giorno==_data.giorno && ora==_data.ora && minuto==_data.minuto && secondi<_data.secondi){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
            
        }
    }
}
