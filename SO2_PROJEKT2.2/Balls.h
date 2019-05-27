#ifndef BALLS_H
#define BALLS_H

#include <vector>
#include "Ball.h"



class Balls
{
private:

public:
    bool lockedBallAtFirst;
    bool lockedBallAtSecond;
    bool lockedBallAtThird;
    bool unlockThird;
    bool unlockSecond;
    bool unlockFirst;

    int id;
    int id2;
    int id3;

    std::vector<Ball> ballsInWindow;
    int quantityofballs;


    Balls();
    ~Balls();
    void addBall();
};


#endif
