#include "Shape.h"

Shape::Shape(std::string name, std::string description) :
        name{name}, description{description} {};

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