#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <algorithm>

class Customer {
    private:
        std::string _name;
        std::string _phone;
        std::string _email;
    protected:
        virtual std::string to_string() const;
    public:
        Customer(std::string name, std::string phone, std::string email);
        Customer(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
        std::string name();
};

#endif
