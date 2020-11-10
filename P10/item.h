#ifndef __ITEM_H
#define __ITEM_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

class Item {
    private:
        Product* _product;
        int _quantity;
    public:
        double subtotal();
        Item(Product& product, int quantity);
        Item(std::istream& ist);
        void save(std::ostream& ost);
};

#endif
