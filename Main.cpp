#include"Shape.h"
#include"Rhombus.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"RightTriangle.h"
#include"AcuteTriangle.h"
#include"SlotMachine.h"
#include<iostream>
#include<memory>

void task1();
void task2();

int main() {

    task1();
    task2();
}

void task1() {

    Rectangle rect {5,7};
    std::cout << rect << std::endl;

    std::unique_ptr<Shape> rectShape { new Rectangle{5,7} };
    Grid rectBox = rectShape->draw();
    std::cout << rectBox << std::endl;

    Rhombus ace {16,"Ace", "Ace of diamond"};
    std::cout << ace << std::endl;

    std::unique_ptr<Shape> aceShape {new Rhombus{16, "Ace", "Ace of diamond"} };
    Grid aceBox = aceShape->draw('+', '.');
    std::cout << aceBox << std::endl;

    AcuteTriangle at {17};
    std::cout << at << std::endl;

    std::unique_ptr<Shape> atShape {new AcuteTriangle{17} };
    Grid atBox = atShape->draw('^');
    std::cout << atBox << std::endl;

    RightTriangle rt {10, "Carpenter's square"};
    std::cout << rt << std::endl;

    std::unique_ptr<Shape> rtShape {new RightTriangle{10, "Carpenter's Square"} };
    Grid rtBox = rtShape->draw('+', '.');
    std::cout << rtBox << std::endl;

}

void tast2() {

    SlotMachine slotMachine;
    slotMachine.run();
}