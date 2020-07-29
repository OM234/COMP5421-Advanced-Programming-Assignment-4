/*
    Author:     Osman Momoh
    Student ID: 26220150
    Course:     COMP 5421: Advanced Programming
    Date:       7/29/2020, Summer 2020
*/

#include "SlotMachine.h"

void SlotMachine::run() {               //runs at startup

    displayGreeting();

    int bet{};

    while(tokens != 0) {                //if player still has tokens, keep looping

        bet = getBet();

        if (bet == 0) {                 //if player bets 0, exit game

            exitMessage();
            break;

        } else {

            make_shapes();              
            printReel();
            printBottomShapeTypes();
            display(bet);
        }
    }

    if(tokens == 0) {                   //display exit message if no more tokens

        exitMessage();
    }
}

void SlotMachine::displayGreeting() {
        
    std::string yesOrNo;                //decision about whether or not to set number of tokens at startup              

    std::cout << "Would you like to set the number of starting tokens? Default is 10 (y/n)? ";
    std::cin >> yesOrNo;

    if(yesOrNo.compare("Y") == 0 || yesOrNo.compare("y") == 0) {

        std::cout << "How many starting tokens? ";
        std::cin >> tokens;             //sets starting tokens to player decision
    }

    if(tokens <= 0) {                   //if tokens less than 0, set it to default of 10

        tokens = 10;
    }

    std::string greeting = "\nWelcome to 3-Reel Lucky Slot Machine Game ! \n"
                           "Each reel will randomly display one of four shapes, each with 25 sizes. \n"
                           "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas. \n"
                           "To win 2 x bet, get 3 similar shapes. \n"
                           "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas \n"
                           "To win or lose nothing, get the same Left and Right shapes \n"
                           "Otherwise, you lost your bet. \n"
                           "You start with " + std::to_string(tokens) + " free slot tokens!\n";

    std::cout << greeting << std::endl;
}

int SlotMachine::getBet() {

    int bet{-1};

    while( bet < 0 || bet > tokens) {           //if bet too small or too large, ask for another bet

        std::cout << "How much would you like to bet (enter 0 to quit)? ";
        std::cin >> bet;
    }

    return bet;
}

void SlotMachine::exitMessage() const{

    if(tokens == 0) {               //if no more tokens

        std::cout << "\nYou just ran out of tokens. Better luck next time!\n"
                     "Game over." << std::endl;
    } else {                        //if some remaining tokents

        std::cout << "\nThank you for playing, come back soon!\n"
                     "Be sure to cash in your remaining " + std::to_string(tokens) +
                     " tokens at the bar!\n"
                     "Game Over." << std::endl;
    }
}

void SlotMachine::printReel() const {

    printTopBottomBorder();         
    printInBetweenRow();
    printTopBottomBorder();
}

void SlotMachine::printInBetweenRow() const {

    int maxShapeHeight = getMaxShapeHeight();               //get the largest height of the shape in the reel
        
    for(int row{0} ; row < maxShapeHeight ; row++ ){        //loop through each row, draw row of each shape

        std::cout << "| ";                                      
        reel[0]->drawRow(row);
        std::cout << " | ";
        reel[1]->drawRow(row);
        std::cout << " | ";
        reel[2]->drawRow(row);
        std::cout << " |" << std::endl;
    }
}

void SlotMachine::printTopBottomBorder() const {                    //print the bottom and top borders

    std::cout << '+';
    std::cout << std::string(reel[0]->getBoxWidth() + 2, '-');      //getboxwidth to print out the right amount of '-' characters
    std::cout << '+';
    std::cout << std::string(reel[1]->getBoxWidth() + 2, '-');
    std::cout << '+';
    std::cout << std::string(reel[2]->getBoxWidth() + 2, '-');
    std::cout << '+' << std::endl;
}

std::size_t SlotMachine::getMaxShapeHeight() const{

    int maxHeight{};

    for( int k = 0 ; k < 3 ; k++ ) {

        maxHeight = std::max<size_t>(maxHeight, reel[k]->getBoxHeight());
    }

    return maxHeight;
}

void SlotMachine::make_shapes() {

    srand(time(NULL));                  //seed rand with time variable

    for( int k = 0 ; k < 3 ; k++ ) {

        make_shape(k);
    }
}

void SlotMachine::make_shape(int k) {

    int n, width, height;               

    n = rand() % 3 + 1;                                                     //n is the number representing type of shape to create
    width = rand() % 25 + 1;
    height = rand() % 25 + 1;

    switch(n) {                                                             //create different shape based on n

        case 0:
            reel[k].reset(new Rhombus{width});                             
            break;
        case 1:
            reel[k].reset(new AcuteTriangle{width});
            break;
        case 2:
            reel[k].reset(new RightTriangle{static_cast<double>(width)});
            break;
        case 3:
            reel[k].reset(new Rectangle{width, height});
            break;
    }

}

void SlotMachine::printBottomShapeTypes() const {                           //prints of description of shapes at bottom of reel

    for( int k = 0 ; k < 3 ; k++) {

        std::cout << "(";
        std::cout << reel[k]->getName();
        std::cout << ", ";
        std::cout << reel[k]->getBoxHeight();
        std::cout << ", ";
        std::cout << reel[k]->getBoxWidth();
        std::cout << ") ";
    }

    std::cout << std::endl;
}

void SlotMachine::display(int bet) {                                                        //display player winnings, or loss

    if(check3xBet()) {

        std::string winning {std::to_string(bet * 3)};
        tokens += bet * 3;

        std::cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas\n"
                     "Congratulations! You win 3 times your bet: " + winning + "\n" +
                     "You now have " + std::to_string(tokens) + " tokens" << std::endl;

        return;
    }

    if(check2xBet()) {

        std::string winning {std::to_string(bet * 2)};
        tokens += bet * 2;

        std::cout << "Three similar shapes\n"
                     "Congratulations! You win 2 times your bet: " + winning + "\n" +
                     "You now have " + std::to_string(tokens) + " tokens" << std::endl;

        return;
    }

    if(check1xBet()) {

        std::string winning {std::to_string(bet)};
        tokens += bet;

        std::cout << "Middle > Left + Right, in Screen Areas\n"
                     "Congratulations! You win your bet: " + winning + "\n" +
                     "You now have " + std::to_string(tokens) + " tokens" << std::endl;

        return;
    }

    if(check0xBet()) {

        std::cout << "Lucky this time!\n"
                     "You don't win, you don't lose, you are safe! \n"
                     "You now have " + std::to_string(tokens) + " tokens" << std::endl;

        return;
    }

    tokens = tokens - bet;
    std::cout << "Oh No!\n"
                 "You lost your bet\n"
                 "You now have " + std::to_string(tokens) + " tokens" << std::endl;

}

bool SlotMachine::check3xBet() const{

    bool twoSimilarShapes{false};                                                           //3x bet is if 2 similar shapes and 2 similar areas
    bool twoSimilarAreas{false};

    std::array<std::string , 3> shapeTypes{};                                               //array of size 3 for the types
    std::array<double , 3> shapeAreas{};                                                    //array of size 3 for the areas

    for( int k = 0 ; k < 3 ; k++) {                                                         //iterate through each shape

        std::string type = reel[k]->getName();                                              //get the kth type
        double area = reel[k]->getArea();                                                   //get the kth area

        if(std::find(shapeTypes.begin(), shapeTypes.end(), type) != shapeTypes.end()) {     //if the type already is in the array, twoSimilarShapes is true
            
            twoSimilarShapes = true;

        } else {

            shapeTypes[k] = type;                                                           //if type not already in array, add it
        }

        if(std::find(shapeAreas.begin(), shapeAreas.end(), area) != shapeAreas.end()) {     //if the area already is in the array, twoSimilarAreas is true
            
            twoSimilarAreas = true;

        } else {

            shapeAreas[k] = area;                                                           //if area not already in array, add it
        }
    }

    return twoSimilarShapes && twoSimilarAreas;
}

bool SlotMachine::check2xBet() const{                                                        //2x bet is won if all 3 shapes of same type

    return (reel[0]->getName() == reel[1]->getName()) &&
           (reel[0]->getName() == reel[2]->getName());
}

bool SlotMachine::check1xBet() const{                                                         //1x bet is won if middle Screen area greater than area of left+right

    return (reel[1]->getScreenArea() >
           (reel[0]->getScreenArea() + reel[2]->getScreenArea()));
}

bool SlotMachine::check0xBet() const{                                                         //0x bet is won if left and right types are the same

    return (reel[0]->getName() == reel[2]->getName());
}

