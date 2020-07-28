#include "Rhombus.h"

Rhombus::Rhombus(size_t diameter, std::string name = "Diamond",
                 std::string description = "Parallelogram with equal sides") :
        Shape{name, description} {

    Shape::ID = Shape::numShapesCreated;

    if (diameter % 2 != 0) {

        this->diameter = diameter;

    } else {

        this->diameter = diameter + 1;
    }
};

std::string Rhombus::toString() const {

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

double Rhombus::getArea() const {

    return pow(diameter, 2)/2;
}

double Rhombus::getPerimeter() const {

    return pow( 2, 0.5 ) * 2 * diameter;
}

double Rhombus::getScreenArea() const {

    double n { floor ( diameter / 2 )};

    return ( 2 * n ) * ( n + 1 ) + 1;
}

double Rhombus::getScreenPerimeter() const {

    return 2 * ( diameter - 1 );
}

Grid Rhombus::draw(char fChar, char bChar) const {

    Grid grid(diameter);

    for( int i = 0 ; i < diameter ; i++ ) {

        std::vector<char> row(diameter);
        std::size_t mid { diameter / 2 };

        for( int j = 0 ; j < diameter ; j++ ) {

            std::size_t distFromMid{ static_cast<size_t>(abs( i - mid ))};
            std::size_t offset{distFromMid};

            if( j < offset ||  j > diameter - 1 - offset  ) {
                row[j] = bChar;
            } else {
                row[j] = fChar;
            }

        }
        grid[i] = row;
    }

    return grid;
//    for( int i = 0 ; i < grid.size() ; i++ ) {
//
//        for( int j = 0 ; j < grid[i].size() ; j++ ) {
//
//            std::cout << grid[i][j];
//        }
//
//        std::cout << std::endl;
//    }
}

double Rhombus::getBoxHeight() const {

    return diameter;
}

double Rhombus::getBoxWidth() const {

    return diameter;
}