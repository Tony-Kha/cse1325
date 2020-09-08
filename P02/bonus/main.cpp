#include <iostream>
#include <ctime>
#include "die.h"

int main(){
    srand(time(NULL));

    int value, faces, roll, sum;
    std::cout<<"Number of dice? ";
    std::cin>>value;

    std::cout<<"Number of faces per die? ";
    std::cin>>faces;

    std::cout<<"Number of rolls? ";
    std::cin>>roll;

    Die rolling(faces, value);
    for(int i=0; i<roll; i++){
        std::cout<<"Roll "<<i+1<<": ";
        sum = rolling.roll();
        std::cout<<"Sum: "<<sum<<"\n";
    }
}
