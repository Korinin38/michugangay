    #include <iostream>
    #include "TXLib.h"
    using namespace std;

    CONST COLORREF  MYOWN_COLOR1 = TX_BLACK,
                    MYOWN_COLOR2 = TX_WHITE;

    COLORREF OGRBLU, OGRHAT, WALLFILL=RGB(200, 200, 200);

    void LogoPS(bool);
    void ToBeContinued();
    void Ryab();
    void Ogr(int);

    int main()
    {
        txCreateWindow (1000, 600);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        /*bool i=0;
        while (i<2)
        {
            LogoPS(i);
            i=(i+1);

        }
        Ryab();*/
        ToBeContinued();
        return 0;
    }



//=============================================================================

    void LogoPS(bool stage)
    {
        int i;
        if (stage==true)
        {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            for (i=-4; i<17; i++)
            {
                txSetColor(TX_WHITE);
                txSetFillColor(TX_WHITE);
                txCircle (500, 300, 150);
                if (i>0)
                {
                    txSetColor(MYOWN_COLOR1, 3);
                    txSetFillColor(TX_TRANSPARENT);
                    txCircle(470, 348, 2);
                    txCircle(580, 348, 2);
                    txLine(430, 350, 430, 225);
                    txChord(481, 300, 381, 225, -90, 180);

                    txChord(500, 287, 600, 227, 50, 210);
                    txChord(480, 285, 580, 350, 225, 215);
                    txSetColor(MYOWN_COLOR2, 4);
                    txLine(545, 283, 571, 233);
                    txLine(534, 288, 504, 341);

                    txSetColor(MYOWN_COLOR1, 3);
                    txSetTextAlign(TA_CENTER);
                    txSelectFont("Comic Sans MS", 40, 12, false, true, false, false, 10);
                    switch (i)
                    {
                        case 4:
                            txTextOut(495, 380, "p");
                            break;
                        case 5:
                            txTextOut(495, 380, "pr");
                            break;
                        case 6:
                            txTextOut(495, 380, "pre");
                            break;
                        case 7:
                            txTextOut(495, 380, "pres");
                            break;
                        case 8:
                            txTextOut(495, 380, "prese");
                            break;
                        case 9:
                            txTextOut(495, 380, "presen");
                            break;
                        case 10:
                            txTextOut(495, 380, "present");
                            break;
                    }
                    if (i>10) txTextOut(495, 380, "presents");
                }
                txSleep(100);
            }
        }
        else
        {
            txSetColor(TX_WHITE, 3);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txLine(500, 299, 500, 301);
            for (i=2; i<128;)
            {
                txLine(500, 301-i, 500, 299+i);
                i+=i-1;
                txSleep(60);
            }
            txLine(500, 159, 500, 441);
            txSleep(60);
            txLine(500, 153, 500, 447);
            txSleep(60);
            txLine(500, 150, 500, 450);
            txSleep(400);
            int ugol;
            txPie(350, 150, 650, 450, 90, 1);
            txPie(350, 150, 650, 450, 270, 1);
            for (ugol=2; ugol<=129;)
            {
                txPie(351, 151, 649, 449, 90, ugol);
                txPie(351, 151, 649, 449, 270, ugol);
                ugol+=ugol-1;
                txSleep(60);
            }
            for (ugol=176; ugol<180;)
            {
                txPie(351, 151, 649, 449, 90, ugol);
                txPie(351, 151, 649, 449, 270, ugol);
                ugol+=(180-ugol)/1.7;
                if (ugol>175) ugol=180;
                txSleep(60);
            }
        }
    }


//-----------------------------------------------------------------------------

    void Ryab()
    {
        COLORREF kek;
        int a[3];
        for (int i = 0; i<10; i++)
        {


            for (int j=0; j<1000; j+=3)
            {
                for (int k=0; k<600; k+=3)
                    {
                        a[0]=rand()%16*15;
                        a[1]=rand()%16*15;
                        a[2]=rand()%16*15;
                        kek=RGB(a[0],a[1],a[2]);
                        txSetColor(kek);
                        txSetFillColor(kek);
                        txRectangle(j,k,j+3,k+3);
                    }
            }
            txSleep(20);
        }
    }


//-----------------------------------------------------------------------------

    void ToBeContinued()
    {
        txSetColor(WALLFILL);
        txSetFillColor(WALLFILL);
        for(int i = 0; i<4; i++)
        {
            for(int q = 0; q<24; q++)
            {
                txSetFillColor(WALLFILL);
                txClear();
        //        Wall(q);
                Ogr(q);
                txSleep(40);
            }
        }

        for (int i = 0; i < 12; i++)
        {
            if (i==11)
            {
          //      OGRBLU = RGB();
          //      OGRHAT = RGB();
          //      WALLFILL = RGB();
                txSleep(5000);
            }
          //  Wall(q, 1);
            Ogr(i);
            txSleep(40);

        }
    }
    void Ogr(int i)
    {
        int x=1, y=1;
        txSetFillColor(TX_BLUE);
        POINT body[41]={{6+x, 417+y},{6+x, 270+y}, {42+x, 196+y}, {65+x, 167+y}, {70+x, 152+y}, {87+x, 130+y}, {97+x, 122+y}, {107+x, 119+y}, {140+x, 110+y}, {156+x, 104+y}, {168+x, 97+y}, {168+x, 86+y}, {172+x, 80+y}, {178+x, 77+y}, {192+x, 77+y}, {226+x, 85+y}, {240+x, 87+y}, {261+x, 94+y}, {244+x, 103+y}, {261+x, 94+y}, {279+x, 90+y}, {290+x, 86+y}, {302+x, 83+y}, {300+x, 68+y}, {313+x, 80+y}, {321+x, 79+y}, {327+x, 70+y}, {358+x, 62+y}, {373+x, 62+y}, {395+x, 72+y}, {411+x, 80+y}, {418+x, 99+y}, {419+x, 114+y}, {420+x, 135+y}, {420+x, 137+y}, {413+x, 159+y}, {408+x, 172+y}, {418+x, 172+y}, {435+x, 188+y}, {442+x, 271+y}, {451+x, 417+y}};
        POINT cloak[25]={{156+x, 104+y}, {153+x, 115+y}, {164+x, 141+y}, {185+x, 170+y}, {225+x, 183+y}, {271+x, 188+y}, {304+x, 181+y}, {356+x, 175+y}, {408+x, 172+y}, {418+x, 172+y}, {435+x, 188+y}, {344+x, 394+y}, {310+x, 407+y}, {260+x, 400+y}, {267+x, 340+y}, {243+x, 363+y}, {257+x, 329+y}, {237+x, 329+y}, {213+x, 315+y}, {194+x, 316+y}, {213+x, 260+y}, {146+x, 231+y}, {107+x, 119+y}, {140+x, 110+y}, {156+x, 104+y}};
        POINT ear1[7]={{419+x, 114+y}, {425+x, 98+y}, {429+x, 86+y}, {431+x,  105+y}, {432+x, 122+y}, {426+x, 131+y}, {420+x, 135+y}};
        POINT ear2[4]={{172+x, 80+y}, {168+x, 66+y}, {168+x, 49+y}, {184+x, 69+y}};
        POINT head[22]={{172+x, 80+y}, {184+x, 69+y}, {198+x, 61+y}, {214+x, 48+y}, {245+x, 36+y}, {255+x, 37+y}, {268+x, 41+y}, {277+x, 46+y}, {284+x, 53+y}, {299+x, 70+y}, {301+x, 83+y}, {290+x, 86+y}, {291+x, 73+y}, {279+x, 90+y}, {261+x, 95+y}, {244+x, 103+y}, {261+x, 95+y}, {240+x, 87+y}, {226+x, 85+y}, {192+x, 77+y}, {178+x, 77+y}, {172+x, 80+y}};
        POINT hat[6]={{245+x, 36+y}, {253+x, 28+y}, {264+x, 27+y}, {270+x, 30+y}, {274+x, 39+y}, {277+x, 46+y}};
        POINT ear3[3]={{290+x, 86+y}, {291+x, 73+y}, {279+x, 90+y}};
        txPolygon(body, 41);
        txPolygon(ear1, 7);
        txPolygon(ear2, 4);
        txPolygon(ear3, 3);
        txPolygon(hat, 6);
        txSetFillColour(TX_BROWN);
        txPolygon(cloak, 25);
        txPolygon(head, 22);
    }
