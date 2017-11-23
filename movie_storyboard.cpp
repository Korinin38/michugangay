    #include <iostream>
    #include "TXLib.h"
    using namespace std;

    CONST COLORREF MYOWN_COLOR1 = TX_BLACK;
    CONST COLORREF MYOWN_COLOR2 = MYOWN_COLOR1;

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
        if (stage==true)
        {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txCircle (500, 300, 150);
            for (i=0; i<10; i++)
            {
                switch(i)
                case 3:




                    break;
                case 4:




                    break;
            }
        }
    }
