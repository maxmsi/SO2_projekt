#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "Balls.h"
#include "Window.h"

using namespace std;

bool Runs = true;
window *Window; 
Balls *vecballs;


void ballThreadFunction(int BallId){
 
    while(Runs){
        usleep(100000);
        vecballs->ballsInWindow[BallId]->ballUpdate();
    }
    
}


void updateWindowF(){

    while(Runs){
        usleep(1);
        Window->updateWindow(vecballs);
    }
    //niszczenie obiektu okna
    delete Window;
}
// konczenie programu przy pomocy x
void exitF(){
    while(Runs){
        char key = getch();
        if(key == 'x')
        Runs = false;
    }
}

int main(){
    
    unsigned ballscreated = 0;
    Window = new window();
  
    vecballs = new Balls();
    srand(time(NULL));
    vector<std::thread> ballsthreads;
    std::thread WindowThread(updateWindowF);
    std::thread exitThread(exitF);
   
	// ustawiamy ilośc kulek ktore zostana wypuszczone
    for(int i=0;i< 5;i++)
    {

        vecballs->addNextBall();
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
	ballscreated = i + 1;
        sleep(3);
        if(!Runs) break;

    }

    WindowThread.join();
    exitThread.join();
  	//endwin();
     for(int i = 0; i <ballscreated; i++)
    {
         ballsthreads[i].join();
    }
    return 0;
    delete Window;
	
}


