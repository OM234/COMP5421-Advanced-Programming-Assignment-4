/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {

protected:
    double base;
    double height;

public:
    Triangle(double, double, std::string, std::string);     //constructor, parameters base, height, name, description
    double getArea() const override;
    double getBoxHeight() const override;
    double getBoxWidth() const override;
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_TRIANGLE_H
