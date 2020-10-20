#ifndef _MULCH_H
#define _MULCH_H

#include "product.h"

enum class Material{
    RUBBER,
    PINE,
    CEDAR,
    HARDWOOD,
};

std::string to_string(Material material);

std::ostream& operator<<(std::ostream& ost, const Material& material);

class Mulch : public Product{
    private:
        int _volume;
        Material _material;
    protected:
        std::string to_string()const override;
    public:
        Mulch(std::string name, double price, std::string description, int volume, Material material);
};

#endif
