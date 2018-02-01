    #include <iostream>
    #include "TXLib.h"
    CONST int YRACKETCONST=500;
    int xRacketGlobal,
        sizeRacketGlobal,
        xBallGlobal,
        yBallGlobal,
        sizeBallGlobal,
        speedBallGlobal,
        variableForGoodRandom;
    double ballDirectionGlobal;

    void interRac()
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            xRacketGlobal -= 6;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            xRacketGlobal += 6;
        }
    }
    void checkBoarderBoom()
    {
        if (xRacketGlobal-sizeRacketGlobal<-10) xRacketGlobal=sizeRacketGlobal+5;
        if (xRacketGlobal+sizeRacketGlobal>810) xRacketGlobal=795-sizeRacketGlobal;
    }

    void drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket()
    {
        txLine(xRacketGlobal - sizeRacketGlobal, YRACKETCONST, xRacketGlobal + sizeRacketGlobal, YRACKETCONST);
    }

    void drawBallOfMyDreamYesIHadBadChildhood()
    {
        txCircle(xBallGlobal, yBallGlobal, sizeBallGlobal);
    }

    void directionChecker()
    {
        ballDirectionGlobal=((variableForGoodRandom%360+360)%360)*M_PI/180;
    }

    void moveBallAndCheckBoardBoom()
    {
        xBallGlobal+=speedBallGlobal*sin(ballDirectionGlobal);
        yBallGlobal+=speedBallGlobal*cos(ballDirectionGlobal);
        if (xBallGlobal-sizeBallGlobal<0)
        {
            xBallGlobal+=5;
            variableForGoodRandom=-variableForGoodRandom;
            directionChecker();
        }
        if (yBallGlobal-sizeBallGlobal<0)
        {
            yBallGlobal+=5;
            variableForGoodRandom=180-variableForGoodRandom;
            directionChecker();
        }
        if (xBallGlobal+sizeBallGlobal>800)
        {
            xBallGlobal-=5;
            variableForGoodRandom=-variableForGoodRandom;
            directionChecker();
        }
        if (yBallGlobal+sizeBallGlobal>600)
        {
            yBallGlobal-=5;
            variableForGoodRandom=180-variableForGoodRandom;
            directionChecker();
        }
    }

    int main()
    {
        txCreateWindow (800, 600);
        txSetColor(TX_BLACK, 5);
        txSetFillColor(TX_WHITE);
        txClear();
        sizeRacketGlobal=80;
        xRacketGlobal=400;
        xBallGlobal=400;
        yBallGlobal=250;
        sizeBallGlobal=30;
        speedBallGlobal=10;
        variableForGoodRandom=rand()%360;
        while(!GetAsyncKeyState(VK_ESCAPE))
        {
            txClear();
            interRac();
            checkBoarderBoom();
            moveBallAndCheckBoardBoom();
            directionChecker();
            drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket();
            drawBallOfMyDreamYesIHadBadChildhood();
            txSleep(10);
        }
        return 0;
    }
