//
// Created by Oz on 7/23/2020.
//

#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(std::size_t base, std::string name, std::string description) :
        Triangle{1, 1, name, description} {

    if (base % 2 == 0) {

        base++;
    }

    this->base = base;
    this->height = (base + 1) / 2;
}

std::string AcuteTriangle::toString() const {

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

double AcuteTriangle::getPerimeter() const {

    return base + (pow(pow(base, 2) + (4 * pow(height, 2)), 0.5));
}

double AcuteTriangle::getScreenArea() const {

    return pow(height, 2);
}

double AcuteTriangle::getScreenPerimeter() const {

    return 4 * (height - 1);
}

void AcuteTriangle::draw(char fchar = '*', char bChar = ' ') const {

    std::vector<std::vector<char>> grid(height);

    for (int i = 0; i < height; i++) {

        std::vector<char> row(base);

        for (int j = 0; j < base; j++) {

            if (j < i || j > base - 1 - i) {

                row[j] = bChar;

            } else {

                row[j] = fchar;
            }
        }

        grid[height - 1 - i] = row;

    }

    for ( int i = 0 ; i < grid.size() ; i++ ) {

        for ( int j = 0 ; j < grid[i].size() ; j++ ) {

            std::cout << grid[i][j];
        }

        std::cout << std::endl;
    }
}
