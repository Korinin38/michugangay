	#include "TXlib.h"
	using namespace std;
//!@brief CONST COLORREF  MYOWN_COLOR1 = TX_BLACK
//! just ����

//!@brief CONST COLORREF  MYOWN_COLOR2 = TX_WHITE
//! just ����

//!@brief void LogoPS(bool)
//! �������, �������� ��� ����
//!@param stage - ������ ����:
//!               0: ��� ��� ���� ��������
//!               1: ��� ��� ����� ����������

//!@brief void Ryab(int x=1000, int y=600, int r=3)
//! ������ ������ ���� � ����
//!@param x - (�� ��������� 1000) x-������ ����
//!@param y - (�� ��������� 600) y-������ ����
//!@param r - (�� ��������� 3) ������ ������� (��-��)

//!@brief void Ogr(int x, int y)
//! Just Ogr � �����������
//!@param x - (�� ��������� 0) x-���������� ������ ���������
//!@param y - (�� ��������� 0) y-���������� ������ ���������

//!@brief void Wall(int a, bool z)
//! ������ ������������ ����� � ����
//!@param a - ����� ������ ������������ �� �����������
//!@param z - ������������ ������ ��������� �����

//!@brief void PudgMovie(int x = 0, int y = 0, int size = 14, bool knifeistoobad = false, bool needbetterknife = false, bool needcolor = true)
//! ��� ������ (���������� ����������)
//!@param x - (�� ��������� 0) x-���������� ������ ���������
//!@param y - (�� ��������� 0) y-���������� ������ ���������
//!@param size - (�� ��������� 14) ������ �����. 5 ��� ���������
//!@param knifeistoobad - (�� ��������� false) ������������� "�� ����� ����������"
//!@param needbetterknife - (�� ��������� false) ������������� "����� �������� �����". �������� ������ ��� �������� knifeistoobad == true
//!@param needcolor - (�� ��������� true) ������������� "�� �����-�� ������ ��� ��"

//!@brief void Hook(int x, int y, double z)
//! ������ ����� ���� ���
//!@param x - x-���������� ������ ���������
//!@param y - y-���������� ������ ���������
//!@param z - ������ ����

//!@brief void Setka(float size, int right = 0, int down = 0)
//! ���������� ��� ����� ������� ��������� - �����
//!@param size - ������ �����
//!@param right - �������� ����� ������ �� * ��������
//!@param down - �������� ����� ���� �� * ��������

//!@brief void ArrowToBeContinued(int x)
//! �� ����� ����������� ���������. ��������� �� ���������� y �� �������������
//!@param x - (�� ��������� 0) x-���������� ������ ���������
//!@param y - (�� ��������� 0) y-���������� ������ ���������

//!@brief void ToBeContinued()
//! ������� ������� ���� (�����) ����������������� �������, ��������� ����������





    CONST COLORREF  MYOWN_COLOR1 = TX_BLACK,
                    MYOWN_COLOR2 = TX_WHITE;

    COLORREF        OGRBLU = RGB(106, 150, 232),
                    OGRHAT = RGB(126, 98, 10),
                    OGRCLOAK = RGB(158, 108, 75),
                    WALLFILL=RGB(200, 200, 200),
                    DARKBLUEDREAM = RGB (0, 78, 156);



    CONST COLORREF SKINCOLOR = RGB (210, 240, 176);
    COLORREF COLDBLADE = RGB (220, 220, 220);
    CONST COLORREF DARKGREEN = RGB (0, 100, 52);
    CONST COLORREF SKINCOLOR1 = RGB (150, 180, 116);
    CONST COLORREF BILLYELLOW = RGB (255, 255, 0);
    CONST COLORREF BILLGREY = RGB (160, 152, 52);


	void LogoPS(bool stage, int x=1000, int y=600);
    void ToBeContinued();
    void Ryab(int x=1000, int y=600, int r=3);
    void Ogr(int x=0, int y=0);
    void Wall(int, bool z=0);
    void PudgMovie(int x = 0, int y = 0, int size = 14, bool knifeistoobad = false, bool needbetterknife = false, bool needcolor = true);
    void Hook(int, int, double);
    void ArrowToBeContinued(int x=0, int y=0);


	void LogoPS(bool stage, int x, int y)
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
                txCircle (x/2, y/2, y/4);
                if (i>0)
                {
                    txSetColor(MYOWN_COLOR1, 3);
                    txSetFillColor(TX_TRANSPARENT);
                    txCircle(x*0.47, y*0.58, 2);
                    txCircle(x*0.58, y*0.58, 2);
                    txLine(x*0.43, y*0.58333, x*0.43, y*0.375);
                    txArc(x*0.481, y/2, x*0.381, y*0.375, -90, 180);

                    txArc(x/2, y*0.47833, x*0.6, y*0.37833, 50, 210);
                    txArc(x*0.48, y*0.475, x*0.58, y*0.58333, 225, 215);

                    txSetColor(MYOWN_COLOR1, 3);
                    txSetTextAlign(TA_CENTER);
                    txSelectFont("Comic Sans MS", 40, 12, false, true, false, false, 10);
                    switch (i)
                    {
                        case 4:
                            txTextOut(x/2-5, y*19/30, "p");
                            break;
                        case 5:
                            txTextOut(x/2-5, y*19/30, "pr");
                            break;
                        case 6:
                            txTextOut(x/2-5, y*19/30, "pre");
                            break;
                        case 7:
                            txTextOut(x/2-5, y*19/30, "pres");
                            break;
                        case 8:
                            txTextOut(x/2-5, y*19/30, "prese");
                            break;
                        case 9:
                            txTextOut(x/2-5, y*19/30, "presen");
                            break;
                        case 10:
                            txTextOut(x/2-5, y*19/30, "present");
                            break;
                    }
                    if (i>10) txTextOut(x/2-5, y*19/30, "presents");
                }
                txSleep(100);
            }
            txPlaySound(NULL);
        }
        else
        {
            txPlaySound("logo.wav");
            txSetColor(TX_WHITE, 3);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_WHITE);
            txLine(x/2, y/2-1, x/2, y/2+1);
            for (i=2; i<y*16/75;)
            {
                txLine(x/2, y/2-1-i, x/2, y/2+1+i);
                i+=i-1;
                txSleep(60);
            }
            txLine(x/2, y*31/100, x/2, y*69/100);
            txSleep(60);
            txLine(x/2, y*27/100, x/2, y*73/100);
            txSleep(60);
            txLine(x/2, y/4, x/2, y*3/4);
            txSleep(400);
            int ugol;
            txPie(x/2-y/4, y/4, x/2+y/4, y*3/4, 90, 1);
            txPie(x/2-y/4, y/4, x/2+y/4, y*3/4, 270, 1);
            for (ugol=2; ugol<=129;)
            {
                txPie(x/2-y/4+1, y/4+1, x/2+y/4-1, y*3/4-1, 90, ugol);
                txPie(x/2-y/4+1, y/4+1, x/2+y/4-1, y*3/4-1, 270, ugol);
                ugol+=ugol-1;
                txSleep(60);
            }
            for (ugol=176; ugol<180;)
            {
                txPie(x/2-y/4+1, y/4+1, x/2+y/4-1, y*3/4-1, 90, ugol);
                txPie(x/2-y/4+1, y/4+1, x/2+y/4-1, y*3/4-1, 270, ugol);
                ugol+=(180-ugol)/1.7;
                if (ugol>178) ugol=180;
                txSleep(60);
            }
        }
    }


//-----------------------------------------------------------------------------

    void Ryab(int x, int y, int r)
    {
        COLORREF kek;
	txPlaySound("ryab.wav");
        int a[3];
        for (int i = 0; i<10; i++)
        {


            for (int j=0; j<x; j+=r)
            {
                for (int k=0; k<y; k+=r)
                    {
                        a[0]=rand()%16*15;
                        a[1]=rand()%16*15;
                        a[2]=rand()%16*15;
                        kek=RGB(a[0],a[1],a[2]);
                        txSetColor(kek);
                        txSetFillColor(kek);
                        txRectangle(j,k,j+r,k+r);
                    }
            }
            txSleep(20);
        }
	txPlaySound(NULL);
    }

//-----------------------------------------------------------------------------

    void ToBeContinued()
    {
        txSetColor(WALLFILL);
        txSetFillColor(WALLFILL);
        int x, y;
        for(int i = 0; i<4; i++)
        {
            for(int q = 0; q<24; q++)
            {
                txSetFillColor(WALLFILL);
                txClear();
                Wall(q);
                if (q<18) x=50+2*q, y=270-4*q;
                else x=86-(q-18)*5, y=198+(q-18)*10;
                Ogr(x, y);
		if (q==16&&i==1) txPlaySound ("SHORT VERSION - ROUNDABOUT.wav");
                txSleep(40);
            }
        }

        for (int i = 0; i < 12; i++)
        {
            if (i==11)
            {
                OGRBLU = RGB(140, 151, 135);
                OGRCLOAK = RGB(191, 109, 0);
                WALLFILL = RGB(234, 201, 104);
                OGRHAT = RGB(161, 99, 0);
                DARKBLUEDREAM = RGB (34, 79, 59);
                txSetFillColor(WALLFILL);
                txClear();
                Wall(i, 1);
                if (i<18) x=50+2*i, y=270-4*i;
                else x=86-(i-18)*5, y=198+(i-18)*10;
                Ogr(x, y);
                ArrowToBeContinued(100, 500);
                txSleep(5600);
            }
            txSetFillColor(WALLFILL);
            txClear();
            Wall(i, 1);
            if (i<18) x=50+2*i, y=270-4*i;
            else x=86-(i-18)*5, y=198+(i-18)*10;
            Ogr(x, y);
            ArrowToBeContinued(2300-i*200, 500);
            txSleep(40);
        }
        txPlaySound (NULL);
    }

//-----------------------------------------------------------------------------

    void Ogr(int x, int y)
    {
        txSetColor(TX_TRANSPARENT);
        txSetFillColor(OGRBLU);
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
        txSetFillColour(OGRCLOAK);
        txPolygon(cloak, 25);
        txSetFillColour(OGRHAT);
        txPolygon(head, 22);
        txSetColor(TX_BLACK,2);
        txLine(353+x, 82+y, 306+x, 32+y);
        txLine(353+x, 82+y, 308+x, 31+y);
        txLine(353+x, 82+y, 312+x, 32+y);
        txLine(353+x, 82+y, 312+x, 29+y);
        txLine(353+x, 82+y, 314+x, 31+y);
        txLine(358+x, 76+y, 314+x, 31+y);
        txLine(358+x, 76+y, 322+x, 31+y);
        txLine(358+x, 76+y, 323+x, 23+y);
        txLine(358+x, 76+y, 325+x, 22+y);
        txLine(358+x, 76+y, 334+x, 30+y);
        txLine(363+x, 72+y, 313+x, 29+y);
        txLine(363+x, 72+y, 322+x, 22+y);
        txLine(363+x, 72+y, 338+x, 17+y);
        txLine(363+x, 72+y, 343+x, 16+y);
        txLine(363+x, 72+y, 347+x, 15+y);
        txLine(363+x, 72+y, 354+x, 12+y);
    }

//-----------------------------------------------------------------------------

    void Wall(int a, bool z)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        for (int i=0; i<950 ; i+=40)
            {
                txLine(0, i, 1000, i-350);
                for (int j=0; j<8000; j+=100)
                {
                    txLine(j+(i/40%2)*50-a*20, i-j/100*35-(i/40%2)*18+a*7, j+(i/40%2)*50-a*20, i-j/100*35-40-(i/40%2)*18+a*7);
                }
            }
        if (z==1) {txSetColor(TX_BLACK); txSetFillColor(DARKBLUEDREAM); txRectangle(1000-a*46, -1, 1000, 601); PudgMovie(1000-a*35, 70, 12); Hook(1275-a*35, 147, a+3);}
    }

//-----------------------------------------------------------------------------

    void PudgMovie(int x, int y, int size, bool knifeistoobad, bool needbetterknife, bool needcolor)
    {
        txSetFillColor(SKINCOLOR);
        txSetColor (SKINCOLOR);
        POINT rightarm[12]={{(15)*size+x, (3)*size+y}, {(10)*size+x, (3)*size+y}, {(9)*size+x, (5)*size+y}, {(8)*size+x, (6)*size+y}, {(7)*size+x, (6)*size+y}, {(6)*size+x, (8)*size+y}, {(5)*size+x, (10)*size+y}, {(5.5)*size+x, (11)*size+y}, {(7)*size+x, (11)*size+y}, {(7)*size+x, (10)*size+y}, {(8)*size+x, (8)*size+y}, {(12)*size+x, (7)*size+y}};
        txPolygon(rightarm, 12);
        POINT leftarm[9]{{(19.7)*size+x, (3)*size+y}, {(20)*size+x, (3)*size+y}, {(24)*size+x, (4)*size+y}, {(25)*size+x, (7)*size+y}, {(24)*size+x, (8)*size+y}, {(23)*size+x, (8.5)*size+y}, {(21.5)*size+x, (8.5)*size+y}, {(21.5)*size+x, (6)*size+y}, {(20)*size+x, (5)*size+y}};
        txPolygon(leftarm, 9);
        txSetColor (DARKGREEN);
        txSetFillColor (DARKGREEN);
        POINT rightleg[8]={{(11)*size+x, (14)*size+y}, {(10)*size+x, (15)*size+y}, {(10)*size+x, (18)*size+y}, {(9)*size+x, (19)*size+y}, {(9.1)*size+x, (20)*size+y}, {(11)*size+x, (20)*size+y}, {(12.75)*size+x, (18)*size+y}, {(14)*size+x, (10)*size+y}};
        txPolygon(rightleg, 8);
        POINT leftleg[8]={{(20.3)*size+x, (17.4)*size+y}, {(20.5)*size+x, (19)*size+y}, {(22)*size+x, (20)*size+y}, {(24.6)*size+x, (20)*size+y}, {(24.6)*size+x, (19.3)*size+y}, {(24)*size+x, (19)*size+y}, {(23)*size+x, (15)*size+y}, {(21)*size+x, (11)*size+y}};
        txPolygon(leftleg, 8);

        if (knifeistoobad==false)
        {
            txSetColor (COLDBLADE, 3);
            txLine ((6)*size+x, (10.3)*size+y, (3.5)*size+x, (14.7)*size+y);           //butcher's knife
            txSetColor (COLDBLADE, 5);
            txLine ((5)*size+x, (12.05)*size+y, (3.5)*size+x, (14.7)*size+y);
        }
        else if (needbetterknife == true)
        {

            txSetColor (COLDBLADE, 3);
            txLine((5)*size+x, (12)*size+y, (3.5)*size+x, (14.7)*size+y);
            txLine ((3.5)*size+x, (14.7)*size+y, (4.6)*size+x, (15.4)*size+y);
            txLine ((4.6)*size+x, (15.4)*size+y, (6.1)*size+x, (13)*size+y);
            txLine ((6.1)*size+x, (13)*size+y, (4.9)*size+x, (12.2)*size+y);
            txSetColor (BILLGREY, 5);
            txLine ((6)*size+x, (10.3)*size+y, (5)*size+x, (12)*size+y);

        }



        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        POINT apron[6]={{(12)*size+x, (14.5)*size+y}, {(13)*size+x, (19)*size+y}, {(22)*size+x, (17)*size+y}, {(21)*size+x, (16)*size+y}, {(21.7)*size+x, (15.3)*size+y}, {(20)*size+x, (14.5)*size+y}};
        txPolygon(apron, 6);

        txSetColor (SKINCOLOR1 );
        txSetFillColor (TX_TRANSPARENT);
        if (needcolor==true) txSetFillColor(SKINCOLOR);
        txCircle ((16)*size+x, (9)*size+y, 7*size);                     //body of Duf

        txPolygon(leftarm, 9);
        txSetColor (SKINCOLOR1);
        txSetFillColor (DARKBLUEDREAM);
        txCircle ((14)*size+x, (5)*size+y, 2*size);
        txSetColor (TX_WHITE);                         //head of Duf
        txSetFillColor (TX_WHITE);
        txCircle ((13)*size+x, (4.5)*size+y, 0.3*size);
        txCircle ((14.5)*size+x, (4.5)*size+y, 0.3*size);
    }

//-----------------------------------------------------------------------------

    void Hook(int x, int y, double z)
    {
        txSetColor(COLDBLADE, z/6);
        txSetFillColor(TX_TRANSPARENT);
        txLine(x-z*0.4472, y+z*0.89442, x-z, y+z*2);
        for (int i=3; i<20; i+=3)
        {
            txCircle(x-z*i/2, y+z*i, z+1);
            txLine(x-z*(i+0.89442)/2, y+z*(i+0.89442), x-z*(i+2)/2, y+z*(i+2));
        }
        txSetColor(COLDBLADE, z/3);
        txArc(x-22*z, y+19.5*z, x-5*z, y+30*z, 200, 212);
    }

//-----------------------------------------------------------------------------

    void Setka(float size, int right = 0, int down = 0)
    {
        txSetColor (TX_WHITE, 1);
        for (int i = 1; i<60; i++)
        {
            txLine (i*size+right, 0+down, i*size+right, 60*size+down);
            txLine (0+right, i*size+down, 60*size+right, i*size+down);
        }
    }

//-----------------------------------------------------------------------------

    void ArrowToBeContinued(int x, int y)
    {
        txSetColor(COLDBLADE, 2);
        txSetFillColor(TX_BLACK);
        POINT arrow[7] = {{0+x, 40+y},{40+x, y}, {40+x, 20+y}, {288+x, 20+y}, {288+x, 60+y}, {40+x, 60+y}, {40+x, 80+y}};
        POINT tri1[3] = {{300+x, 22+y}, {300+x, 60+y}, {320+x, 60+y}};
        POINT tri2[3] = {{310+x, 20+y}, {332+x, 20+y}, {332+x, 60+y}};
        POINT tri3[3] = {{338+x, 20+y}, {338+x, 56+y}, {356+x, 20+y}};
        txPolygon(arrow, 7);
        txPolygon(tri1, 3);
        txPolygon(tri2, 3);
        txPolygon(tri3, 3);
        txSelectFont("Comic Sans MS", 30, 12);
        txSetTextAlign(TA_LEFT);
        txTextOut(64+x, 25+y, "To Be Continued");
}
