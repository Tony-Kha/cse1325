#ifndef _TOOL_H
#define _TOOL_H

#include "product.h"

class Tool : public Product{
    public:
        Tool(std::string name, double price, std::string description);
};

#endif
