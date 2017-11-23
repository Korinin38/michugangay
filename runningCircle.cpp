    #include <iostream>
    #include "TXLib.h"
    using namespace std;

    CONST COLORREF MYOWN_COLOR1 = TX_BLACK;
    CONST COLORREF MYOWN_COLOR2 = MYOWN_COLOR1;
    int GoGoCi(int radius = 50, int length = 100, int amount = 1);

    int main()
    {
        txCreateWindow (1000, 700);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        GoGoCi(50, 840);
        return 0;
    }


    int GoGoCi(int radius, int length, int amount)
    {
        int i = 2*radius+20, s=0;
        while (1)
        {
            int z;
            txSetFillColor(MYOWN_COLOR1);
            txClear();
            for (int a=0; a<amount; a++)
            {
                txSetColor(TX_WHITE);
                txSetFillColor(TX_WHITE);
                txCircle(radius+20+i, radius+20+(2*radius+20)*(a), radius);
                if (i<2*radius+40)
                {
                    z=2*radius+20-i;
                    if (z>radius) z=radius;
                    if (z<0) z=0;
                    txLine(length+radius+20, radius+20-z+(2*radius+20)*a, length+radius+20, radius+20+z+(2*radius+20)*a);
                    txLine(radius+20, radius+20-z+(2*radius+20)*a, radius+20, radius+20+z+(2*radius+20)*a);
                    txCircle(radius+19+length+i, radius+(2*radius+20)*(a)+20, radius);
                    txSetColor(MYOWN_COLOR2);
                    txSetFillColor(MYOWN_COLOR1);
                    txRectangle(length+radius+21, 20, 5*length+21, (2*radius+20)*(a+1));
                    txRectangle(0, 20, radius+19, (2*radius+20)*(a+1));
                }

                if (i>length-2*radius-20)
                {
                    z=i-length+radius+40;
                    if (z>radius) z=radius;
                    if (z<0) z=0;
                    txLine(length+radius+20, radius+20-z+(2*radius+20)*a, length+radius+20, radius+20+z+(2*radius+20)*a);
                    txLine(radius+20, radius+20-z+(2*radius+20)*a, radius+20, radius+20+z+(2*radius+20)*a);
                    if (length-i<radius) txCircle(radius+20+i-length, radius+(2*radius+20)*(a)+20, radius);
                    txSetColor(MYOWN_COLOR2);
                    txSetFillColor(MYOWN_COLOR1);
                    txRectangle(length+radius+21, 20, 5*length+21, (2*radius+20)*(a+1));
                    txRectangle(0, 20, radius+19, (2*radius+20)*(a+1));
                }
            }
            Sleep(33);
            if (i>=length-1){i=0;s++;}
            i+=5;
        }
    }
