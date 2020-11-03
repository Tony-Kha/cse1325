#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

class Product{
    private:
        static int _nextsn;
        std::string _name;
        int _stocknum;
        double _price;
        std::string _description;
    protected:
        virtual std::string to_string() const;
    public:
        Product(std::string name, double price, std::string description);
        friend std::ostream& operator<<(std::ostream& ost, const Product& product);
        Product(std::istream& ist);
        virtual void save(std::ostream& ost);
};

#endif
