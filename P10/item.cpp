#include "item.h"

double Item::subtotal(){
    double product = _product->Product::price() * _quantity;
    return product;
}

Item::Item(Product& product, int quantity): _product{nullptr}, _quantity{quantity} {}

/*Item::Item(std::istream& ist){
    ist >> _product >> _quantity;
    ist.ignore(32767, '\n');     
}*/

void Item::save(std::ostream& ost){
    ost << _product << std::endl;
    ost << _quantity << std::endl;
}
