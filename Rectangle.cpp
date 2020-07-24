//
// Created by Oz on 7/23/2020.
//

#include "Rectangle.h"

Rectangle::Rectangle(std::size_t height, std::size_t width, std::string name,
                     std::string description ) :
        Shape(name, description), height{height}, width{width} {

    Shape::ID = Shape::numShapesCreated;
};

std::string Rectangle::toString() const {

    std::string returnStr{};

    returnStr += "Shape Information\n";
    returnStr += "-----------------\n";
    returnStr += "id:\t\t\t\t" + std::to_string(ID) + "\n";
    returnStr += "Shape name:\t\t" + getName() + "\n";
    returnStr += "Description:\t" + getDescription() + "\n";
    returnStr += "B. box width:\t" + std::to_string(getBoxWidth()) + "\n";
    returnStr += "B. box height:\t" + std::to_string(getBoxHeight()) + "\n";
    returnStr += "Scr area:\t\t" + std::to_string(getScreenArea()) + "\n";
    returnStr += "Geo area:\t\t" + std::to_string(getArea()) + "\n";
    returnStr += "Scr perimeter:\t" + std::to_string(getScreenPerimeter()) + "\n";
    returnStr += "Geo perimeter:\t" + std::to_string(getPerimeter()) + "\n";
    returnStr += "Static type:\t" + getStaticType() + "\n";
    returnStr += "Dynamic type:\t" + getDynamicType() + "\n";

    return returnStr;
}

double Rectangle::getArea() const {

    return height*width;
}

double Rectangle::getPerimeter() const {

    return 2*(height + width);
}

double Rectangle::getScreenArea() const {

    return getArea();
}

double Rectangle::getScreenPerimeter() const {

    return getPerimeter() - 4;
}

void Rectangle::draw() const {


}

double Rectangle::getBoxHeight() const {

    return height;
}

double Rectangle::getBoxWidth() const {

    return width;
}
