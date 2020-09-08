#include <iostream>
#include <ctime>
#include "die.h"

int main() {
    srand(time(NULL));

    std::cout<<"d4: ";
    Die four(4,20);
    four.roll();
    
    std::cout<<"\nd6: ";
    Die six(6,20);
    six.roll();
    
    std::cout<<"\nd8: ";
    Die eight(8,20);
    eight.roll();

    std::cout<<"\nd12: ";
    Die twelve(12,20);
    twelve.roll();

    std::cout<<"\nd20: ";
    Die twenty(20,20);
    twenty.roll();
    std::cout<<"\n";
}

