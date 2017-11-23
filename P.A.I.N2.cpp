    #include "TXLib.h"

    //CONST int size=14;                                  //coefficient of pic, needs only for coordinate line

    CONST COLORREF DARKBLUEDREAM = RGB (0, 128, 210);   //colors
    CONST COLORREF SKINCOLOR = RGB (210, 240, 176);
    CONST COLORREF DKHOOK = RGB (220, 240, 176);
    CONST COLORREF COLDBLADE = RGB (220, 220, 220);
    CONST COLORREF DARKGREEN = RGB (0, 100, 52);
    CONST COLORREF SKINCOLOR1 = RGB (220, 225, 150);
    CONST COLORREF BILLYELLOW = RGB (255, 255, 0);
    CONST COLORREF BILLGREY = RGB (160, 152, 52);
    bool Dotalogo(int x = 0, int y = 0, int size = 14, bool dire = true, bool radiant = true, bool river = true, int sizeDire = -1, int sizeRadiant = -1, int sizeRiver = -1, bool letters = false);

    bool Setka(float size)
    {
        txSetColor (TX_BLACK, 1);
        for (int i = 1; i<60; i++)
        {
            txLine (i*size, 0, i*size, 60*size);
            txLine (0, i*size, 60*size, i*size);
        }
    }

//-----------------------------------------------------------------------------

    bool Duf(int x = 0, int y = 0, int size = 14, bool knifeistoobad = false, bool needbetterknife = false, bool needchains = true, bool dkbetter = true, bool needcolor = false, bool signa = false, bool dotlog = false)
    {
        txSetFillColor(SKINCOLOR);
        txSetColor (SKINCOLOR);
        txLine ((15+x)*size, (3+y)*size, (10+x)*size, (3+y)*size);
        txLine ((10+x)*size, (3+y)*size, (9+x)*size, (5+y)*size);
        txLine ((9+x)*size, (5+y)*size, (8+x)*size, (6+y)*size);
        txLine ((8+x)*size, (6+y)*size, (7+x)*size, (6+y)*size);
        txLine ((7+x)*size, (6+y)*size, (6+x)*size, (8+y)*size);                   //right arm of Duf
        txLine ((6+x)*size, (8+y)*size, (5+x)*size, (10+y)*size);
        txLine ((5+x)*size, (10+y)*size, (5.5+x)*size, (11+y)*size);
        txLine ((5.5+x)*size, (11+y)*size, (7+x)*size, (11+y)*size);
        txLine ((7+x)*size, (11+y)*size, (7+x)*size, (10+y)*size);
        txLine ((7+x)*size, (10+y)*size, (8+x)*size, (8+y)*size);
        txLine ((8+x)*size, (8+y)*size, (12+x)*size, (7+y)*size);

        txLine ((18+x)*size, (3+y)*size, (23+x)*size, (3+y)*size);
        txLine ((23+x)*size, (3+y)*size, (26+x)*size, (4+y)*size);
        txLine ((26+x)*size, (4+y)*size, (27+x)*size, (6+y)*size);
        txLine ((27+x)*size, (6+y)*size, (27.2+x)*size, (7+y)*size);
        txLine ((27.2+x)*size, (7+y)*size, (28+x)*size, (8+y)*size);               //left arm of Duf
        txLine ((28+x)*size, (8+y)*size, (28+x)*size, (9+y)*size);
        txLine ((28+x)*size, (9+y)*size, (26+x)*size, (9+y)*size);
        txLine ((26+x)*size, (9+y)*size, (25+x)*size, (8+y)*size);
        txLine ((25+x)*size, (8+y)*size, (25+x)*size, (6+y)*size);
        txLine ((25+x)*size, (6+y)*size, (23+x)*size, (5+y)*size);
        txLine ((23+x)*size, (5+y)*size, (21+x)*size, (5+y)*size);

        txSetColor (DARKGREEN);
        txLine ((11+x)*size, (14+y)*size, (10+x)*size, (15+y)*size);
        txLine ((10+x)*size, (15+y)*size, (10+x)*size, (18+y)*size);
        txLine ((10+x)*size, (18+y)*size, (9+x)*size, (19+y)*size);
        txLine ((9+x)*size, (19+y)*size, (9.1+x)*size, (20+y)*size);               //left leg of Duf
        txLine ((9.1+x)*size, (20+y)*size, (11+x)*size, (20+y)*size);
        txLine ((11+x)*size, (20+y)*size, (12.75+x)*size, (18+y)*size);
        txLine ((12.75+x)*size, (18+y)*size, (10+x)*size, (18+y)*size);

        txLine ((20.3+x)*size, (17.4+y)*size, (20.5+x)*size, (19+y)*size);
        txLine ((20.5+x)*size, (19+y)*size, (24+x)*size, (19+y)*size);
        txLine ((24+x)*size, (19+y)*size, (24.6+x)*size, (19.3+y)*size);
        txLine ((24.6+x)*size, (19.3+y)*size, (24.6+x)*size, (20+y)*size);         //left leg of Duf
        txLine ((24.6+x)*size, (20+y)*size, (22+x)*size, (20+y)*size);
        txLine ((22+x)*size, (20+y)*size, (21+x)*size, (19+y)*size);
        txLine ((24+x)*size, (19+y)*size, (23+x)*size, (15+y)*size);
        txLine ((23+x)*size, (15+y)*size, (21+x)*size, (11+y)*size);

        if (knifeistoobad==false)
        {
            txSetColor (COLDBLADE, 3);
            txLine ((6+x)*size, (10.3+y)*size, (3.5+x)*size, (14.7+y)*size);           //butcher's knife
            txSetColor (COLDBLADE, 5);
            txLine ((5+x)*size, (12.05+y)*size, (3.5+x)*size, (14.7+y)*size);
        }
        else if (needbetterknife == true)
        {

            txSetColor (COLDBLADE, 3);
            txLine((5+x)*size, (12+y)*size, (3.5+x)*size, (14.7+y)*size);
            txLine ((3.5+x)*size, (14.7+y)*size, (4.6+x)*size, (15.4+y)*size);
            txLine ((4.6+x)*size, (15.4+y)*size, (6.1+x)*size, (13+y)*size);
            txLine ((6.1+x)*size, (13+y)*size, (4.9+x)*size, (12.2+y)*size);
            txSetColor (BILLGREY, 5);
            txLine ((6+x)*size, (10.3+y)*size, (5+x)*size, (12+y)*size);

        }

        if (dkbetter == true)
        {
            txSetColor (COLDBLADE, 3);
            txLine ((26.3+x)*size, (12+y)*size, (28+x)*size, (14+y)*size);
            txLine ((26.3+x)*size, (12+y)*size, (26.2+x)*size, (12+y)*size);
            txLine ((26.3+x)*size, (12+y)*size, (26.33+x)*size, (11.85+y)*size);
            txLine ((28+x)*size, (14+y)*size, (28+x)*size, (15+y)*size);
            txLine ((28+x)*size, (14+y)*size, (28.13+x)*size, (13.94+y)*size);
            txLine ((28+x)*size, (14+y)*size, (27.87+x)*size, (14.15+y)*size);
            txLine ((28+x)*size, (14+y)*size, (27.88+x)*size, (13.97+y)*size);
            txLine ((28+x)*size, (15+y)*size, (31+x)*size, (15.7+y)*size);             //DK hook
            txLine ((28+x)*size, (15+y)*size, (27.87+x)*size, (15.1+y)*size);
            txLine ((28+x)*size, (15+y)*size, (28.13+x)*size, (15.1+y)*size);
            txLine ((28+x)*size, (15+y)*size, (27.92+x)*size, (14.86+y)*size);
            txLine ((31+x)*size, (15.7+y)*size, (31.2+x)*size, (14.6+y)*size);
            txLine ((31+x)*size, (15.7+y)*size, (31.06+x)*size, (15.62+y)*size);
            txLine ((31+x)*size, (15.7+y)*size, (31.02+x)*size, (15.8+y)*size);
            txLine ((31+x)*size, (15.7+y)*size, (30.91+x)*size, (15.76+y)*size);
            txLine ((31.2+x)*size, (14.6+y)*size, (30.8+x)*size, (13.5+y)*size);
            txLine ((31.2+x)*size, (14.6+y)*size, (31.1+x)*size, (14.61+y)*size);
            txLine ((31.2+x)*size, (14.6+y)*size, (31.26+x)*size, (14.6+y)*size);
            txLine ((30.8+x)*size, (13.5+y)*size, (30.72+x)*size, (13.5+y)*size);
            txLine ((30.8+x)*size, (13.5+y)*size, (30.86+x)*size, (13.43+y)*size);
        }
        else
        {
            txSetColor(DARKGREEN, 3);
            txSetFillColor(DARKBLUEDREAM);
            txLine ((26.3+x)*size, (12+y)*size, (26.8+x)*size, (14.8+y)*size);
            txCircle((27.4+x)*size, (15.8+y)*size, 1.2*size);
            txLine ((28.4+x)*size, (16.2+y)*size, (28.3+x)*size, (16.4+y)*size);
            txLine ((28.45+x)*size, (16.15+y)*size, (28.4+x)*size, (16.45+y)*size);
            txSetColor(TX_TRANSPARENT);
            txCircle((28+x)*size, (15.2+y)*size, 1.2*size);
        }

        if (needchains==true)
        {
            txSetColor (TX_WHITE);
            txLine ((26.3+x)*size, (9+y)*size, (26.3+x)*size, (12+y)*size);
            txSetFillColor (DARKBLUEDREAM);
            txCircle ((26.3+x)*size, (9.3+y)*size, 0.25*size);              //chains_Y
            txCircle ((26.3+x)*size, (9.9+y)*size, 0.25*size);
            txCircle ((26.3+x)*size, (10.5+y)*size, 0.25*size);
            txCircle ((26.3+x)*size, (11.1+y)*size, 0.25*size);
            txCircle ((26.3+x)*size, (11.7+y)*size, 0.25*size);

            txLine ((22+x)*size, (6.5+y)*size, (25+x)*size, (7+y)*size);
            txCircle ((22.7+x)*size, (6.588+y)*size, 0.25*size);
            txCircle ((23.2+x)*size, (6.666+y)*size, 0.25*size);
            txCircle ((23.7+x)*size, (6.744+y)*size, 0.25*size);            //chains_x
            txCircle ((24.2+x)*size, (6.822+y)*size, 0.25*size);
            txCircle ((24.7+x)*size, (6.911+y)*size, 0.25*size);
        }
        txSetColor (TX_WHITE);
        txLine ((12+x)*size, (14.5+y)*size, (13+x)*size, (19+y)*size);
        txLine ((13+x)*size, (19+y)*size, (22+x)*size, (17+y)*size);               //apron
        txLine ((22+x)*size, (17+y)*size, (21+x)*size, (16+y)*size);
        txLine ((21+x)*size, (16+y)*size, (21.7+x)*size, (15.3+y)*size);
        txLine ((21.7+x)*size, (15.3+y)*size, (20+x)*size, (14.5+y)*size);
        txLine ((12.9+x)*size, (18.6+y)*size, (13.8+x)*size, (18.815+y)*size);
        txLine ((12.81+x)*size, (18.2+y)*size, (14.6+x)*size, (18.63+y)*size);
        txLine ((12.72+x)*size, (17.8+y)*size, (15.4+x)*size, (18.445+y)*size);
        txLine ((12.63+x)*size, (17.4+y)*size, (16.2+x)*size, (18.26+y)*size);
        txLine ((12.54+x)*size, (17+y)*size, (17+x)*size, (18.075+y)*size);
        txLine ((12.45+x)*size, (16.6+y)*size, (17.8+x)*size, (17.89+y)*size);
        txLine ((12.36+x)*size, (16.2+y)*size, (18.6+x)*size, (17.705+y)*size);    //still apron
        txLine ((12.27+x)*size, (15.8+y)*size, (19.4+x)*size, (17.52+y)*size);
        txLine ((12.19+x)*size, (15.4+y)*size, (20.2+x)*size, (17.35+y)*size);
        txLine ((12.09+x)*size, (15+y)*size, (21+x)*size, (17.2+y)*size);
        txLine ((12+x)*size, (14.6+y)*size, (21.8+x)*size, (17+y)*size);
        txLine ((11.8+x)*size, (14.2+y)*size, (21.5+x)*size, (16.5+y)*size);
        txLine ((11.7+x)*size, (13.8+y)*size, (21+x)*size, (16+y)*size);
        txLine ((11.6+x)*size, (13.4+y)*size, (21.3333+x)*size, (15.6666+y)*size);
        txLine ((11.5+x)*size, (13+y)*size, (21.6666+x)*size, (15.3333+y)*size);   //yep, apron
        txLine ((11.4+x)*size, (12.6+y)*size, (20.6+x)*size, (14.75+y)*size);

        txSetColor (SKINCOLOR);
        if (needcolor==true) txSetFillColor(SKINCOLOR);
        txCircle ((16+x)*size, (9+y)*size, 7*size);                     //body of Duf

        txSetColor (SKINCOLOR1);
        txSetFillColor (DARKBLUEDREAM);
        txCircle ((14+x)*size, (5+y)*size, 2*size);
        txSetColor (TX_WHITE);                         //head of Duf
        txSetFillColor (TX_WHITE);
        txCircle ((13+x)*size, (4.5+y)*size, 0.3*size);
        txCircle ((14.5+x)*size, (4.5+y)*size, 0.3*size);
        if (dotlog==true) Dotalogo((15+x), (113+y), 0.2*size);
        if (signa==true)
        {
            txSetColor(COLDBLADE);
            txSetFillColor(DARKBLUEDREAM);
            txCircle ((11.8+x)*size, (24.1+y)*size, 1.1*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((11.3+x)*size, (24.1+y)*size, 1.2*size);

            txSetColor(COLDBLADE);
            txCircle ((11.7+x)*size, (24.1+y)*size, 0.5*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((11.2+x)*size, (24.1+y)*size, 0.7*size);

            txSetColor(COLDBLADE);
            txLine ((11.75+x)*size, (25.15+y)*size, (11+x)*size, (25.2+y)*size);
            txLine ((11+x)*size, (25.2+y)*size, (10.5+x)*size, (27+y)*size);
            txLine ((10.5+x)*size, (27+y)*size, (9.5+x)*size, (27+y)*size);            //P
            txLine ((9.5+x)*size, (27+y)*size, (10.5+x)*size, (23+y)*size);
            txLine ((10.5+x)*size, (23+y)*size, (11.9+x)*size, (23+y)*size);

            txLine ((11.05+x)*size, (24.55+y)*size, (11.3+x)*size, (23.55+y)*size);
            txLine ((11.3+x)*size, (23.55+y)*size, (11.7+x)*size, (23.55+y)*size);
            txLine ((11.05+x)*size, (24.55+y)*size, (11.7+x)*size, (24.55+y)*size);

            txSetColor(COLDBLADE);
            txCircle ((14.5+x)*size, (26+y)*size, 1.25*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((14.55+x)*size, (25.7+y)*size, 1.25*size);

            txSetColor(COLDBLADE);
            txCircle ((14.55+x)*size, (25.8+y)*size, 0.45*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((14.55+x)*size, (25.7+y)*size, 0.45*size);

            txSetColor(COLDBLADE);
            txCircle ((18.5+x)*size, (25+y)*size, 2.05*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((18+x)*size, (24.9+y)*size, 2.15*size);

            txSetColor(COLDBLADE);
            txCircle ((18.5+x)*size, (25+y)*size, 1.05*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((18+x)*size, (24.9+y)*size, 1.15*size);

            txSetColor(COLDBLADE);
            txLine ((13.25+x)*size, (25.8+y)*size, (14+x)*size, (23+y)*size);
            txLine ((14+x)*size, (23+y)*size, (14.8+x)*size, (23+y)*size);
            txLine ((14.8+x)*size, (23+y)*size, (14.05+x)*size, (25.8+y)*size);       //U
            txLine ((14.95+x)*size, (25.8+y)*size, (15.7+x)*size, (23+y)*size);
            txLine ((15.7+x)*size, (23+y)*size, (16.5+x)*size, (23+y)*size);
            txLine ((16.5+x)*size, (23+y)*size, (15.7+x)*size, (26.1+y)*size);



            txSetColor(COLDBLADE);
            txLine ((19+x)*size, (23+y)*size, (18+x)*size, (23+y)*size);
            txLine ((18+x)*size, (23+y)*size, (17+x)*size, (27+y)*size);              //D
            txLine ((17+x)*size, (27+y)*size, (18.3+x)*size, (27+y)*size);
            txLine ((18.7+x)*size, (24+y)*size, (18.3+x)*size, (26+y)*size);

            txSetColor(COLDBLADE);
            txCircle ((23.5+x)*size, (25+y)*size, 2*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((24.7+x)*size, (24.2+y)*size, 1.2*size);

            txSetColor(COLDBLADE);
            txCircle ((23.5+x)*size, (25+y)*size, 1.3*size);
            txSetColor(DARKBLUEDREAM);
            txCircle ((24+x)*size, (24.8+y)*size, 1*size);

            txSetColor(COLDBLADE);
            txLine ((24.2+x)*size, (23.15+y)*size, (23.9+x)*size, (23.8+y)*size);
            txLine ((25.5+x)*size, (24.95+y)*size, (24+x)*size, (24.95+y)*size);       //G
            txLine ((24+x)*size, (24.95+y)*size, (23.8+x)*size, (25.5+y)*size);
            txLine ((23.8+x)*size, (25.5+y)*size, (24.6+x)*size, (25.5+y)*size);

            txLine ((27+x)*size, (23+y)*size, (26+x)*size, (27+y)*size);
            txLine ((26+x)*size, (27+y)*size, (28.5+x)*size, (27+y)*size);
            txLine ((28.5+x)*size, (27+y)*size, (28.7+x)*size, (26.3+y)*size);
            txLine ((28.7+x)*size, (26.3+y)*size, (26.9+x)*size, (26.3+y)*size);
            txLine ((26.9+x)*size, (26.3+y)*size, (27.2+x)*size, (25.3+y)*size);
            txLine ((27.2+x)*size, (25.3+y)*size, (27.9+x)*size, (25.3+y)*size);
            txLine ((27.9+x)*size, (25.3+y)*size, (28.1+x)*size, (24.6+y)*size);      //E
            txLine ((28.1+x)*size, (24.6+y)*size, (27.4+x)*size, (24.6+y)*size);
            txLine ((27.4+x)*size, (24.6+y)*size, (27.6+x)*size, (23.7+y)*size);
            txLine ((27.6+x)*size, (23.7+y)*size, (29.1+x)*size, (23.7+y)*size);
            txLine ((29.1+x)*size, (23.7+y)*size, (29.25+x)*size, (23+y)*size);
            txLine ((29.25+x)*size, (23+y)*size, (27+x)*size, (23+y)*size);

        }
    }


//-----------------------------------------------------------------------------

    bool Gnoiny(int x = 0, int y = 0, int size = 14, bool ru = true, int col1 = 210, int col2 = 240, int col3 = 176, int coll1 = 220, int coll2 = 220, int coll3 = 220)
    {
        COLORREF FING = RGB(col1, col2, col3);
        COLORREF FRAME = RGB(coll1, coll2, coll3);
        txSetColor(FING);
        txSetFillColor(DARKBLUEDREAM);

        txCircle ((11.5+x)*size, (10.5+y)*size, 2*size);
        txCircle ((11+x)*size, (3+y)*size, 1.4142135*size);
        txCircle ((22+x)*size, (8+y)*size, 1.4142135*size);             //fingersend1
        txCircle ((9.5+x)*size, (9.5+y)*size, 2.1213203*size);
        txCircle ((12.5+x)*size, (12.5+y)*size, 2.1213203*size);

        txSetColor(DARKBLUEDREAM);
        txCircle ((10+x)*size, (4+y)*size, 2*size);
        txCircle ((21+x)*size, (9+y)*size, 2*size);                     //fingersend2
        txCircle ((8+x)*size, (11+y)*size, 3*size);
        txCircle ((11+x)*size, (14+y)*size, 3*size);

        txSetColor(FING);
        txLine ((10+x)*size, (2+y)*size, (5+x)*size, (7+y)*size);
        txLine ((12+x)*size, (3.95+y)*size, (5+x)*size, (10.98+y)*size);
        txLine ((11+x)*size, (10.95+y)*size, (7+x)*size, (14.98+y)*size);
        txLine ((21+x)*size, (7+y)*size, (10+x)*size, (18+y)*size);                //fingers
        txLine ((23+x)*size, (8.95+y)*size, (5+x)*size, (26.98+y)*size);
        txLine ((6+x)*size, (26+y)*size, (10.5+x)*size, (24.5+y)*size);
        txLine ((10.5+x)*size, (24.5+y)*size, (11+x)*size, (24+y)*size);
        txLine ((11+x)*size, (24+y)*size, (12+x)*size, (19.98+y)*size);

        txSetColor(FRAME);
        txLine ((14+x)*size, (3.5+y)*size, (22.5+x)*size, (3.5+y)*size);
        txLine ((25.5+x)*size, (3.5+y)*size, (26.5+x)*size, (3.5+y)*size);           //frame
        txLine ((14+x)*size, (3.5+y)*size, (14+x)*size, (6.5+y)*size);
        txLine ((14+x)*size, (6.5+y)*size, (20+x)*size, (6.5+y)*size);
        txLine ((24.5+x)*size, (6.5+y)*size, (26.5+x)*size, (6.5+y)*size);
        txLine ((26.5+x)*size, (3.5+y)*size, (26.5+x)*size, (6.5+y)*size);


        txLine ((15+x)*size, (4+y)*size, (14.5+x)*size, (6+y)*size);
        txLine ((15+x)*size, (4+y)*size, (15.5+x)*size, (6+y)*size);               //A
        txLine ((14.75+x)*size, (5+y)*size, (15.25+x)*size, (5+y)*size);

            txLine ((17.5+x)*size, (4+y)*size, (18.5+x)*size, (4+y)*size);             //T
            txLine ((18+x)*size, (4+y)*size, (18+x)*size, (6+y)*size);

        if (ru==true)
        {


            txLine ((16+x)*size, (4+y)*size, (16+x)*size, (6+y)*size);
            txLine ((17+x)*size, (4+y)*size, (17+x)*size, (6+y)*size);                 //H
            txLine ((16+x)*size, (5+y)*size, (17+x)*size, (5+y)*size);

            txLine ((19+x)*size, (4+y)*size, (19+x)*size, (6+y)*size);
            txLine ((19+x)*size, (6+y)*size, (20+x)*size, (4+y)*size);                 //N
            txLine ((20+x)*size, (4+y)*size, (20+x)*size, (6+y)*size);

            txLine ((20.5+x)*size, (4+y)*size, (21.5+x)*size, (6+y)*size);             //Z
            txLine ((20.5+x)*size, (6+y)*size, (21.5+x)*size, (4+y)*size);

            txLine ((22.5+x)*size, (4+y)*size, (22+x)*size, (6+y)*size);
            txLine ((22.5+x)*size, (4+y)*size, (23+x)*size, (6+y)*size);               //A
            txLine ((22.25+x)*size, (5+y)*size, (22.75+x)*size, (5+y)*size);

            txLine ((23.5+x)*size, (4+y)*size, (23.5+x)*size, (6+y)*size);
            txLine ((23.5+x)*size, (6+y)*size, (24.5+x)*size, (4+y)*size);
            txLine ((24.5+x)*size, (4+y)*size, (24.5+x)*size, (6+y)*size);             //N
            txLine ((23.5+x)*size, (3.5+y)*size, (24+x)*size, (4+y)*size);
            txLine ((24+x)*size, (4+y)*size, (24.5+x)*size, (3.5+y)*size);

            txLine ((25+x)*size, (4+y)*size, (25+x)*size, (6+y)*size);
            txLine ((25+x)*size, (4+y)*size, (26+x)*size, (4+y)*size);                 //P
            txLine ((26+x)*size, (4+y)*size, (26+x)*size, (6+y)*size);
        }
        else
        {
            txLine ((16+x)*size, (4+y)*size, (16+x)*size, (6+y)*size);
            txLine ((17+x)*size, (4+y)*size, (17+x)*size, (6+y)*size);                 //N
            txLine ((16+x)*size, (4+y)*size, (17+x)*size, (6+y)*size);

            txLine ((19+x)*size, (4+y)*size, (20+x)*size, (4+y)*size);
            txLine ((19+x)*size, (6+y)*size, (20+x)*size, (6+y)*size);                 //I
            txLine ((19.5+x)*size, (4+y)*size, (19.5+x)*size, (6+y)*size);

            txLine ((20.5+x)*size, (4+y)*size, (20.5+x)*size, (6+y)*size);
            txLine ((21.5+x)*size, (6+y)*size, (21.5+x)*size, (4+y)*size);             //H
            txLine ((20.5+x)*size, (5+y)*size, (21.5+x)*size, (5+y)*size);

            txLine ((22+x)*size, (4+y)*size, (22.5+x)*size, (5+y)*size);
            txLine ((22.5+x)*size, (5+y)*size, (23+x)*size, (4+y)*size);               //Y
            txLine ((22.5+x)*size, (5+y)*size, (22.5+x)*size, (6+y)*size);

            txLine ((23.5+x)*size, (4+y)*size, (23.5+x)*size, (6+y)*size);
            txLine ((23.5+x)*size, (4+y)*size, (24.5+x)*size, (4.2+y)*size);             //P
            txLine ((23.5+x)*size, (5+y)*size, (24.5+x)*size, (4.8+y)*size);
            txLine ((24.5+x)*size, (4.2+y)*size, (24.5+x)*size, (4.8+y)*size);

            txLine ((25+x)*size, (4+y)*size, (25+x)*size, (6+y)*size);
            txLine ((25+x)*size, (4+y)*size, (26+x)*size, (4+y)*size);                 //E
            txLine ((25+x)*size, (5+y)*size, (25.5+x)*size, (5+y)*size);
            txLine ((25+x)*size, (6+y)*size, (26+x)*size, (6+y)*size);

            txLine ((22.5+x)*size, (3.5+y)*size, (25.5+x)*size, (3.5+y)*size);         //framefix
        }
    }



//-----------------------------------------------------------------------------

    bool Bill(int x = 0, int y = 0, int size = 14, bool eye = true, bool standardilluminate = false, bool needbricks = true, bool needtie = true, bool needhat = true, bool needarms = true, bool needlegs = true)
    {
        if (eye == true)
        {
            txSetColor(TX_WHITE, 3);
            txSetFillColor(TX_TRANSPARENT);

            txCircle ((12+x)*size, (12+y)*size, 3.7*size);
            txCircle ((12+x)*size, (15+y)*size, 3.7*size);
            txSetColor(TX_BLACK, 5);
            txLine ((12+x)*size, (12.4+y)*size, (12+x)*size, (14.6+y)*size);
            txSetColor(TX_BLACK, 3);
            txLine ((12+x)*size, (12+y)*size, (12+x)*size, (15+y)*size);

            txSetColor(DARKBLUEDREAM);
            txSetFillColor(DARKBLUEDREAM);
            txCircle ((6.9+x)*size, (12+y)*size, 2.2*size);
            txCircle ((6.9+x)*size, (15+y)*size, 2.2*size);
            txCircle ((10+x)*size, (9+y)*size, 2.5*size);                  //eyes
            txCircle ((10+x)*size, (18+y)*size, 2.5*size);
            txCircle ((14+x)*size, (9+y)*size, 2.5*size);
            txCircle ((14+x)*size, (18+y)*size, 2.5*size);
            txCircle ((17.16+x)*size, (12.1+y)*size, 2.2*size);
            txCircle ((17+x)*size, (15.1+y)*size, 2.2*size);
            txLine ((8.5+x)*size, (13.4+y)*size, (8.5+x)*size, (13.6+y)*size);
            txLine ((15.35+x)*size, (13.4+y)*size, (15.35+x)*size, (13.6+y)*size);
        }

        if (standardilluminate == false)
        {
            if (needbricks == true)
            {
                txSetColor(BILLGREY, 3);
                txLine ((5.5+x)*size, (17.5+y)*size, (18.5+x)*size, (17.5+y)*size);
                txLine ((4.75+x)*size, (19+y)*size, (10+x)*size, (19+y)*size);
                txLine ((14+x)*size, (19+y)*size, (19.25+x)*size, (19+y)*size);
                txLine ((3.8+x)*size, (20.5+y)*size, (20.2+x)*size, (20.5+y)*size);
                txLine ((7+x)*size, (17.5+y)*size, (7+x)*size, (19+y)*size);
                txLine ((7+x)*size, (20.5+y)*size, (7+x)*size, (22+y)*size);
                txLine ((9.5+x)*size, (19+y)*size, (9.5+x)*size, (20.5+y)*size);         //bricks
                txLine ((12+x)*size, (17.5+y)*size, (12+x)*size, (19+y)*size);
                txLine ((12+x)*size, (20.5+y)*size, (12+x)*size, (22+y)*size);
                txLine ((14.5+x)*size, (19+y)*size, (14.5+x)*size, (20.5+y)*size);
                txLine ((17+x)*size, (17.5+y)*size, (17+x)*size, (19+y)*size);
                txLine ((17+x)*size, (20.5+y)*size, (17+x)*size, (22+y)*size);
            }
            txSetColor(TX_BLACK, 3);
            if (needtie == true)
            {

                txLine ((10+x)*size, (18+y)*size, (10+x)*size, (20+y)*size);
                txLine ((10+x)*size, (20+y)*size, (14+x)*size, (18+y)*size);               //bow-tie
                txLine ((14+x)*size, (18+y)*size, (14+x)*size, (20+y)*size);
                txLine ((14+x)*size, (20+y)*size, (10+x)*size, (18+y)*size);
            }
            if (needarms == true)
            {
                txLine ((7+x)*size, (15+y)*size, (4+x)*size, (16+y)*size);
                txLine ((4+x)*size, (16+y)*size, (2.7+x)*size, (15.2+y)*size);
                txLine ((2.7+x)*size, (15.2+y)*size, (2.5+x)*size, (12.2+y)*size);
                txLine ((2.5+x)*size, (12+y)*size, (1+x)*size, (12.2+y)*size);
                txLine ((2.5+x)*size, (12+y)*size, (1.2+x)*size, (11.4+y)*size);         //right arm
                txLine ((2.5+x)*size, (12+y)*size, (2+x)*size, (10.8+y)*size);
                txLine ((2.5+x)*size, (12+y)*size, (3.3+x)*size, (11.5+y)*size);

                txLine ((17+x)*size, (15+y)*size, (20+x)*size, (16+y)*size);
                txLine ((20+x)*size, (16+y)*size, (21+x)*size, (15.7+y)*size);
                txLine ((21+x)*size, (15.7+y)*size, (21.5+x)*size, (15.5+y)*size);
                txLine ((21.5+x)*size, (15.5+y)*size, (21.6+x)*size, (13+y)*size);
                txLine ((21.6+x)*size, (13+y)*size, (20.6+x)*size, (12.4+y)*size);         //left arm
                txLine ((21.6+x)*size, (13+y)*size, (22+x)*size, (11.9+y)*size);
                txLine ((21.6+x)*size, (13+y)*size, (23+x)*size, (12.5+y)*size);
                txLine ((21.6+x)*size, (13+y)*size, (22.8+x)*size, (13.5+y)*size);
            }

            if (needlegs == true)
            {
                txLine ((9.4+x)*size, (22+y)*size, (8.2+x)*size, (25+y)*size);
                txLine ((8.2+x)*size, (25+y)*size, (8.4+x)*size, (26+y)*size);
                txLine ((8.4+x)*size, (26+y)*size, (9+x)*size, (26.6+y)*size);           //right leg
                txLine ((9+x)*size, (26.6+y)*size, (11+x)*size, (26+y)*size);
                txLine ((11+x)*size, (25.55+y)*size, (11+x)*size, (28+y)*size);

                txLine ((14.4+x)*size, (22+y)*size, (15+x)*size, (24.3+y)*size);
                txLine ((15+x)*size, (24.3+y)*size, (15.2+x)*size, (26.4+y)*size);
                txLine ((15.2+x)*size, (26.4+y)*size, (14.5+x)*size, (27.3+y)*size);       //left leg
                txLine ((14.5+x)*size, (27.3+y)*size, (13.6+x)*size, (27.2+y)*size);
                txLine ((13.6+x)*size, (27.2+y)*size, (12.5+x)*size, (26.5+y)*size);
                txLine ((12.5+x)*size, (26.5+y)*size, (12.6+x)*size, (28.4+y)*size);
            }
            if (needhat == true)
            {
                txLine ((11+x)*size, (5.5+y)*size, (11+x)*size, (0.5+y)*size);
                txLine ((11+x)*size, (0.5+y)*size, (13+x)*size, (0.5+y)*size);
                txLine ((13+x)*size, (0.5+y)*size, (13+x)*size, (5.5+y)*size);               //hat-cylinder
                txSetColor(TX_BLACK, 5);
                txLine ((10+x)*size, (5.5+y)*size, (14+x)*size, (5.5+y)*size);
            }
        }
        txSetColor(BILLYELLOW, 3);
        txLine ((12+x)*size, (6+y)*size, (21+x)*size, (22+y)*size);
        txLine ((21+x)*size, (22+y)*size, (3+x)*size, (22+y)*size);               //body
        txLine ((3+x)*size, (22+y)*size, (12+x)*size, (6+y)*size);
    }


    float max(float a, float b)
    {
        if (a>b) return a;
        else return b;
    }

//-----------------------------------------------------------------------------

    bool Pokerface(int x = 0, int y = 0, int size = 14, float length = 1, float heigth = 1, bool silh = true, int col1 = 0, int col2 = 0, int col3 = 0, bool downmouth = true)
    {
        txSetColor(RGB(col1, col2, col3), 2);
        txSetFillColor(RGB(col1, col2, col3));
        if (silh == true)
        {
            txLine ((13+x)*length*size, (32+y)*heigth*size, (13+x)*length*size, (28.5+y)*heigth*size);
            txLine ((13+x)*length*size, (28.5+y)*heigth*size, (7+x)*length*size, (26+y)*heigth*size);
            txLine ((7+x)*length*size, (26+y)*heigth*size, (4+x)*length*size, (23+y)*heigth*size);
            txLine ((4+x)*length*size, (23+y)*heigth*size, (2+x)*length*size, (19+y)*heigth*size);
            txLine ((2+x)*length*size, (19+y)*heigth*size, (2+x)*length*size, (8+y)*heigth*size);
            txLine ((2+x)*length*size, (8+y)*heigth*size, (4.5+x)*length*size, (3.5+y)*heigth*size);
            txLine ((4.5+x)*length*size, (3.5+y)*heigth*size, (12+x)*length*size, (0.5+y)*heigth*size);           //silhouette
            txLine ((12+x)*length*size, (0.5+y)*heigth*size, (18+x)*length*size, (1+y)*heigth*size);
            txLine ((18+x)*length*size, (1+y)*heigth*size, (23+x)*length*size, (4+y)*heigth*size);
            txLine ((23+x)*length*size, (4+y)*heigth*size, (25+x)*length*size, (8+y)*heigth*size);
            txLine ((25+x)*length*size, (8+y)*heigth*size, (26+x)*length*size, (12+y)*heigth*size);
            txLine ((26+x)*length*size, (12+y)*heigth*size, (26.5+x)*length*size, (16+y)*heigth*size);
            txLine ((26.5+x)*length*size, (16+y)*heigth*size, (26+x)*length*size, (22+y)*heigth*size);
            txLine ((26+x)*length*size, (22+y)*heigth*size, (23+x)*length*size, (26+y)*heigth*size);
            txLine ((23+x)*length*size, (26+y)*heigth*size, (19+x)*length*size, (28.5+y)*heigth*size);
            txLine ((19+x)*length*size, (28.5+y)*heigth*size, (13+x)*length*size, (28.5+y)*heigth*size);
        }
        txCircle ((7+x)*length*size, (12+y)*heigth*size, 0.7*size);
        txCircle ((7.1+x)*length*size, (12+y)*heigth*size, 0.7*size);
        txCircle ((7.2+x)*length*size, (12+y)*heigth*size, 0.7*size);
        txCircle ((7.3+x)*length*size, (12+y)*heigth*size, 0.7*size);
        txCircle ((21+x)*length*size, (10.2+y)*heigth*size, 0.5*size);

        txSetColor(RGB(col1, col2, col3), 5);
        txLine ((5+x)*length*size, (17.5+y)*heigth*size, (24+x)*length*size, (14.5+y)*heigth*size);             //mouth   mmmmm  m m m m
        txSetColor(RGB(col1, col2, col3), 4);
        if (downmouth == true)
        {
        txLine ((14+x)*length*size, (17.7+y)*heigth*size, (17+x)*length*size, (17.4+y)*heigth*size);
        }

        txLine ((7.9+x)*length*size, (12+y)*heigth*size, (7.9+x)*length*size, (13+y)*heigth*size);
        txLine ((21+x)*length*size, (10.6+y)*heigth*size, (22+x)*length*size, (10.6+y)*heigth*size);            //eyes2
    }



//-----------------------------------------------------------------------------
    bool Dotalogo(int x, int y, int size, bool dire, bool radiant, bool river, int sizeDire, int sizeRadiant, int sizeRiver, bool letters)
    {
        if (sizeDire == -1) sizeDire = size;
        if (sizeRadiant == -1) sizeRadiant = size;
        if (sizeRiver == -1) sizeRiver = size;
        txSetColor(TX_RED);
 		txLine((3.07+x)*size, (0.65+y)*size, (2.88+x)*size, (1.35+y)*size);
		txLine((2.88+x)*size, (1.35+y)*size, (3.05+x)*size, (2.5+y)*size);
		txLine((3.05+x)*size, (2.5+y)*size, (3.03+x)*size, (4.4+y)*size);
		txLine((3.03+x)*size, (4.4+y)*size, (2.68+x)*size, (6.22+y)*size);
		txLine((2.68+x)*size, (6.22+y)*size, (2.73+x)*size, (7.1+y)*size);
		txLine((2.73+x)*size, (7.1+y)*size, (3.17+x)*size, (9.07+y)*size);
		txLine((3.17+x)*size, (9.07+y)*size, (3.23+x)*size, (9.88+y)*size);
		txLine((3.23+x)*size, (9.88+y)*size, (3.12+x)*size, (10.57+y)*size);
		txLine((3.12+x)*size, (10.57+y)*size, (3.15+x)*size, (10.98+y)*size);
		txLine((3.15+x)*size, (10.98+y)*size, (3.28+x)*size, (11.33+y)*size);
		txLine((3.28+x)*size, (11.33+y)*size, (3.57+x)*size, (11.67+y)*size);
		txLine((3.57+x)*size, (11.67+y)*size, (3.55+x)*size, (12.3+y)*size);
		txLine((3.55+x)*size, (12.3+y)*size, (3.38+x)*size, (12.7+y)*size);
		txLine((3.38+x)*size, (12.7+y)*size, (3.03+x)*size, (12.88+y)*size);
		txLine((3.03+x)*size, (12.88+y)*size, (2.85+x)*size, (12.9+y)*size);
		txLine((2.85+x)*size, (12.9+y)*size, (3+x)*size, (15.33+y)*size);
		txLine((3+x)*size, (15.33+y)*size, (3.07+x)*size, (15.62+y)*size);
		txLine((3.07+x)*size, (15.62+y)*size, (3.37+x)*size, (15.9+y)*size);
		txLine((3.37+x)*size, (15.9+y)*size, (3.5+x)*size, (16.02+y)*size);
		txLine((3.5+x)*size, (16.02+y)*size, (3.55+x)*size, (16.12+y)*size);
		txLine((3.55+x)*size, (16.12+y)*size, (3.6+x)*size, (16.47+y)*size);
		txLine((3.6+x)*size, (16.47+y)*size, (3.35+x)*size, (18.45+y)*size);
		txLine((3.35+x)*size, (18.45+y)*size, (2.92+x)*size, (19.1+y)*size);
		txLine((2.92+x)*size, (19.1+y)*size, (2.93+x)*size, (20.52+y)*size);
		txLine((2.93+x)*size, (20.52+y)*size, (3.03+x)*size, (21.68+y)*size);
		txLine((3.03+x)*size, (21.68+y)*size, (3.03+x)*size, (22.13+y)*size);
		txLine((3.03+x)*size, (22.13+y)*size, (2.92+x)*size, (22.9+y)*size);
		txLine((2.92+x)*size, (22.9+y)*size, (2.92+x)*size, (23.37+y)*size);
		txLine((2.92+x)*size, (23.37+y)*size, (3.68+x)*size, (23.63+y)*size);
		txLine((3.68+x)*size, (23.63+y)*size, (4.5+x)*size, (23.68+y)*size);
		txLine((4.5+x)*size, (23.68+y)*size, (5.13+x)*size, (23.6+y)*size);
		txLine((5.13+x)*size, (23.6+y)*size, (6.42+x)*size, (23.58+y)*size);
		txLine((6.42+x)*size, (23.58+y)*size, (6.62+x)*size, (23.63+y)*size);
		txLine((6.62+x)*size, (23.63+y)*size, (7.22+x)*size, (23.53+y)*size);
		txLine((7.22+x)*size, (23.53+y)*size, (7.6+x)*size, (23.67+y)*size);
		txLine((7.6+x)*size, (23.67+y)*size, (7.62+x)*size, (23.65+y)*size);
		txLine((7.62+x)*size, (23.65+y)*size, (7.95+x)*size, (23.6+y)*size);
		txLine((7.95+x)*size, (23.6+y)*size, (8.4+x)*size, (23.6+y)*size);
		txLine((8.4+x)*size, (23.6+y)*size, (8.68+x)*size, (23.68+y)*size);
		txLine((8.68+x)*size, (23.68+y)*size, (8.95+x)*size, (23.7+y)*size);
		txLine((8.95+x)*size, (23.7+y)*size, (9.32+x)*size, (23.67+y)*size);
		txLine((9.32+x)*size, (23.67+y)*size, (10.05+x)*size, (23.6+y)*size);
		txLine((10.05+x)*size, (23.6+y)*size, (10.55+x)*size, (23.57+y)*size);
		txLine((10.55+x)*size, (23.57+y)*size, (10.82+x)*size, (23.58+y)*size);
		txLine((10.82+x)*size, (23.58+y)*size, (10.98+x)*size, (23.72+y)*size);
		txLine((10.98+x)*size, (23.72+y)*size, (11.72+x)*size, (23.73+y)*size);
		txLine((11.72+x)*size, (23.73+y)*size, (11.83+x)*size, (23.75+y)*size);
		txLine((11.83+x)*size, (23.75+y)*size, (12.08+x)*size, (23.88+y)*size);
		txLine((12.08+x)*size, (23.88+y)*size, (12.32+x)*size, (23.67+y)*size);
		txLine((12.32+x)*size, (23.67+y)*size, (12.52+x)*size, (23.65+y)*size);
		txLine((12.52+x)*size, (23.65+y)*size, (12.55+x)*size, (23.77+y)*size);
		txLine((12.55+x)*size, (23.77+y)*size, (12.98+x)*size, (24.42+y)*size);
		txLine((12.98+x)*size, (24.42+y)*size, (13.08+x)*size, (24.52+y)*size);
		txLine((13.08+x)*size, (24.52+y)*size, (13.3+x)*size, (24.65+y)*size);
		txLine((13.3+x)*size, (24.65+y)*size, (13.62+x)*size, (24.35+y)*size);
		txLine((13.62+x)*size, (24.35+y)*size, (13.8+x)*size, (24.15+y)*size);
		txLine((13.8+x)*size, (24.15+y)*size, (14.03+x)*size, (24.1+y)*size);
		txLine((14.03+x)*size, (24.1+y)*size, (14.23+x)*size, (24.13+y)*size);
		txLine((14.23+x)*size, (24.13+y)*size, (14.72+x)*size, (24.3+y)*size);
		txLine((14.72+x)*size, (24.3+y)*size, (15.07+x)*size, (24.32+y)*size);
		txLine((15.07+x)*size, (24.32+y)*size, (15.25+x)*size, (24.23+y)*size);
		txLine((15.25+x)*size, (24.23+y)*size, (15.45+x)*size, (24.48+y)*size);
		txLine((15.45+x)*size, (24.48+y)*size, (15.62+x)*size, (24.58+y)*size);
		txLine((15.62+x)*size, (24.58+y)*size, (15.68+x)*size, (24.58+y)*size);
		txLine((15.68+x)*size, (24.58+y)*size, (16.33+x)*size, (24.28+y)*size);
		txLine((16.33+x)*size, (24.28+y)*size, (16.7+x)*size, (24.13+y)*size);
		txLine((16.7+x)*size, (24.13+y)*size, (17.12+x)*size, (24.07+y)*size);
		txLine((17.12+x)*size, (24.07+y)*size, (17.47+x)*size, (24.05+y)*size);
		txLine((17.47+x)*size, (24.05+y)*size, (18.7+x)*size, (24.05+y)*size);
		txLine((18.7+x)*size, (24.05+y)*size, (19.08+x)*size, (24.07+y)*size);
		txLine((19.08+x)*size, (24.07+y)*size, (19.17+x)*size, (24.08+y)*size);
		txLine((19.17+x)*size, (24.08+y)*size, (19.65+x)*size, (24.08+y)*size);
		txLine((19.65+x)*size, (24.08+y)*size, (20.13+x)*size, (24.02+y)*size);
		txLine((20.13+x)*size, (24.02+y)*size, (20.7+x)*size, (24+y)*size);
		txLine((20.7+x)*size, (24+y)*size, (20.97+x)*size, (23.92+y)*size);
		txLine((20.97+x)*size, (23.92+y)*size, (21.25+x)*size, (23.73+y)*size);
		txLine((21.25+x)*size, (23.73+y)*size, (21.8+x)*size, (23.97+y)*size);
		txLine((21.8+x)*size, (23.97+y)*size, (22.27+x)*size, (23.98+y)*size);
		txLine((22.27+x)*size, (23.98+y)*size, (24.37+x)*size, (24.08+y)*size);
		txLine((24.37+x)*size, (24.08+y)*size, (24.62+x)*size, (23.95+y)*size);
		txLine((24.62+x)*size, (23.95+y)*size, (24.87+x)*size, (23.93+y)*size);
		txLine((24.87+x)*size, (23.93+y)*size, (24.8+x)*size, (23.72+y)*size);
		txLine((24.8+x)*size, (23.72+y)*size, (24.6+x)*size, (23.72+y)*size);
		txLine((24.6+x)*size, (23.72+y)*size, (24.6+x)*size, (23.52+y)*size);
		txLine((24.6+x)*size, (23.52+y)*size, (25.37+x)*size, (23.43+y)*size);
		txLine((25.37+x)*size, (23.43+y)*size, (25.65+x)*size, (23.47+y)*size);
		txLine((25.65+x)*size, (23.47+y)*size, (26.42+x)*size, (23.63+y)*size);
		txLine((26.42+x)*size, (23.63+y)*size, (26.55+x)*size, (23.68+y)*size);
		txLine((26.55+x)*size, (23.68+y)*size, (27.03+x)*size, (23.92+y)*size);
		txLine((27.03+x)*size, (23.92+y)*size, (27.2+x)*size, (23.95+y)*size);
		txLine((27.2+x)*size, (23.95+y)*size, (27.2+x)*size, (22.98+y)*size);
		txLine((27.2+x)*size, (22.98+y)*size, (27.22+x)*size, (22.38+y)*size);
		txLine((27.22+x)*size, (22.38+y)*size, (27.15+x)*size, (20.85+y)*size);
		txLine((27.15+x)*size, (20.85+y)*size, (27.17+x)*size, (18.72+y)*size);
		txLine((27.17+x)*size, (18.72+y)*size, (27.18+x)*size, (16.55+y)*size);
		txLine((27.18+x)*size, (16.55+y)*size, (27.18+x)*size, (16.03+y)*size);
		txLine((27.18+x)*size, (16.03+y)*size, (27.25+x)*size, (15.73+y)*size);
		txLine((27.25+x)*size, (15.73+y)*size, (27.25+x)*size, (15.53+y)*size);
		txLine((27.25+x)*size, (15.53+y)*size, (27.18+x)*size, (15.28+y)*size);
		txLine((27.18+x)*size, (15.28+y)*size, (27.18+x)*size, (14.05+y)*size);
		txLine((27.18+x)*size, (14.05+y)*size, (26.4+x)*size, (14.05+y)*size);
		txLine((26.4+x)*size, (14.05+y)*size, (26.4+x)*size, (14+y)*size);
		txLine((26.4+x)*size, (14+y)*size, (26.45+x)*size, (13.92+y)*size);
		txLine((26.45+x)*size, (13.92+y)*size, (26.55+x)*size, (13.83+y)*size);
		txLine((26.55+x)*size, (13.83+y)*size, (26.65+x)*size, (13.78+y)*size);
		txLine((26.65+x)*size, (13.78+y)*size, (26.77+x)*size, (13.73+y)*size);
		txLine((26.77+x)*size, (13.73+y)*size, (26.83+x)*size, (13.7+y)*size);
		txLine((26.83+x)*size, (13.7+y)*size, (26.83+x)*size, (13.32+y)*size);     //silhouette
		txLine((26.83+x)*size, (13.32+y)*size, (26.87+x)*size, (12.9+y)*size);
		txLine((26.87+x)*size, (12.9+y)*size, (26.9+x)*size, (12.47+y)*size);
		txLine((26.9+x)*size, (12.47+y)*size, (26.92+x)*size, (11.6+y)*size);
		txLine((26.92+x)*size, (11.6+y)*size, (26.88+x)*size, (11.5+y)*size);
		txLine((26.88+x)*size, (11.5+y)*size, (26.88+x)*size, (11.32+y)*size);
		txLine((26.88+x)*size, (11.32+y)*size, (26.73+x)*size, (10.82+y)*size);
		txLine((26.73+x)*size, (10.82+y)*size, (26.3+x)*size, (10.15+y)*size);
		txLine((26.3+x)*size, (10.15+y)*size, (26.15+x)*size, (9.8+y)*size);
		txLine((26.15+x)*size, (9.8+y)*size, (26.62+x)*size, (9.2+y)*size);
		txLine((26.62+x)*size, (9.2+y)*size, (26.5+x)*size, (8.82+y)*size);
		txLine((26.5+x)*size, (8.82+y)*size, (26.5+x)*size, (8.72+y)*size);
		txLine((26.5+x)*size, (8.72+y)*size, (26.68+x)*size, (8.6+y)*size);
		txLine((26.68+x)*size, (8.6+y)*size, (26.97+x)*size, (8.47+y)*size);
		txLine((26.97+x)*size, (8.47+y)*size, (27.1+x)*size, (8.37+y)*size);
		txLine((27.1+x)*size, (8.37+y)*size, (27.18+x)*size, (8.17+y)*size);
		txLine((27.18+x)*size, (8.17+y)*size, (27.23+x)*size, (6.08+y)*size);
		txLine((27.23+x)*size, (6.08+y)*size, (27.15+x)*size, (3.4+y)*size);
		txLine((27.15+x)*size, (3.4+y)*size, (27.02+x)*size, (2.57+y)*size);
		txLine((27.02+x)*size, (2.57+y)*size, (27.18+x)*size, (1.87+y)*size);
		txLine((27.18+x)*size, (1.87+y)*size, (27.12+x)*size, (1.38+y)*size);
		txLine((27.12+x)*size, (1.38+y)*size, (27.12+x)*size, (1.17+y)*size);
		txLine((27.12+x)*size, (1.17+y)*size, (26.75+x)*size, (1.03+y)*size);
		txLine((26.75+x)*size, (1.03+y)*size, (26.3+x)*size, (0.73+y)*size);
		txLine((26.3+x)*size, (0.73+y)*size, (25.52+x)*size, (0.67+y)*size);
		txLine((25.52+x)*size, (0.67+y)*size, (24.63+x)*size, (0.63+y)*size);
		txLine((24.63+x)*size, (0.63+y)*size, (24.45+x)*size, (0.52+y)*size);
		txLine((24.45+x)*size, (0.52+y)*size, (24.23+x)*size, (0.53+y)*size);
		txLine((24.23+x)*size, (0.53+y)*size, (24.1+x)*size, (0.65+y)*size);
		txLine((24.1+x)*size, (0.65+y)*size, (23.58+x)*size, (0.55+y)*size);
		txLine((23.58+x)*size, (0.55+y)*size, (23.57+x)*size, (0.5+y)*size);
		txLine((23.57+x)*size, (0.5+y)*size, (22.68+x)*size, (0.38+y)*size);
		txLine((22.68+x)*size, (0.38+y)*size, (21.8+x)*size, (0.32+y)*size);
		txLine((21.8+x)*size, (0.32+y)*size, (20.45+x)*size, (0.28+y)*size);
		txLine((20.45+x)*size, (0.28+y)*size, (19.82+x)*size, (0.23+y)*size);
		txLine((19.82+x)*size, (0.23+y)*size, (19.18+x)*size, (0.25+y)*size);
		txLine((19.18+x)*size, (0.25+y)*size, (18.93+x)*size, (0.37+y)*size);
		txLine((18.93+x)*size, (0.37+y)*size, (18.83+x)*size, (0.57+y)*size);
		txLine((18.83+x)*size, (0.57+y)*size, (18.78+x)*size, (0.73+y)*size);
		txLine((18.78+x)*size, (0.73+y)*size, (18.75+x)*size, (1.07+y)*size);
		txLine((18.75+x)*size, (1.07+y)*size, (17.88+x)*size, (1.2+y)*size);
		txLine((17.88+x)*size, (1.2+y)*size, (17.68+x)*size, (1.18+y)*size);
		txLine((17.68+x)*size, (1.18+y)*size, (17.47+x)*size, (1.05+y)*size);
		txLine((17.47+x)*size, (1.05+y)*size, (17.38+x)*size, (0.87+y)*size);
		txLine((17.38+x)*size, (0.87+y)*size, (17.37+x)*size, (0.72+y)*size);
		txLine((17.37+x)*size, (0.72+y)*size, (16.53+x)*size, (0.67+y)*size);
		txLine((16.53+x)*size, (0.67+y)*size, (16.38+x)*size, (0.58+y)*size);
		txLine((16.38+x)*size, (0.58+y)*size, (16.57+x)*size, (0.25+y)*size);
		txLine((16.57+x)*size, (0.25+y)*size, (16.27+x)*size, (0.18+y)*size);
		txLine((16.27+x)*size, (0.18+y)*size, (15.15+x)*size, (0.15+y)*size);
		txLine((15.15+x)*size, (0.15+y)*size, (14.63+x)*size, (0.22+y)*size);
		txLine((14.63+x)*size, (0.22+y)*size, (13.65+x)*size, (0.15+y)*size);
		txLine((13.65+x)*size, (0.15+y)*size, (13.22+x)*size, (0.22+y)*size);
		txLine((13.22+x)*size, (0.22+y)*size, (12.83+x)*size, (0.17+y)*size);
		txLine((12.83+x)*size, (0.17+y)*size, (12.77+x)*size, (0.18+y)*size);
		txLine((12.77+x)*size, (0.18+y)*size, (12.45+x)*size, (0.45+y)*size);
		txLine((12.45+x)*size, (0.45+y)*size, (11.5+x)*size, (0.93+y)*size);
		txLine((11.5+x)*size, (0.93+y)*size, (11.13+x)*size, (0.98+y)*size);
		txLine((11.13+x)*size, (0.98+y)*size, (10.78+x)*size, (0.98+y)*size);
		txLine((10.78+x)*size, (0.98+y)*size, (10.65+x)*size, (0.95+y)*size);
		txLine((10.65+x)*size, (0.95+y)*size, (10.4+x)*size, (0.97+y)*size);
		txLine((10.4+x)*size, (0.97+y)*size, (10.13+x)*size, (0.93+y)*size);
		txLine((10.13+x)*size, (0.93+y)*size, (9.77+x)*size, (0.97+y)*size);
		txLine((9.77+x)*size, (0.97+y)*size, (9.23+x)*size, (0.92+y)*size);
		txLine((9.23+x)*size, (0.92+y)*size, (9.07+x)*size, (0.77+y)*size);
		txLine((9.07+x)*size, (0.77+y)*size, (8.7+x)*size, (0.7+y)*size);
		txLine((8.7+x)*size, (0.7+y)*size, (8.38+x)*size, (0.67+y)*size);
		txLine((8.38+x)*size, (0.67+y)*size, (8.28+x)*size, (0.72+y)*size);
		txLine((8.28+x)*size, (0.72+y)*size, (5.2+x)*size, (0.62+y)*size);
		txLine((5.2+x)*size, (0.62+y)*size, (4.3+x)*size, (0.62+y)*size);
		txLine((4.3+x)*size, (0.62+y)*size, (3.93+x)*size, (0.7+y)*size);
		txLine((3.93+x)*size, (0.7+y)*size, (3.62+x)*size, (0.7+y)*size);
		txLine((3.62+x)*size, (0.7+y)*size, (3.48+x)*size, (0.67+y)*size);
		txLine((3.48+x)*size, (0.67+y)*size, (3.07+x)*size, (0.65+y)*size);

        if (river == true)
        {
            txLine((-9.45*sizeRiver+(x+14.9)*size), (-7.49*sizeRiver+(y+12.29)*size), (-9.18*sizeRiver+(x+14.9)*size), (-7.52*sizeRiver+(y+12.29)*size));
            txLine((-9.18*sizeRiver+(x+14.9)*size), (-7.52*sizeRiver+(y+12.29)*size), (-8.7*sizeRiver+(x+14.9)*size), (-7.69*sizeRiver+(y+12.29)*size));
            txLine((-8.7*sizeRiver+(x+14.9)*size), (-7.69*sizeRiver+(y+12.29)*size), (-8*sizeRiver+(x+14.9)*size), (-8.02*sizeRiver+(y+12.29)*size));
            txLine((-8*sizeRiver+(x+14.9)*size), (-8.02*sizeRiver+(y+12.29)*size), (-7.75*sizeRiver+(x+14.9)*size), (-8.07*sizeRiver+(y+12.29)*size));
            txLine((-7.75*sizeRiver+(x+14.9)*size), (-8.07*sizeRiver+(y+12.29)*size), (-7.5*sizeRiver+(x+14.9)*size), (-8.07*sizeRiver+(y+12.29)*size));
            txLine((-7.5*sizeRiver+(x+14.9)*size), (-8.07*sizeRiver+(y+12.29)*size), (-7.33*sizeRiver+(x+14.9)*size), (-8.02*sizeRiver+(y+12.29)*size));
            txLine((-7.33*sizeRiver+(x+14.9)*size), (-8.02*sizeRiver+(y+12.29)*size), (-7.12*sizeRiver+(x+14.9)*size), (-7.89*sizeRiver+(y+12.29)*size));
            txLine((-7.12*sizeRiver+(x+14.9)*size), (-7.89*sizeRiver+(y+12.29)*size), (-6.83*sizeRiver+(x+14.9)*size), (-7.64*sizeRiver+(y+12.29)*size));
            txLine((-6.83*sizeRiver+(x+14.9)*size), (-7.64*sizeRiver+(y+12.29)*size), (-6.4*sizeRiver+(x+14.9)*size), (-7.39*sizeRiver+(y+12.29)*size));
            txLine((-6.4*sizeRiver+(x+14.9)*size), (-7.39*sizeRiver+(y+12.29)*size), (-5.05*sizeRiver+(x+14.9)*size), (-6.56*sizeRiver+(y+12.29)*size));
            txLine((-5.05*sizeRiver+(x+14.9)*size), (-6.56*sizeRiver+(y+12.29)*size), (-5*sizeRiver+(x+14.9)*size), (-6.34*sizeRiver+(y+12.29)*size));
            txLine((-5*sizeRiver+(x+14.9)*size), (-6.34*sizeRiver+(y+12.29)*size), (-4.8*sizeRiver+(x+14.9)*size), (-6.07*sizeRiver+(y+12.29)*size));
            txLine((-4.8*sizeRiver+(x+14.9)*size), (-6.07*sizeRiver+(y+12.29)*size), (-4.65*sizeRiver+(x+14.9)*size), (-5.97*sizeRiver+(y+12.29)*size));
            txLine((-4.65*sizeRiver+(x+14.9)*size), (-5.97*sizeRiver+(y+12.29)*size), (-4.53*sizeRiver+(x+14.9)*size), (-5.91*sizeRiver+(y+12.29)*size));
            txLine((-4.53*sizeRiver+(x+14.9)*size), (-5.91*sizeRiver+(y+12.29)*size), (-4.2*sizeRiver+(x+14.9)*size), (-5.77*sizeRiver+(y+12.29)*size));
            txLine((-4.2*sizeRiver+(x+14.9)*size), (-5.77*sizeRiver+(y+12.29)*size), (-4.05*sizeRiver+(x+14.9)*size), (-5.71*sizeRiver+(y+12.29)*size));
            txLine((-4.05*sizeRiver+(x+14.9)*size), (-5.71*sizeRiver+(y+12.29)*size), (-3.87*sizeRiver+(x+14.9)*size), (-5.51*sizeRiver+(y+12.29)*size));
            txLine((-3.87*sizeRiver+(x+14.9)*size), (-5.51*sizeRiver+(y+12.29)*size), (-3.7*sizeRiver+(x+14.9)*size), (-5.41*sizeRiver+(y+12.29)*size));
            txLine((-3.7*sizeRiver+(x+14.9)*size), (-5.41*sizeRiver+(y+12.29)*size), (-3.37*sizeRiver+(x+14.9)*size), (-5.27*sizeRiver+(y+12.29)*size));
            txLine((-3.37*sizeRiver+(x+14.9)*size), (-5.27*sizeRiver+(y+12.29)*size), (-3.22*sizeRiver+(x+14.9)*size), (-5.22*sizeRiver+(y+12.29)*size));
            txLine((-3.22*sizeRiver+(x+14.9)*size), (-5.22*sizeRiver+(y+12.29)*size), (-3*sizeRiver+(x+14.9)*size), (-5.07*sizeRiver+(y+12.29)*size));
            txLine((-3*sizeRiver+(x+14.9)*size), (-5.07*sizeRiver+(y+12.29)*size), (-2.82*sizeRiver+(x+14.9)*size), (-4.94*sizeRiver+(y+12.29)*size));
            txLine((-2.82*sizeRiver+(x+14.9)*size), (-4.94*sizeRiver+(y+12.29)*size), (-2.43*sizeRiver+(x+14.9)*size), (-4.69*sizeRiver+(y+12.29)*size));
            txLine((-2.43*sizeRiver+(x+14.9)*size), (-4.69*sizeRiver+(y+12.29)*size), (-2.15*sizeRiver+(x+14.9)*size), (-4.51*sizeRiver+(y+12.29)*size));
            txLine((-2.15*sizeRiver+(x+14.9)*size), (-4.51*sizeRiver+(y+12.29)*size), (0.92*sizeRiver+(x+14.9)*size), (-2.42*sizeRiver+(y+12.29)*size));
            txLine((0.92*sizeRiver+(x+14.9)*size), (-2.42*sizeRiver+(y+12.29)*size), (1.35*sizeRiver+(x+14.9)*size), (-2.12*sizeRiver+(y+12.29)*size));    //river
            txLine((1.35*sizeRiver+(x+14.9)*size), (-2.12*sizeRiver+(y+12.29)*size), (1.62*sizeRiver+(x+14.9)*size), (-1.91*sizeRiver+(y+12.29)*size));
            txLine((1.62*sizeRiver+(x+14.9)*size), (-1.91*sizeRiver+(y+12.29)*size), (2.37*sizeRiver+(x+14.9)*size), (-1.47*sizeRiver+(y+12.29)*size));
            txLine((2.37*sizeRiver+(x+14.9)*size), (-1.47*sizeRiver+(y+12.29)*size), (2.77*sizeRiver+(x+14.9)*size), (-1.22*sizeRiver+(y+12.29)*size));
            txLine((2.77*sizeRiver+(x+14.9)*size), (-1.22*sizeRiver+(y+12.29)*size), (3.1*sizeRiver+(x+14.9)*size), (-0.97*sizeRiver+(y+12.29)*size));
            txLine((3.1*sizeRiver+(x+14.9)*size), (-0.97*sizeRiver+(y+12.29)*size), (4.07*sizeRiver+(x+14.9)*size), (-0.34*sizeRiver+(y+12.29)*size));
            txLine((4.07*sizeRiver+(x+14.9)*size), (-0.34*sizeRiver+(y+12.29)*size), (4.35*sizeRiver+(x+14.9)*size), (-0.11*sizeRiver+(y+12.29)*size));
            txLine((4.35*sizeRiver+(x+14.9)*size), (-0.11*sizeRiver+(y+12.29)*size), (4.82*sizeRiver+(x+14.9)*size), (0.19*sizeRiver+(y+12.29)*size));
            txLine((4.82*sizeRiver+(x+14.9)*size), (0.19*sizeRiver+(y+12.29)*size), (5.37*sizeRiver+(x+14.9)*size), (0.58*sizeRiver+(y+12.29)*size));
            txLine((5.37*sizeRiver+(x+14.9)*size), (0.58*sizeRiver+(y+12.29)*size), (5.98*sizeRiver+(x+14.9)*size), (0.98*sizeRiver+(y+12.29)*size));
            txLine((5.98*sizeRiver+(x+14.9)*size), (0.98*sizeRiver+(y+12.29)*size), (6.2*sizeRiver+(x+14.9)*size), (1.08*sizeRiver+(y+12.29)*size));
            txLine((6.2*sizeRiver+(x+14.9)*size), (1.08*sizeRiver+(y+12.29)*size), (6.55*sizeRiver+(x+14.9)*size), (1.36*sizeRiver+(y+12.29)*size));
            txLine((6.55*sizeRiver+(x+14.9)*size), (1.36*sizeRiver+(y+12.29)*size), (6.97*sizeRiver+(x+14.9)*size), (1.73*sizeRiver+(y+12.29)*size));
            txLine((6.97*sizeRiver+(x+14.9)*size), (1.73*sizeRiver+(y+12.29)*size), (7.23*sizeRiver+(x+14.9)*size), (1.86*sizeRiver+(y+12.29)*size));
            txLine((7.23*sizeRiver+(x+14.9)*size), (1.86*sizeRiver+(y+12.29)*size), (7.33*sizeRiver+(x+14.9)*size), (1.89*sizeRiver+(y+12.29)*size));
            txLine((7.33*sizeRiver+(x+14.9)*size), (1.89*sizeRiver+(y+12.29)*size), (7.5*sizeRiver+(x+14.9)*size), (1.89*sizeRiver+(y+12.29)*size));
            txLine((7.5*sizeRiver+(x+14.9)*size), (1.89*sizeRiver+(y+12.29)*size), (7.75*sizeRiver+(x+14.9)*size), (2.08*sizeRiver+(y+12.29)*size));
            txLine((7.75*sizeRiver+(x+14.9)*size), (2.08*sizeRiver+(y+12.29)*size), (7.98*sizeRiver+(x+14.9)*size), (2.26*sizeRiver+(y+12.29)*size));
            txLine((7.98*sizeRiver+(x+14.9)*size), (2.26*sizeRiver+(y+12.29)*size), (8.33*sizeRiver+(x+14.9)*size), (2.48*sizeRiver+(y+12.29)*size));
            txLine((8.33*sizeRiver+(x+14.9)*size), (2.48*sizeRiver+(y+12.29)*size), (9.28*sizeRiver+(x+14.9)*size), (3.19*sizeRiver+(y+12.29)*size));
            txLine((9.28*sizeRiver+(x+14.9)*size), (3.19*sizeRiver+(y+12.29)*size), (9.47*sizeRiver+(x+14.9)*size), (4.08*sizeRiver+(y+12.29)*size));
            txLine((9.47*sizeRiver+(x+14.9)*size), (4.08*sizeRiver+(y+12.29)*size), (9.27*sizeRiver+(x+14.9)*size), (4.79*sizeRiver+(y+12.29)*size));
            txLine((9.27*sizeRiver+(x+14.9)*size), (4.79*sizeRiver+(y+12.29)*size), (9.03*sizeRiver+(x+14.9)*size), (5.59*sizeRiver+(y+12.29)*size));
            txLine((9.03*sizeRiver+(x+14.9)*size), (5.59*sizeRiver+(y+12.29)*size), (8.73*sizeRiver+(x+14.9)*size), (6.56*sizeRiver+(y+12.29)*size));
            txLine((8.73*sizeRiver+(x+14.9)*size), (6.56*sizeRiver+(y+12.29)*size), (8.15*sizeRiver+(x+14.9)*size), (7.74*sizeRiver+(y+12.29)*size));
            txLine((8.15*sizeRiver+(x+14.9)*size), (7.74*sizeRiver+(y+12.29)*size), (8*sizeRiver+(x+14.9)*size), (7.91*sizeRiver+(y+12.29)*size));
            txLine((8*sizeRiver+(x+14.9)*size), (7.91*sizeRiver+(y+12.29)*size), (7.82*sizeRiver+(x+14.9)*size), (7.99*sizeRiver+(y+12.29)*size));
            txLine((7.82*sizeRiver+(x+14.9)*size), (7.99*sizeRiver+(y+12.29)*size), (7.72*sizeRiver+(x+14.9)*size), (8.01*sizeRiver+(y+12.29)*size));
            txLine((7.72*sizeRiver+(x+14.9)*size), (8.01*sizeRiver+(y+12.29)*size), (7.45*sizeRiver+(x+14.9)*size), (8.03*sizeRiver+(y+12.29)*size));
            txLine((7.45*sizeRiver+(x+14.9)*size), (8.03*sizeRiver+(y+12.29)*size), (6.93*sizeRiver+(x+14.9)*size), (7.99*sizeRiver+(y+12.29)*size));
            txLine((6.93*sizeRiver+(x+14.9)*size), (7.99*sizeRiver+(y+12.29)*size), (5.37*sizeRiver+(x+14.9)*size), (7.83*sizeRiver+(y+12.29)*size));
            txLine((5.37*sizeRiver+(x+14.9)*size), (7.83*sizeRiver+(y+12.29)*size), (5*sizeRiver+(x+14.9)*size), (7.73*sizeRiver+(y+12.29)*size));
            txLine((5*sizeRiver+(x+14.9)*size), (7.73*sizeRiver+(y+12.29)*size), (3.77*sizeRiver+(x+14.9)*size), (6.46*sizeRiver+(y+12.29)*size));
            txLine((3.77*sizeRiver+(x+14.9)*size), (6.46*sizeRiver+(y+12.29)*size), (2.85*sizeRiver+(x+14.9)*size), (5.51*sizeRiver+(y+12.29)*size));
            txLine((2.85*sizeRiver+(x+14.9)*size), (5.51*sizeRiver+(y+12.29)*size), (1.75*sizeRiver+(x+14.9)*size), (4.31*sizeRiver+(y+12.29)*size));
            txLine((1.75*sizeRiver+(x+14.9)*size), (4.31*sizeRiver+(y+12.29)*size), (1.63*sizeRiver+(x+14.9)*size), (4.06*sizeRiver+(y+12.29)*size));
            txLine((1.63*sizeRiver+(x+14.9)*size), (4.06*sizeRiver+(y+12.29)*size), (1.48*sizeRiver+(x+14.9)*size), (3.89*sizeRiver+(y+12.29)*size));
            txLine((1.48*sizeRiver+(x+14.9)*size), (3.89*sizeRiver+(y+12.29)*size), (1.08*sizeRiver+(x+14.9)*size), (3.61*sizeRiver+(y+12.29)*size));
            txLine((1.08*sizeRiver+(x+14.9)*size), (3.61*sizeRiver+(y+12.29)*size), (-0.78*sizeRiver+(x+14.9)*size), (1.64*sizeRiver+(y+12.29)*size));
            txLine((-0.78*sizeRiver+(x+14.9)*size), (1.64*sizeRiver+(y+12.29)*size), (-1.33*sizeRiver+(x+14.9)*size), (1.18*sizeRiver+(y+12.29)*size));
            txLine((-1.33*sizeRiver+(x+14.9)*size), (1.18*sizeRiver+(y+12.29)*size), (-5.87*sizeRiver+(x+14.9)*size), (-3.54*sizeRiver+(y+12.29)*size));
            txLine((-5.87*sizeRiver+(x+14.9)*size), (-3.54*sizeRiver+(y+12.29)*size), (-6.13*sizeRiver+(x+14.9)*size), (-3.91*sizeRiver+(y+12.29)*size));
            txLine((-6.13*sizeRiver+(x+14.9)*size), (-3.91*sizeRiver+(y+12.29)*size), (-6.38*sizeRiver+(x+14.9)*size), (-4.16*sizeRiver+(y+12.29)*size));
            txLine((-6.38*sizeRiver+(x+14.9)*size), (-4.16*sizeRiver+(y+12.29)*size), (-9.32*sizeRiver+(x+14.9)*size), (-7.14*sizeRiver+(y+12.29)*size));
            txLine((-9.32*sizeRiver+(x+14.9)*size), (-7.14*sizeRiver+(y+12.29)*size), (-9.45*sizeRiver+(x+14.9)*size), (-7.49*sizeRiver+(y+12.29)*size));
        }


        if (dire == true)
        {
            txLine((-2.65*sizeDire+(x+19.95)*size), (-1.2*sizeDire+(y+6.6)*size), (-2.53*sizeDire+(x+19.95)*size), (-1.03*sizeDire+(y+6.6)*size));
            txLine((-2.53*sizeDire+(x+19.95)*size), (-1.03*sizeDire+(y+6.6)*size), (-2.23*sizeDire+(x+19.95)*size), (-0.82*sizeDire+(y+6.6)*size));
            txLine((-2.23*sizeDire+(x+19.95)*size), (-0.82*sizeDire+(y+6.6)*size), (-1.95*sizeDire+(x+19.95)*size), (-0.57*sizeDire+(y+6.6)*size));
            txLine((-1.95*sizeDire+(x+19.95)*size), (-0.57*sizeDire+(y+6.6)*size), (-1.7*sizeDire+(x+19.95)*size), (-0.4*sizeDire+(y+6.6)*size));
            txLine((-1.7*sizeDire+(x+19.95)*size), (-0.4*sizeDire+(y+6.6)*size), (-0.85*sizeDire+(x+19.95)*size), (0.32*sizeDire+(y+6.6)*size));
            txLine((-0.85*sizeDire+(x+19.95)*size), (0.32*sizeDire+(y+6.6)*size), (-0.22*sizeDire+(x+19.95)*size), (0.73*sizeDire+(y+6.6)*size));
            txLine((-0.22*sizeDire+(x+19.95)*size), (0.73*sizeDire+(y+6.6)*size), (0.18*sizeDire+(x+19.95)*size), (1.08*sizeDire+(y+6.6)*size));
            txLine((0.18*sizeDire+(x+19.95)*size), (1.08*sizeDire+(y+6.6)*size), (1.35*sizeDire+(x+19.95)*size), (1.83*sizeDire+(y+6.6)*size));     //dire
            txLine((1.35*sizeDire+(x+19.95)*size), (1.83*sizeDire+(y+6.6)*size), (1.68*sizeDire+(x+19.95)*size), (2.15*sizeDire+(y+6.6)*size));
            txLine((1.68*sizeDire+(x+19.95)*size), (2.15*sizeDire+(y+6.6)*size), (1.92*sizeDire+(x+19.95)*size), (2.22*sizeDire+(y+6.6)*size));
            txLine((1.92*sizeDire+(x+19.95)*size), (2.22*sizeDire+(y+6.6)*size), (2.1*sizeDire+(x+19.95)*size), (2.22*sizeDire+(y+6.6)*size));
            txLine((2.1*sizeDire+(x+19.95)*size), (2.22*sizeDire+(y+6.6)*size), (2.22*sizeDire+(x+19.95)*size), (2.13*sizeDire+(y+6.6)*size));
            txLine((2.22*sizeDire+(x+19.95)*size), (2.13*sizeDire+(y+6.6)*size), (2.27*sizeDire+(x+19.95)*size), (1.98*sizeDire+(y+6.6)*size));
            txLine((2.27*sizeDire+(x+19.95)*size), (1.98*sizeDire+(y+6.6)*size), (2.32*sizeDire+(x+19.95)*size), (1.25*sizeDire+(y+6.6)*size));
            txLine((2.32*sizeDire+(x+19.95)*size), (1.25*sizeDire+(y+6.6)*size), (2.4*sizeDire+(x+19.95)*size), (0.7*sizeDire+(y+6.6)*size));
            txLine((2.4*sizeDire+(x+19.95)*size), (0.7*sizeDire+(y+6.6)*size), (2.67*sizeDire+(x+19.95)*size), (-0.22*sizeDire+(y+6.6)*size));
            txLine((2.67*sizeDire+(x+19.95)*size), (-0.22*sizeDire+(y+6.6)*size), (2.7*sizeDire+(x+19.95)*size), (-1.27*sizeDire+(y+6.6)*size));
            txLine((2.7*sizeDire+(x+19.95)*size), (-1.27*sizeDire+(y+6.6)*size), (2.47*sizeDire+(x+19.95)*size), (-1.4*sizeDire+(y+6.6)*size));
            txLine((2.47*sizeDire+(x+19.95)*size), (-1.4*sizeDire+(y+6.6)*size), (1.78*sizeDire+(x+19.95)*size), (-1.85*sizeDire+(y+6.6)*size));
            txLine((1.78*sizeDire+(x+19.95)*size), (-1.85*sizeDire+(y+6.6)*size), (1*sizeDire+(x+19.95)*size), (-2.23*sizeDire+(y+6.6)*size));
            txLine((1*sizeDire+(x+19.95)*size), (-2.23*sizeDire+(y+6.6)*size), (0.8*sizeDire+(x+19.95)*size), (-2.13*sizeDire+(y+6.6)*size));
            txLine((0.8*sizeDire+(x+19.95)*size), (-2.13*sizeDire+(y+6.6)*size), (0.42*sizeDire+(x+19.95)*size), (-2.02*sizeDire+(y+6.6)*size));
            txLine((0.42*sizeDire+(x+19.95)*size), (-2.02*sizeDire+(y+6.6)*size), (0.08*sizeDire+(x+19.95)*size), (-1.93*sizeDire+(y+6.6)*size));
            txLine((0.08*sizeDire+(x+19.95)*size), (-1.93*sizeDire+(y+6.6)*size), (-2.65*sizeDire+(x+19.95)*size), (-1.2*sizeDire+(y+6.6)*size));
        }



        if (radiant == true)
        {
            txLine((-1.67*sizeRadiant+(x+9)*size), (-2.88*sizeRadiant+(y+17.65)*size), (-0.58*sizeRadiant+(x+9)*size), (-1.87*sizeRadiant+(y+17.65)*size));
            txLine((-0.58*sizeRadiant+(x+9)*size), (-1.87*sizeRadiant+(y+17.65)*size), (0*sizeRadiant+(x+9)*size), (-1.32*sizeRadiant+(y+17.65)*size));
            txLine((0*sizeRadiant+(x+9)*size), (-1.32*sizeRadiant+(y+17.65)*size), (0.62*sizeRadiant+(x+9)*size), (-0.67*sizeRadiant+(y+17.65)*size));
            txLine((0.62*sizeRadiant+(x+9)*size), (-0.67*sizeRadiant+(y+17.65)*size), (2.97*sizeRadiant+(x+9)*size), (1.48*sizeRadiant+(y+17.65)*size));
            txLine((2.97*sizeRadiant+(x+9)*size), (1.48*sizeRadiant+(y+17.65)*size), (3.23*sizeRadiant+(x+9)*size), (1.78*sizeRadiant+(y+17.65)*size));
            txLine((3.23*sizeRadiant+(x+9)*size), (1.78*sizeRadiant+(y+17.65)*size), (3.22*sizeRadiant+(x+9)*size), (1.85*sizeRadiant+(y+17.65)*size));
            txLine((3.22*sizeRadiant+(x+9)*size), (1.85*sizeRadiant+(y+17.65)*size), (2.48*sizeRadiant+(x+9)*size), (2.1*sizeRadiant+(y+17.65)*size));
            txLine((2.48*sizeRadiant+(x+9)*size), (2.1*sizeRadiant+(y+17.65)*size), (2.2*sizeRadiant+(x+9)*size), (2.25*sizeRadiant+(y+17.65)*size));
            txLine((2.2*sizeRadiant+(x+9)*size), (2.25*sizeRadiant+(y+17.65)*size), (1.82*sizeRadiant+(x+9)*size), (2.37*sizeRadiant+(y+17.65)*size));
            txLine((1.82*sizeRadiant+(x+9)*size), (2.37*sizeRadiant+(y+17.65)*size), (1.53*sizeRadiant+(x+9)*size), (2.4*sizeRadiant+(y+17.65)*size));
            txLine((1.53*sizeRadiant+(x+9)*size), (2.4*sizeRadiant+(y+17.65)*size), (1.23*sizeRadiant+(x+9)*size), (2.47*sizeRadiant+(y+17.65)*size));
            txLine((1.23*sizeRadiant+(x+9)*size), (2.47*sizeRadiant+(y+17.65)*size), (1.03*sizeRadiant+(x+9)*size), (2.53*sizeRadiant+(y+17.65)*size));    //radiant
            txLine((1.03*sizeRadiant+(x+9)*size), (2.53*sizeRadiant+(y+17.65)*size), (0.57*sizeRadiant+(x+9)*size), (2.77*sizeRadiant+(y+17.65)*size));
            txLine((0.57*sizeRadiant+(x+9)*size), (2.77*sizeRadiant+(y+17.65)*size), (0.27*sizeRadiant+(x+9)*size), (2.85*sizeRadiant+(y+17.65)*size));
            txLine((0.27*sizeRadiant+(x+9)*size), (2.85*sizeRadiant+(y+17.65)*size), (-1.22*sizeRadiant+(x+9)*size), (2.85*sizeRadiant+(y+17.65)*size));
            txLine((-1.22*sizeRadiant+(x+9)*size), (2.85*sizeRadiant+(y+17.65)*size), (-2.25*sizeRadiant+(x+9)*size), (1.98*sizeRadiant+(y+17.65)*size));
            txLine((-2.25*sizeRadiant+(x+9)*size), (1.98*sizeRadiant+(y+17.65)*size), (-2.55*sizeRadiant+(x+9)*size), (1.8*sizeRadiant+(y+17.65)*size));
            txLine((-2.55*sizeRadiant+(x+9)*size), (1.8*sizeRadiant+(y+17.65)*size), (-2.68*sizeRadiant+(x+9)*size), (1.65*sizeRadiant+(y+17.65)*size));
            txLine((-2.68*sizeRadiant+(x+9)*size), (1.65*sizeRadiant+(y+17.65)*size), (-3.1*sizeRadiant+(x+9)*size), (1.4*sizeRadiant+(y+17.65)*size));
            txLine((-3.1*sizeRadiant+(x+9)*size), (1.4*sizeRadiant+(y+17.65)*size), (-3.18*sizeRadiant+(x+9)*size), (1.23*sizeRadiant+(y+17.65)*size));
            txLine((-3.18*sizeRadiant+(x+9)*size), (1.23*sizeRadiant+(y+17.65)*size), (-3.18*sizeRadiant+(x+9)*size), (0.63*sizeRadiant+(y+17.65)*size));
            txLine((-3.18*sizeRadiant+(x+9)*size), (0.63*sizeRadiant+(y+17.65)*size), (-2.87*sizeRadiant+(x+9)*size), (-0.02*sizeRadiant+(y+17.65)*size));
            txLine((-2.87*sizeRadiant+(x+9)*size), (-0.02*sizeRadiant+(y+17.65)*size), (-2.65*sizeRadiant+(x+9)*size), (-0.62*sizeRadiant+(y+17.65)*size));
            txLine((-2.65*sizeRadiant+(x+9)*size), (-0.62*sizeRadiant+(y+17.65)*size), (-2.13*sizeRadiant+(x+9)*size), (-1.82*sizeRadiant+(y+17.65)*size));
            txLine((-2.13*sizeRadiant+(x+9)*size), (-1.82*sizeRadiant+(y+17.65)*size), (-1.67*sizeRadiant+(x+9)*size), (-2.88*sizeRadiant+(y+17.65)*size));
        }
        if (letters == true)
        {
            txLine((2.7+x)*size, (5.9+y)*size, (2+x)*size, (5.8+y)*size);
            txLine((2+x)*size, (5.8+y)*size, (0.3+x)*size, (5.9+y)*size);
            txLine((0.3+x)*size, (5.9+y)*size, (0.3+x)*size, (7+y)*size);
            txLine((0.3+x)*size, (7+y)*size, (0.2+x)*size, (11+y)*size);//D
            txLine((0.2+x)*size, (11+y)*size, (0.1+x)*size, (17+y)*size);
            txLine((0.1+x)*size, (17+y)*size, (1.9+x)*size, (16.9+y)*size);
            txLine((1.9+x)*size, (16.9+y)*size, (2.8+x)*size, (16.7+y)*size);
            txLine((2.8+x)*size, (16.7+y)*size, (3.6+x)*size, (16.5+y)*size);

            txLine((2.8+x)*size, (7.6+y)*size, (1.8+x)*size, (7.5+y)*size);
            txLine((1.8+x)*size, (7.5+y)*size, (1.9+x)*size, (15.3+y)*size);//d
            txLine((1.9+x)*size, (15.3+y)*size, (2.6+x)*size, (15.2+y)*size);
            txLine((2.6+x)*size, (15.2+y)*size, (3+x)*size, (15.1+y)*size);

            txLine((8.8+x)*size, (16.1+y)*size, (9.1+x)*size, (16.6+y)*size);
            txLine((9.1+x)*size, (16.6+y)*size, (9.7+x)*size, (17+y)*size);//o underneath

            txLine((9.4+x)*size, (9.1+y)*size, (9.8+x)*size, (8.1+y)*size);
            txLine((9.8+x)*size, (8.1+y)*size, (10+x)*size, (7.5+y)*size);
            txLine((10+x)*size, (7.5+y)*size, (11.1+x)*size, (7.2+y)*size);
            txLine((11.1+x)*size, (7.2+y)*size, (11.6+x)*size, (7.3+y)*size);
            txLine((11.6+x)*size, (7.3+y)*size, (12+x)*size, (7.45+y)*size);
            txLine((12+x)*size, (7.45+y)*size, (12.8+x)*size, (8.2+y)*size);//o
            txLine((12.8+x)*size, (8.2+y)*size, (13.2+x)*size, (9.2+y)*size);
            txLine((13.2+x)*size, (9.2+y)*size, (13.3+x)*size, (10.8+y)*size);
            txLine((13.3+x)*size, (10.8+y)*size, (13.3+x)*size, (13.3+y)*size);

            txLine((8.4+x)*size, (8+y)*size, (9+x)*size, (6.4+y)*size);
            txLine((9+x)*size, (6.4+y)*size, (10+x)*size, (6.1+y)*size);
            txLine((14.2+x)*size, (8.8+y)*size, (14.6+x)*size, (11+y)*size);//O
            txLine((14.6+x)*size, (11+y)*size, (14.5+x)*size, (12.5+y)*size);
            txLine((14.5+x)*size, (12.5+y)*size, (14.4+x)*size, (14.2+y)*size);

            txLine((17.6+x)*size, (17.6+y)*size, (19.5+x)*size, (17.55+y)*size);
            txLine((19.5+x)*size, (17.55+y)*size, (19.55+x)*size, (17.1+y)*size);
            txLine((19.55+x)*size, (17.1+y)*size, (19+x)*size, (16.8+y)*size);
            txLine((19+x)*size, (16.8+y)*size, (18.8+x)*size, (16.4+y)*size);//t right
            txLine((18.8+x)*size, (16.4+y)*size, (18.7+x)*size, (15.8+y)*size);
            txLine((18.7+x)*size, (15.8+y)*size, (18.7+x)*size, (11.8+y)*size);

            txLine((17.1+x)*size, (17.1+y)*size, (17.4+x)*size, (16.9+y)*size);
            txLine((17.4+x)*size, (16.9+y)*size, (17.7+x)*size, (16.4+y)*size);
            txLine((17.7+x)*size, (16.4+y)*size, (17.8+x)*size, (11.1+y)*size);//t left

            txLine((17.35+x)*size, (5.5+y)*size, (19.9+x)*size, (5.55+y)*size);
            txLine((19.9+x)*size, (5.55+y)*size, (22+x)*size, (5.55+y)*size);
            txLine((22+x)*size, (5.55+y)*size, (22.1+x)*size, (5.5+y)*size);
            txLine((22.1+x)*size, (5.5+y)*size, (22.05+x)*size, (6.6+y)*size);
            txLine((22.05+x)*size, (6.6+y)*size, (22+x)*size, (6.55+y)*size);//t up
            txLine((22+x)*size, (6.55+y)*size, (18.9+x)*size, (6.6+y)*size);
            txLine((18.9+x)*size, (6.6+y)*size, (18.9+x)*size, (6.8+y)*size);

            txLine((22.5+x)*size, (14.3+y)*size, (20.7+x)*size, (17.5+y)*size);
            txLine((20.7+x)*size, (17.5+y)*size, (21.8+x)*size, (17.6+y)*size);
            txLine((21.8+x)*size, (17.6+y)*size, (23.3+x)*size, (14.8+y)*size);

            txLine((27.2+x)*size, (7.25+y)*size, (31+x)*size, (17.6+y)*size);
            txLine((31+x)*size, (17.6+y)*size, (29.8+x)*size, (17.6+y)*size);
            txLine((29.8+x)*size, (17.6+y)*size, (28.1+x)*size, (13+y)*size);
            txLine((28.1+x)*size, (13+y)*size, (26.85+x)*size, (13+y)*size);

            txLine((26.55+x)*size, (8.65+y)*size, (27.85+x)*size, (12+y)*size);
            txLine((27.85+x)*size, (12+y)*size, (26.9+x)*size, (12+y)*size);



        }
    }



//-----------------------------------------------------------------------------

    bool Swan(int x = 0, int y = 0, int size = 14, int col1 = 255, int col2 = 255, int col3 = 255, bool horrormode = false, int cluvcol1 = -1, int cluvcol2 = -1, int cluvcol3 = -1)
    {
        if (cluvcol1==-1) cluvcol1=col1;
        if (cluvcol2==-1) cluvcol2=col2;
        if (cluvcol3==-1) cluvcol3=col3;
        if (horrormode == false)
        {
            txSetColor(RGB(col1, col2, col3));
            txSetFillColor(TX_TRANSPARENT);
            txCircle((2.8+x)*size, (13+y)*size, 3.4*size);                //1

            txCircle((4.3+x)*size, (10+y)*size, 2.6*size);                //2



            txSetColor(TX_TRANSPARENT);
            txSetFillColor(DARKBLUEDREAM);
            txCircle((2.2+x)*size, (12.8+y)*size, 3.75*size);
            txCircle((2.8+x)*size, (13+y)*size, 3.4*size);
            txCircle((2.45+x)*size, (13.3+y)*size, 3.5*size);
            txCircle((6.5+x)*size, (9.3+y)*size, 1.77*size);
            txCircle((7.3+x)*size, (11.1+y)*size, 1.55*size);

            txSetColor(RGB(col1, col2, col3));
            txSetFillColor(TX_TRANSPARENT);
            txCircle((1+x)*size, (13.65+y)*size, 7.5*size);               //4
        }
        txSetColor(RGB(col1, col2, col3));
        txSetFillColor(TX_TRANSPARENT);
        txCircle((16.5+x)*size, (24.1+y)*size, 10.4*size);             //3

        txSetColor(DARKBLUEDREAM, 0.7*size);
        txSetFillColor(DARKBLUEDREAM);
        txLine((1+x)*size, (6+y)*size, (8.1+x)*size, (8+y)*size);
        txCircle((-4.4+x)*size, (8+y)*size, 6*size);
        txSetColor(DARKBLUEDREAM);
        txCircle((3+x)*size, (21+y)*size, 5*size);
        txCircle((-3+x)*size, (17+y)*size, 5*size);
        txCircle((25+x)*size, (25.7+y)*size, 10*size);
        txCircle((13.5+x)*size, (36.1+y)*size, 7.4*size);

        txSetColor(RGB(col1, col2, col3));
        txSetFillColor(TX_TRANSPARENT);
        txCircle((25+x)*size, (13.65+y)*size, 3.2*size);                //5
        txCircle((3.75+x)*size, (19.75+y)*size, 0.85*size);           //6

        txSetColor(DARKBLUEDREAM);
        txSetFillColor(DARKBLUEDREAM);
        txCircle((3.95+x)*size, (19.6+y)*size, 0.95*size);
        txCircle((9+x)*size, (19+y)*size, 2*size);
        txCircle((9+x)*size, (26+y)*size, 5*size);
        txCircle((25+x)*size, (13.1+y)*size, 3.55*size);

        if (horrormode == false)
        {
            txSetColor(RGB(cluvcol1, cluvcol2, cluvcol3));
            txLine((1.4+x)*size, (10.8+y)*size, (1.6+x)*size, (11.6+y)*size);
            txLine((1.6+x)*size, (11.6+y)*size, (1+x)*size, (13+y)*size);
            txLine((1+x)*size, (13+y)*size, (2.8+x)*size, (11.5+y)*size);
            txSetColor(RGB(col1, col2, col3));
            txLine((1.9+x)*size, (9+y)*size, (1.4+x)*size, (10.8+y)*size);
            txLine((2.8+x)*size, (11.5+y)*size, (5.1+x)*size, (10.5+y)*size);
            txLine((5.1+x)*size, (10.5+y)*size, (5.75+x)*size, (11.4+y)*size);
        }

        txSetColor(RGB(col1, col2, col3));
        txSetFillColor(TX_TRANSPARENT);

        txLine((5.2+x)*size, (15.3+y)*size, (3+x)*size, (19.3+y)*size);

        txLine((7+x)*size, (18+y)*size, (9+x)*size, (17+y)*size);

        txLine((27+x)*size, (16+y)*size, (28.8+x)*size, (14.5+y)*size);
        txLine((28.8+x)*size, (14.5+y)*size, (28.2+x)*size, (16.2+y)*size);
        txLine((28.2+x)*size, (16.2+y)*size, (26.5+x)*size, (17.9+y)*size);
        txLine((26.5+x)*size, (17.9+y)*size, (25+x)*size, (19.8+y)*size);
        txLine((25+x)*size, (19.8+y)*size, (21.2+x)*size, (20.5+y)*size);
        txLine((21.2+x)*size, (20.5+y)*size, (18.7+x)*size, (20.8+y)*size);
        txLine((18.7+x)*size, (20.8+y)*size, (15.6+x)*size, (21+y)*size);
        txLine((15.6+x)*size, (21+y)*size, (10+x)*size, (20.9+y)*size);
        txLine((10+x)*size, (20.9+y)*size, (5+x)*size, (20.6+y)*size);
        txLine((5+x)*size, (20.6+y)*size, (3.8+x)*size, (20.5+y)*size);
    }

//=============================================================================

    int main()
    {
        int x=0, y=0;
        int size=15;
        txCreateWindow(93*size, 63*size);
        txSetFillColor(DARKBLUEDREAM);
        txClear();

        Duf(x, y, size, true, true, true, true, false, true, true);
        Gnoiny(30+x, y, size);
        Bill(60+x, y, size);
        Swan(30+x, 30+y, size);
        Pokerface(x, 30+y, size);
        Dotalogo(60+x, 30+y, size);
        //Setka(size);
        return 0;
    }

