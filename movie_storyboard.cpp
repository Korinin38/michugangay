    #include <iostream>
    #include "TXLib.h"
    using namespace std;

    CONST COLORREF MYOWN_COLOR1 = TX_BLACK;
    CONST COLORREF MYOWN_COLOR2 = TX_WHITE;

    void LogoPS(bool);

    int main()
    {
        txCreateWindow (1000, 600);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        bool i=0;
        while (1)
        {
            LogoPS(i);
            i=(i+1)%2;
        }
        return 0;
    }

    void LogoPS(bool stage)
    {
        int i;
        if (stage==true)
        {
            txSetColor(TX_WHITE);
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


            txSetFillColor(TX_BLACK);
            txClear();
        }
    }
