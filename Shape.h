/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H

#include <string>
#include <cmath>                                            //for pow function
#include <iostream>
#include <ostream>
#include <vector>
#include <typeinfo>                                         //for dynamic and static types

using Grid = std::vector<std::vector<char>>;                //Grid is a 2d vector of type char
    
class Shape {

protected:                                                  //protected, not private, to allow for inheritance

    static int numShapesCreated;                            //static int to keep track of # shapes created (for shape ID)
    int ID;         
    std::string name;   
    std::string description;

public:
    Shape(std::string, std::string);                        //constructor of shape. Sets the name and description
    int getID() const;
    std::string getName() const;
    std::string getDescription() const;
    void setName(std::string);
    void setDescription(std::string);
    virtual std::string toString() const = 0;               //pure virtual methods that must be implemented in derived classes
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getScreenArea() const = 0;
    virtual double getScreenPerimeter() const = 0;
    virtual Grid draw(char = '*', char = ' ') const = 0;
    virtual void drawRow(int) const = 0;                    //draw a row of a shape, for the reel
    virtual double getBoxHeight() const = 0;
    virtual double getBoxWidth() const = 0;
    std::string getStaticType() const;
    std::string getDynamicType() const;
};

std::ostream& operator << (std::ostream&, Shape&);          //overload << for Shape
std::ostream& operator << (std::ostream&, Grid&);           //overload << for Grid

#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
