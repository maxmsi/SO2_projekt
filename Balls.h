#ifndef BALLS_H
#define BALLS_H

#include <vector>
#include "Ball.h"


class Balls
{
private:

public:

    std::vector<Ball*> ballsInWindow;
    int quantityofballs;

    Balls();
    ~Balls();
    void addNextBall();
};


#endif
