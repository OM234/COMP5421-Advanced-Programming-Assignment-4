#include"Shape.h"
#include"Rhombus.h"
#include"Rectangle.h"
#include<iostream>

int main() {
    Rectangle s{5, 7};
    Rhombus b{16, "Ace", "Ace of diamond"};

    std::cout << b.toString();
}