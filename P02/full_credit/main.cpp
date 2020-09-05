#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>

void roll(int num, int sides, int rolls){
    for(int i=0; i<rolls; i++){
        std::vector<int>v;
        for(int j=0; j<num; j++){
            v.push_back(rand()%sides+1);
        }
        std::cout<<"Roll "<<i+1<<": ";
        for(auto x : v) std::cout<<x<<" ";
        std::cout<<"Sum: "<<accumulate(v.begin(),v.end(),0)<<"\n";
    }
}

int main() {
    srand(time(NULL));

    int num, sides, rolls;
    std::cout<<"Enter the number of dice to roll"<<std::endl;
    std::cin>>num;

    std::cout<<"Enter the number of sides for each dice"<<std::endl;
    std::cin>>sides;

    std::cout<<"Enter the number of times to roll"<<std::endl;
    std::cin>>rolls;

    roll(num,sides,rolls);
}

