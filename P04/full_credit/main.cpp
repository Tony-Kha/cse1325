#include "modulo.h"
#include <iomanip>

int main(){
    Modulo minutes{60, 15};
    Modulo hours{12, 10, 1};
    minutes.set_nmsd(&hours);

    const int step = 23;
    std::cout<< "From " << hours << ':' << minutes << " count by " << step << "\n\n";

    while(hours != 2){
        minutes += step;
        std::cout << hours << ':' << std::setw(2) << std::setfill('0') << minutes << ", ";
    }
    std::cout << std::endl;
}
