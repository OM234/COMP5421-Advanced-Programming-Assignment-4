
#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {

private:

    int diameter;

public:

    Rhombus(std::size_t , std::string = "Diamond", std::string = "Parallelogram with equal sides");
    std::string toString() const override;
    double getArea() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    Grid draw(char = '*', char = ' ') const override;
    void drawRow(int) const override;
    double getBoxHeight() const override;
    double getBoxWidth() const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H
