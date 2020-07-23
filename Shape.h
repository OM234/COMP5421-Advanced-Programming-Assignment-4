
#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H

#include <string>

class Shape {

protected:
    std::size_t numShapes;
    std::size_t idNum;
    std::string name;
    std::string description;

public:
    Shape(std::string name, std::string description);
    std::size_t getID() const;
    std::string getName() const;
    std::string getDescription() const;
    void setName(std::string);
    void setDescription(std::string);
    virtual std::string toString() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getScreenArea() const = 0;
    virtual double getScreenPerimeter() const = 0;
    virtual void draw() const = 0;
    virtual void getBoxHeight() const = 0;
    virtual void getBoxWidth() const = 0;
};



#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
