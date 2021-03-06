/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {

public:

    RightTriangle(double, std::string = "Ladder", std::string = "One right and two acute angles");  //constructor, parameters: base, name, description
    std::string toString() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    Grid draw(char = '*', char = ' ') const override;
    void drawRow(int) const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RIGHTTRIANGLE_H
