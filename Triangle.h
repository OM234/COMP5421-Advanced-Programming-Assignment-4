
#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {

protected:
    std::size_t base;
    std::size_t height;

public:
    Triangle(std::size_t, std::size_t, std::string, std::string);
    double getArea() const override;
    double getBoxHeight() const override;
    double getBoxWidth() const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H
