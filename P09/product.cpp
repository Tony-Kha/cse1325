#include "product.h"
#include <cmath>

Product::Product(std::string name, double price, std::string description)
    :   _name{name}, _price{price}, _description{description}, _stocknum{++_nextsn} {}

Product::Product(std::istream& ist){
    std::getline(ist, _name);
    std::getline(ist, _description);
    ist >> _stocknum >> _price;
    ist.ignore(32767, '\n');

}

void Product::save(std::ostream& ost){
    ost << _name << std::endl;
    ost << _description << std::endl;
    //ost << _nextsn << std::endl;
    ost << _stocknum << std::endl;
    ost << _price << std::endl;

}

std::string Product::to_string() const{
    return _name + " (Stock#" + std::to_string(_stocknum)
                 + ", $" + std::to_string(round(_price*100)/100) + ")\n "
                 + _description;
}

std::ostream& operator<<(std::ostream& ost, const Product& product){
    ost << product.to_string();
    return ost;
}

int Product::_nextsn = 0;
