#ifndef _ORDER_H
#define _ORDER_H

#include <vector>
#include "customer.h"
#include "item.h"

class Order{
    private:
        std::vector<Item> _items;
        Customer _customer;
    public:
        Order(const Customer& customer);
        Order(std::istream ist);
        void save(std::ostream ost);
        void add_item(const Item& item);
        double total() const;
        friend std::ostream&  operator<<(std::ostream& ost, const Order& order);
};

#endif
