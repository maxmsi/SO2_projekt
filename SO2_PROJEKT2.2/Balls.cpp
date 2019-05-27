#include "Balls.h"



Balls::Balls(){
    quantityofballs = 0;
    lockedBallAtFirst = false;
    lockedBallAtSecond = false;
    lockedBallAtThird = false;
    unlockFirst=false;
    unlockSecond=false;
    unlockThird=false;

    int id=-1;
    int id2=-1;
    int id3=-1;
}

Balls::~Balls(){
    ballsInWindow.clear();
}

void Balls::addBall(){


    ballsInWindow.push_back(Ball(quantityofballs++));
}
