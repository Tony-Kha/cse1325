#include "gate.h"
#include "and.h"
#include "or.h"
#include <iostream>

int main(){
    And pins1, pins2;
    Or gate;
    
    pins1.input(1);
    pins1.input(2);

    std::cout<<pins1.output();
}
