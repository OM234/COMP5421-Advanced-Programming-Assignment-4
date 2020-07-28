//
// Created by Oz on 7/28/2020.
//

#include "SlotMachine.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Shape.h"
#include "Rhombus.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "Rectangle.h"

void SlotMachine::run() {

    int tokens{displayGreeting()};
    int bet{getBet(tokens)};

    if(bet == 0) {

        exitMessage(tokens);

    } else {

        make_shapes();
    }

    printReel();
}

int SlotMachine::displayGreeting() {

    int tokens{};
    std::string yesOrNo;

    std::cout << "Would you like to set the number of starting tokens? Default is 10 (y/n)? ";
    std::cin >> yesOrNo;

    if(yesOrNo.compare("Y") == 0 || yesOrNo.compare("y") == 0) {

        std::cout << "How many starting tokens? ";
        std::cin >> tokens;
    }

    if(tokens <= 0) {

        tokens = 10;
    }

    std::string greeting = "\nWelcome to 3—Ree1 Lucky Slot Machine Game ! \n"
                           "Each reel will randomly display one of four shapes, each with 25 sizes. \n"
                           "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas. \n"
                           "To win 2 x bet, get 3 similar shapes. \n"
                           "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas \n"
                           "To win or lose nothing, get the same Left and Right shapes \n"
                           "Otherwise, you lost your bet. \n"
                           "You start with " + std::to_string(tokens) + " free slot tokens!\n";

    std::cout << greeting << std::endl;

    return tokens;
}

int SlotMachine::getBet(int tokens) {

    int bet{-1};

    while( bet < 0 || bet > tokens) {
        std::cout << "How much would you like to bet (enter 0 to quit)? ";
        std::cin >> bet;
    }
}

void SlotMachine::exitMessage(int tokens) {

}

void SlotMachine::printReel() {

    std::size_t borderHeight = getBorderHeight();

    std::cout << borderHeight << std::endl;
}

std::size_t SlotMachine::getBorderHeight() {

    std::size_t maxHeight{};

    for( int k = 0 ; k < 3 ; k++ ) {

        Grid grid = reel[k]->draw();
        std::cout << grid << std::endl;
        maxHeight = std::max<size_t>(maxHeight, reel[k]->getBoxHeight());
    }

    return maxHeight + 2;
}

void SlotMachine::make_shapes() {

    for( int k = 0 ; k < 3 ; k++ ) {

        make_shape(k);
    }
}

void SlotMachine::make_shape(int k) {

    size_t n, width, height;

    srand(time(NULL));

    n = rand() % 3 + 1;
    width = rand() % 25 + 1;
    height = rand() % 25 + 1;

    switch(n) {

        case 0:
            reel[k].reset(new Rhombus{width});
            break;
        case 1:
            reel[k].reset(new AcuteTriangle{width});
            break;
        case 2:
            reel[k].reset(new RightTriangle{width});
            break;
        case 3:
            reel[k].reset(new Rectangle{width, height});
            break;
    }

}