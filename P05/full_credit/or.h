#ifndef _OR_H
#define _OR_H

#include "gate.h"

class Or : public Gate{
    public:
        Signal output()override;
};
#endif
