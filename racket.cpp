    #include <iostream>
    #include "TXLib.h"
    #include "movie.h"
    CONST int YRACKETCONST=500;
    int xRacketGlobal,
        sizeRacketGlobal,
        xBallGlobal,
        yBallGlobal,
        sizeBallGlobal,
        speedBallGlobal,
        variableForGoodRandom,
        bounceNumber,
        gameOver;
    double ballDirectionGlobal, sinus, cosinus;

    void interfaceRac()
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            xRacketGlobal -= 6;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            xRacketGlobal += 6;
        }
        if (GetAsyncKeyState('9'))
        {
            gameOver=-999;
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
        sinus=sin(ballDirectionGlobal);
        cosinus=cos(ballDirectionGlobal);
    }

    void moveBallAndCheckBoardBoom()
    {
        xBallGlobal+=speedBallGlobal*sinus;
        yBallGlobal+=speedBallGlobal*cosinus;
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
        if (yBallGlobal + sizeBallGlobal >= YRACKETCONST
            &&
            xBallGlobal >= xRacketGlobal - sizeRacketGlobal
            &&
            xBallGlobal <= xRacketGlobal + sizeRacketGlobal)
        {
            yBallGlobal-=5;
            variableForGoodRandom=180-variableForGoodRandom;
            directionChecker();
        }
        if (yBallGlobal+sizeBallGlobal>600)
        {
            yBallGlobal-=5;
            variableForGoodRandom=180-variableForGoodRandom;
            directionChecker();
            gameOver++;
        }
    }

    void screenOfGameOver()
    {
        txSetTextAlign(TA_CENTER);
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE, 5);
        txSelectFont("Calibri",200,40,5);
        txTextOut(200, 200, "GAME OVER");
    }

    void bounceNumberOut()
    {
        txSetColor(TX_BLACK);
        txTextOut(80, 80, "bounceNumber");
    }

    int main()
    {
        txCreateWindow (800, 600);
        txClear();
        sizeRacketGlobal=80;
        xRacketGlobal=400;
        xBallGlobal=400;
        yBallGlobal=250;
        sizeBallGlobal=30;
        speedBallGlobal=10;
        gameOver=0;
        bounceNumber=0;
        variableForGoodRandom=rand()%360;
        directionChecker();
        LogoPS(0, 800, 600);
        LogoPS(1, 800, 600);
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_BLACK, 5);
        drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket();
        drawBallOfMyDreamYesIHadBadChildhood();
        txSleep(2000);
        while(!GetAsyncKeyState(VK_ESCAPE)&&gameOver!=1)
        {
            txClear();
            bounceNumberOut();
            txSetColor(TX_BLACK, 5);
            interfaceRac();
            checkBoarderBoom();
            moveBallAndCheckBoardBoom();
            drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket();
            drawBallOfMyDreamYesIHadBadChildhood();
            txSleep(1);
        }
        if (gameOver==1) screenOfGameOver();
        txSleep(1);
        return 0;
    }
