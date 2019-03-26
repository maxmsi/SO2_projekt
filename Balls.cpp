#include "Balls.h"


Balls::Balls(){
    this->quantityofballs = 0;
}

Balls::~Balls(){
}

void Balls::addNextBall(){

    Ball* nextBall = new Ball(this->quantityofballs++);
    this->ballsInWindow.push_back(nextBall);
}
