#include "board.h"
#include "tile.h"
#include <cstdlib>
#include <algorithm>
#include <vector>

Board::Board(int tiles){
    std::vector<std::string>words{
        "bang", "beam", "bear", "cafe", "came",
        "cold", "come", "cool", "date", "diet",
        "door", "doth", "echo", "exes", "exit",
        "face", "fame", "feed", "fire", "five",
        "four", "free", "frog", "from", "game",
        "goes", "good", "grit", "have", "heal",
        "hear", "here", "hide", "hole", "home",
        "hope", "huge", "keep", "kill", "lace",
        "lame", "leek", "life", "live", "maps",
        "mass", "mate", "maze", "move", "near",
        "need", "nine", "once", "quit", "ques",
        "race", "read", "reed", "reef", "rice",
        "roof", "sins", "stay", "tame", "teen",
        "tens", "tide", "tied", "tree", "twin",
        "zero", "zips",
    };
    random_shuffle(words.begin(), words.end());
    for(int i=0; i<tiles/2; i++){
        _tiles.push_back(words.at(i));
        _tiles.push_back(words.at(i));
    }
    random_shuffle(_tiles.begin(), _tiles.end());
}
std::string Board::attempt(int tile1, int tile2){
    std::string m = " and ";
    if(_tiles[tile1]==_tiles[tile2]){
        _tiles[tile2]==_tiles[tile1];
        m = " MATCHES ";
    }
    return _tiles[tile1].Tile::word() + m + _tiles[tile2].Tile::word() + "\n";
}
bool Board::solved(){
    for(int i=0; i<_tiles.size(); i++){
        if(!_tiles[i].Tile::matched()){
            return false;
        }
    }
    return true;
}
std::string Board::to_string(){
    for(int i=0; i<_tiles.size()-1; i++){
        std::cout<<i<<") "<<_tiles[i].Tile::to_string()<<"\n";
    }
    std::cout<<_tiles.size()-1<<") ";
    return _tiles[_tiles.size()-1].Tile::to_string() + "\n";
}
