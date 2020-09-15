#ifndef __BOARD_H
#define __BOARD_H
#include "tile.h"
#include <iostream>
#include <vector>

class Board{
    private:
        std::vector<Tile>_tiles;
    public:
        Board(int tiles);
        std::string attempt(int tile1, int tile2);
        bool solved();
        std::string to_string();
};
#endif
