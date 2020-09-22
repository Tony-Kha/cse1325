#include "modulo.h"
#include <iomanip>

int main(){
    Modulo hours{12, 0, 1};
    std::cout<<"Initial value of hours?   ";
    std::cin>>hours;

    Modulo minutes{60};
    std::cout<<"Initial value of minutes?   ";
    std::cin>>minutes;

    Modulo seconds{60};
    std::cout<<"Initial value of seconds?   ";
    std::cin>>seconds;

    seconds.set_nmsd(&minutes);
    minutes.set_nmsd(&hours);

    int step;
    std::cout<<"Step by how many seconds per tic? ";
    std::cin>>step;

    int iterations;
    std::cou<<"How many iterations? ";
    std::cin>>iterations;

    std::cout<<"\mFrom "<<hours<<';'<<minutes<<';'<<seconds<<" counting by "<<step<<" second for "<<iterations<<" iterations\n\n";

    Modulo columns{10};

    std::cout<<std::setfill('0');
    while(iterations--){
        seconds+=step;
        std::cout<<std::setw(2)<<hours<<';'<<std::setw(2)<<minutes<<';'<<std::setw(2)<<seconds<<", ";
        if(++columns == 0) std::cout<<'\n';
    }
    std::cout<<std::endl;
}
