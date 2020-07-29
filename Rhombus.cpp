/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "Rhombus.h"

Rhombus::Rhombus(int diagonal, std::string name,
                 std::string description) :
        Shape{name, description} {

    Shape::ID = Shape::numShapesCreated;

    if (diagonal % 2 != 0) {            

        this->diagonal = diagonal;

    } else {                                //if diagonal is even, increase diagonal by 1

        this->diagonal = diagonal + 1;
    }
};

std::string Rhombus::toString() const {

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

double Rhombus::getArea() const {

    return pow(diagonal, 2)/2;
}

double Rhombus::getPerimeter() const {

    return pow( 2, 0.5 ) * 2 * diagonal;
}

double Rhombus::getScreenArea() const {

    double n { floor ( diagonal / 2 )};

    return ( 2 * n ) * ( n + 1 ) + 1;
}

double Rhombus::getScreenPerimeter() const {

    return 2 * ( diagonal - 1 );
}

Grid Rhombus::draw(char fChar, char bChar) const {

    Grid grid(diagonal);                                        //grid has diagonal number of rows

    for( int i = 0 ; i < diagonal ; i++ ) {                     //iterate through rows

        std::vector<char> row(diagonal);                        //row is a vector of characters
        int mid { diagonal / 2 };                                   

        for( int j = 0 ; j < diagonal ; j++ ) {

            int offset{ abs(i - mid) };                         //offset for background characters is increased in correlation to row distance from mid

            if( j < offset ||  j > diagonal - 1 - offset  ) {   //if in background index
                row[j] = bChar;
            } else {
                row[j] = fChar;
            }

        }
        grid[i] = row;
    }

    return grid;
}

double Rhombus::getBoxHeight() const {

    return diagonal;
}

double Rhombus::getBoxWidth() const {

    return diagonal;
}

void Rhombus::drawRow(int row) const {                  //see AcuteTriangle.cpp for information

    if( row >= diagonal ) {

        std::cout << std::string(diagonal, ' ');
        return;
    }

    Grid grid = draw();

    for( int i = 0 ; i < diagonal ; i++ ) {

        std::cout << grid[row][i];
    }
}
