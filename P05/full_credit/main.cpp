#include "gate.h"
#include "and.h"
#include "or.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<int>A={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    std::vector<int>B={0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
    std::vector<int>C={0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    std::vector<int>D={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    And gate1, gate2;
    Or gate3;
    gate1.connect(gate3, 1);
    gate2.connect(gate3, 2);
    

    std::cout<<"A B C D  O"<<"\n= = = =  =\n";
    for(int i=0; i<16; i++){
        gate1.input(1, A[i]);
        gate1.input(2, B[i]);
        gate2.input(1, C[i]);
        gate2.input(2, D[i]);
        std::cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<"  "<<gate3.output()<<"\n";
    }
}
