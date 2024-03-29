#include "mandelbrot.h"
#include <thread>

const int MAX_COLOR = 255;

Mandelbrot::Mandelbrot(int width, int height, int icount, int nthreads) 
  : _width{width}, _height{height}, _icount{icount} {

    std::thread t[nthreads];
    // Allocate memory for the results
    _values = new int[_width * _height];
    
    // Calculate the results
    /*for (int y = 0; y < _height; y++)  {
        calculate_rows(y, y);
    }*/

    _row = height/nthreads-1;
    for(int i=0; i<nthreads; i++){
        t[i] = std::thread{&Mandelbrot::calculate_rows, this};
    }
    for(int i=0; i<nthreads; i++){
        t[i].join();
    }

}

// Deallocate results memory
Mandelbrot::~Mandelbrot() {delete[] _values;}

// Calculate a range of rows (y values) 
void Mandelbrot::calculate_rows () {
    for (int y = 0; y <= _row; y++)  {
        for (int x = 0; x < _width; x++) {
            m.lock();
            calculate_point(x, y);
            m.unlock();
        }
    }
}

// Calculate a specific point in the Mandelbrot set
void Mandelbrot::calculate_point (int x, int y)  {
    std::complex<double> point{static_cast<double>(x) / static_cast<double>(_width)  - 1.5, 
                               static_cast<double>(y) / static_cast<double>(_height) - 0.5};
    std::complex<double> z(0, 0);
    int iterations = 0;
    while (std::abs(z) < 2 && iterations++ <= _icount) z = z*z + point;
    _values[y*_width+x] = (iterations < _icount) ? (MAX_COLOR*iterations)/_icount : 0;
}

// Print out the results in ppm type 3 file format
std::ostream& operator<<(std::ostream& ost, const Mandelbrot& mandelbrot) {
    ost << "P3\n" << mandelbrot._width << ' ' << mandelbrot._height << ' '<< MAX_COLOR << '\n';
    for (int i = 0; i < mandelbrot._width * mandelbrot._height; i++) {
             ost << mandelbrot._values[i] << ' ' << 0 << ' ' << 0 << "\n";
    }
    return ost;
}

