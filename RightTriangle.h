#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {

public:

    RightTriangle(std::size_t, std::string = "Ladder", std::string = "One right and two acute angles");

    std::string toString() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    void draw() const override;

};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H
