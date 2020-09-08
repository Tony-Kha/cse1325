#include <iostream>
#include <ctime>

void roll(int value, int faces, int rolls){
    int sum, ran;
    for(int i=0; i<rolls; i++){
        sum = 0;
        std::cout<<"Roll "<<i+1<<": ";
        for(int j=0; j<value; j++){
            ran = rand()%faces+1;
            sum += ran;
            std::cout<<ran<<" ";                            
        }
        std::cout<<"Sum: "<<sum<<"\n";
    }
}

int main() {
    srand(time(NULL));

    int value, faces, rolls;
    std::cout<<"Number of dice? ";
    std::cin>>value;

    std::cout<<"Number of faces per die? ";
    std::cin>>faces;

    std::cout<<"Number of rolls? ";
    std::cin>>rolls;

    roll(value,faces,rolls);
}

