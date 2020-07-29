/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

private:

    int height;
    int width;

public:

    Rectangle(int, int, std::string = "Rectangle", std::string = "Four right angles");      //constructor, parameters: width, height, name, description
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


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H
