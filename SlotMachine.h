/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H

#include "Shape.h"
#include <array>
#include <memory>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Rhombus.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "Rectangle.h"

class SlotMachine {

private:

    std::array<std::unique_ptr<Shape>, 3> reel{};       //reel is an array of 3 smart pointers to shapes
    int tokens;                                         //number of player tokens
    void make_shapes();                                 //loop of size 3 to make shapes
    void make_shape(int);                               //creates the actual shape, puts shape in reel array
    std::size_t  getMaxShapeHeight() const;             //get the largest height of the shapes
    void displayGreeting();                             //startup greeting, sets number of tokens at the beginning
    int getBet();                                       //returns the player's bet
    void exitMessage() const;
    void printReel() const;                             //print the reel to screen
    void printTopBottomBorder() const;                  //prints the top or bottom border
    void printInBetweenRow() const;                     //prints every other row besides top or bottom of reel
    void printBottomShapeTypes() const;                 //prints the bottoms types of the shapes and the height/width
    void display(int);                                  //displays the player's winnings or loss
    bool check3xBet() const;                            //check if the player won 3x their bet
    bool check2xBet() const;                            //check if the player won 2x their bet
    bool check1xBet() const;                            //check if the player won 1x their bet
    bool check0xBet() const;                            //check if the player won 0x their bet

public:

    SlotMachine() = default;
    SlotMachine(const SlotMachine&) = delete;
    SlotMachine(SlotMachine&&) = delete;
    SlotMachine& operator = (const SlotMachine&) = delete;
    SlotMachine& operator = (SlotMachine&&) = delete;
    virtual ~SlotMachine() = default;
    void run();
};


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_4_SLOTMACHINE_H
