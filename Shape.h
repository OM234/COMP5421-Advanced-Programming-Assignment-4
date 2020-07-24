
#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H

#include <string>
#include <cmath>
#include <ostream>

class Shape {

protected:

    static std::size_t numShapesCreated;
    std::size_t ID;
    std::string name;
    std::string description;

public:
    Shape(std::string, std::string);
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
    virtual double getBoxHeight() const = 0;
    virtual double getBoxWidth() const = 0;
    std::string getStaticType() const;
    std::string getDynamicType() const;
};

std::ostream& operator << (std::ostream&, Shape&);

#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SHAPE_H
