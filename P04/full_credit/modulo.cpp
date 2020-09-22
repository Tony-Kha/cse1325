#include "modulo.h"

int Modulo::compare(const int rhs){
    if(_value < rhs._value) return -1;
    if(_value > rhs._value) return 1;
    return 0;
}

Modulo::Modulo(int modulo, int value, int offset):_modulo{modulo}, _value{value}, _offset{offset}{}

Modulo::set_nmsd(Modulo* nmsd){ 
    if(++_value==_offset)
        ++nmsd._value;
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
    if(_value == _modulo) 
        _value = _offset;
    else
        ++_value;
    return *this;
}

Modulo Modulo::operator++(int ignored){
    Modulo modulo{*this};
    ++*this;
    return modulo;
}

inline bool Modulo::operator==(int rhs){return (compare(rhs) == 0);}

inline bool Modulo::operator!=(int rhs){return (compare(rhs) != 0);}  

inline bool Modulo::operator< (int rhs){return (compare(rhs) <  0):}

inline bool Modulo::operator<=(int rhs){return (compare(rhs) <= 0);}

inline bool Modulo::operator> (int rhs){return (compare(rhs) >  0);}

inline bool Modulo::operator>=(int rhs){return (compare(rhs) >= 0);}

std::ostream& operator<<(std::ostream& ost, Modulo& m){
    ost<<m._value;
    return ost;
}

std::istream& operator>>(std::istream& is, Modulo& m){
    is>>m._value;
    if(m._value > m.modulo)
        throw std::runtime_error{"Invalid number"};
    return is;
}





