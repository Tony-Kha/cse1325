#include "modulo.h"
#include <iostream>

int Modulo::compare(const int rhs){
    if(_value < rhs) return -1;
    if(_value > rhs) return 1;
    return 0;
}

Modulo::Modulo(int modulo, int value, int offset):_modulo{modulo}, _value{value}, _offset{offset}{}

void Modulo::set_nmsd(Modulo* nmsd){ 
    _nmsd = nmsd;
}

int Modulo::value(){return _value;}

Modulo& Modulo::operator+=(int rhs){ 
    for( ; rhs>0; --rhs) ++(*this);
    return *this;     
}

Modulo Modulo::operator+(int rhs){ 
    Modulo d{*this};
    d += rhs;
    return d;      
}

Modulo& Modulo::operator++(){
    ++_value;
    if(_value > _modulo){
        _value = _offset;
        if(_nmsd){
            ++(*_nmsd);
        }
    }
    return *this;
}

Modulo Modulo::operator++(int){
    Modulo modulo{*this};
    ++*this;
    return modulo;
}

std::ostream& operator<<(std::ostream& ost, Modulo& m){
    ost<<m._value;
    return ost;
}

std::istream& operator>>(std::istream& is, Modulo& m){
    is>>m._value;
    if(m._value > m._modulo)
        throw std::runtime_error{"Invalid number"};
    return is;
}





