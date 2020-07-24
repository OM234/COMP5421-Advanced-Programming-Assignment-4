#include "Shape.h"
#include <typeinfo>

Shape::Shape(std::string name, std::string description) :
        name{name}, description{description} {

    numShapesCreated++;
};

size_t Shape::numShapesCreated = 0;

std::size_t Shape::getID() const {
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

std::string Shape::getStaticType() const {

    return typeid(this).name();
}

std::string Shape::getDynamicType() const {

    return typeid(*this).name();
}

std::ostream& operator<< (std::ostream& sout, Shape& shape) {

    sout << shape.toString();
    return sout;
}