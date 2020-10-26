#ifndef _STORE_H
#define _STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

#include <stdexcept>
#include <cstdlib>
#include <vector>

class Store{
    private:
        std::string _name;
        std::vector<Product*> _products;
    public:
        Store(std::string name);
        Store(std::istream& ist);
        void save(std::ostream& ost);
        void add_product(const Tool& product);
        void add_product(const Plant& product);
        void add_product(const Mulch& product);
        int products();
        const Product& product(int index);
};

#endif
