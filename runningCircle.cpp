    #include <iostream>
    #include "TXLib.h"
    using namespace std;

    int GoGoCi(int radius = 50, int length = 100);

    int main()
    {
        txCreateWindow (800, 400);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        GoGoCi(60, 600);
        return 0;
    }


    int GoGoCi(int radius, int length)
    {
        int i = 200, s=0;
        while (1)
        {
            int z;
            txSetColor(TX_WHITE);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txCircle(radius+20+i, radius+20, radius);
            if (i<2*radius+40)
            {
                z=2*radius+20-i;
                if (z>radius) z=radius;
                if (z<0) z=0;
                txLine(length+radius+20, radius+20-z, length+radius+20, radius+20+z);
                txLine(radius+20, radius+20-z, radius+20, radius+20+z);
                txCircle(radius+19+length+i, radius+20, radius);
                txSetColor(TX_BLACK);
                txSetFillColor(TX_BLACK);
                txRectangle(length+radius+21, 20, 5*length+21, 2*radius+20);
                txRectangle(0, 20, radius+19, 2*radius+20);
            }

            if (i>length-2*radius-20)
            {
                z=i-length+radius+40;
                if (z>radius) z=radius;
                if (z<0) z=0;
                txLine(length+radius+20, radius+20-z, length+radius+20, radius+20+z);
                txLine(radius+20, radius+20-z, radius+20, radius+20+z);
                if (length-i<radius) txCircle(radius+20+i-length, radius+20, radius);
                txSetColor(TX_BLACK);
                txSetFillColor(TX_BLACK);
                txRectangle(length+radius+21, 20, 5*length+21, 2*radius+20);
                txRectangle(0, 20, radius+19, 2*radius+20);
            }
            Sleep(30);
            if (i>=length-1){i=0;s++;}
            i+=5;
        }
    }
