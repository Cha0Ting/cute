#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std ;
const int N = 23;
struct Point {
    int x,y;
    void set(int X, int Y) {x=X; y=Y;}
};
HANDLE hIn, hOut; 
Point  body[32], v = {-2,0} ;  //體塊,移動向量,
Point  love[23]={{7,2},{9,2},{11,2},{12,3},{14,3},{15,2},{17,2},{19,2},{20,3},{21,4},{20,5},{19,6},{18,7},{17,8},{15,9},{13,10},{11,9},{9,8},{8,7},{7,6},{6,5},{5,4},{6,3}};       
int    delay_time =100;             //延遲時間 
int    len=4;                      //房間邊界, 身長     
bool   bExit = false;

void gotoxy (int x, int y)
{
    static COORD c;  
    c.X = x; c.Y = y;
    SetConsoleCursorPosition (hOut, c);
}

void draw (int x, int y, char* s)
{
    gotoxy (x,y);
    cout << s;
}

void init()
{
	hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    hIn  = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE err = INVALID_HANDLE_VALUE;
    gotoxy (0,0);
    body[0]=love[3];
    body[1]=love[2];
    body[2]=love[1];
    body[3]=love[0];
}

void move_snack(int da)
{   
    int i;
    int& x = body[0].x;
    int& y = body[0].y;
    draw (body[len-1].x, body[len-1].y, " ");//消除  自身走過的路 

    for (i=len-1; i>0; --i)
        body[i] = body[i-1];
    x =love[da%23].x;
    y =love[da%23].y;
    for (i=0; i<len; ++i)
        draw (body[i].x, body[i].y, "●");
}

int main ()
{   
    int da=4; 
    init();
    bool a=true;
    while (!bExit)
    {       
	/*    if(da==23){
	    	if(len<24&&a){
	    	   ++len;
	    	   da=0;}
	    	else if(len==24){
	    		 Sleep (delay_time);
	    		 ++len;
	    		 a=!a;
	    		 da=0;
			}
			else if(len>4&&(!a)){
				--len;
				da=0;
			}
			else{
				a=(!a);
			}   
		}*/
		if(da==23){
	    	++len;
	    	da=0;} 
        move_snack(da);
        Sleep (delay_time); if (kbhit()) break; 
		++da;     
    }
}
