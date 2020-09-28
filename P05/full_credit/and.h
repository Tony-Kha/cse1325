#ifndef _AND_H
#define _AND_H

#include "gate.h"

class And : public Gate{
    public:
        Signal output()override;
};
#endif
