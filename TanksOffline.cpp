    #include "TXLib.h"
    #include <fstream>
    #include <string>
    using namespace std;

    int mapMas[1000][1000],
        tankAmount=2;

    struct tank{
        int x,
            y,
            statHealth,
            statHP,
            statAttack,
            statSpeed,
            statAim;
        COLORREF color;
    };


    //logic
    void mapInitializer(bool sav, int* mapDat1, int* mapDat2);
    bool correctMapChecker(bool onlyCheck, int mapDat1, int mapDat2);
    bool checkThisPoint(int n);
    bool mapSavedChecker();
    void mapBoundController(int* xOfCenter, int* yOfCenter, int mapDat1, int mapDat2, double mapSize, int xWindowSize, int yWindowSize);

    //interface
    void interfaceOfMap(double* mapSize, int* xOfCenter, int* yOfCenter);
    void interfaceTankMoveCheck(tank[], int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    bool secretFunction(int* ss);
    bool windowSizeChooseAndConfirmation(int* xWindowSize, int* yWindowSize);
    void changeResolution(int* xWindowSize, int* yWindowSize);

    //drawing
    void drawMap(int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawWelcome(int xWindowSize, int yWindowSize);
    void drawMapInit(int xWindowSize, int yWindowSize);
    void drawMapSaveFound(int xWindowSize, int yWindowSize);
    void drawMapGlowTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void drawMapLoad(int xWindowSize, int yWindowSize);
    void drawTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2);
    void Tank(int x, int y, float k, int pozition);
    void drawDefinitionChoose(int* xWindowSize, int* yWindowSize);
    void drawTankStat(tank t[], int tankAmount, int xWindowSize, int yWindowSize);


    int main()
    {
        double mapSize=15;

        int
            xWindowSize=1276,
            yWindowSize=800,
            xOfCenter=xWindowSize/2,
            yOfCenter=yWindowSize/2,
            mapDat1=30,
            mapDat2=30,
            po=0,
            pi=0;


        windowSizeChooseAndConfirmation(&xWindowSize, &yWindowSize);
        srand(time(NULL));
        txCreateWindow (xWindowSize, yWindowSize);
        xOfCenter=xWindowSize/2;
        yOfCenter=yWindowSize/2;
        drawWelcome(xWindowSize, yWindowSize);
        txSleep(1000);
        tank t[2];
        t[0].x=0;
        t[0].y=0;
        t[0].color=TX_BLUE;
        t[1].x=2;
        t[1].y=2;
        t[1].color=TX_RED;
        while(!GetAsyncKeyState(VK_ESCAPE)&&!GetAsyncKeyState(VK_F9))
        {
            drawMapInit(xWindowSize, yWindowSize);
            txSleep(500);
            bool counter=0, counterWhile=0;
            if (mapSavedChecker())
            {
                drawMapSaveFound(xWindowSize, yWindowSize);
                while (counterWhile==0)
                {
                    if (GetAsyncKeyState('Y'))
                    {
                        counter=1;
                        counterWhile=1;
                    }
                    if (GetAsyncKeyState('N'))
                    {
                        counter=0;
                        counterWhile=1;
                    }
                }
            }
            drawMapLoad(xWindowSize, yWindowSize);
            mapInitializer(counter, &mapDat1, &mapDat2);
            correctMapChecker(0, mapDat1, mapDat2);
            txSleep(1000);

            while (!GetAsyncKeyState(VK_ESCAPE)&&!GetAsyncKeyState(VK_F9)&&!GetAsyncKeyState('R'))
            {
                txSetFillColor(TX_WHITE);
                txClear();
                interfaceOfMap(&mapSize, &xOfCenter, &yOfCenter);
                drawMap(xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                interfaceTankMoveCheck(t, xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                Tank(xOfCenter-mapDat1*mapSize, yOfCenter-mapDat2*mapSize, mapSize, 1);
               // drawTank(t[0], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                drawTank(t[1], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
                drawTankStat(t, 2, xWindowSize, yWindowSize);
                if (pi==0)
                {
                    if (secretFunction(&po)) pi=1;
                    mapBoundController(&xOfCenter, &yOfCenter, mapDat1, mapDat2, mapSize, xWindowSize, yWindowSize);
                }
                txSleep(10);

            }
        }
        return 0;
    }


    //{============================================================================
    //}============================================================================


    //logic
    void mapInitializer(bool sav, int* mapDat1, int* mapDat2)
    {
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        if (sav)
        {
            in>>*mapDat1;
            in>>*mapDat2;
            for (int i=0; i<*mapDat1; i++)
            {
                for (int j=0; j<*mapDat2; j++)
                {
                    in>>mapMas[i][j];
                }
            }
        }
        else
        for (int i=0; i<*mapDat1; i++)
        {
            for (int j=0; j<*mapDat2; j++)
            {
                mapMas[i][j]=rand()%20/4;
                if (mapMas[i][j]>0) mapMas[i][j]=1;
            }
        }
        in.close();
    }


    bool mapSavedChecker()
    {
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        in.close();
        if (saveController=="SAVE_DATA_RIGHT_FILE=true") return 1;
        else return 0;
    }




    int graph[1000000][5];             //^0 >1 v2 <3 checked - 4




    bool correctMapChecker(bool onlyCheck, int mapDat1, int mapDat2)
    {
        int i, j;
        for (i=0; i<mapDat1; i++)
        {
            for (j=0; j<mapDat2; j++)
            {
                if (mapMas[i][j]==0)
                {
                    graph[mapDat2*i+j][0]=-1;
                    graph[mapDat2*i+j][1]=-1;
                    graph[mapDat2*i+j][2]=-1;
                    graph[mapDat2*i+j][3]=-1;
                    graph[mapDat2*i+j][4]=-1;
                }
            }
        }
        if (mapMas[0][0]>0)graph[0][4]=0;
        if (mapMas[0][mapDat2-1]>0)graph[mapDat2-1][4]=0;
        if (mapMas[mapDat1-1][0]>0)graph[mapDat2*(mapDat1-1)][4]=0;
        if (mapMas[mapDat1-1][mapDat2-1]>0)graph[mapDat1*mapDat2-1][4]=0;
        graph[0][0]=-1;
        graph[0][3]=-1;
        if (mapMas[1][0]==0) graph[0][2]=-1;
        else graph[0][2]=mapDat2;
        if (mapMas[0][1]==0) graph[0][1]=-1;
        else graph[0][1]=1;                                   //initializing key points (corners)
        graph[mapDat2-1][0]=-1;
        graph[mapDat2-1][1]=-1;
        if (mapMas[1][mapDat2-1]==0) graph[mapDat2-1][2]=-1;
        else graph[mapDat2-1][2]=mapDat2*2-1;
        if (mapMas[mapDat2-2][3]==0) graph[mapDat2-1][3]=-1;
        else graph[mapDat2-1][3]=mapDat2-2;
        graph[mapDat2*(mapDat1-1)][2]=-1;
        graph[mapDat2*(mapDat1-1)][3]=-1;
        if (mapMas[mapDat1-2][0]==0) graph[mapDat2*(mapDat1-1)][0]=-1;
        else graph[mapDat2*(mapDat1-1)][0]=mapDat2*(mapDat1-2);
        if (mapMas[mapDat1-1][1]==0) graph[mapDat2*(mapDat1-1)][1]=-1;
        else graph[mapDat2*(mapDat1-1)][1]=mapDat2*(mapDat1-1)+1;
        graph[mapDat1*mapDat2-1][1]=-1;
        graph[mapDat1*mapDat2-1][2]=-1;
        if (mapMas[mapDat1-1][mapDat2-2]==0) graph[mapDat1*mapDat2-1][0]=-1;
        else graph[mapDat1*mapDat2-1][0]=(mapDat1-1)*mapDat2-1;
        if (mapMas[mapDat1-2][mapDat2-1]==0) graph[mapDat1*mapDat2-1][3]=-1;
        else graph[mapDat1*mapDat2-1][3]=mapDat1*mapDat2-2;



        for (i=1; i<mapDat1-1; i++)
        {
            if (mapMas[i][0]>0) graph[mapDat2*i][4]=0;
            if (mapMas[i][mapDat2-1]>0) graph[mapDat2*(i+1)-1][4]=0;
            graph[mapDat2*i][3]=-1;
            graph[mapDat2*(i+1)-1][1]=-1;
            if (mapMas[i-1][0]==0) graph[mapDat2*i][0]=-1;
            else graph[mapDat2*i][0]=mapDat2*(i-1);
            if (mapMas[i][1]==0) graph[mapDat2*i][1]=-1;
            else graph[mapDat2*i][1]=mapDat2*i+1;
            if (mapMas[i+1][0]==0) graph[mapDat2*i][2]=-1;
            else graph[mapDat2*i][2]=mapDat2*(i+1);
            if (mapMas[i-1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][0]=-1;          //OMG i did it
            else graph[mapDat2*(i+1)-1][0]=mapDat2*i-1;
            if (mapMas[i+1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][2]=-1;
            else graph[mapDat2*(i+1)-1][2]=mapDat2*(i+2)-1;
            if (mapMas[i][mapDat2-2]==0) graph[mapDat2*(i+1)-1][3]=-1;
            else graph[mapDat2*(i+1)-1][3]=mapDat2*(i+1)-2;
        }
        for (j=1; j<mapDat2-1; j++)
        {
            if (mapMas[0][j]>0) graph[j][4]=0;
            if (mapMas[mapDat1-1][j]>0)graph[mapDat2*(mapDat1-1)+j][4]=0;
            graph[j][0]=-1;
            graph[mapDat2*(mapDat1-1)+j][2]=-1;
            if (mapMas[0][j+1]==0) graph[j][1]=-1;
            else graph[j][1]=j+1;
            if (mapMas[1][j]==0) graph[j][2]=-1;
            else graph[j][2]=mapDat2+j;
            if (mapMas[0][j-1]==0) graph[j][3]=-1;
            else graph[j][3]=j-1;
            if (mapMas[mapDat1-2][j]==0) graph[(mapDat1-1)*mapDat2+j][0]=-1;
            else graph[(mapDat1-1)*mapDat2+j][0]=(mapDat1-2)*mapDat2+j;
            if (mapMas[mapDat1-1][j-1]==0) graph[(mapDat1-1)*mapDat2+j][1]=-1;
            else graph[(mapDat1-1)*mapDat2+j][1]=(mapDat1-1)*mapDat2+j+1;
            if (mapMas[mapDat1-1][j]==0) graph[(mapDat1-1)*mapDat2+j][3]=-1;
            else graph[(mapDat1-1)*mapDat2+j][3]=(mapDat1-1)*mapDat2+j-1;

        }
        for (i=1; i<mapDat1-1; i++)
        {
            for (j=1; j<mapDat2-1; j++)
            {
                if (mapMas[i][j]>0)graph[mapDat2*i+j][4]=0;
                if (mapMas[i-1][j]==0) graph[mapDat2*i+j][0]=-1;
                else graph[mapDat2*i+j][0]=mapDat2*(i-1)+j;
                if (mapMas[i][j+1]==0) graph[mapDat2*i+j][1]=-1;
                else graph[mapDat2*i+j][1]=mapDat2*i+j+1;
                if (mapMas[i+1][j]==0) graph[mapDat2*i+j][2]=-1;
                else graph[mapDat2*i+j][2]=mapDat2*(i+1)+j;
                if (mapMas[i][j-1]==0) graph[mapDat2*i+j][3]=-1;
                else graph[mapDat2*i+j][3]=mapDat2*i+j-1;
            }
        }
        for (i=0; i<mapDat1; i++)
        {
        for (j=0; j<mapDat2; j++)
        {
            for (int i1=0; i1<mapDat1; i1++)  for (int j1=0; j1<mapDat2; j1++) graph[mapDat2*i1+j1][4]=0;
            for (int i1=0; i1<mapDat1; i1++)  for (int j1=0; j1<mapDat2; j1++)
            {
                if (mapMas[i1][j1]==0) graph[mapDat2*i1+j1][4]=-1;
            }
            if (graph[mapDat2*i+j][4]!=-1)
            {
            if(!checkThisPoint(mapDat2*i+j))
            {
                if (onlyCheck)
                return 0;
                int i1=i, j1=j;

                while (mapMas[i1][j1]!=0&&(i1>0||j1>0))
                {
                    if (rand()%2==0&&i1>0||j1==0) i1--;
                    else j1--;
                }
                mapMas[i1][j1]=1;
                graph[mapDat2*i1+j1][4]=0;
                if (i1>0&&mapMas[i1-1][j1]!=0)
                {
                    graph[mapDat2*i1+j1][0]=mapDat2*(i1-1)+j1;
                    graph[mapDat2*(i1-1)+j1][2]=mapDat2*i1+j1;
                }
                if (j1<mapDat2-1&&mapMas[i1][j1+1]!=0)
                {
                    graph[mapDat2*i1+j1][1]=mapDat2*i1+j1+1;
                    graph[mapDat2*i1+j1+1][3]=mapDat2*i1+j1;

                }
                if (i1<mapDat1-1&&mapMas[i1+1][j1]!=0)
                {
                   graph[mapDat2*i1+j][2]=mapDat2*(i1+1)+j1;
                   graph[mapDat2*(i1+1)+j1][0]=mapDat2*i1+j1;
                }
                if (j1>0&&mapMas[i1][j1-1]!=0)
                {
                    graph[mapDat2*i1+j1][3]=mapDat2*i1+j1-1;
                    graph[mapDat2*i1+j1-1][1]=mapDat2*i1+j1;
                }
                j--;
            }
            }

      //  cout<<graph[(mapDat1-1)*mapDat2][0]<<" "<<graph[(mapDat1-1)*mapDat2][1]<<" "<<graph[(mapDat1-1)*mapDat2][2]<<" "<<graph[(mapDat1-1)*mapDat2][3]<<" "<<graph[(mapDat1-1)*mapDat2][4]<<endl;

      //  cout<<graph[(mapDat1-2)*mapDat2][0]<<" "<<graph[(mapDat1-2)*mapDat2][1]<<" "<<graph[(mapDat1-2)*mapDat2][2]<<" "<<graph[(mapDat1-2)*mapDat2][3]<<" "<<graph[(mapDat1-2)*mapDat2][4]<<endl<<i<<" "<<j<<" "<<endl;
        //txSleep(30);
        }
        }
        return 1;
    }

    bool checkThisPoint(int n)
    {
        if (graph[n][4]==1||graph[n][4]==-1) return 0;
        else if (n==0) return 1;
        else
        {
            graph[n][4]=1;
            for (int i=0; i<4; i++)
            {
                if (graph[n][i]!=-1) if (checkThisPoint(graph[n][i])) return 1;
            }
            return 0;
        }
    }

    void mapBoundController(int* xOfCenter, int* yOfCenter, int mapDat1, int mapDat2, double mapSize, int xWindowSize, int yWindowSize)
    {
        if (mapDat1*2*mapSize>xWindowSize-xWindowSize/4-20)
        {
            if (*xOfCenter>(mapDat1+1)*mapSize+xWindowSize/4+20)
                *xOfCenter=(mapDat1+1)*mapSize+xWindowSize/4+20;
            if (*xOfCenter<xWindowSize-(mapDat1-1)*mapSize)
                *xOfCenter=xWindowSize-(mapDat1-1)*mapSize;
        }
        else
        {
            if (*xOfCenter<(mapDat1+1)*mapSize+xWindowSize/4+20)
            {
                *xOfCenter=(mapDat1+1)*mapSize+xWindowSize/4+20;
            }
            if (*xOfCenter+(mapDat1-1)*mapSize>xWindowSize)
            {
                *xOfCenter=xWindowSize-(mapDat1-1)*mapSize;
            }
        }
        if (mapDat2*2*mapSize>yWindowSize)
        {
            if (*yOfCenter>(mapDat2+1)*mapSize)
                *yOfCenter=(mapDat2+1)*mapSize;
            if (*yOfCenter<yWindowSize-(mapDat2-1)*mapSize)
                *yOfCenter=yWindowSize-(mapDat2-1)*mapSize;
        }
        else
        {
            if (*yOfCenter<(mapDat2+1)*mapSize)
            {
                *yOfCenter=(mapDat2+1)*mapSize;
            }
            if (*yOfCenter+(mapDat2-1)*mapSize>yWindowSize)
            {
                *yOfCenter=yWindowSize-(mapDat2-1)*mapSize;
            }
        }
    }

    //interface
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
        if (GetAsyncKeyState(VK_RIGHT))     *xOfCenter-=ceil(*mapSize/20);
        if (GetAsyncKeyState(VK_LEFT))      *xOfCenter+=ceil(*mapSize/20);
        if (GetAsyncKeyState(VK_DOWN))      *yOfCenter-=ceil(*mapSize/20);
        if (GetAsyncKeyState(VK_UP))        *yOfCenter+=ceil(*mapSize/20);
        if (*mapSize<5) *mapSize=5;
        if (*mapSize>35) *mapSize=35;
    }

    void interfaceTankMoveCheck(tank t[], int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        for (int i=0; i<tankAmount; i++)
        {
            if (In  (   txMouseX(),
                        (int)(xOfCenter-(mapDat1-t[i].x*2+1)*mapSize),
                        (int)(xOfCenter-(mapDat1-t[i].x*2-1)*mapSize)
                    )
                &&
                In  (   txMouseY(),
                        (int)(yOfCenter-(mapDat2-t[i].y*2+1)*mapSize),
                        (int)(yOfCenter-(mapDat2-t[i].y*2-1)*mapSize)
                    )
               )
            {
                drawMapGlowTank(t[i], xOfCenter, yOfCenter, mapSize, mapDat1, mapDat2);
            }
        }
    }

    bool windowSizeChooseAndConfirmation(int* xWindowSize, int* yWindowSize)
    {
        ifstream in;
        ofstream out;
        string str;
        in.open("pcPref.txt");
        getline(in, str);
        if (str=="//This file is for saving your PC's preferences like screen resolution, etc.")
        {
            while (str.length()!=0)
            {
                getline(in, str);
                if (str.substr(0, 20)=="screenDefinitionX = ")
                {
                    str.erase(0, 20);
                    *xWindowSize = atoi(str.c_str());
                }
                else if (str.substr(0, 20)=="screenDefinitionY = ")
                {
                    str.erase(0, 20);
                    *yWindowSize = atoi(str.c_str());
                }
            }
            in.close();
            return 1;
        }
        else
        {
            in.close();
            out.open("pcPref.txt");
            out << "//This file is for saving your PC's preferences like screen resolution, etc.\n";
            drawDefinitionChoose(xWindowSize, yWindowSize);
            out << "screenDefinitionX = " << *xWindowSize <<endl << "screenDefinitionY = " << *yWindowSize << endl;
            return 0;
        }
    }

    void changeResolution(int* xWindowSize, int* yWindowSize)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            *xWindowSize=*xWindowSize-2;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            *xWindowSize=*xWindowSize+2;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            *yWindowSize=*yWindowSize-1;
        }
        if (GetAsyncKeyState(VK_UP))
        {
            *yWindowSize=*yWindowSize+1;
        }
        if (*xWindowSize<0) *xWindowSize=0;
        if (*xWindowSize>2715) *xWindowSize=2715;
        if (*yWindowSize<0) *yWindowSize=0;
        if (*yWindowSize>1527) *yWindowSize=1527;
    }

    //drawing
    void drawMap(int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetColor(TX_BLACK, mapSize);
        txRectangle(xOfCenter-(1+mapDat1)*mapSize, yOfCenter-(1+mapDat2)*mapSize, xOfCenter+(mapDat1-1)*mapSize, yOfCenter+(mapDat2-1)*mapSize);
        txSetColor(TX_BLACK );
        for (int i=0; i<mapDat1; i++)
        {
            for (int j=0; j<mapDat2; j++)
            {
                if (mapMas[j][i]==0)
                {
                    txSetColor(RGB(25, 25, 25));
                    txSetFillColor(RGB(25, 25, 25));
                }
                else
                {
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_WHITE);
                }
                txRectangle(xOfCenter-(mapDat1-i*2-1)*mapSize, yOfCenter-(mapDat2-j*2-1)*mapSize, xOfCenter-(mapDat1-i*2+1)*mapSize, yOfCenter-(mapDat2-j*2+1)*mapSize);
            }
        }
    }

    void drawWelcome(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txSelectFont("SYSTEM_FIXED_FONT", 80);
        txTextOut(xWindowSize/2, yWindowSize/2, "TANKS OFFLINE");
        txSelectFont("SYSTEM_FIXED_FONT", 40);
        txTextOut(xWindowSize/2+30, yWindowSize/2+15, "beta");

    }

    void drawMapInit(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "creating map");
    }

    void drawMapLoad(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "loading map");
    }

    void drawMapSaveFound(int xWindowSize, int yWindowSize)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2-5, yWindowSize/2-5, "saved map found. Load?\n");
        txTextOut(xWindowSize/2+5, yWindowSize/2+5, "Y - yes  N - no");
    }

    void drawMapGlowTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetFillColor(TX_YELLOW);
        txRectangle (   xOfCenter-(mapDat1-t.x*2-1)*mapSize,
                        yOfCenter-(mapDat2-t.y*2+1)*mapSize,
                        xOfCenter-(mapDat1-t.x*2+1)*mapSize,
                        yOfCenter-(mapDat2-t.y*2-1)*mapSize
                    );
    }

    void drawTank(tank t, int xOfCenter, int yOfCenter, double mapSize, int mapDat1, int mapDat2)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(t.color);
        txCircle(xOfCenter-(mapDat1-t.x*2)*mapSize, yOfCenter-(mapDat2-t.y*2)*mapSize, mapSize/3);
    }

    bool secretFunction(int* ss)
    {
        switch(*ss)
        {
            case 0:
                if (GetAsyncKeyState('U')) *ss++;
                break;
            case 1:
                if (GetAsyncKeyState('M')) return 1;
                break;
        }
    }

    void drawDefinitionChoose(int* xWindowSize, int* yWindowSize)
    {
        txCreateWindow(2715, 1527, true);
        while (!GetAsyncKeyState(VK_ESCAPE))
        {
            txSetColor(TX_RED, 2);
            txSetFillColor(TX_BLACK);
            txClear();
            txSetFillColor(TX_NULL);
            txRectangle(2715/2-*xWindowSize/2,
                        1527/2-*yWindowSize/2,
                        2715/2+*xWindowSize/2,
                        1527/2+*yWindowSize/2
                        );
            txSetTextAlign(TA_CENTER);
            txSetColor(TX_WHITE);
            txTextOut(2715/2-10, 1527/2-10, "CHOOSE RESOLUTION");
            txTextOut(2715/2, 1527/2, "ALIGN RED FRAMES TO WINDOW'S BOARDS");
            txTextOut(2715/2+10, 1527/2+10, "LEFT/RIGHT - HORIZONTAL  UP/DOWN - VERTICAL");
            txTextOut(2715/2+30, 1527/2+30, "ENTER - CONFIRM");
            changeResolution(xWindowSize, yWindowSize);
            txSleep(1);
        }
    }

    void Tank(int x, int y, float k, int pozition)
    {
        if(pozition==1)
        {//wheels
            txSetFillColour(TX_BLACK);
            txSetColour(TX_BLACK, 0.04*k);
             txRectangle(x-0.6*k,y-0.8*k,x-0.4*k,y+0.8*k);
             txRectangle(x+0.6*k,y-0.8*k,x+0.4*k,y+0.8*k);
             //The main part
             txSetFillColour(TX_PINK);
             txRectangle(x-0.4*k,y-0.8*k,x+0.4*k,y+0.8*k);
             //The Top of tank
             txPie(x-0.4*k,y-0.2*k,x+0.4*k,y+0.6*k,180,180);
             POINT kuk[4]=
         {
         {x-0.4*k,y+0.2*k},
         {x-0.2*k,y-0.2*k},
         {x+0.2*k,y-0.2*k},
         {x+0.4*k,y+0.2*k}
         };
         txPolygon(kuk,4);
          txRectangle(x-0.1*k,y-0.9*k,x+0.1*k,y-0.2*k);
           txSetFillColour(TX_PINK);
            txSetColour(TX_PINK);
            txRectangle(x-0.38*k,y+0.23*k,x+0.38*k,y+0.17*k);
      }


    }



    void drawTankStat(tank t[], int tankAmount, int xWindowSize, int yWindowSize)
    {
        txSetColor(TX_BLACK, 3);
        txSetFillColor(RGB(191, 219, 83));
        POINT statWindow[5]=
        {
            {-10, 0},
            {xWindowSize/4, 0},
            {xWindowSize/4+20, 20},
            {xWindowSize/4+20, yWindowSize-50},
            {-10, yWindowSize-50}
        };
        txPolygon(statWindow, 5);
        POINT buttons[4]=
        {
            {-10, yWindowSize-50},
            {xWindowSize/4+20, yWindowSize-50},
            {xWindowSize/4+20, yWindowSize+10},
            {-10, yWindowSize+10}
        };
        txSetFillColor(RGB(142, 159, 145));
        txPolygon(buttons, 4);
    }
