#ifndef _STORE_H
#define _STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "customer.h"
#include "order.h"

#include <vector>
#include <iostream>
#include <algorithm>

class Store{
    private:
        std::string _name;
        std::vector<Product*> _products;
        std::vector<Customer*> _customers;
    protected:
        std::string filename;
    public:
        Store(std::string name);
        std::string get_filename();
        void set_filename(std::string filename);
        Store(std::istream& ist);
        void save(std::ostream& ost);
        void add_product(const Tool& product);
        void add_product(const Plant& product);
        void add_product(const Mulch& product);
        int products();
        Product& product(int index);

        void add_customer(const Customer& customer);
        int customers();
        const Customer& customer(int index);

        typedef std::vector<Order*> Orders;
        Orders _orders;
        int add_order(const Customer& customer);
        typedef Orders::iterator iterator;
        typedef Orders::const_iterator const_iterator;
        iterator begin(){return _orders.begin();}
        iterator end(){return _orders.end();}
        void add_item(int order, Product& product, int quantity);
      //  int orders();
       // const Order& order(int index);
};

#endif
