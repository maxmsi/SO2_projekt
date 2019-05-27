#include <iostream>
#include <ncurses.h>
#include "Window.h"
#include "Balls.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <unistd.h>
#include <ncurses.h>
#include <vector>
#include <mutex>

std::mutex m_mutex2;

window::~window()
{
        endwin();

}

window::window(){

    prepareWindow();
    drawWindow();
}

void window::prepareWindow(){
    initscr(); // rozpoczęcie trybu curses
    noecho();  // wylaczenie efektu echa
    curs_set(0); // wylaczenie kursora
    clear();     // wyczyszczenie ekranu
    refresh(); // wypisanie na ekranie
}
void window::printSymbol(int x, int y){
    move(y,x);
    printw("O");
}

void window::clearPreviousSymbol(int x, int y){
    move(y,x);
    printw(" ");
}
void window::drawWindow(){

    int xsize=0,ysize=0;
    getmaxyx(stdscr,ysize, xsize);
    float stair= 0.25 * ysize;
    float st1=xsize- 6*stair;
    float st2=xsize- 4* stair;
    float st3=xsize- 2*stair;

    for(int i = 0; i < xsize; i++)
    {
        //rysowanie kolumn
	
        move(0,i);
        printw("-");
	move(ysize-1,i);
        printw("~");

    }

    for(int i = 0; i < xsize; i++)
    {
        //rysowanie wierszy
        move(i,0);
        printw("|");
	move(i,xsize-1);
        printw("|");
    }

    for(int i =0 ; i < 0.25 *ysize; i++)
    {
        //rysowanie schodkow pionowych

       move(0.75*ysize + i,st1);
        printw("*");

        move(0.5*ysize + i,st2);
        printw("*");

        move(0.25*ysize + i,st3);
        printw("*");

    }
    for(int i =0 ; i < 0.5 *ysize; i++)
    {
        //rysowanie schodkow poziomych

        move(0.75*ysize,st1+i);
        printw("*");

        move(0.5*ysize,st2+i);
        printw("*");

        move(0.25*ysize,st3+i);
        printw("*");

    }

     refresh();
}

void window::updateWindow(Balls vecballs){
    ;
    drawWindow();
    for(int i = 0; i < vecballs.quantityofballs; i++)
       {
        lock_guard<mutex> locker(m_mutex2);
               //rysowanie kulek

               clearPreviousSymbol(vecballs.ballsInWindow[i].previousX,vecballs.ballsInWindow[i].previousY);

                if(vecballs.ballsInWindow[i].helpX==vecballs.ballsInWindow[i].currentX && vecballs.ballsInWindow[i].helpY!=vecballs.ballsInWindow[i].currentY)
                {continue;}
                else if(vecballs.ballsInWindow[i].helpX==vecballs.ballsInWindow[i].previousX && vecballs.ballsInWindow[i].helpY==vecballs.ballsInWindow[i].previousY)
                    {
                        clearPreviousSymbol(vecballs.ballsInWindow[i].previousX,vecballs.ballsInWindow[i].previousY);
                        printSymbol(vecballs.ballsInWindow[i].currentX, vecballs.ballsInWindow[i].currentY);
                        refresh();
                     vecballs.ballsInWindow[i].helpX = vecballs.ballsInWindow[i].currentX;
                     vecballs.ballsInWindow[i].helpY = vecballs.ballsInWindow[i].currentY;
                }
                  else  {
                         clearPreviousSymbol(vecballs.ballsInWindow[i].helpX,vecballs.ballsInWindow[i].helpY);
                         printSymbol(vecballs.ballsInWindow[i].currentX, vecballs.ballsInWindow[i].currentY);
                         refresh();
                      vecballs.ballsInWindow[i].helpX = vecballs.ballsInWindow[i].currentX;
                      vecballs.ballsInWindow[i].helpY = vecballs.ballsInWindow[i].currentY;

                     }


    }
}
