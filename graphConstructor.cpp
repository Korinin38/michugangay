    #include "TXLib.h"
    #include <string>
    #include <cmath>
    #include <sstream>
    using namespace std;

    void toMasOfChar(string s, char* c)
    {
        unsigned int i;
        for (i = 0; i < s.length()+5; i ++)
        {
            c[i]=s[i];
        }
        for (i = s.length(); i < s.length()*2; i ++)
        c[i]=' ';
    }

    string pointAfterZero(string s, int n)
    {
        char c=0;
        for (int i = 0; i < s.length(); i ++)
        {
            if (n==0) s.erase (i, s.length()-i+1);
            if (s[i]=='.')
            {
                c=1;
                if (n==1) s.erase (i, s.length()-i+1);
            }
            if (c) n--;
        }
        return s;
    }

    template<typename T>
    string toString(T value)
    {
        std:ostringstream oss;
        oss<<value;
        return oss.str();
    }

    void interfaceRound(int* r)
    {
        if (GetAsyncKeyState('0')) *r=0;
        if (GetAsyncKeyState('1')) *r=1;
        if (GetAsyncKeyState('2')) *r=2;
        if (GetAsyncKeyState('3')) *r=3;
        if (GetAsyncKeyState('4')) *r=4;
        if (GetAsyncKeyState('5')) *r=5;
        if (GetAsyncKeyState('6')) *r=6;
    }

    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter)
    {
        if (GetAsyncKeyState('V'))
        {
            *mapSize+=0.19;
        }
        if (GetAsyncKeyState('B'))
        {
            *mapSize-=0.19;
        }
        int x=0;
        if (GetAsyncKeyState(VK_SHIFT))     x=80;
        if (GetAsyncKeyState('P'))          x=4000;
        if (GetAsyncKeyState(VK_RIGHT))     *xOfCenter-=1+(int)(*mapSize/20)+x;
        if (GetAsyncKeyState(VK_LEFT))      *xOfCenter+=1+(int)(*mapSize/20)+x;
        if (GetAsyncKeyState(VK_DOWN))      *yOfCenter-=1+(int)(*mapSize/20)+x;
        if (GetAsyncKeyState(VK_UP))        *yOfCenter+=1+(int)(*mapSize/20)+x;
        if (GetAsyncKeyState('C'))         {*xOfCenter=400; *yOfCenter=300;}
        if (*mapSize<3) *mapSize=3;
        if (*mapSize>85) *mapSize=85;
    }

    bool ultimateCircleButtonInterface(int xCenter, int yCenter, int radius)
    {
        if ((txMouseX()-xCenter)*(txMouseX()-xCenter)+(txMouseY()-yCenter)*(txMouseY()-yCenter)<radius*radius)
            return 1;
        else return 0;
    }

    int chooseFigura()
    {
        if (txMouseX()>720 && txMouseY()>560 && txMouseButtons()&1)
        {
            int s=(txMouseY()-560)/20;
            return s;
        }
        else
        return -1;
    }

    int main()
    {
        txCreateWindow(800, 600);
        int xCenter=400,
            yCenter=300,
            figure=0,
            ff,
            debugVar,
            roundn=2;
        double mapSize=10,
               prX,
               prX1,
               prA=1,
               prB=0,
               prC=0,
               crX=0,
               crY=0,
               crR=1;
        bool mouseClickedV=0,
             mouseClickedO=0;
        string s;
        char c[100];
        txBegin();

        while (!GetAsyncKeyState(VK_ESCAPE))
        {
            txSetFillColor(TX_WHITE);
            txClear();
            interfaceRound(&roundn);
            interfaceOfMap(&mapSize, &xCenter, &yCenter);
            ff=chooseFigura();
            if (ff!=-1)
            {
                figure=ff;
                prA=1;
                prB=0;
                prC=0;
                crX=0;
                crY=0;
                crR=1;
            }
            txSetColor(TX_BLACK, 2);
            txLine(xCenter, 0, xCenter, 600);
            txLine(0, yCenter, 800, yCenter);
            txSetColor(TX_BLACK);
            for (int i = xCenter; i >= 0; i -=mapSize)
                txLine(i, 0, i, 600);
            for (int i = xCenter; i <= 800; i +=mapSize)
                txLine(i, 0, i, 600);
            for (int i = yCenter; i >= 0; i -=mapSize)
                txLine(0, i, 800, i);
            for (int i = yCenter; i <= 600; i +=mapSize)
                txLine(0, i, 800, i);
            txSelectFont("Arial", 10);
            txTextOut(xCenter-6, yCenter+2, "0");
            txTextOut(xCenter-6+mapSize, yCenter+2, "1");
            txTextOut(xCenter-6-mapSize, yCenter+2, "-1");
            txTextOut(xCenter-6, yCenter+2+mapSize, "1");
            txTextOut(xCenter-6, yCenter+2-mapSize, "-1");
            txRectangle(720, 560, 800, 600);
            txRectangle(720, 560, 800, 580);
            txSelectFont("Arial", 20);
            txDrawText (720, 560, 800, 580, "Parabola");
            txDrawText (720, 580, 800, 600, "Circleola");
            txSetColor(TX_BLACK, 3);
            prX = -xCenter/mapSize;
            switch(figure)
            {
                case 0:
                    for (int i = 1; i <=800; i ++)
                    {
                        prX1 = (i-xCenter)/mapSize;
                        txLine(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, xCenter+prX1*mapSize, yCenter-(prA*prX1*prX1+prB*prX1+prC)*mapSize);
                        prX=prX1;
                    }
                    prX=-prB/(2*prA);
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);
                    txCircle(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, 5);
                    if (ultimateCircleButtonInterface(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, 5) && txMouseButtons()&1 || (mouseClickedV==true &&mouseClickedO==false))
                    {
                        mouseClickedV=true;
                        prB=-(txMouseX()-xCenter)/mapSize*2*prA;
                        prC=-prA*prX*prX-prB*prX-(txMouseY()-yCenter)/mapSize;
                        if (!txMouseButtons()&1) mouseClickedV=false;
                    }

                    txCircle(xCenter+prX*mapSize, yCenter-(prA*(prX+1)*(prX+1)+prB*(prX+1)+prC)*mapSize, 5);
                    if (ultimateCircleButtonInterface(xCenter+prX*mapSize, yCenter-(prA*(prX+1)*(prX+1)+prB*(prX+1)+prC)*mapSize, 5) && txMouseButtons()&1 || mouseClickedO==true)
                    {
                        mouseClickedO=true;
                        if (abs(txMouseY()-yCenter-(prA*prX*prX+prB*prX+prC)*mapSize)<0.0001) prA=0.0000001;
                        else prA=(yCenter-(prA*prX*prX+prB*prX+prC)*mapSize-txMouseY())/mapSize;
                        if (!txMouseButtons()&1) mouseClickedO=false;
                    }

                    s="y=";
                    if (prA!=1) s+=pointAfterZero(toString(prA), roundn+1);
                    s+="x^2";
                    if (prB>0)  s+="+"+pointAfterZero(toString(prB), roundn+1)+"x";
                    else if (prB<0) s+=pointAfterZero(toString(prB), roundn+1)+"x";
                    if (prC>0)  s+="+"+pointAfterZero(toString(prC), roundn+1);
                    else if (prC<0) s+=pointAfterZero(toString(prC), roundn+1);
                    toMasOfChar(s, c);
                    txRectangle(0, 580, s.length()*10, 600);
                    txDrawText(0, 580, s.length()*10, 600, c, DT_LEFT);
                    break;
                case 1:
                    txSetFillColor(TX_NULL);
                    txCircle(xCenter+crX, yCenter-crY, crR*mapSize);
                    break;
            }
            txSleep(1);
        }
    }
