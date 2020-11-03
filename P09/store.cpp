#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name}, filename{"untitled.store"} {}
std::string Store::get_filename(){return filename;}
void Store::set_filename(std::string filename){this->filename = filename;}

Store::Store(std::istream& ist){
    std::getline(ist, _name);
    while(ist){
        std::string type;
        std::getline(ist, type);
        if(type.compare("tool") == 0) _products.push_back(new Tool{ist});
        else if(type.compare("plant") == 0) _products.push_back(new Plant{ist});
        else if(type.compare("mulch") == 0) _products.push_back(new Mulch{ist});
        else if(type.compare("customer") == 0) _customers.push_back(new Customer{ist});
    }
}
void Store::save(std::ostream& ost){
    ost << _name << std::endl;
    for(int i=0; i<_products.size(); i++){
        _products.at(i)->save(ost);
        ost << std::endl;
    }
    for(int i=0; i<_customers.size(); i++){
        _customers.at(i)->save(ost);
        ost << std::endl;  
    }
}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store::product(int index) {return *_products.at(index);}

void Store::add_customer(const Customer& customer){_customers.push_back(new Customer{customer});}
int Store::customers(){return _customers.size();}
const Customer& Store::customer(int index){return *_customers.at(index);}
