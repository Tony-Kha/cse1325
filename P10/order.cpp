#include "order.h"

Order::Order(const Customer& customer): _customer{customer} {}

//Order::Order(std::istream ist){}
/*    ist >> _customer;
    while(ist){
        _items.push_back(new Item{ist});
    }
*/

void Order::save(std::ostream ost){
    ost << _customer << std::endl;
    for(int i=0; i<_items.size(); i++){
        _items.at(i).save(ost);
        ost << std::endl;
    }
}

void Order::add_item(const Item& item) {_items.push_back(item);}

double Order::total(){
    double sum;
    for(int i=0; i<_items.size(); i++){
        sum += _items.at(i).subtotal();
    }
    return sum;
}

std::string Order::to_string() const{
    return "order";
}

std::ostream& operator<<(std::ostream& ost, const Order& order){
    ost << order.to_string();
    return ost;
}
