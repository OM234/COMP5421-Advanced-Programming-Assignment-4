/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "Shape.h"

Shape::Shape(std::string name, std::string description) :
        name{name}, description{description} {

    numShapesCreated++;                                     //# shapes creates increments by one each time a shape is made
};

int Shape::numShapesCreated = 0;                            //initializes # shapes to 0 at runtime               

int Shape::getID() const {

    return ID;
}

std::string Shape::getName() const {

    return name;
}

std::string Shape::getDescription() const {

    return description;
}

void Shape::setName(std::string name) {

    this->name = name;
}

void Shape::setDescription(std::string description) {

    this->description = description;
}

std::string Shape::getStaticType() const {                  //get static type, which is the base class

    return typeid(this).name();
}

std::string Shape::getDynamicType() const {                 //get dynamic type, which is the actual object created

    return typeid(*this).name();
}

std::ostream& operator << (std::ostream& sout, Shape& shape) {

    sout << shape.toString();
    return sout;
}

std::ostream& operator << (std::ostream& sout, Grid& grid) {

    for( int i = 0 ; i < grid.size() ; i++ ) {              //loops through all the grid rows, and outputs the characters of each row

        for( int j = 0 ; j < grid[i].size() ; j++) {

            sout << grid[i][j];
        }

        sout << std::endl;
    }

    return sout;
}