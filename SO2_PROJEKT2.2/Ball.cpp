#include "Ball.h"
#include <cstdlib>
#include "ncurses.h"
#include <iostream>
#include <ncurses.h>
#include "Window.h"
#include "Balls.h"
#include <mutex>

        void Ball::ballNextPos()
	{

	    int xsize,ysize = 0;
	    // uzyskanie rozmiaru terminala
	    getmaxyx(stdscr,ysize,xsize);

            int tmpX = currentX;
            int tmpY = currentY;

            float stair= 0.25 * ysize;
            float st1=xsize- 6*stair;
            float st2=xsize- 4*stair;
            float st3=xsize- 2*stair;


                //odbicie od pierwszego schodka
                if (tmpX + angleX > st1-2 && tmpY >= 0.75*ysize && tmpY+ angleY >(0.75* ysize) && angleX>0) {


                        atFirstStep=true;
                        tmpX=st1;
                        angleX = -angleX;
                        unlock=false;

                    }
                if (tmpX + angleX > st1  && tmpY <= 0.75*ysize && tmpY+ angleY >= 0.75* ysize) {



                        unlock=true;
                        atFirstStep=false;
                        tmpY=0.75*ysize-1;
                        angleY=-angleY;
                   }



                //odbicie drugiego schodka
                if (tmpX + angleX > st2-2 && tmpY >= 0.5*ysize && tmpY+ angleY >=(0.5* ysize)&& angleX>0){


                         atSecondStep=true;
                         tmpX=st2;
                         angleX = -angleX;
                         //unlock2=false;
                    }

                if (tmpX + angleX > st2 && tmpY <= 0.5*ysize && tmpY+ angleY>= 0.5* ysize) {
                    unlock2=true;
                   //atSecondStep=false;
                    tmpY=0.5*ysize-1;
                    angleY = -angleY;

                    }

                //odbicie od trzeciego schodka
                if (tmpX + angleX > st3-3  && tmpY >= 0.25*ysize && tmpY+ angleY >(0.25* ysize)&& angleX>0) {

                    atThirdStep=true;
                    tmpX=st3;
                    angleX = -angleX;
                    unlock3=false;


                    }


                if (tmpX + angleX > st3 && tmpY <= 0.25*ysize && tmpY+ angleY >= 0.25* ysize) {
                    unlock3=true;
                    atThirdStep-false;
                    tmpY=0.25*ysize-1;
                    angleY=-angleY;

                   }





                    if (tmpX + angleX > xsize -2) {
                        tmpX = xsize -1;
		        angleX = -angleX;
		    }
		    
		    if ( tmpX + angleX < 1) {
		        tmpX = 1;
		        angleX = -angleX; 
		    }
		    
		    else
		    {
                        tmpX = tmpX + angleX ;
		    }

		    
                    if (tmpY + angleY > ysize - 2) {
                        tmpY = ysize - 3;
                        angleY = -angleY;
		    }
		   
                    if ( tmpY + angleY <= 1) {
                        tmpY = 1;
                        angleY = -angleY;
                    }

                    else
                    {

                        tmpY=tmpY + angleY;
                    }


	    previousX = currentX;
	    previousY = currentY;
            currentX = tmpX;
            currentY = tmpY;



        }



	Ball::Ball(int number){
	    int yScreen = 0,xScreen = 0;
	    getmaxyx(stdscr,yScreen,xScreen);
            currentX = xScreen/2;
            currentY = yScreen/2;
            angleX = -(rand()%7-3);
            angleY = 1;
            id = number;
            previousX =0;
            previousY =0;
            direction=angleX;
            helpX=-1;
            helpY=-1;

            stopedBall=false;
            atFirstStep=false;
            atSecondStep=false;
            atThirdStep=false;
            unlock=false;
            unlock2=false;
}
        Ball::~Ball(){

        }
