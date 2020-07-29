/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "RightTriangle.h"


RightTriangle::RightTriangle(double base, std::string name, std::string description) :
        Triangle{base, base, name, description} {};

std::string RightTriangle::toString() const {

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

double RightTriangle::getPerimeter() const {

   return ( 2 + pow( 2 , 0.5 )) * height;
}

double RightTriangle::getScreenArea() const {

    return ( height * ( height + 1 )) / 2;
}

double RightTriangle::getScreenPerimeter() const {

    return 3 * (height - 1);
}

Grid RightTriangle::draw(char fChar, char bChar) const {    

    Grid grid(height);                                      //grid has height number of rows

    for( int i = 0 ; i < height ; i++) {                    //iterate through rows

        std::vector<char> row(base);                        //row is a vector of characters of base size

        for( int j = 0 ; j < base ; j++ ) {

            if( j > i ) {                                   //if index in background

                row[j] = bChar;

            } else {

                row[j] = fChar;

            }
        }

        grid[i] = row;                                      //appropriate row of grid is set s
    }

    return grid;
}

void RightTriangle::drawRow(int row) const {    //see description in AcuteTriangle.cppp

    if( row >= height ) {

        std::cout << std::string(base, ' ');
        return;
    }

    Grid grid = draw();

    for( int i = 0 ; i < base ; i++ ) {

        std::cout << grid[row][i];
    }
}
