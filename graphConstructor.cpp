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

    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter, int xWindowSize, int yWindowSize)
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
        if (GetAsyncKeyState('C'))         {*xOfCenter=xWindowSize/2; *yOfCenter=yWindowSize/2;}
        if (*mapSize<3) *mapSize=3;
        if (*mapSize>85) *mapSize=85;
    }

    bool ultimateCircleButtonInterface(int xCenter, int yCenter, int radius)
    {
        if ((txMouseX()-xCenter)*(txMouseX()-xCenter)+(txMouseY()-yCenter)*(txMouseY()-yCenter)<radius*radius)
            return 1;
        else return 0;
    }

    int chooseFigura(int xWindowSize, int yWindowSize)
    {
        if (txMouseX()>(xWindowSize-80) && txMouseY()>(yWindowSize-60) && txMouseButtons()&1)
        {
            int s=(txMouseY()-(yWindowSize-60))/20;
            return s;
        }
        else
        return -1;
    }

    int main()
    {
        int xWindowSize=1200,
            yWindowSize=800,
            xCenter=xWindowSize/2,
            yCenter=yWindowSize/2,
            figure=0,
            ff,
            roundn=2;
        double mapSize=60,
               prX,
               prX1,
               prA=1,
               prB=0,
               prC=0,
               crX=0,
               crY=0,
               crBx=0,
               crBy=0,
               sinX,
               sinX1,
               sinA=1,
               sinB=0,
               sinT=1,
               debugVar,
               crR=1;
        bool mouseClickedV=0,
             mouseClickedO=0,
             mouseClickedU=0;
        string s;
        char c[100];
        txCreateWindow(xWindowSize, yWindowSize);
        txBegin();

        while (!GetAsyncKeyState(VK_ESCAPE))
        {
            txSetFillColor(TX_WHITE);
            txClear();
            interfaceRound(&roundn);
            interfaceOfMap(&mapSize, &xCenter, &yCenter, xWindowSize, yWindowSize);
            if (!mouseClickedV && !mouseClickedO) ff=chooseFigura(xWindowSize, yWindowSize);
            if (ff!=-1 || GetAsyncKeyState('R'))
            {
                if (ff>-1)figure=ff;
                prA=1;
                prB=0;
                prC=0;
                crX=0;
                crY=0;
                crR=1;
                crBx=1;
                crBy=0;
                sinA=1;
                sinB=0;
                sinT=1;
            }
            txSetColor(TX_BLACK, 2);
            txLine(xCenter, 0, xCenter, yWindowSize);
            txLine(0, yCenter, xWindowSize, yCenter);
            txSetColor(TX_BLACK);
            if (figure==2)
            {
                for (int i = xCenter; i >= 0; i -=mapSize*M_PI/2)
                    txLine(i, 0, i, yWindowSize);
                for (int i = xCenter; i <= xWindowSize; i +=mapSize*M_PI/2)
                    txLine(i, 0, i, yWindowSize);
            }
            else
            {
                for (int i = xCenter; i >= 0; i -=mapSize)
                    txLine(i, 0, i, yWindowSize);
                for (int i = xCenter; i <= xWindowSize; i +=mapSize)
                    txLine(i, 0, i, yWindowSize);
            }
            for (int i = yCenter; i >= 0; i -=mapSize)
                txLine(0, i, xWindowSize, i);
            for (int i = yCenter; i <= yWindowSize; i +=mapSize)
                txLine(0, i, xWindowSize, i);


            txSelectFont("Arial", 10);
            txTextOut(xCenter-6, yCenter+2, "0");
            if (figure==2)
            {
                txSelectFont("Arial", 14);
                txTextOut(xCenter-10+mapSize*M_PI/2, yCenter+2, "pi");
                txTextOut(xCenter-14-mapSize*M_PI/2, yCenter+2, "-pi");
            }
            else
            {
                txSelectFont("Arial", 10);
                txTextOut(xCenter-6+mapSize, yCenter+2, "1");
                txTextOut(xCenter-6-mapSize, yCenter+2, "-1");
            }
            txSelectFont("Arial", 10);
            txTextOut(xCenter-6, yCenter+2-mapSize, "1");
            txTextOut(xCenter-6, yCenter+2+mapSize, "-1");
            txSetColor(TX_BLACK, 3);
            prX = -xCenter/mapSize;
            switch(figure)
            {
                case 0:
                    prX = -xCenter/mapSize;
                    for (int i = 1; i <=xWindowSize; i ++)
                    {
                        prX1 = (i-xCenter)/mapSize;
                        txLine(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, xCenter+prX1*mapSize, yCenter-(prA*prX1*prX1+prB*prX1+prC)*mapSize);
                        prX=prX1;
                    }
                    prX=-prB/(2*prA);
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);
                    txCircle(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, 5);
                    if ((ultimateCircleButtonInterface(xCenter+prX*mapSize, yCenter-(prA*prX*prX+prB*prX+prC)*mapSize, 5) && txMouseButtons()&1 || mouseClickedV) && !mouseClickedO)
                    {
                        mouseClickedV=true;
                        prB=-(txMouseX()-xCenter)/mapSize*2*prA;
                        prC=-prA*prX*prX-prB*prX-(txMouseY()-yCenter)/mapSize;
                        if (!txMouseButtons()&1) mouseClickedV=false;
                    }

                    debugVar=prA*prX*prX+prB*prX+prC;

                    txCircle(xCenter+prX*mapSize, yCenter-(prA*(prX+1)*(prX+1)+prB*(prX+1)+prC)*mapSize, 5);
                    if (ultimateCircleButtonInterface(xCenter+prX*mapSize, yCenter-(prA*(prX+1)*(prX+1)+prB*(prX+1)+prC)*mapSize, 5) && txMouseButtons()&1 || mouseClickedO)
                    {
                        mouseClickedO=true;
                        prA=(yCenter-debugVar*mapSize-txMouseY())/mapSize;
                        if (prA==0) prA=0.000001;
                        prB=-prX*2*prA;
                        prC=debugVar+prA*prX*prX;
                        mouseClickedV=false;
                        if (!txMouseButtons()&1) mouseClickedO=false;
                    }

                    s="y=";
                    if (prA!=1) s+=pointAfterZero(toString(prA), roundn+1);
                    s+="x^2";
                    if (prB==1)       s+="+x";
                    else if (prB==-1) s+="-x";
                    else if (prB>0)   s+="+"+pointAfterZero(toString(prB), roundn+1)+"x";
                    else if (prB<0)   s+=pointAfterZero(toString(prB), roundn+1)+"x";
                    if (prC>0)        s+="+"+pointAfterZero(toString(prC), roundn+1);
                    else if (prC<0)   s+=pointAfterZero(toString(prC), roundn+1);
                    toMasOfChar(s, c);
                    txRectangle(0, yWindowSize-20, s.length()*10, yWindowSize);
                    txSelectFont("Arial", 20);
                    txDrawText(0, yWindowSize-20, s.length()*10, yWindowSize, c, DT_LEFT);
                    break;
                case 1:
                    txSetFillColor(TX_NULL);
                    txCircle(xCenter+crX*mapSize, yCenter-crY*mapSize, crR*mapSize);

                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);

                    txCircle (xCenter+crX*mapSize, yCenter-crY*mapSize, 5);
                    if ((ultimateCircleButtonInterface(xCenter+crX*mapSize, yCenter-crY*mapSize, 5) && txMouseButtons() & 1 || mouseClickedO) && !mouseClickedV)
                    {
                        mouseClickedO=true;
                        crX = (txMouseX()-xCenter)/mapSize;
                        crY = -(txMouseY()-yCenter)/mapSize;
                        if (!txMouseButtons()&1) mouseClickedO=false;
                    }

                    txCircle (xCenter+(crBx+crX)*mapSize, yCenter-(crBy+crY)*mapSize, 5);
                    if (ultimateCircleButtonInterface(xCenter+(crBx+crX)*mapSize, yCenter-(crBy+crY)*mapSize, 5) && txMouseButtons() & 1 || mouseClickedV)
                    {
                        mouseClickedV=true;
                        crBx = (txMouseX()-xCenter)/mapSize-crX;
                        crBy = -(txMouseY()-yCenter)/mapSize-crY;
                        crR  = sqrt(crBx*crBx+crBy*crBy);
                        mouseClickedO=false;
                        if (!txMouseButtons()&1) mouseClickedV=false;
                    }

                    if (crX==0)       s="x^2";
                    else if (crX>0)   s="(x"+pointAfterZero(toString(-crX), roundn+1)+")^2";
                    else              s="(x+"+pointAfterZero(toString(-crX), roundn+1)+")^2";
                    if (crY==0)       s+="+y^2";
                    else if (crY>0)   s+="+(y"+pointAfterZero(toString(-crY), roundn+1)+")^2";
                    else              s+="+(y+"+pointAfterZero(toString(-crY), roundn+1)+")^2";
                    s+="="+pointAfterZero(toString(crR*crR), roundn+1);
                    toMasOfChar(s, c);
                    txRectangle(0, yWindowSize-20, s.length()*10, yWindowSize);
                    txSelectFont("Arial", 20);
                    txDrawText(0, yWindowSize-20, s.length()*10, yWindowSize, c, DT_LEFT);
                    break;
                case 2:
                    sinX = -xCenter/mapSize-sinB;
                    for (int i = 1; i <=xWindowSize; i ++)
                    {
                        sinX1 = (i-xCenter)/mapSize-sinB;
                        txLine(xCenter+(sinX+sinB)*mapSize, yCenter-sinA*sin(sinX/sinT*2)*mapSize, xCenter+(sinX1+sinB)*mapSize, yCenter-sinA*sin(sinX1/sinT*2)*mapSize);
                        sinX=sinX1;
                    }
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);
                    txCircle(xCenter+sinB*mapSize, yCenter, 5);
                    if ((ultimateCircleButtonInterface(xCenter+sinB*mapSize, yCenter, 5) && txMouseButtons() & 1 || mouseClickedO) && !mouseClickedV)
                    {
                        mouseClickedO=true;
                        sinB = (txMouseX()-xCenter)/mapSize;
                        while (sinB>M_PI) sinB-=M_PI*2;
                        while (sinB<-M_PI) sinB+=M_PI*2;
                        if (!txMouseButtons()&1) mouseClickedO=false;
                    }
                    txCircle(xCenter+(sinB+sinT*M_PI_2)*mapSize, yCenter, 5);
                    if ((ultimateCircleButtonInterface(xCenter+(sinB+sinT*M_PI_2)*mapSize, yCenter, 5)) && txMouseButtons() & 1 || mouseClickedV)
                    {
                        mouseClickedV=true;
                        sinT = ((txMouseX()-xCenter)/mapSize-sinB)/M_PI_2;
                        if (sinT <1.01 && sinT > 0.999) sinT=1;
                        if (sinT==0) sinT=0.000001;
                        mouseClickedO=false;
                        mouseClickedU=false;
                        if (!txMouseButtons()&1) mouseClickedV=false;
                    }
                    txCircle(xCenter+(sinB+sinT*M_PI_2/2)*mapSize, yCenter-sinA*mapSize, 5);
                    if ((ultimateCircleButtonInterface(xCenter+(sinB+sinT*M_PI_2/2)*mapSize, yCenter-sinA*mapSize, 5)) && txMouseButtons() & 1|| mouseClickedU)
                    {
                        mouseClickedU=true;
                        sinA = -(txMouseY()-yCenter)/mapSize;
                        mouseClickedO=false;
                        mouseClickedV=false;
                        if (!txMouseButtons()&1) mouseClickedU=false;
                    }
                    s="y=sin (";
                    if (sinT==1) s+="x";
                    else s+=pointAfterZero(toString(sinT), roundn)+"x";
                    if (sinB==0) s+=")";
                    else if (sinB>0) s+="+"+pointAfterZero(toString(sinB), roundn)+")";
                    else             s+=pointAfterZero(toString(sinB), roundn)+")";
                    toMasOfChar(s, c);
                    txRectangle(0, yWindowSize-20, s.length()*10, yWindowSize);
                    txSelectFont("Arial", 20);
                    txDrawText(0, yWindowSize-20, s.length()*10, yWindowSize, c, DT_LEFT);
                    break;
            }
            txSetColor(TX_BLACK);
            txSetFillColor(TX_WHITE);
            txRectangle(xWindowSize-80, yWindowSize-60, xWindowSize, yWindowSize);
            txRectangle(xWindowSize-80, yWindowSize-40, xWindowSize, yWindowSize-20);
            txSelectFont("Arial", 20);
            txDrawText (xWindowSize-80, yWindowSize-60, xWindowSize, yWindowSize-40, "Parabola");
            txDrawText (xWindowSize-80, yWindowSize-40, xWindowSize, yWindowSize-20, "Circleola");
            txDrawText (xWindowSize-80, yWindowSize-20, xWindowSize, yWindowSize, "Sinusoide");
            txSleep(1);
        }
    }
