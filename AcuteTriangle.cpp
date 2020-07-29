/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(int base, std::string name, std::string description) :
        Triangle{1, 1, name, description} {

    if (base % 2 == 0) {                                               //if base is positive int, increase it by 1

        base++;
    }

    this->base = base;
    this->height = (base + 1) / 2;                                      //calculate height
}

std::string AcuteTriangle::toString() const {

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

double AcuteTriangle::getPerimeter() const {

    return base + (pow(pow(base, 2) + (4 * pow(height, 2)), 0.5));
}

double AcuteTriangle::getScreenArea() const {

    return pow(height, 2);
}

double AcuteTriangle::getScreenPerimeter() const {

    return 4 * (height - 1);
}

Grid AcuteTriangle::draw(char fchar, char bChar) const {

    Grid grid(height);                                  //grid has height # of rows

    for (int i = 0; i < height; i++) {

        std::vector<char> row(base);                    //each row is a vector of characters

        for (int j = 0; j < base; j++) {                //loop through each character in row

            if (j < i || j > base - 1 - i) {            //if in background index, set index to bChar

                row[j] = bChar;

            } else {                                    //else set index to fChar

                row[j] = fchar;
            }
        }

        grid[height - 1 - i] = row;                     //set the appropriate grid row to the created row

    }

    return grid;
}

void AcuteTriangle::drawRow(int row) const {            //draw a row, for the reels

    if( row >= height ) {                               //if requested row does not exist, print a string of empty characters of base length
    
        std::cout << std::string(base, ' ');
        return;
    }

    Grid grid = draw();                                 //get the entire shape grid 

    for( int i = 0 ; i < base ; i++ ) {     

        std::cout << grid[row][i];                      //print the appropriate row
    }
}
