//
// Created by Oz on 7/23/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_ACUTETRIANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_ACUTETRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle {

public:

    AcuteTriangle(std::size_t, std::string = "wedge", std::string = "Three acute angles");
    std::string toString() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    void draw() const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_ACUTETRIANGLE_H
