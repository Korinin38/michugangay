    #include <iostream>
    #include "TXLib.h"
    #include "movie.h"
    CONST int YRACKETCONST=500, YHEADCONST=50;
    int xRacketGlobal,
        sizeRacketGlobal,
        xBallGlobal,
        yBallGlobal,
        sizeBallGlobal,
        speedBallGlobal,
        variableForGoodRandom,
        bounceNumber,
        xHeadGlobal,
        sizeHead,
        headDirection,
        yBomb,
        xBomb,
        bombSaved,
        gameOver;
    double ballDirectionGlobal, sinus, cosinus;
    bool bomb, launch;

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

    void drawFlyingHead()
    {
        POINT head[3]={{xHeadGlobal-20+sizeHead, YHEADCONST}, {xHeadGlobal+10-sizeHead, YHEADCONST-20}, {xHeadGlobal+10-sizeHead, YHEADCONST+20}};
        txSetColor(TX_BLACK);
        txSetFillColor(TX_TRANSPARENT);
        txPolygon(head, 3);
        txCircle(xHeadGlobal-sizeHead/3, YHEADCONST-5, 3);
    }

    void moveHead()
    {
        if (xHeadGlobal>790){headDirection=-1; sizeHead=0;}
        if (xHeadGlobal<20) {headDirection=1; sizeHead=30;}
        xHeadGlobal+=5*headDirection;
    }

    void bombInit()
    {
        if (!launch)
        {
            launch=1;
            yBomb=55;
            xBomb=xHeadGlobal;
        }
        else
        {
            if (bomb) launch=0;
            else
            if (yBomb>600)
            {
                bomb=1;
                launch=0;
                gameOver++;
            }
        }
    }

    void drawBomb()
    {
        POINT bombImage[10]={{xBomb, yBomb}, {xBomb-3, yBomb-1}, {xBomb-1, yBomb+2}, {xBomb-3, yBomb+3}, {xBomb-3, yBomb+6}, {xBomb, yBomb+8}, {xBomb+3, yBomb+6}, {xBomb+3, yBomb+3}, {xBomb+1, yBomb+2}, {xBomb+3, yBomb-1}};
        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txPolygon(bombImage, 10);
    }

    void bombFalls()
    {
        if (launch)
        {
            drawBomb();
            yBomb+=yBomb/48;
            if (    xBomb>=xRacketGlobal-sizeRacketGlobal
                    &&
                    xBomb<=xRacketGlobal+sizeRacketGlobal
                    &&
                    yBomb==YRACKETCONST
                )
            {
                bombSaved++;
                bomb=1;
                launch=0;
                cout<<bombSaved;
            }
        }
    }

    int main()
    {
        txCreateWindow (800, 600);
        txClear();
        srand(time(NULL));
        sizeRacketGlobal=80;
        xRacketGlobal=400;
        xHeadGlobal=300;
        xBallGlobal=400;
        yBallGlobal=250;
        sizeBallGlobal=30;
        speedBallGlobal=10;
        headDirection=1;
        sizeHead=30;
        gameOver=0;
        bounceNumber=0;
        bomb=1;
        bombSaved=0;
        launch=0;
        variableForGoodRandom=rand()%360;
        directionChecker();
        LogoPS(0, 800, 600);
        LogoPS(1, 800, 600);
        txSetFillColor(TX_WHITE);
        txClear();
        txSelectFont("Calibri", 20, 10, 0, 0, 0);
        txTextOut(400, 10, "в 1945 году Соединённые штаты Америки сбросили атомную бомбу на г. Херосима, Япония");
        txSleep(3000);
        txTextOut(400, 30, "В далёком будущем изобрели машину времени и щит, способный выдержать взрыв бомбы");
        txSleep(3000);
        txTextOut(400, 50, "Спаси Японию от сине-красной угрозы!");
        txSetColor(TX_BLACK, 5);
        drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket();
      //  drawBallOfMyDreamYesIHadBadChildhood();
      //  txSleep(2000);
        while(!GetAsyncKeyState(VK_ESCAPE)&&gameOver!=1)
        {
            txSetFillColor(TX_WHITE);
            txClear();
            txSetColor(TX_BLACK, 5);
            interfaceRac();
            checkBoarderBoom();
         //   moveBallAndCheckBoardBoom();
            drawCoolRacketThatIsSoCoolThatYourEyesWillBeBrokenWhenYouSeeMyCoolRacket();
            moveHead();
            drawFlyingHead();
            if (!bomb)
            {
                bombInit();
                bombFalls();
            }
            else
                bomb=rand()%20;
         //   drawBallOfMyDreamYesIHadBadChildhood();
            txSleep(1);
        }
        if (gameOver==1) screenOfGameOver();
        txSleep(1);
        return 0;
}
