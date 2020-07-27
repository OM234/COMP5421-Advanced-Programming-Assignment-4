#include"Shape.h"
#include"Rhombus.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"RightTriangle.h"
#include"AcuteTriangle.h"
#include<iostream>

int main() {
    Rectangle s{10, 3};
    Rhombus b{7, "Ace", "Ace of diamond"};
    AcuteTriangle at {19};
    RightTriangle t{5, "Carpenter's Square"};
    //std::cout << s;
    b.draw('*','!');
}