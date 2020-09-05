#include <iostream>
#include <vector>

int main() {
    int num, sides, rolls;
    std::cout<<"Enter the number of dice to roll"<<std::endl;
    std::cin>>num;

    std::cout<<"Enter the number of sides for each dice"<<std::endl;
    std::cin>>sides;
    std::vector<int>v;
    for(int i=0; i<sides;i++) v.push_back(i+1);

    std::cout<<"Enter the number of times to roll"<<std::endl;
    std::cin>>rolls;
}

