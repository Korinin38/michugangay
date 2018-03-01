    #include "TXLib.h"
    #include <fstream>
    #include <string>
    using namespace std;
    CONST int   YRACKETCONST=500,
                xWindowSize=800,
                yWindowSize=600;

    int mapMas[1000][1000],
        xOfCenter=xWindowSize/2,
        mapDat1=20,
        mapDat2=20,
        yOfCenter=yWindowSize/2,
        tankAmount=2;

    struct tank{
        int x,
            y;
        COLORREF color;
    };

    double mapSize=15;

    //logic
    void mapInitializer(bool sav);
    bool correctMapChecker(bool onlyCheck=0);
    bool checkThisPoint(int n);
    bool mapSavedChecker();
    void mapBoundController();

    //interface
    void interfaceOfMap();
    void interfaceTankMoveCheck(tank*);

    //drawing
    void drawMap();
    void drawWelcome();
    void drawMapInit();
    void drawMapSaveFound();
    void drawMapGlowTank(tank t);
    void drawMapLoad();
    void drawTank(tank t);


    int main()
    {
        srand(time(NULL));
        txCreateWindow (xWindowSize, yWindowSize);
        xOfCenter=xWindowSize/2;
        yOfCenter=yWindowSize/2;
        drawWelcome();
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
            drawMapInit();
            txSleep(500);
            bool counter=0, counterWhile=0;
            if (mapSavedChecker())
            {
                drawMapSaveFound();
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
            drawMapLoad();
            mapInitializer(counter);
            correctMapChecker();
            txSleep(1000);

            while (!GetAsyncKeyState(VK_ESCAPE)&&!GetAsyncKeyState(VK_F9)&&!GetAsyncKeyState('R'))
            {
                txSetFillColor(TX_WHITE);
                txClear();
                interfaceOfMap();
                mapBoundController();
                drawMap();
                interfaceTankMoveCheck(t);
                drawTank(t[0]);
                drawTank(t[1]);
                txSleep(1);

            }
        }
        return 0;
    }

    //logic
    void mapInitializer(bool sav)
    {
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        if (sav)
        {
            in>>mapDat1;
            in>>mapDat2;
            for (int i=0; i<mapDat1; i++)
            {
                for (int j=0; j<mapDat2; j++)
                {
                    in>>mapMas[i][j];
                }
            }
        }
        else
        for (int i=0; i<mapDat1; i++)
        {
            for (int j=0; j<mapDat2; j++)
            {
                mapMas[i][j]=rand()%20/4;
                if (mapMas[i][j]>0) mapMas[i][j]=1;
            }
        }
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

    CONST int graphMax=mapDat1*mapDat2;
    int graph[1000000][5];             //^0 >1 v2 <3 checked - 4
    bool correctMapChecker(bool onlyCheck)
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

    void mapBoundController()
    {
        if (mapDat1*2*mapSize>xWindowSize)
        {
            if (xOfCenter>(mapDat1+1)*mapSize)
                xOfCenter=(mapDat1+1)*mapSize;
            if (xOfCenter<xWindowSize-(mapDat1-1)*mapSize)
                xOfCenter=xWindowSize-(mapDat1-1)*mapSize;
        }
        else
        {
            if (xOfCenter<(mapDat1+1)*mapSize)
            {
                xOfCenter=(mapDat1+1)*mapSize;
            }
            if (xOfCenter+(mapDat1-1)*mapSize>xWindowSize)
            {
                xOfCenter=xWindowSize-(mapDat1-1)*mapSize;
            }
        }
        if (mapDat2*2*mapSize>yWindowSize)
        {
            if (yOfCenter>(mapDat2+1)*mapSize)
                yOfCenter=(mapDat2+1)*mapSize;
            if (yOfCenter<yWindowSize-(mapDat2-1)*mapSize)
                yOfCenter=yWindowSize-(mapDat2-1)*mapSize;
        }
        else
        {
            if (yOfCenter<(mapDat2+1)*mapSize)
            {
                yOfCenter=(mapDat2+1)*mapSize;
            }
            if (yOfCenter+(mapDat2-1)*mapSize>yWindowSize)
            {
                yOfCenter=yWindowSize-(mapDat2-1)*mapSize;
            }
        }
    }

    //interface
    void interfaceOfMap()
    {
        if (GetAsyncKeyState('V'))
        {
            mapSize+=0.09;
        }
        if (GetAsyncKeyState('B'))
        {
            mapSize-=0.09;
        }
        if (GetAsyncKeyState(VK_RIGHT))     xOfCenter-=ceil(mapSize/20);
        if (GetAsyncKeyState(VK_LEFT))      xOfCenter+=ceil(mapSize/20);
        if (GetAsyncKeyState(VK_DOWN))      yOfCenter-=ceil(mapSize/20);
        if (GetAsyncKeyState(VK_UP))        yOfCenter+=ceil(mapSize/20);
        if (mapSize<5) mapSize=5;
        if (mapSize>35) mapSize=35;
    }

    void interfaceTankMoveCheck(tank t[])
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
                drawMapGlowTank(t[i]);
            }
        }
    }

    //drawing
    void drawMap()
    {
        txSetColor(TX_BLACK, mapSize);
        txRectangle(xOfCenter-(1+mapDat1)*mapSize, yOfCenter-(1+mapDat2)*mapSize, xOfCenter+(mapDat1-1)*mapSize, yOfCenter+(mapDat2-1)*mapSize);
        txSetColor(TX_BLACK, mapSize/3);
        for (int i=0; i<mapDat1; i++)
        {
            for (int j=0; j<mapDat2; j++)
            {
                if (mapMas[j][i]==0) txSetFillColor(TX_BLACK);
                else txSetFillColor(TX_WHITE);
                txRectangle(xOfCenter-(mapDat1-i*2-1)*mapSize, yOfCenter-(mapDat2-j*2-1)*mapSize, xOfCenter-(mapDat1-i*2+1)*mapSize, yOfCenter-(mapDat2-j*2+1)*mapSize);
            }
        }
    }

    void drawWelcome()
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txSelectFont("SYSTEM_FIXED_FONT", 30);
        txTextOut(xWindowSize/2, yWindowSize/2, "TANKS OFFLINE");
        txSelectFont("SYSTEM_FIXED_FONT", 10);
        txTextOut(xWindowSize/2+30, yWindowSize/2+15, "beta");

    }

    void drawMapInit()
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "creating map");
    }

    void drawMapLoad()
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2, yWindowSize/2, "loading map");
    }

    void drawMapSaveFound()
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_WHITE);
        txSetTextAlign(TA_CENTER);
        txTextOut(xWindowSize/2-5, yWindowSize/2-5, "saved map found. Load?\n");
        txTextOut(xWindowSize/2+5, yWindowSize/2+5, "Y - yes  N - no");
    }

    void drawMapGlowTank(tank t)
    {
        txSetFillColor(TX_YELLOW);
        txRectangle (   xOfCenter-(mapDat1-t.x*2-1)*mapSize,
                        yOfCenter-(mapDat2-t.y*2+1)*mapSize,
                        xOfCenter-(mapDat1-t.x*2+1)*mapSize,
                        yOfCenter-(mapDat2-t.y*2-1)*mapSize
                    );
    }

    void drawTank(tank t)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(t.color);
        txCircle(xOfCenter-(mapDat1-t.x*2)*mapSize, yOfCenter-(mapDat2-t.y*2)*mapSize, mapSize/3);
    }
