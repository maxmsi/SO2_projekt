#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "Balls.h"
#include "Window.h"
#include <mutex>
#include <condition_variable>
#include <stdio.h>
using namespace std;


bool Runs = true;
window Window;
Balls balls;

Balls * balls2=&balls;

std::mutex mutex_1;
std::condition_variable condVar1;

std::mutex mutex_2;
std::condition_variable condVar2;


std::mutex mutex_3;
std::condition_variable condVar3;


bool stoped1=false;
bool stoped2=false;
bool stoped3=false;

bool unstoped1=false;
bool unstoped2=false;
bool unstoped3=false;

int step1=0,step2=0,step3=0;


void ballThreadFunction(int BallId){

    while(Runs){

        usleep(89500);
        balls.ballsInWindow[BallId].ballNextPos();

        if(balls.ballsInWindow[BallId].atFirstStep==true && step1==0){
            std::unique_lock<std::mutex> lock1(mutex_1);
            stoped1=true;
            step1=1;
            condVar1.wait(lock1,[]{return unstoped1;});
            stoped1=false;

        }


        if(balls.ballsInWindow[BallId].atSecondStep==true && step2==0){
            std::unique_lock<std::mutex> lock2(mutex_2);
            stoped2=true;
            step2=1;
            condVar2.wait(lock2,[]{return unstoped2;});
            stoped2-false;
        }

        if(balls.ballsInWindow[BallId].atThirdStep==true && step3 ==0 ){
            std::unique_lock<std::mutex> lock3(mutex_3);
            stoped3=true;
            step3=1;
            condVar3.wait(lock3,[]{return unstoped3;});
            stoped3-false;
        }

        if(stoped2==true && balls.ballsInWindow[BallId].unlock2==true){

            {
               std::lock_guard<std::mutex> lock2(mutex_2);
               unstoped2=true;
                step2=0;
           }
           condVar2.notify_all();
}

        if(stoped1==true && balls.ballsInWindow[BallId].unlock==true){
           {
               std::lock_guard<std::mutex> lock1(mutex_1);
               unstoped1=true;
               step1=0;

           }

           condVar1.notify_all();
}


        if(stoped3==true && balls.ballsInWindow[BallId].unlock3==true){
           {
               std::lock_guard<std::mutex> lock3(mutex_3);
               unstoped3=true;
               step3=0;

           }

           condVar3.notify_all();
}

    }
}



void updateWindowTh(){
    while(Runs){
        usleep(10);
        Window.updateWindow(balls);
    }
    usleep(10000);
    endwin();
}
void exitTh(){
    while(Runs){
        char key = getch();
        if(key == 'x')
        Runs = false;
    }
    //usleep(100000);
}

int main(){
    
    unsigned ballscreated = 0;


    srand(time(NULL));
    vector<std::thread> ballsthreads;
    std::thread WindowThread(updateWindowTh);
    std::thread exitThread(exitTh);

    for(int i=0;i<6;i++)
    {

        balls.addBall();
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
	ballscreated = i + 1;
        sleep(2);
        if(!Runs) break;

    }


    WindowThread.join();
    exitThread.join();
    for(int i = 0; i <ballscreated; i++)
    {
         ballsthreads[i].join();
    }
   while(Runs){}
   usleep(1000);
    return 0;
}


