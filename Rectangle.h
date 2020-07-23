//
// Created by Oz on 7/23/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H

#include<Shape.h>

class Rectangle : public Shape {

private:

    std::size_t height;
    std::size_t width;

public:

    Rectangle(std::string, std::string, std::size_t, std::size_t);
    std::string toString() const override;
    double getArea() const override;
    double getPerimeter() const override;
    double getScreenArea() const override;
    double getScreenPerimeter() const override;
    void draw() const override;
    double getBoxHeight() const;
    double getBoxWidth() const;


};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_RECTANGLE_H
