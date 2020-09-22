#ifndef _MODULO_H
#define _MODULO_H
#include <iostream>
#include <ostream>

class Modulo{
    private:
        int _value, _modulo, _offset;
        Modulo* _nmsd;
        int compare(const int rhs);
    public:
        Modulo(int modulo=10, int value=0, int offset=0); 
        Modulo set_nmsd(Modulo* nmsd);
        int value();
        Modulo& operator+=(int rhs);
        Modulo operator+(int rhs);
        Modulo& operator++();
        Modulo operator++(int ignored);
        inline bool operator==(const int rhs){return (compare(rhs) == 0);}
        inline bool operator!=(const int rhs){return (compare(rhs) != 0);} 
        inline bool operator< (const int rhs){return (compare(rhs) <  0);}
        inline bool operator<=(const int rhs){return (compare(rhs) <= 0);}
        inline bool operator> (const int rhs){return (compare(rhs) >  0);}
        inline bool operator>=(const int rhs){return (compare(rhs) >= 0);}
        friend std::ostream& operator<<(std::ostream& ost, Modulo& m);
        friend std::istream& operator>>(std::istream& ost, Modulo& m);
};

#endif
