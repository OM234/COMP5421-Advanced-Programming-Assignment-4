
#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {

private:

    std::size_t diameter;

public:

    Rhombus(size_t, std::string, std::string);
    std::string toString() const override;
    double getArea() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    Grid draw(char, char) const override;
    double getBoxHeight() const override;
    double getBoxWidth() const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H
