#include "tile.h"
#include "board.h"
#include <string>
#include <vector>
#include <iostream>

int main(){
    int num, tile1, tile2, guess=1;
    std::cout<<"Number of tiles? ";
    std::cin>>num;
    Board game(num);
    bool solved = false;
    while(!solved){
        std::cout<<"Guess "<<guess<<", select 2 unmatched tiles: ";
        std::cin>>tile1;
        std::cin>>tile2;
        std::cout<<game.attempt(tile1, tile2);
        std::cout<<game.Board::to_string();
        guess++;
        solved = game.solved();
    }
    std::cout<<"It took you "<<guess<<" guesses."<<std::endl;
}
