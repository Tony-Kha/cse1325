#ifndef __TILE_H
#define __TILE_H
#include <iostream>

class Tile{
    private:
        std::string _word;
        static std::string _blank;
        bool _matched = false;
        static int _width;
    public:
        Tile(std::string word);
        bool operator==(const Tile& rhs);
        std::string word();
        bool matched();
        int width();
        std::string to_string();
};
#endif
