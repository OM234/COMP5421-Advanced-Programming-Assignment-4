//
// Created by Oz on 7/23/2020.
//

#include "Triangle.h"

Triangle::Triangle(double base, double height, std::string name, std::string description) :
    Shape{name, description}, base{base}, height{height} {

    ID = numShapesCreated;
}

double Triangle::getArea() const {

    return base * height / 2;
}

double Triangle::getBoxHeight() const {

    return height;
}

double Triangle::getBoxWidth() const {

    return base;
}
