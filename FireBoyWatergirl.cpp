#include <iostream>
#include<windows.h>
#include <conio.h>
using namespace std;
void generateColors();
void gotoxy(int x, int y);

int startGame();
void startMenu();
void wongameMenu();

void printmaze1();
void printmaze2();
void printPlayer1();
void erasePlayer1();
void movePlayerRight1(int &exitPlayer1);
void movePlayerLeft1(int &exitPlayer1);
void movePlayerUp1(int &exitPlayer1);
void jumpPlayer1Right(int &exitPlayer1);
void jumpPlayer1Left(int &exitPlayer1);
void automaticallyMovePlayer1Down(int &exitPlayer1);
void printPlayer2();
void erasePlayer2();
void movePlayerRight2(int &exitPlayer2);
void movePlayerLeft2(int &exitPlayer2);
void movePlayerUp2(int &exitPlayer2);
void jumpPlayer2Right(int &exitPlayer2);
void jumpPlayer2Left(int &exitPlayer2);
void automaticallyMovePlayer2Down(int &exitPlayer2);
bool cheakForFireForPlayer1();
bool cheakForWaterForPlayer2();
void printEnemy1();
void eraseEnemy1();
void moveEnemy1();
void Enemy1ChasingPlayer1();
void Enemy1ChasingPlayer2();

void printEnemy2();
void eraseEnemy2();
void moveEnemy2();
void Enemy2ChasingPlayer1();
void Enemy2ChasingPlayer2();
bool cheakForWinGamePlayer2();
bool cheakForWinGamePlayer1();
char getCharAtxy(short int x, short int y);
void setCharAtxy(short int x, short int y, char ch);
void endGameMenu();

void enemyCollideWithPlayer1();
void enemyCollideWithPlayer2();
void bulletcollisionwithEnemy1();
void bulletcollisionwithEnemy2();




void printBulletLeftPlayer1(int x,int y);
void eraseBulletLeftPlayer1(int x,int y);
void makeBulletInactiveLeftPlayer1(int index);
void deleteBulletLeftPlayer1(int index);
void createBulletLeftPlayer1();
void moveBulletLeftPlayer1();
void printBulletRightPlayer1(int x,int y);
void eraseBulletRightPlayer1(int x,int y);
void makeBulletInactiveRightPlayer1(int index);
void deleteBulletRightPlayer1(int index);
void moveBulletRightPlayer1();
void createBulletRightPlayer1();


void printBulletLeftPlayer2(int x,int y);
void eraseBulletLeftPlayer2(int x,int y);
void makeBulletInactiveLeftPlayer2(int index);
void deleteBulletLeftPlayer2(int index);
void createBulletLeftPlayer2();
void moveBulletLeftPlayer2();
void printBulletRightPlayer2(int x,int y);
void eraseBulletRightPlayer2(int x,int y);
void makeBulletInactiveRightPlayer2(int index);
void deleteBulletRightPlayer2(int index);
void moveBulletRightPlayer2();
void createBulletRightPlayer2();


int bulletXLeftPlayer2[100];
int bulletYLeftPlayer2[100];
bool bulletValueLeftPlayer2[100];
int bulletcountLeftPlayer2=0;
int bulletXRightPlayer2[100];
int bulletYRightPlayer2[100];
bool bulletValueRightPlayer2[100];
int bulletcountRightPlayer2=0;

int bulletXLeftPlayer1[100];
int bulletYLeftPlayer1[100];
bool bulletValueLeftPlayer1[100];
int bulletcountLeftPlayer1=0;
int bulletXRightPlayer1[100];
int bulletYRightPlayer1[100];
bool bulletValueRightPlayer1[100];
int bulletcountRightPlayer1=0;

const int rows1 = 40;  // Number of rows1 in the maze1
const int cols1 = 110; // Number of columns in the maze1
const int rows2 = 40;  // Number of rows1 in the maze2
const int cols2 = 110; // Number of columns in the maze2
const int playerHeight1 = 2;
const int playerWidth1 = 6;
const int playerHeight2 = 2;
const int playerWidth2 = 6;
const int EnemyHeight1 = 2;
const int EnemyWidth1 = 6;
const int EnemyHeight2 = 2;
const int EnemyWidth2 = 6;
int pX1 = 0, pY1 = 0;
int pX2 = 0, pY2 = 0;
int eX1 = 0, eY1 = 0;
int eX2 = 0, eY2 = 0;
int bEXR1 = eX1 , bEYR1 = eY1;
int player1Health=0;
int player2Health=0;
int enemy1Health=0,enemy2Health=0;




int player1MouthX=0, player1MouthY=0;





char maze1[rows1][cols1]= {
    "#############################################################################################################",
    "#############################################################################################################",
    "#############################################################################################################",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                                              =====      .....           ##",
    "##                                                                              =====      .....           ##",
    "##               #############&&&&&&#########################################################################",
    "##                         #############                                             ##########            ##",
    "###########                #############                                               ######              ##",
    "###########                                                                                                ##",
    "###############                                ##################\\                                         ##",
    "###############                                ###################\\                                        ##",
    "###########################################################\\#########@@@@@@#################               ##",
    "##                                                          \\##################################            ##",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                                                                     ######",
    "##                                                                                                 ##########",
    "##                                                                                                 ##########",
    "##                #############\\                                                         ####################",
    "##                ##           #\\############################################################################",
    "##            ######                                                                                 ########",
    "##                                                                                                    #######",
    "##                                                                                                    #######",
    "#########                                                                                             #######",
    "#############                                                                                           #####",
    "#########################\\                                                                                 ##",
    "##                       #\\                                                                                ##",
    "##                         ##########&&&&&&&&#####################@@@@@@#########################          ##",
    "##                                                                                                         ##",
    "#################                                                                                          ##",
    "##                                                                                                    #######",
    "##                                                                                                    #######",
    "##                                                                                                    #######",
    "##                                                                                              #############",
    "##############################@@@@@@@@########################&&&&&&&&#######################################",
    "#############################################################################################################",
    "#############################################################################################################"
};

char maze2[rows2][cols2]= {
    "#############################################################################################################",
    "#############################################################################################################",
    "#############################################################################################################",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##        .....     =====                                                                                  ##",
    "##        .....     =====                                                                                  ##",
    "#########################################@@@@@@@@#####################&&&&&&&&###################          ##",
    "############                                                                                    ###        ##",
    "#########                                                                                                  ##",
    "##                                                                                                      #####",
    "##                                                                                                     ######",
    "##                                                                                                 ##########",
    "##                                                                                                         ##",
    "##                  #########################################################################################",
    "##                                                                                                         ##",
    "##############                                                                                             ##",
    "##################                                                                                         ##",
    "######################                                                                                     ##",
    "##########################                                                                                 ##",
    "##############################                                                                             ##",
    "###############################################@@@@@@@######################\\                              ##",
    "##                                                                          #\\#############                ##",
    "##                                                                                        #####            ##",
    "##                                                                                                         ##",
    "##               ###############                                                                     ########",
    "##               ##           ##                                                                 ############",
    "##               ##           ##                                                                 ############",
    "##########################################                  ###############&&&&&&&&##########################",
    "##                                       ##                ##                                              ##",
    "##                                                                                                         ##",
    "##                                                                                                         ##",
    "##                                                ####                                                     ##",
    "##                                       #######################                                           ##",
    "##         #####################@@@@#####################################&&&&###################           ##",
    "################                                                                           ##################",
    "#############################################################################################################",
    "#############################################################################################################"
};

char player2D1[playerHeight1][playerWidth1] = 
                        {"  O  ",
                         "(|||)",
                        
                        };
char player2D2[playerHeight2][playerWidth2] = 
                        {"  v  ",
                         "(|||)",
                        
                        };

char Enemy2D1[EnemyHeight1][EnemyWidth1] = 
                        {" =U= ",
                         "|||||",
                        
                        };
                    
char Enemy2D2[EnemyHeight2][EnemyWidth2] = 
                        {" -8- ",
                         "|||||",
                        
                        };


int main()
{
    int exitPlayer1=0,exitPlayer2=0;

    
    
    system("cls");
    startMenu();
    if(startGame()==1)
    {
    pX1 = 37, pY1 = 34;
    pX2 = 37, pY2 = 40;
    eX1 = 30, eY1 = 60;
    eX2 = 22, eY2 = 65;
    player1MouthX=pX1, player1MouthY=pY1;
    player1Health=50,player2Health=50;
    enemy1Health=15,enemy2Health=15;
    

    printmaze1();
    printPlayer1();
    printPlayer2();
    printEnemy1();
    printEnemy2();
    
    gotoxy(80,1);
    cout<<"\33[32m"<<"Level 1";
    
    while(true)   
    {
    gotoxy(2,10);
    cout<<"\33[32m"<<"Player 1 Health: "<<player1Health;
    gotoxy(2,12);
    cout<<"\33[32m"<<"Player 2 Health: "<<player2Health;
    gotoxy(142,10);
    cout<<"\033[38;5;93m"<<"Enemy 1 Health: "<<enemy1Health;
    gotoxy(142,12);
    cout<<"\033[38;5;93m"<<"Enemy 2 Health: "<<enemy2Health;

    
    
    
    if(enemy1Health>0)
    {
    if(eX1!=pX1 && eX1!=pX2 )
    {
        moveEnemy1();
    }
    else if(eX1==pX1)
    {
        Enemy1ChasingPlayer1();
    }
    else if(eX1==pX2)
    {
        Enemy1ChasingPlayer2();
    }
    }
    else{
        eraseEnemy1();
    }
    if(enemy2Health>0)
    {
    if(eX2!=pX1 && eX2!=pX2 )
    {
        moveEnemy2();
    }
    else if(eX2==pX1 )
    {
        Enemy2ChasingPlayer1();
    }
    else if( eX2==pX2 )
    {
        Enemy2ChasingPlayer2();
    }
    }
    else{
        eraseEnemy2();
    }

    automaticallyMovePlayer1Down(exitPlayer1);
    automaticallyMovePlayer2Down(exitPlayer2);
    if(GetAsyncKeyState(VK_RIGHT))
    {
    movePlayerRight1(exitPlayer1);
    }
    if(GetAsyncKeyState(VK_LEFT))
    {
    movePlayerLeft1(exitPlayer1);
    }
    if(GetAsyncKeyState(VK_UP))
    {
    movePlayerUp1(exitPlayer1);
    }
    if(GetAsyncKeyState('M'))
    {
    jumpPlayer1Right(exitPlayer1);
    }
    if(GetAsyncKeyState('N'))
    {
    jumpPlayer1Left(exitPlayer1);
    }

    if(GetAsyncKeyState('D'))
    {
    movePlayerRight2(exitPlayer2);
    }
    if(GetAsyncKeyState('A'))
    {
    movePlayerLeft2(exitPlayer2);
    }
    if(GetAsyncKeyState('W'))
    {
    movePlayerUp2(exitPlayer2);
    }
    if(GetAsyncKeyState('V'))
    {
    jumpPlayer2Right(exitPlayer2);
    }
    if(GetAsyncKeyState('C'))
    {
    jumpPlayer2Left(exitPlayer2);
    }

    if(GetAsyncKeyState('K'))
    {
        createBulletLeftPlayer1();
    }
    
    

    
    moveBulletLeftPlayer1();
    

    if(cheakForFireForPlayer1()==true || cheakForWaterForPlayer2()==true)
    {
        endGameMenu();
        break;
    }
    if(cheakForWinGamePlayer1()==true && cheakForWinGamePlayer2()==true)
    {
        wongameMenu();
        break;
    }

    enemyCollideWithPlayer1();
    enemyCollideWithPlayer2();
    if(player1Health==0 || player2Health==0)
    {
        endGameMenu();
        break;
    }
    bulletcollisionwithEnemy1();
    bulletcollisionwithEnemy2();

    Sleep(100);
    }
    }
    else if(startGame()==2)
    {

    system("cls");
    printmaze2();
    printPlayer1();
    printPlayer2();
    printEnemy1();
    printEnemy2();
    pX1 = 35, pY1 = 127;
    pX2 = 35, pY2 = 32;
    eX1 = 23, eY1 = 60;
    eX2 = 16, eY2 = 65;
    gotoxy(2,10);
    cout<<"Player 1 Health: "<<player1Health;
    player1Health=100,player2Health=100;
    int enemy1Health=80,enemy2Health=100;
    while(true)
    {
    gotoxy(2,10);
    cout<<"\33[32m"<<"Player 1 Health: "<<player1Health;
    gotoxy(2,12);
    cout<<"\33[32m"<<"Player 2 Health: "<<player2Health;
    gotoxy(142,10);
    cout<<"\033[38;5;93m"<<"Enemy 1 Health: "<<enemy1Health;
    gotoxy(142,12);
    cout<<"\033[38;5;93m"<<"Player 2 Health: "<<player2Health;
    
    bulletcollisionwithEnemy1();
    bulletcollisionwithEnemy2();
    
    if(enemy1Health>0)
    {
    if(eX1!=pX1 && eX1!=pX2 )
    {
        moveEnemy1();
    }
    else if(eX1==pX1)
    {
        Enemy1ChasingPlayer1();
    }
    else if(eX1==pX2)
    {
        Enemy1ChasingPlayer2();
    }
    }
    else{
        eraseEnemy1();
    }
    if(enemy2Health>0)
    {
    if(eX2!=pX1 && eX2!=pX2 )
    {
        moveEnemy2();
    }
    else if(eX2==pX1 )
    {
        Enemy2ChasingPlayer1();
    }
    else if( eX2==pX2 )
    {
        Enemy2ChasingPlayer2();
    }
    }
    else
    {
        eraseEnemy2();
    }

    automaticallyMovePlayer1Down(exitPlayer1);
    automaticallyMovePlayer2Down(exitPlayer2);
    if(GetAsyncKeyState(VK_RIGHT))
    {
    movePlayerRight1(exitPlayer1);
    }
    if(GetAsyncKeyState(VK_LEFT))
    {
    movePlayerLeft1(exitPlayer1);
    }
    if(GetAsyncKeyState(VK_UP))
    {
    movePlayerUp1(exitPlayer1);
    }
    if(GetAsyncKeyState('M'))
    {
    jumpPlayer1Right(exitPlayer1);
    }
    if(GetAsyncKeyState('N'))
    {
    jumpPlayer1Left(exitPlayer1);
    }

    if(GetAsyncKeyState('D'))
    {
    movePlayerRight2(exitPlayer2);
    }
    if(GetAsyncKeyState('A'))
    {
    movePlayerLeft2(exitPlayer2);
    }
    if(GetAsyncKeyState('W'))
    {
    movePlayerUp2(exitPlayer2);
    }
    if(GetAsyncKeyState('V'))
    {
    jumpPlayer2Right(exitPlayer2);
    }
    if(GetAsyncKeyState('C'))
    {
    jumpPlayer2Left(exitPlayer2);
    }

    if(GetAsyncKeyState(VK_SPACE))
    {
    
    }
    if(cheakForFireForPlayer1()==true || cheakForWaterForPlayer2()==true)
    {
        endGameMenu();
        break;
    }
    if(cheakForWinGamePlayer1()==true && cheakForWinGamePlayer2()==true)
    {
        wongameMenu();
        break;
    }
    enemyCollideWithPlayer1();
    enemyCollideWithPlayer2();
    if(player1Health==0 || player2Health==0)
    {
        endGameMenu();
        break;
    }



    Sleep(100);
    }

    }


}





/*Player 1 functions (WaterBoy)  start*/

void printPlayer1(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for(int i=0;i<playerHeight1;i++){
        for(int j=0;j<playerWidth1;j++) {
            gotoxy(pY1+j,pX1+i);
            cout<<player2D1[i][j];
        }
    }
    // Reset text color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void erasePlayer1()
{
    for(int i=0;i<playerHeight1;i++){
        for(int j=0;j<playerWidth1-5;j++) {
            gotoxy(pY1+j,pX1+i);
            cout<<"     ";
        }
    }
}

void player1ContactWithEnemy()
{
    if ( getCharAtxy(pY1+5, pX1) == '|' || getCharAtxy(pY1+5, pX1+1)=='|' || getCharAtxy(pY1 -1,pX1) == '|' && getCharAtxy(pY1 -1,pX1+1) == '|')
    int x;
    
}

void movePlayerRight1(int &exitPlayer1)
{
    // Check if moving right won't go beyond the maze1 boundaries
    if ( getCharAtxy(pY1+5, pX1) == ' ' && getCharAtxy(pY1+5, pX1+1)==' ')
    {   
        erasePlayer1();
        pY1 = pY1 + 1;
        player1MouthY=pY1;
        printPlayer1();
    }
    if(cheakForFireForPlayer1()==true)
    {
        exitPlayer1=1;
    }
}

void movePlayerLeft1(int &exitPlayer1)
{
if (getCharAtxy(pY1 -1,pX1) == ' ' && getCharAtxy(pY1 -1,pX1+1) == ' ')
{
erasePlayer1();
pY1 = pY1 - 1;
player1MouthY=pY1;
printPlayer1();
}
if(cheakForFireForPlayer1()==true)
{
    exitPlayer1=1;
}
}



void movePlayerUp1(int &exitPlayer1)
{


int count=0;
bool cheak=true;
while(count<=3 && getCharAtxy(pY1,pX1-1) == ' ' && getCharAtxy(pY1+2,pX1-1)== ' ' && getCharAtxy(pY1+1,pX1-1)== ' '  && getCharAtxy(pY1+4,pX1-1)== ' '  && getCharAtxy(pY1+3,pX1-1)== ' ')
{
count++;                             
erasePlayer1();
pX1 = pX1 -1 ;
player1MouthX=pX1;
printPlayer1();
if(count>3 || getCharAtxy(pY1,pX1-1) != ' ' || getCharAtxy(pY1+2,pX1-1)!= ' ' || getCharAtxy(pY1+1,pX1-1)!= ' ' || getCharAtxy(pY1+4,pX1-1)!= ' '  || getCharAtxy(pY1+3,pX1-1)!= ' ')
{
break;
}
}
Sleep(300);
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' ')
{
break;
}

}
if(cheakForFireForPlayer1()==true)
{
    exitPlayer1=1;
}
}

void jumpPlayer1Right(int &exitPlayer1)
{


int count=0;
bool cheak=true;
if(pY1<120 && pY1>47)
{
while(count<=3 && getCharAtxy(pY1,pX1-1) == ' ' && getCharAtxy(pY1+2,pX1-1)== ' ' && getCharAtxy(pY1+1,pX1-1)== ' ' && getCharAtxy(pY1+4,pX1-1)== ' '  && getCharAtxy(pY1+3,pX1-1)== ' ' && getCharAtxy(pY1+5, pX1-1) == ' '  && getCharAtxy(pY1+5, pX1) == ' ' && getCharAtxy(pY1+5, pX1+1)==' ' && getCharAtxy(pY1+6, pX1) == ' ' && getCharAtxy(pY1+6, pX1+1)==' ')
{
count++;                             
erasePlayer1();
pX1 = pX1 -1 ;
player1MouthX=pX1;
pY1=pY1+2;
player1MouthY=pY1;
printPlayer1();
if(count>3 || getCharAtxy(pY1,pX1-1) != ' ' || getCharAtxy(pY1+2,pX1-1)!= ' ' || getCharAtxy(pY1+1,pX1-1)!= ' ' || getCharAtxy(pY1+4,pX1-1)!= ' '  || getCharAtxy(pY1+3,pX1-1)!= ' '  || getCharAtxy(pY1+5, pX1-1) != ' ' || getCharAtxy(pY1+5, pX1) != ' ' || getCharAtxy(pY1+5, pX1+1)!=' ' || getCharAtxy(pY1+6, pX1) != ' ' || getCharAtxy(pY1+6, pX1+1)!=' ')
{
break;
}
}
}
else
{
while(count<=3 && getCharAtxy(pY1,pX1-1) == ' ' && getCharAtxy(pY1+2,pX1-1)== ' ' && getCharAtxy(pY1+1,pX1-1)== ' ' && getCharAtxy(pY1+4,pX1-1)== ' '   && getCharAtxy(pY1+3,pX1-1)== ' ' && getCharAtxy(pY1+5, pX1-1) == ' ' && getCharAtxy(pY1+5, pX1) == ' ' && getCharAtxy(pY1+5, pX1+1)==' ')
{
count++;                             
erasePlayer1();
pX1 = pX1 -1 ;
player1MouthX=pX1;
pY1=pY1+1;
player1MouthY=pY1;
printPlayer1();
if(count>3 || getCharAtxy(pY1,pX1-1) != ' ' || getCharAtxy(pY1+2,pX1-1)!= ' ' || getCharAtxy(pY1+1,pX1-1)!= ' ' || getCharAtxy(pY1+4,pX1-1)!= ' ' || getCharAtxy(pY1+5, pX1-1) != ' ' || getCharAtxy(pY1+3,pX1-1)!= ' ' || getCharAtxy(pY1+5, pX1) != ' ' || getCharAtxy(pY1+5, pX1+1)!=' ' )
{
break;
}
}
}
Sleep(300);

if(pY1<120 && pY1>47)
{
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '   && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1+5, pX1) == ' ' && getCharAtxy(pY1+5, pX1+1)==' ' && getCharAtxy(pY1+6, pX1) == ' ' && getCharAtxy(pY1+6, pX1+1)==' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
pY1=pY1+2;
player1MouthY=pY1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' '  || getCharAtxy(pY1+5, pX1) != ' ' || getCharAtxy(pY1+5, pX1+1)!=' ' || getCharAtxy(pY1+6, pX1) != ' ' || getCharAtxy(pY1+6, pX1+1)!=' ')
{
break;
}

}
}
else 
{
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' ' && getCharAtxy(pY1+5,pX1+2)== ' ' && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1+5, pX1) == ' ' && getCharAtxy(pY1+5, pX1+1)==' ' )
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
pY1=pY1+1;
player1MouthY=pY1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+5,pX1+2)== ' '  || getCharAtxy(pY1+3,pX1+2)!= ' '  || getCharAtxy(pY1+5, pX1) != ' ' || getCharAtxy(pY1+5, pX1+1)!=' ' )
{
break;
}

}
}
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1+5, pX1) != ' ' && getCharAtxy(pY1+5, pX1+1)!=' ' && getCharAtxy(pY1+6, pX1) != ' ' && getCharAtxy(pY1+6, pX1+1)!=' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' ' )
{
break;
}

}
if(cheakForFireForPlayer1()==true)
{
    exitPlayer1=1;
}
}

void jumpPlayer1Left(int &exitPlayer1)
{


int count=0;
bool cheak=true;
if(pY1<120 && pY1>47)
{
while(count<=3 && getCharAtxy(pY1,pX1-1) == ' ' && getCharAtxy(pY1-1,pX1-1) == ' ' && getCharAtxy(pY1+2,pX1-1)== ' ' && getCharAtxy(pY1+1,pX1-1)== ' ' && getCharAtxy(pY1+4,pX1-1)== ' '  && getCharAtxy(pY1+3,pX1-1)== ' ' && getCharAtxy(pY1-1, pX1) == ' ' && getCharAtxy(pY1-1, pX1+1)==' ' && getCharAtxy(pY1-2, pX1) == ' ' && getCharAtxy(pY1-2, pX1+1)==' ')
{
count++;                             
erasePlayer1();
pX1 = pX1 -1 ;
player1MouthX=pX1;
pY1=pY1-2;
player1MouthY=pY1;
printPlayer1();
if(count>3 || getCharAtxy(pY1,pX1-1) != ' ' || getCharAtxy(pY1-1,pX1-1) != ' ' || getCharAtxy(pY1+2,pX1-1)!= ' ' || getCharAtxy(pY1+1,pX1-1)!= ' ' || getCharAtxy(pY1+4,pX1-1)!= ' '  || getCharAtxy(pY1+3,pX1-1)!= ' ' || getCharAtxy(pY1-1, pX1) != ' ' || getCharAtxy(pY1-1, pX1+1)!=' ' || getCharAtxy(pY1-2, pX1) != ' ' || getCharAtxy(pY1-2, pX1+1)!=' ')
{
break;
}
}
}
else
{
while(count<=3 && getCharAtxy(pY1,pX1-1) == ' '  && getCharAtxy(pY1-1,pX1-1) == ' ' && getCharAtxy(pY1+2,pX1-1)== ' ' && getCharAtxy(pY1+1,pX1-1)== ' ' && getCharAtxy(pY1+4,pX1-1)== ' '  && getCharAtxy(pY1+3,pX1-1)== ' ' && getCharAtxy(pY1-1, pX1) == ' ' && getCharAtxy(pY1-1, pX1+1)==' ')
{
count++;                             
erasePlayer1();
pX1 = pX1 -1 ;
player1MouthX=pX1;
pY1=pY1-1;
player1MouthY=pY1;
printPlayer1();
if(count>3 || getCharAtxy(pY1,pX1-1) != ' ' || getCharAtxy(pY1-1,pX1-1) != ' ' || getCharAtxy(pY1+2,pX1-1)!= ' ' || getCharAtxy(pY1+1,pX1-1)!= ' ' || getCharAtxy(pY1+4,pX1-1)!= ' '  || getCharAtxy(pY1+3,pX1-1)!= ' ' || getCharAtxy(pY1-1, pX1) != ' ' || getCharAtxy(pY1-1, pX1+1)!=' ' )
{
break;
}
}
}
Sleep(300);

if(pY1<120 && pY1>47)
{
while(getCharAtxy(pY1,pX1+2) == ' ' &&  getCharAtxy(pY1-1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1-1, pX1) == ' ' && getCharAtxy(pY1-1, pX1+1)==' ' && getCharAtxy(pY1-2, pX1) == ' ' && getCharAtxy(pY1-2, pX1+1)==' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
pY1=pY1-2;
player1MouthY=pY1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1-1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' '  || getCharAtxy(pY1-1, pX1) != ' ' || getCharAtxy(pY1-1, pX1+1)!=' ' || getCharAtxy(pY1-2, pX1) != ' ' || getCharAtxy(pY1-2, pX1+1)!=' ')
{
break;
}

}
}
else
{
while(getCharAtxy(pY1,pX1+2) == ' ' &&  getCharAtxy(pY1-1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1-1, pX1) == ' ' && getCharAtxy(pY1-1, pX1+1)==' ' )
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
pY1=pY1-1;
player1MouthY=pY1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1-1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' '  || getCharAtxy(pY1-1, pX1) != ' ' || getCharAtxy(pY1-1, pX1+1)!=' ' )
{
break;
}

}
}
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' '  && getCharAtxy(pY1-1, pX1) != ' ' && getCharAtxy(pY1-1, pX1+1)!=' ' && getCharAtxy(pY1-2, pX1) != ' ' && getCharAtxy(pY1-2, pX1+1)!=' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' ' )
{
break;
}

}
if(cheakForFireForPlayer1()==true)
{
    exitPlayer1=1;
}
}


void automaticallyMovePlayer1Down(int &exitPlayer1)
{
while(getCharAtxy(pY1,pX1+2) == ' ' && getCharAtxy(pY1+2,pX1+2)== ' ' && getCharAtxy(pY1+1,pX1+2)== ' ' && getCharAtxy(pY1+4,pX1+2)== ' '  && getCharAtxy(pY1+3,pX1+2)== ' ')
{
erasePlayer1();
pX1 = pX1 +1 ;
player1MouthX=pX1;
printPlayer1();
if(getCharAtxy(pY1,pX1+2) != ' ' || getCharAtxy(pY1+2,pX1+2)!= ' ' || getCharAtxy(pY1+1,pX1+2)!= ' ' || getCharAtxy(pY1+4,pX1+2)!= ' '  || getCharAtxy(pY1+3,pX1+2)!= ' ' )
{
break;
}

}
if(cheakForFireForPlayer1()==true)
{
    exitPlayer1=1;
}
}

bool cheakForWinGamePlayer1()
{
    bool cheak=false;
    if ( (getCharAtxy(pY1+5, pX1) == '=' && getCharAtxy(pY1+5, pX1+1)=='=') ||  (getCharAtxy(pY1 -1,pX1) == '=' && getCharAtxy(pY1 -1,pX1+1) == '=') )
    {
        cheak=true;
    }
    return cheak;
}

/*Player 1 functions (WaterBoy)  end*/


/*Player 2 functions (Firegirl)  start*/
void printPlayer2(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    for(int i=0;i<playerHeight2;i++){
        for(int j=0;j<playerWidth2;j++) {
            gotoxy(pY2+j,pX2+i);
            cout<<player2D2[i][j];
        }
    }
    // Reset text color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void erasePlayer2()
{
    for(int i=0;i<playerHeight2;i++){
        for(int j=0;j<playerWidth2-5;j++) {
            gotoxy(pY2+j,pX2+i);
            cout<<"     ";
        }
    }
}

void movePlayerRight2(int &exitPlayer2)
{
    // Check if moving right won't go beyond the maze1 boundaries
    if ( getCharAtxy(pY2+5, pX2) == ' ' && getCharAtxy(pY2+5, pX2+1)==' ')
    {   
        erasePlayer2();
        pY2 = pY2 + 1;
        printPlayer2();
    }
    if(cheakForWaterForPlayer2()==true)
    {
        exitPlayer2=1;
    }
}

void movePlayerLeft2(int &exitPlayer2)
{
if (getCharAtxy(pY2 -1,pX2) == ' ' && getCharAtxy(pY2 -1,pX2+1) == ' ')
{
erasePlayer2();
pY2 = pY2 - 1;
printPlayer2();
}
if(cheakForWaterForPlayer2()==true)
{
    exitPlayer2=1;
}
}


void movePlayerUp2(int &exitPlayer2)
{


int count=0;
bool cheak=true;
while(count<=3 && getCharAtxy(pY2,pX2-1) == ' ' && getCharAtxy(pY2+2,pX2-1)== ' ' && getCharAtxy(pY2+1,pX2-1)== ' '  && getCharAtxy(pY2+4,pX2-1)== ' '  && getCharAtxy(pY2+3,pX2-1)== ' ')
{
count++;                             
erasePlayer2();
pX2 = pX2 -1 ;
printPlayer2();
if(count>3 || getCharAtxy(pY2,pX2-1) != ' ' || getCharAtxy(pY2+2,pX2-1)!= ' ' || getCharAtxy(pY2+1,pX2-1)!= ' ' || getCharAtxy(pY2+4,pX2-1)!= ' '  || getCharAtxy(pY2+3,pX2-1)!= ' ')
{
break;
}
}
Sleep(300);
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' ')
{
break;
}

}
if(cheakForWaterForPlayer2()==true)
{
    exitPlayer2=1;
}
}

void jumpPlayer2Right(int &exitPlayer2)
{


int count=0;
bool cheak=true;
if(pY2<120 && pY2>47)
{
while(count<=3 && getCharAtxy(pY2,pX2-1) == ' ' && getCharAtxy(pY2+2,pX2-1)== ' ' && getCharAtxy(pY2+1,pX2-1)== ' ' && getCharAtxy(pY2+4,pX2-1)== ' '  && getCharAtxy(pY2+3,pX2-1)== ' ' && getCharAtxy(pY2+5, pX2-1) == ' '  && getCharAtxy(pY2+5, pX2) == ' ' && getCharAtxy(pY2+5, pX2+1)==' ' && getCharAtxy(pY2+6, pX2) == ' ' && getCharAtxy(pY2+6, pX2+1)==' ')
{
count++;                             
erasePlayer2();
pX2 = pX2 -1 ;
pY2=pY2+2;
printPlayer2();
if(count>3 || getCharAtxy(pY2,pX2-1) != ' ' || getCharAtxy(pY2+2,pX2-1)!= ' ' || getCharAtxy(pY2+1,pX2-1)!= ' ' || getCharAtxy(pY2+4,pX2-1)!= ' '  || getCharAtxy(pY2+3,pX2-1)!= ' '  || getCharAtxy(pY2+5, pX2-1) != ' ' || getCharAtxy(pY2+5, pX2) != ' ' || getCharAtxy(pY2+5, pX2+1)!=' ' || getCharAtxy(pY2+6, pX2) != ' ' || getCharAtxy(pY2+6, pX2+1)!=' ')
{
break;
}
}
}
else
{
while(count<=3 && getCharAtxy(pY2,pX2-1) == ' ' && getCharAtxy(pY2+2,pX2-1)== ' ' && getCharAtxy(pY2+1,pX2-1)== ' ' && getCharAtxy(pY2+4,pX2-1)== ' '   && getCharAtxy(pY2+3,pX2-1)== ' ' && getCharAtxy(pY2+5, pX2-1) == ' ' && getCharAtxy(pY2+5, pX2) == ' ' && getCharAtxy(pY2+5, pX2+1)==' ')
{
count++;                             
erasePlayer2();
pX2 = pX2 -1 ;
pY2=pY2+1;
printPlayer2();
if(count>3 || getCharAtxy(pY2,pX2-1) != ' ' || getCharAtxy(pY2+2,pX2-1)!= ' ' || getCharAtxy(pY2+1,pX2-1)!= ' ' || getCharAtxy(pY2+4,pX2-1)!= ' ' || getCharAtxy(pY2+5, pX2-1) != ' ' || getCharAtxy(pY2+3,pX2-1)!= ' ' || getCharAtxy(pY2+5, pX2) != ' ' || getCharAtxy(pY2+5, pX2+1)!=' ' )
{
break;
}
}
}
Sleep(300);

if(pY2<120 && pY2>47)
{
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '   && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2+5, pX2) == ' ' && getCharAtxy(pY2+5, pX2+1)==' ' && getCharAtxy(pY2+6, pX2) == ' ' && getCharAtxy(pY2+6, pX2+1)==' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
pY2=pY2+2;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' '  || getCharAtxy(pY2+5, pX2) != ' ' || getCharAtxy(pY2+5, pX2+1)!=' ' || getCharAtxy(pY2+6, pX2) != ' ' || getCharAtxy(pY2+6, pX2+1)!=' ')
{
break;
}

}
}
else 
{
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' ' && getCharAtxy(pY2+5,pX2+2)== ' ' && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2+5, pX2) == ' ' && getCharAtxy(pY2+5, pX2+1)==' ' )
{
erasePlayer2();
pX2 = pX2 +1 ;
pY2=pY2+1;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+5,pX2+2)== ' '  || getCharAtxy(pY2+3,pX2+2)!= ' '  || getCharAtxy(pY2+5, pX2) != ' ' || getCharAtxy(pY2+5, pX2+1)!=' ' )
{
break;
}

}
}
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2+5, pX2) != ' ' && getCharAtxy(pY2+5, pX2+1)!=' ' && getCharAtxy(pY2+6, pX2) != ' ' && getCharAtxy(pY2+6, pX2+1)!=' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' ' )
{
break;
}

}
if(cheakForWaterForPlayer2()==true)
{
    exitPlayer2=1;
}
}

void jumpPlayer2Left(int &exitPlayer2)
{


int count=0;
bool cheak=true;
if(pY2<120 && pY2>47)
{
while(count<=3 && getCharAtxy(pY2,pX2-1) == ' ' && getCharAtxy(pY2-1,pX2-1) == ' ' && getCharAtxy(pY2+2,pX2-1)== ' ' && getCharAtxy(pY2+1,pX2-1)== ' ' && getCharAtxy(pY2+4,pX2-1)== ' '  && getCharAtxy(pY2+3,pX2-1)== ' ' && getCharAtxy(pY2-1, pX2) == ' ' && getCharAtxy(pY2-1, pX2+1)==' ' && getCharAtxy(pY2-2, pX2) == ' ' && getCharAtxy(pY2-2, pX2+1)==' ')
{
count++;                             
erasePlayer2();
pX2 = pX2 -1 ;
pY2=pY2-2;
printPlayer2();
if(count>3 || getCharAtxy(pY2,pX2-1) != ' ' || getCharAtxy(pY2-1,pX2-1) != ' ' || getCharAtxy(pY2+2,pX2-1)!= ' ' || getCharAtxy(pY2+1,pX2-1)!= ' ' || getCharAtxy(pY2+4,pX2-1)!= ' '  || getCharAtxy(pY2+3,pX2-1)!= ' ' || getCharAtxy(pY2-1, pX2) != ' ' || getCharAtxy(pY2-1, pX2+1)!=' ' || getCharAtxy(pY2-2, pX2) != ' ' || getCharAtxy(pY2-2, pX2+1)!=' ')
{
break;
}
}
}
else
{
while(count<=3 && getCharAtxy(pY2,pX2-1) == ' '  && getCharAtxy(pY2-1,pX2-1) == ' ' && getCharAtxy(pY2+2,pX2-1)== ' ' && getCharAtxy(pY2+1,pX2-1)== ' ' && getCharAtxy(pY2+4,pX2-1)== ' '  && getCharAtxy(pY2+3,pX2-1)== ' ' && getCharAtxy(pY2-1, pX2) == ' ' && getCharAtxy(pY2-1, pX2+1)==' ')
{
count++;                             
erasePlayer2();
pX2 = pX2 -1 ;
pY2=pY2-1;
printPlayer2();
if(count>3 || getCharAtxy(pY2,pX2-1) != ' ' || getCharAtxy(pY2-1,pX2-1) != ' ' || getCharAtxy(pY2+2,pX2-1)!= ' ' || getCharAtxy(pY2+1,pX2-1)!= ' ' || getCharAtxy(pY2+4,pX2-1)!= ' '  || getCharAtxy(pY2+3,pX2-1)!= ' ' || getCharAtxy(pY2-1, pX2) != ' ' || getCharAtxy(pY2-1, pX2+1)!=' ' )
{
break;
}
}
}
Sleep(300);

if(pY2<120 && pY2>47)
{
while(getCharAtxy(pY2,pX2+2) == ' ' &&  getCharAtxy(pY2-1,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2-1, pX2) == ' ' && getCharAtxy(pY2-1, pX2+1)==' ' && getCharAtxy(pY2-2, pX2) == ' ' && getCharAtxy(pY2-2, pX2+1)==' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
pY2=pY2-2;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2-1,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' '  || getCharAtxy(pY2-1, pX2) != ' ' || getCharAtxy(pY2-1, pX2+1)!=' ' || getCharAtxy(pY2-2, pX2) != ' ' || getCharAtxy(pY2-2, pX2+1)!=' ')
{
break;
}

}
}
else
{
while(getCharAtxy(pY2,pX2+2) == ' ' &&  getCharAtxy(pY2-1,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2-1, pX2) == ' ' && getCharAtxy(pY2-1, pX2+1)==' ' )
{
erasePlayer2();
pX2 = pX2 +1 ;
pY2=pY2-1;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2-1,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' '  || getCharAtxy(pY2-1, pX2) != ' ' || getCharAtxy(pY2-1, pX2+1)!=' ' )
{
break;
}

}
}
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' '  && getCharAtxy(pY2-1, pX2) != ' ' && getCharAtxy(pY2-1, pX2+1)!=' ' && getCharAtxy(pY2-2, pX2) != ' ' && getCharAtxy(pY2-2, pX2+1)!=' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' ' )
{
break;
}

}
if(cheakForWaterForPlayer2()==true)
{
    exitPlayer2=1;
}
}


void automaticallyMovePlayer2Down(int &exitPlayer2)
{
while(getCharAtxy(pY2,pX2+2) == ' ' && getCharAtxy(pY2+2,pX2+2)== ' ' && getCharAtxy(pY2+1,pX2+2)== ' ' && getCharAtxy(pY2+4,pX2+2)== ' '  && getCharAtxy(pY2+3,pX2+2)== ' ')
{
erasePlayer2();
pX2 = pX2 +1 ;
printPlayer2();
if(getCharAtxy(pY2,pX2+2) != ' ' || getCharAtxy(pY2+2,pX2+2)!= ' ' || getCharAtxy(pY2+1,pX2+2)!= ' ' || getCharAtxy(pY2+4,pX2+2)!= ' '  || getCharAtxy(pY2+3,pX2+2)!= ' ' )
{
break;
}

}
if(cheakForWaterForPlayer2()==true)
{
    exitPlayer2=1;
}
}

bool cheakForWinGamePlayer2()
{
    bool cheak=false;
    if ( (getCharAtxy(pY2+5, pX2) == '.' && getCharAtxy(pY2+5, pX2+1)=='.') ||  (getCharAtxy(pY2 -1,pX2) == '.' && getCharAtxy(pY2 -1,pX2+1) == '.') )
    {
        cheak=true;
    }
    return cheak;
}

/*Player 2 functions (Firegirl)  end*/

/*Enemy 1 functions start*/
void printEnemy1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    for(int i=0;i<EnemyHeight1;i++){
        for(int j=0;j<EnemyWidth1;j++) {
            gotoxy(eY1+j,eX1+i);
            cout<<Enemy2D1[i][j];
        }
    }
    // Reset text color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void eraseEnemy1()
{
    for(int i=0;i<EnemyHeight1;i++){
        for(int j=0;j<EnemyWidth1-5;j++) {
            gotoxy(eY1+j,eX1+i);
            cout<<"     ";
        }
    }
}

bool enemy1MovingRight = true; 
void moveEnemy1() {
    eraseEnemy1();
    if (enemy1MovingRight) {
        eY1 = eY1 + 1;
    } else {
        eY1 = eY1 - 1;
    }
    if (eY1<=60 || eY1>=120) {
        enemy1MovingRight = !enemy1MovingRight; 
    }
    printEnemy1(); 
}

void Enemy1ChasingPlayer1()
{
    eraseEnemy1();
    if(pY1>eY1 )
    {
        eY1++;
    }
    else{
        eY1--;
    }
    printEnemy1();
}
void Enemy1ChasingPlayer2()
{
    eraseEnemy1();
    if(pY2>eY1 )
    {
        eY1++;
    }
    else{
        eY1--;
    }
    printEnemy1();
}


/*Enemy 1 functions end*/

/*Enemy 2 functions start*/
void printEnemy2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for(int i=0;i<EnemyHeight2;i++){
        for(int j=0;j<EnemyWidth2;j++) {
            gotoxy(eY2+j,eX2+i);
            cout<<Enemy2D2[i][j];
        }
    }
    // Reset text color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void eraseEnemy2()
{
    for(int i=0;i<EnemyHeight2;i++){
        for(int j=0;j<EnemyWidth2-5;j++) {
            gotoxy(eY2+j,eX2+i);
            cout<<"     ";
        }
    }
}

bool enemy2MovingRight = true; 
void moveEnemy2() {
    eraseEnemy2();
    if (enemy2MovingRight) {
        eY2 = eY2 + 1;
    } else {
        eY2 = eY2 - 1;
    }
    if (eY2<=65 || eY2>=110) {
        enemy2MovingRight = !enemy2MovingRight; 
    }
    printEnemy2(); 
}

void Enemy2ChasingPlayer1()
{
    eraseEnemy2();
    if(pY1>eY2)
    {
        eY2++;
    }
    else{
        eY2--;
    }
    printEnemy2();
}

void Enemy2ChasingPlayer2()
{
    eraseEnemy2();
    if(pY2>eY2)
    {
        eY2++;
    }
    else{
        eY2--;
    }
    printEnemy2();
}


/*Enemy 1 functions end*/

void printmaze1()   /*Printing maze one*/
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get console window size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calculate left margin to center the maze1 horizontally
    int leftMargin = (consoleWidth - cols1) / 2;

    // Calculate top margin to center the maze1 vertically
    int topMargin = (consoleHeight - rows1) / 2;

    int x = 30, y = 20;

    for (int i = 0; i < rows1; ++i)
    {
        // Set cursor position for vertical centering
        gotoxy(leftMargin, topMargin + i);

        for (int j = 0; j < cols1; ++j)
        {
            if (i < 2 || i >= rows1 - 2 || j < 2 || j >= cols1 - 3)
            {
                // Set text color to purple for borders
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else if (i == 37 && j >= 30 && j <= 39)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 37 && j >= 63 && j <= 72)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 30 && j >= 66 && j <= 75)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 30 && j >= 37 && j <= 46)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 14 && j >= 72 && j <= 77)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 8 && j >= 31 && j <= 36)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            
            else if (i == 6 && j >= 79 && j <= 85)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 7 && j >= 79 && j <= 85)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }

            
            else if (i == 6 && j >= 90 && j <= 96)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 7 && j >= 90 && j <= 96)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (maze1[i][j] != ' ')
            {
                // Set text color to green for inside maze1
                SetConsoleTextAttribute(hConsole, 136);
            }
            else
            {
                // Set text color to blue for spaces
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }

            // Print the character
            std::cout << maze1[i][j];
        }

        std::cout << std::endl;
    }

    // Reset text color to default after printing the maze1
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printmaze2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get console window size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calculate left margin to center the maze1 horizontally
    int leftMargin = (consoleWidth - cols2) / 2;

    // Calculate top margin to center the maze1 vertically
    int topMargin = (consoleHeight - rows2) / 2;

    int x = 30, y = 20;

    for (int i = 0; i < rows2; ++i)
    {
        // Set cursor position for vertical centering
        gotoxy(leftMargin, topMargin + i);

        for (int j = 0; j < cols2; ++j)
        {
            if (i < 2 || i >= rows2 - 2 || j < 2 || j >= cols2 - 3)
            {
                // Set text color to purple for borders
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else if (i == 36 && j >= 33 && j <= 37)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 36 && j >= 71 && j <= 75)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 30 && j >= 75 && j <= 82)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            
            else if (i == 23 && j >= 48 && j <= 54)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 9 && j >= 71 && j <= 77)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 9 && j >= 41 && j <= 48)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            
            
            else if (i == 7 && j >= 20 && j <= 24)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }
            else if (i == 8 && j >= 20 && j <= 24)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,153);
            }

            
            else if (i == 7 && j >= 10 && j <= 14)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (i == 8 && j >= 10 && j <= 14)  // Adjusted row to 31 for 0-based indexing
            {
                // Set text color to blue for the specified row and column range
                SetConsoleTextAttribute(hConsole,204);
            }
            else if (maze2[i][j] != ' ')
            {
                // Set text color to green for inside maze1
                SetConsoleTextAttribute(hConsole, 136);
            }
            else
            {
                // Set text color to blue for spaces
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }

            // Print the character
            std::cout << maze2[i][j];

        }
        std::cout << std::endl;
    }
    // Reset text color to default after printing the maze1
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

bool cheakForFireForPlayer1()  /*cheaks if the waterboy has touched the fire or not, if he touches fire cheak becomes true and game ends*/
{
    bool cheak=false;
    if(getCharAtxy(pY1,pX1+2) == '&' || getCharAtxy(pY1+2,pX1+2)== '&' || getCharAtxy(pY1+1,pX1+2)== '&' || getCharAtxy(pY1+4,pX1+2)== '&'  || getCharAtxy(pY1+3,pX1+2)== '&' )
    {
    cheak=true;
    }
    return cheak;
}

bool cheakForWaterForPlayer2()  /*cheaks if the waterboy has touched the fire or not, if he touches fire cheak becomes true and game ends*/
{
    bool cheak=false;
    if(getCharAtxy(pY2,pX2+2) == '@' || getCharAtxy(pY2+2,pX2+2)== '@' || getCharAtxy(pY2+1,pX2+2)== '@' || getCharAtxy(pY2+4,pX2+2)== '@'  || getCharAtxy(pY2+3,pX2+2)== '@' )
    {
    cheak=true;
    }
    return cheak;
}


void endGameMenu()
{
system("cls");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"========================================================================================================================================================================"<<endl;
Sleep(100);
cout<<"========================================================================================================================================================================"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###              _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _            ###"<<endl;
Sleep(100);
cout<<"###             |_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_|           ###"<<endl;
Sleep(100);
cout<<"###             |_|                                                                                                                                    |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_|   ____                             _             ___                   _     __   __               _              _             __ |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_|  / ___| __ _ _ __ ___   ___       (_)___        / _ \\__   _____ _ __  | |    \\ \\ / /__  _   _     | |    ___  ___| |_      _   / / |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_| | |  _ / _` | '_ ` _ \\ / _ \\      | / __|      | | | \\ \\ / / _ \\ '__| | |     \\ V / _ \\| | | |    | |   / _ \\/ __| __|    (_) | |  |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_| | |_| | (_| | | | | | |  __/      | \\__ \\      | |_| |\\ V /  __/ |    |_|      | | (_) | |_| |    | |__| (_) \\__ \\ |_      _  | |  |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_|  \\____|\\__,_|_| |_| |_|\\___|      |_|___/       \\___/  \\_/ \\___|_|    (_)      |_|\\___/ \\__,_|    |_____\\___/|___/\\__|    (_) | |  |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_|                                                                                                                                \\_\\ |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_| _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ |_|           ###"<<endl;
Sleep(100);
cout<<"###             |_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_|           ###"<<endl;                                                                                                                                                  
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
Sleep(100);
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###";
getch();
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void generateColors()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for (int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " Learning is never done without errors and defeat!" << endl;
  }
}

char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void setCharAtxy(short int x, short int y, char ch) {
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize = {1, 1};
    ci.Char.AsciiChar = ch;


    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect);
}

void startMenu()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"========================================================================================================================================================================"<<endl;
cout<<"========================================================================================================================================================================"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                Enter Level To Play:                                                                                                              ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###                                                                                                                                                   ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###             ##                             ##               ##     ##################          ##################                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##     ##                ##        ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##                      ##         ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##                     ##          ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##                    ##           ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ###################                   ##            ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##                 ##              ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##               ##                ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##             ##                  ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##           ##                    ##              ##                                 ##             ###"<<endl;
cout<<"###             ##                             ##               ##        ################         ##################                                 ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                        ##################       ####################      ####################    ###################              ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##                ##    ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##                ##    ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##                ##    ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##                ##    ##                               ##             ###"<<endl;
cout<<"###             ##                        ##################                ##               ####################    ###################              ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ####                    ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##  ##                  ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##     ##               ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                                ##               ##        ##            ##                               ##             ###"<<endl;
cout<<"###             ##                        ##                       #####################     ##           ##         ####################             ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###";

}

void wongameMenu()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"========================================================================================================================================================================"<<endl;
cout<<"========================================================================================================================================================================"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###                                                                                                                                                                  ###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###                                                                                                                                                   ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                               ##      ##      ##########################       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                               ##      ##      ##                      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                ##    ##       ##          YOU         ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                 ######        ##                      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                   ##          ##                      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                   ##          ##                      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                   ##          ##      WOOOOON !!      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                   ##          ##                      ##       ##               ##                                 ##             ###"<<endl;
cout<<"###             ##                                   ##          ##                      ##        ##             ##                                  ##             ###"<<endl;
cout<<"###             ##                                   ##          ##                      ##         ##           ##                                   ##             ###"<<endl;
cout<<"###             ##                                   ##          ##########################           ###########                                     ##             ###"<<endl;
SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##########################       ## #               ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##                      ##       ##  ##             ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##         YOU          ##       ##   ##            ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##                      ##       ##    ##           ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##                      ##       ##     ##          ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##                      ##       ##      ##         ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##        WOOON !!      ##       ##       ##        ##                               ##             ###"<<endl;
cout<<"###             ##                          ##     ##     ##     ##                      ##       ##         ##      ##                               ##             ###"<<endl;
cout<<"###             ##                          ##   ##   ##  ##     ##                      ##       ##          ##     ##                               ##             ###"<<endl;
cout<<"###             ##                          ## ##      ## ##     ##                      ##       ##            ##   ##                               ##             ###"<<endl;
cout<<"###             ##                          ##            ##     ##########################       ##             ##  ##                               ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###             ##                                                                                                                                    ##             ###"<<endl;
cout<<"###==================================================================================================================================================================###"<<endl;
cout<<"###==================================================================================================================================================================###";

}

int  startGame()
{
    gotoxy(56,5);
    string askForLevel="";
    cin>>askForLevel;
    int result=stoi(askForLevel);
    return result;
}

void printBulletLeftPlayer1(int x,int y)
{
    HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,4);
    gotoxy(x,y);
    cout<<'<';
    SetConsoleTextAttribute(c,6);

}

void eraseBulletLeftPlayer1(int x,int y)
{
    gotoxy(x,y);
    cout<<' ';
}


void makeBulletInactiveLeftPlayer1(int index)
{
    bulletValueLeftPlayer1[index]=false;
}
void deleteBulletLeftPlayer1(int index)
{
    for(int i=index;i<bulletcountLeftPlayer1;i++)
    {
        bulletXLeftPlayer1[i]=bulletXLeftPlayer1[i+1];
        bulletYLeftPlayer1[i]=bulletYLeftPlayer1[i+1];

    }
    bulletcountLeftPlayer1--;
}
void createBulletLeftPlayer1()
{
    bulletXLeftPlayer1[bulletcountLeftPlayer1]=pY1-3;
    bulletYLeftPlayer1[bulletcountLeftPlayer1]=pX1;

    bulletValueLeftPlayer1[bulletcountLeftPlayer1]=true;
    printBulletLeftPlayer1(bulletXLeftPlayer1[bulletcountLeftPlayer1],bulletYLeftPlayer1[bulletcountLeftPlayer1]);
    bulletcountLeftPlayer1++;
}
void moveBulletLeftPlayer1()
{
    for(int x=0;x<bulletcountLeftPlayer1;x++)
    {
        
        
            char next=getCharAtxy(bulletXLeftPlayer1[x]-1,bulletYLeftPlayer1[x]);
            if(next== ' ')
            {
                eraseBulletLeftPlayer1(bulletXLeftPlayer1[x],bulletYLeftPlayer1[x]);
                bulletXLeftPlayer1[x]=bulletXLeftPlayer1[x]-1;
                printBulletLeftPlayer1(bulletXLeftPlayer1[x],bulletYLeftPlayer1[x]);
            }
            else
            {
                eraseBulletLeftPlayer1(bulletXLeftPlayer1[x],bulletYLeftPlayer1[x]);
                makeBulletInactiveLeftPlayer1(x);
                deleteBulletLeftPlayer1(x);
                
            }

        
    }
}

void printBulletRightPlayer1(int x,int y)
{
    HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,4);
    gotoxy(x,y);
    cout<<'>';
    SetConsoleTextAttribute(c,6);

}

void eraseBulletRightPlayer1(int x,int y)
{
    gotoxy(x,y);
    cout<<' ';
}


void makeBulletInactiveRightPlayer1(int index)
{
    bulletValueRightPlayer1[index]=false;
}
void deleteBulletRightPlayer1(int index)
{
    for(int i=index;i<bulletcountRightPlayer1;i++)
    {
        bulletXRightPlayer1[i]=bulletXRightPlayer1[i+1];
        bulletYRightPlayer1[i]=bulletYRightPlayer1[i+1];

    }
    bulletcountLeftPlayer1--;
}

void moveBulletRightPlayer1()
{
    for(int x=0;x<bulletcountRightPlayer1;x++)
    {
        
        
            char next=getCharAtxy(bulletXRightPlayer1[x]+1,bulletYRightPlayer1[x]);
            if(next== ' ')
            {
                eraseBulletRightPlayer1(bulletXRightPlayer1[x],bulletYRightPlayer1[x]);
                bulletXRightPlayer1[x]=bulletXRightPlayer1[x]+1;
                printBulletRightPlayer1(bulletXRightPlayer1[x],bulletYRightPlayer1[x]);
            }
            else
            {
                eraseBulletRightPlayer1(bulletXRightPlayer1[x],bulletYRightPlayer1[x]);
                makeBulletInactiveRightPlayer1(x);
                deleteBulletRightPlayer1(x);
                
            }

        
    }
}



void createBulletRightPlayer1()
{
    bulletXRightPlayer1[bulletcountRightPlayer1]=pY1+3;
    bulletYRightPlayer1[bulletcountRightPlayer1]=pX1;

    bulletValueRightPlayer1[bulletcountRightPlayer1]=true;
    printBulletRightPlayer1(bulletXRightPlayer1[bulletcountRightPlayer1],bulletYRightPlayer1[bulletcountRightPlayer1]);
    bulletcountRightPlayer1++;
}



/*bullet functions for player 2*/
void printBulletLeftPlayer2(int x,int y)
{
    HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,4);
    gotoxy(x,y);
    cout<<'<';
    SetConsoleTextAttribute(c,6);

}

void eraseBulletLeftPlayer2(int x,int y)
{
    gotoxy(x,y);
    cout<<' ';
}


void makeBulletInactiveLeftPlayer2(int index)
{
    bulletValueLeftPlayer2[index]=false;
}
void deleteBulletLeftPlayer2(int index)
{
    for(int i=index;i<bulletcountLeftPlayer2;i++)
    {
        bulletXLeftPlayer2[i]=bulletXLeftPlayer2[i+1];
        bulletYLeftPlayer2[i]=bulletYLeftPlayer2[i+1];

    }
    bulletcountLeftPlayer2--;
}
void createBulletLeftPlayer2()
{
    bulletXLeftPlayer2[bulletcountLeftPlayer2]=pY2-3;
    bulletYLeftPlayer2[bulletcountLeftPlayer2]=pX2;

    bulletValueLeftPlayer2[bulletcountLeftPlayer2]=true;
    printBulletLeftPlayer2(bulletXLeftPlayer2[bulletcountLeftPlayer2],bulletYLeftPlayer2[bulletcountLeftPlayer2]);
    bulletcountLeftPlayer2++;
}
void moveBulletLeftPlayer2()
{
    for(int x=0;x<bulletcountLeftPlayer2;x++)
    {
        if(bulletValueLeftPlayer2[x]==true)
        {
            char next=getCharAtxy(bulletXLeftPlayer2[x]-1,bulletYLeftPlayer2[x]);
            if(next== ' ')
            {
                eraseBulletLeftPlayer2(bulletXLeftPlayer2[x],bulletYLeftPlayer2[x]);
                bulletXLeftPlayer2[x]=bulletXLeftPlayer2[x]-1;
                printBulletLeftPlayer2(bulletXLeftPlayer2[x],bulletYLeftPlayer2[x]);
            }
            else
            {
                eraseBulletLeftPlayer2(bulletXLeftPlayer2[x],bulletYLeftPlayer2[x]);
                makeBulletInactiveLeftPlayer2(x);
                deleteBulletLeftPlayer2(x);
                
            }

        }
    }
}

void printBulletRightPlayer2(int x,int y)
{
    HANDLE c= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c,4);
    gotoxy(x,y);
    cout<<'>';
    SetConsoleTextAttribute(c,6);

}

void eraseBulletRightPlayer2(int x,int y)
{
    gotoxy(x,y);
    cout<<' ';
}


void makeBulletInactiveRightPlayer2(int index)
{
    bulletValueRightPlayer2[index]=false;
}
void deleteBulletRightPlayer2(int index)
{
    for(int i=index;i<bulletcountRightPlayer2;i++)
    {
        bulletXRightPlayer2[i]=bulletXRightPlayer2[i+1];
        bulletYRightPlayer2[i]=bulletYRightPlayer2[i+1];

    }
    bulletcountLeftPlayer2--;
}

void moveBulletRightPlayer2()
{
    for(int x=0;x<bulletcountRightPlayer2;x++)
    {
        if(bulletValueRightPlayer2[x]==true)
        {
            char next=getCharAtxy(bulletXRightPlayer2[x]+1,bulletYRightPlayer2[x]);
            if(next== ' ')
            {
                eraseBulletRightPlayer2(bulletXRightPlayer2[x],bulletYRightPlayer2[x]);
                bulletXRightPlayer2[x]=bulletXRightPlayer2[x]+1;
                printBulletRightPlayer2(bulletXRightPlayer2[x],bulletYRightPlayer2[x]);
            }
            else
            {
                eraseBulletRightPlayer2(bulletXRightPlayer2[x],bulletYRightPlayer2[x]);
                makeBulletInactiveRightPlayer2(x);
                deleteBulletRightPlayer2(x);
                
            }

        }
    }
}



void createBulletRightPlayer2()
{
    bulletXRightPlayer2[bulletcountRightPlayer2]=pY2+3;
    bulletYRightPlayer2[bulletcountRightPlayer1]=pX2;

    bulletValueRightPlayer2[bulletcountRightPlayer2]=true;
    printBulletRightPlayer2(bulletXRightPlayer2[bulletcountRightPlayer2],bulletYRightPlayer2[bulletcountRightPlayer2]);
    bulletcountRightPlayer2++;
}

void enemyCollideWithPlayer1()
{
    if(getCharAtxy(pY1 -1,pX1) == '=' || getCharAtxy(pY1 -1,pX1) == '-' ||  getCharAtxy(pY1+5, pX1) == '=' || getCharAtxy(pY1+5, pX1)=='-' )
    {
        player1Health=player1Health-5;
    }
}

void enemyCollideWithPlayer2()
{
    if(getCharAtxy(pY2 -1,pX2) == '=' || getCharAtxy(pY2 -1,pX2) == '-' ||  getCharAtxy(pY2+5, pX2) == '=' || getCharAtxy(pY2+5, pX2)=='-' )
    {
        player2Health=player2Health-5;
    }
}

void  bulletcollisionwithEnemy1()
{
    if(getCharAtxy(eY1 +5,eX1) == '<' )
    {
        enemy1Health=enemy1Health-5;
    }

}
void  bulletcollisionwithEnemy2()
{
    if(getCharAtxy(eY2 +5,eX2) == '<' )
    {
        enemy2Health=enemy2Health-5;
    }

}