#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std ;

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

struct Rect{
int width, height, length;
vector<Rect> Blocks;
};
struct baserectblocks{
int width, length;
};
struct cuboid{
int length;
};
struct cylinder{
int diameter, height;
};


#endif // BLOCK_H_INCLUDED
