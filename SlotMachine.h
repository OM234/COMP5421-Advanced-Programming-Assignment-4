//
// Created by Oz on 7/28/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H

#include "Shape.h"
#include<array>
#include<memory>
class SlotMachine {

private:

    std::array<std::unique_ptr<Shape>, 3> reel{};
    int tokens;
    void make_shapes();
    void make_shape(int);
    void display();
    void printReel() const;
    std::size_t  getMaxShapeHeight() const;
    void displayGreeting();
    int getBet();
    void exitMessage();
    void printBottomShapeTypes() const;
    void displayWinnings();
    bool check3xBet();
    bool check2xBet();
    bool check1xBet();
    bool check0xBet();
public:

    SlotMachine() = default;
    SlotMachine(const SlotMachine&) = delete;
    SlotMachine(SlotMachine&&) = delete;
    SlotMachine& operator = (const SlotMachine&) = delete;
    SlotMachine& operator = (SlotMachine&&) = delete;
    virtual ~SlotMachine() = default;
    void run();
    void printTopBottomBorder() const;
    void printInBetweenRow() const;


};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H
