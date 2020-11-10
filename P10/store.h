#ifndef _STORE_H
#define _STORE_H

#include "order.h"

#include <stdexcept>
#include <cstdlib>
#include <vector>

class Store{
    private:
        std::string _name;
        std::vector<Product*> _products;
        std::vector<Customer*> _customers;
        std::vector<Order*> _orders;
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
        const Product& product(int index);

        void add_customer(const Customer& customer);
        int customers();
        const Customer& customer(int index);

        int add_order(const Customer& customer);
        void add_item(int order, const Product& product, int quantity);
        int orders();
        const Order& order(int index);

        std::string c_to_string(int index);
        std::string p_to_string(int index);
};

#endif
