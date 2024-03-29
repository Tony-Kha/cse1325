#include "item.h"

double Item::subtotal(){
    return _product->price() * static_cast<double>(_quantity);
}

Item::Item(Product& product, int quantity): _product{&product}, _quantity{quantity} {}

Item::Item(std::istream& ist){
    ist >>  _quantity;
    ist.ignore(32767, '\n');
    std::string s;
    std::getline(ist, s);
    if(s == "tool") _product = new Tool(ist);
    else if(s == "plant") _product = new Plant(ist);
    else if(s == "mulch") _product = new Mulch(ist);
    else if(s.size()) throw std::runtime_error{"Invalid input: " + s};
}

void Item::save(std::ostream& ost){
    ost << _quantity << std::endl;
    _product->save(ost);
}

std::ostream& operator<<(std::ostream& ost, const Item& item){
    ost << item._quantity << ' ' << *item._product;
    return ost;
}
