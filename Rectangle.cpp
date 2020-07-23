//
// Created by Oz on 7/23/2020.
//

#include "Rectangle.h"

Rectangle::Rectangle(std::string name, std::string description, std::size_t height, std::size_t width) :
Shape(name, description), height{height}, width{width} {};

std::string Rectangle::toString() const {

    return "Todo: I'm a rectangle";
}

double Rectangle::getArea() const {


}

double Rectangle::getPerimeter() const {


}

double Rectangle::getScreenArea() const {


}

double Rectangle::getScreenPerimeter() const {


}

void Rectangle::draw() const {


}

double Rectangle::getBoxHeight() const {


}

double Rectangle::getBoxWidth() const {


}