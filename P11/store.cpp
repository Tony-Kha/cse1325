#include "store.h"

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
        else if(type.compare("customer") == 0) {
            _customers.push_back(new Customer{ist});
            std::sort(_customers.begin(), _customers.end(), [](Customer* &customer1, Customer* &customer2) -> bool{return customer1->name() < customer2->name();});
        }
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
Product& Store::product(int index) {return *_products.at(index);}

void Store::add_customer(const Customer& customer){
    _customers.push_back(new Customer{customer});
    std::sort(_customers.begin(), _customers.end(), [](Customer* &customer1, Customer* &customer2) -> bool{return customer1->name() < customer2->name();});
}
int Store::customers(){return _customers.size();}
const Customer& Store::customer(int index){return *_customers.at(index);}

int Store::add_order(const Customer& customer){ 
    _orders.push_back(new Order{customer});
    return _orders.size()-1;
}


void Store::add_item(int order, Product& product, int quantity){ 
    _orders[order]->add_item(Item{product, quantity});
}
//int Store::orders(){return _orders.size();}
//const Order& Store::order(int index){return *_orders.at(index);}



