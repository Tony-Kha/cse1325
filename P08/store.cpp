#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name}{}
Store::Store(std::istream& ist){
    ist >> _name;
    for(int i=0; i<_products.size(); i++){
        std::string type;
        std::getline(ist, type);
        if(type.compare("tool") == 0) _products.push_back(new Tool{ist});
        else if(type.compare("plant") == 0) _products.push_back(new Plant{ist});
        else if(type.compare("mulch") == 0) _products.push_back(new Mulch{ist});
    }
}
void Store::save(std::ostream& ost){
    ost << _name << std::endl;
    for(int i=0; i<_products.size(); i++){
        ost<< *_products.at(i)<<std::endl;
    }
}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store::product(int index) {return *_products.at(index);}
