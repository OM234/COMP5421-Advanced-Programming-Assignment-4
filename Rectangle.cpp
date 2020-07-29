/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, std::string name,
                     std::string description ) :
        Shape(name, description), height{height}, width{width} {

    Shape::ID = Shape::numShapesCreated;
};

std::string Rectangle::toString() const {

    std::string returnStr{};

    returnStr += "Shape Information\n";
    returnStr += "-----------------\n";
    returnStr += "id:\t\t" + std::to_string(ID) + "\n";
    returnStr += "Shape name:\t" + getName() + "\n";
    returnStr += "Description:\t" + getDescription() + "\n";
    returnStr += "B. box width:\t" + std::to_string(getBoxWidth()) + "\n";
    returnStr += "B. box height:\t" + std::to_string(getBoxHeight()) + "\n";
    returnStr += "Scr area:\t" + std::to_string(getScreenArea()) + "\n";
    returnStr += "Geo area:\t" + std::to_string(getArea()) + "\n";
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

Grid Rectangle::draw(char fChar, char bChar) const {

    Grid grid;

    for( int i = 0 ; i < height ; i++ ) {           //height # of rows in grid

        std::vector<char> row;                      //row is a vector of characters

        for( int j = 0 ; j < width ; j++ ) {        //loop through all the elements of the row

            row.push_back(fChar);                   //push back fChar in row
        }

        grid.push_back(row);                        //push back row into grid
    }

    return grid;
}

double Rectangle::getBoxHeight() const {

    return height;
}

double Rectangle::getBoxWidth() const {

    return width;
}

void Rectangle::drawRow(int row) const {            //see description in AcuteTriangle.cpp

    if( row >= height ) {

        std::cout << std::string(width, ' ');
        return;
    }

    Grid grid = draw();

    for( int i = 0 ; i < width ; i++ ) {

        std::cout << grid[row][i];
    }
}
