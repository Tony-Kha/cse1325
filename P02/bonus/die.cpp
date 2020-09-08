#include "die.h"

Die::Die(int f, int v){
    faces = f;
    value = v;
}
int Die::roll(){
    int sum, ran;
    for(int i=0; i<value; i++){
        ran = rand()%faces+1;
        sum += ran;
        std::cout<<ran<<" ";
    }
    return sum;
}
