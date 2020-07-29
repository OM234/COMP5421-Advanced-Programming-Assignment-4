/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {

private:

    int diagonal;

public:

    Rhombus(int, std::string = "Diamond", std::string = "Parallelogram with equal sides"); //constructor, parameters: diagonal, name, description
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
