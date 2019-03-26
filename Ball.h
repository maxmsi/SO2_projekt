#ifndef BALL_H
#define BALL_H

class Ball
{
private:

public:
    int previousX;
    int previousY;
    int currentX;
    int currentY;
    double angleX;
    double angleY;
    int speed;
    double direction;
    int id;
    bool beyond_border(int x, int y);
    void ballUpdate();
    void randOfAngle();
    bool coordsHasChanged();
    Ball(int number);
    ~Ball();
};


#endif
