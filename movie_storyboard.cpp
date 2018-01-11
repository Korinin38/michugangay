    #include <iostream>
    #include "TXLib.h"
    #include "movie.h"
    using namespace std;

    int main()
    {
        txCreateWindow (1000, 600);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        LogoPS(0);
        LogoPS(1);
        Ryab(1000, 600, 4);
        ToBeContinued();
        return 0;
    }

//=============================================================================
