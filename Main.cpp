#include"Shape.h"
#include"Rhombus.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"RightTriangle.h"
#include"AcuteTriangle.h"
#include<iostream>

int main() {
    Rectangle s{5, 7};
    Rhombus b{16, "Ace", "Ace of diamond"};
    AcuteTriangle at {17};
    RightTriangle t{10, "Carpenter's Square"};
    std::cout << t;
}