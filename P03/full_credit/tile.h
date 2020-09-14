#ifndef __TILE_H
#define __TILE_H
#include <iostream>

class Tile{
    private:
        std::string _word, _blank;
        static bool _matched;
        int _width = -1;
    public:
        Tile(std::string word);
        bool match(Tile& tile);
        std::string word();
        bool matched();
        int width();
        std::string to_string();
};
#endif
