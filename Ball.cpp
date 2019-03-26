#include "Ball.h"
#include <cstdlib>
#include "ncurses.h"

	bool Ball::beyond_border(int x, int y)
	{
	    int xsize,ysize = 0;
	    bool outofscreen = false;
	    // uzyskanie rozmiaru terminala
	    getmaxyx(stdscr,ysize,xsize);
	    if ( x <= 0 || x >= xsize|| y <= 0 || y >= ysize ) {
		return true;
	    }
	    else
	    {
		return false;
	    }
	    
	}

	void Ball::ballUpdate()
	{
	    int xsize,ysize = 0;
	    // uzyskanie rozmiaru terminala
	    getmaxyx(stdscr,ysize,xsize);

	    int tmpX = this->currentX;
	    int tmpY = this->currentY;
            double dir  = this->direction;


                    if (tmpX + angleX > xsize +dir) {
                        tmpX = xsize +dir;
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

		    
                    if (tmpY + angleY > ysize + 1) {
                        tmpY = ysize + 1;
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



	bool Ball::coordsHasChanged()
	{
	    return currentX != previousX || currentY != previousY; 
	}

	Ball::Ball(int number){
	    int yScreen = 0,xScreen = 0;
	    getmaxyx(stdscr,yScreen,xScreen);
	    this->currentX = xScreen/2;
	    this->currentY = yScreen/2;
            this->angleX = -(rand()%8-1);
            this->angleY = 1;
	    this->id = number;
	    this->previousX = 0;
            this->previousY = 0;
            this->direction=this->angleX;


	  

}
