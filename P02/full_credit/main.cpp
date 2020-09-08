#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>

void roll(int value, int faces, int rolls){
    for(int i=0; i<rolls; i++){
        std::vector<int>v;
        for(int j=0; j<value; j++){
            v.push_back(rand()%faces+1);
        }
        std::cout<<"Roll "<<i+1<<": ";
        for(auto x : v) std::cout<<x<<" ";
        std::cout<<"Sum: "<<accumulate(v.begin(),v.end(),0)<<"\n";
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

