#ifndef BALL_H
#define BALL_H
using namespace std;
class Ball
{
private:

public:
    int previousX;
    int previousY;
    int currentX;
    int currentY;
    int helpX;
    int helpY;

    bool atFirstStep;
    bool atSecondStep;
    bool atThirdStep;

    bool stopedBall;
    bool unlock;
    bool unlock2;
    bool unlock3;

    double angleX;
    double angleY;
    int speed;
    double direction;
    int id;
    void ballNextPos();
    Ball(int number);
    ~Ball();
};


#endif
