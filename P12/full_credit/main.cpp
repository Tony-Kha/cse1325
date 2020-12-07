#include <iostream>
#include <fstream>
#include <string>
#include "mandelbrot.h"

bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while(it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char* argv[]){
    std::ofstream output;
    if(argc == 1){
        Mandelbrot result;
        output.open("image.ppm");
        output << result;
        std::cout << "  width: " << 500 << "  height: " << 500 << "  icount: " << 60 << "  threads: " << 1 << std::endl; 
        std::cout << "  wrote: image.ppm" << std::endl;
    }else if(argc == 2){
        Mandelbrot result{atoi(argv[1])};
        for(int i=1; i<argc; i++){
            if(!(is_number(argv[i]))){
                std::cout << "Invalid argument" << std::endl;
                return -2;
            }
        }
        output.open("image.ppm");
        output << result;
        std::cout << "  width: " << argv[1] << "  height: " << 500 << "  icount: " << 60 << "  threads: " << 1 << std::endl; 
        std::cout << "  wrote: image.ppm" << std::endl;
    }else if(argc == 3){
        Mandelbrot result{atoi(argv[1]), atoi(argv[2])};
        for(int i=1; i<argc; i++){
            if(!(is_number(argv[i]))){
                std::cout << "Invalid argument" << std::endl;
                return -2;
            }
        }
        output.open("image.ppm");
        output << result;
        std::cout << "  width: " << argv[1] << "  height: " << argv[2] << "  icount: " << 60 << "  threads: " << 1 << std::endl; 
        std::cout << "  wrote: image.ppm" << std::endl;
    }else if(argc == 4){
        Mandelbrot result{atoi(argv[1]), atoi(argv[2]), atoi(argv[3])}; 
        for(int i=1; i<argc; i++){
            if(!(is_number(argv[i]))){
                std::cout << "Invalid argument" << std::endl;
                return -2;
            }
        }
        output.open("image.ppm");
        output << result;
        std::cout << "  width: " << argv[1] << "  height: " << argv[2] << "  icount: " << argv[3] << "  threads: " << 1 << std::endl; 
        std::cout << "  wrote: image.ppm" << std::endl;
    }else if(argc == 5){
        Mandelbrot result{atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
        for(int i=1; i<argc; i++){
            if(!(is_number(argv[i]))){
                std::cout << "Invalid argument" << std::endl;
                return -2;
            }
        }
        output.open("image.ppm");
        output << result;
        std::cout << "  width: " << argv[1] << "  height: " << argv[2] << "  icount: " << argv[3] << "  threads: " << argv[4] << std::endl; 
        std::cout << "  wrote: image.ppm" << std::endl;
    }else if(argc == 6){
        Mandelbrot result{atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
        for(int i=1; i<argc-1; i++){
            if(!(is_number(argv[i]))){
                std::cout << "Invalid argument" << std::endl;
                return -2;
            }
        }
        output.open(argv[5]);
        output << result;
        std::cout << "  width: " << argv[1] << "  height: " << argv[2] << "  icount: " << argv[3] << "  threads: " << argv[4] << std::endl; 
        std::cout << "  wrote: " << argv[5] << std::endl;
    }else{    
        std::cout << "Enter a valid number of arguments!" << std::endl;
    }
    


}
