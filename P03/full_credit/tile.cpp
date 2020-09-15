#include "tile.h"
#include "board.h"
#include <cstdlib>
int Tile::_width = -1;
std::string Tile::_blank;
Tile::Tile(std::string word):_word{word}{
    if((int)word.length() > _width){
        _width = word.length();
    }
    _blank.resize(_width);
    for(int i=0; i<_width; i++){
        _blank.replace(i,1,"-");
    }
}
bool Tile::match(Tile& tile){
    if(_word == tile._word){
        _matched = true;    
    }else{
        _matched = false;
    }
    return _matched;
}
std::string Tile::word() {return _word;}

bool Tile::matched() {return _matched;}

int Tile::width() {return _width;}

std::string Tile::to_string() {
    if(_matched){return _word;}
    return _blank;
}
