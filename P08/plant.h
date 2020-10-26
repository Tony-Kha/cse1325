#ifndef _PLANT_H
#define _PLANT_H

#include "product.h"

enum class Exposure{
    SHADE,
    PARTSUN,
    SUN,
};

std::string to_string(Exposure exposure);

std::ostream& operator<<(std::ostream& ost, const Exposure& exposure);

class Plant: public Product{
    private:
        std::string _species;
        Exposure _exposure;
    protected:
        std::string to_string() const override;
    public:
        Plant(std::string name, double price, std::string description, std::string species, Exposure exposure);
        Plant(std::istream& ist);
        void save(std::ostream& ost);
};

#endif
