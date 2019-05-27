#ifndef SCREEN_H
#define SCREEN_H

#include "Balls.h"

class window
{
private:

public:
    window();
    ~window();

    void prepareWindow();
    void drawWindow();
    void printSymbol(int x, int y);
    void clearPreviousSymbol(int x, int y);
    void updateWindow(Balls vecballs) ;
};

#endif
