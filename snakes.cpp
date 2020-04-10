#include <iostream>
#include <conio.h>
#include <string>
 using namespace std;
bool gameOver;
const int width= 30;
const int height = 30;
int x,y, fruitX,fruitY,score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP,DOWN};
eDirection dir;

void Setup(){
    gameOver= false;
    dir = STOP;
    srand(time(0));
    x=width/2;
    y=height/2;
    fruitX=rand()%20;
    fruitY=rand()%20;
    score =0;
}


void Draw(){
    system("clear");
    for(int i=0;i<width;i++){
        cout << "#";
    }
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(j=0)
                cout << "#";
            else if(j==y && i==x)
                cout << "O";
            else if(j== fruitY && i== fruitX)
                cout << "F";
            if(j=width-1)
                cout <<"#";
            else
                cout << " ";
            
        }
    }
    for(int i=0;i<width;i++){
        cout << "#";
    }
    cout << endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
                dir=UP;
                break;
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir= RIGHT;
                break;
            case 's':
                dir= DOWN;
                break;
            case 'esc':
                gameOver=true;
                break;




        }
    }
}

void Logic(){
    switch (dir)
    {
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case 's':
            y--;
            break;
        case 'esc'
                gameOver=true;
                break;
    }
    if(x<0 || x>width || y < 0 || y > height)
        gameover =true;
        break;
    if(x==fruitX || y== fruitY){
        score=score+10;
        fruitY=rand()%20;
        fruitX=rand()%20;

    }
}


 int main(){
     Setup();
    while(gameOver!=false){
        Draw();
        input();
        Logic();
    
    }
    cout << "You scored" << score << "do you wanna play aggain" << endl;
    if(_kwhit())
    _switch (_getch())
        case 'Y';
            main();
    
    return 0;
 }