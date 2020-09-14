#include "tile.h"
#include "board.h"
#include <cstdlib>

Tile::Tile(std::string word):_word{word}{
    _matched = false;
    if(word.length() > _width){
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
