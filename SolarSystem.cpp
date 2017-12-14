    #include "TXLib.h"

    void SolarSystem(double* a, int size = 15, int diff = 20, int x = 0, int y = 0, int angle = 0);

    int main()
    {
        txCreateWindow (1000, 800);
        txSetFillColor(TX_WHITE);
        txClear();
        double a[10]={109.2, 0.383, 0.95, 1, 0.532, 10.973, 9.14, 3.98, 3.86, 0.18};
        int i = 0;
        while (i<360)
        {
            SolarSystem(a, 2, 1, 300, 200, i);
            i++;
            txSleep(30);
        }
        return 0;
    }

    void SolarSystem(double* a, int size, int diff, int x, int y, int angle)
    {
        txSetFillColor(TX_WHITE);
        txClear();
        int r=255, g=255, b=0, x1=x, y1, x2;
        txSetColor(RGB(r, g, b));
        txSetFillColor(RGB(r, g, b));
        txCircle(x1*size, y*size, a[0]*size);
        for (int i = 1; i < 10; i++)
        {
            r=rand()%255;
            g=rand()%255;
            b=rand()%255;
            txSetColor(RGB(r, g, b));
            txSetFillColor(RGB(r, g, b));
            x1+=diff*2+a[i-1]+a[i];
            x2=(x1-x)*cos(-angle*M_PI/180)+x;
            y1=(x1-x)*sin(-angle*M_PI/180)+y;
            txCircle(x2*size, y1*size, a[i]*size);
        }
    }
