//
// Created by Oz on 7/23/2020.
//

#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(std::size_t base, std::string name, std::string description) :
    Triangle{ 1, 1 , name, description}{

    if(base % 2 == 0) {

        base++;
    }

    height = ( base + 1 ) / 2;

    this->base = base;
    this->height = height;
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

    return base + (pow (pow( base , 2 ) + ( 4 * pow( height, 2 )) , 0.5 ));
}

double AcuteTriangle::getScreenArea() const {

    return pow ( height , 2 );
}

double AcuteTriangle::getScreenPerimeter() const {

    return 4 * ( height - 1 );
}

void AcuteTriangle::draw() const {

}
