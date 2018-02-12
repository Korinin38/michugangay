    #include <fstream>
    #include <string>
    #include "TXLib.h"
    using namespace std;
    CONST int   YRACKETCONST=500,
                xWindowSize=800,
                yWindowSize=600,
                tankAmount=1;

    int mapMas[1000][1000],
        tankPlaceX[tankAmount],
        tankPlaceY[tankAmount],
        xOfCenter,
        mapDat1=8,
        mapDat2=8,
        yOfCenter;

    double mapSize=15;


    void interfaceOfMap();
    void drawMap();
    void correctMapChecker();
    bool checkThisPoint(int n);

    int main()
    {
        srand(time(NULL));
        txCreateWindow (xWindowSize, yWindowSize);
        xOfCenter=xWindowSize/2;
        yOfCenter=yWindowSize/2;
        ifstream in;
        ofstream out;
        string saveController;
        in.open("ss.txt");
        getline(in, saveController);
        if (saveController=="SAVE_DATA_RIGHT_FILE=true")
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
        correctMapChecker();
        while (!GetAsyncKeyState(VK_ESCAPE))
        {
            txSetFillColor(TX_WHITE);
            txClear();
            interfaceOfMap();
            drawMap();
            txSleep(1);

        }
        return 0;
    }

    CONST int graphMax=mapDat1*mapDat2;
    int graph[1000000][5];             //^0 >1 v2 <3 checked - 4
    void correctMapChecker()
    {
        int i, j;
        graph[0][4]=0;
        graph[mapDat2-1][4]=0;
        graph[mapDat2*(mapDat1-1)][4]=0;
        graph[mapDat1*mapDat2-1][4]=0;
        graph[0][0]=-1;
        graph[0][3]=-1;
        if (mapMas[1][0]==0) graph[0][2]=-1;
        else graph[0][2]=mapDat2;
        if (mapMas[0][1]==0) graph[0][1]=-1;
        else graph[0][1]=1;                                   //initializing key points (corners)
        graph[mapDat2-1][0]=-1;
        graph[mapDat2-1][1]=-1;
        if (mapMas[1][mapDat2-1]==0) graph[mapDat2*2-1][2]=-1;
        else graph[mapDat2*2-1][2]=1;
        if (mapMas[mapDat2-2][3]==0) graph[mapDat2-2][3]=-1;
        else graph[mapDat2-2][3]=mapDat2-2;
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
            graph[mapDat2*i][4]=0;
            graph[mapDat2*(i+1)-1][4]=0;
            graph[mapDat2*i][3]=-1;
            graph[mapDat2*(i+1)-1][1]=-1;
            if (mapMas[i-1][0]==0) graph[mapDat2*i][0]=-1;
            else graph[mapDat2*i][0]=mapDat2*(i-1);
            if (mapMas[i][1]==0) graph[mapDat2*i][1]=-1;
            else graph[mapDat2*i][2]=mapDat2*i+1;
            if (mapMas[i+1][0]==0) graph[mapDat2*i][2]=-1;
            else graph[mapDat2*i][2]=mapDat2*(i+1);
            if (mapMas[i-1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][0]=-1;          //OMG i did it
            else graph[mapDat2*(i+1)-1][0]=mapDat2*i-1;
            if (mapMas[i][mapDat2-2]==0) graph[mapDat2*(i+1)-1][3]=-1;
            else graph[mapDat2*(i+1)-1][3]=mapDat2*(i+1)-2;
            if (mapMas[i+1][mapDat2-1]==0) graph[mapDat2*(i+1)-1][2]=-1;
            else graph[mapDat2*(i+1)-1][2]=mapDat2*(i+2)-1;
        }
        for (j=1; j<mapDat2-1; j++)
        {
            graph[j][4]=0;
            graph[mapDat2*(mapDat1-1)+j][4]=0;
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
                graph[mapDat2*i+j][4]=0;
                if (mapMas[i-1][j]==0) graph[mapDat2*i+j][0]=-1;
                else graph[mapDat2*i+j][0]=mapDat2*(i-1)+j;
                if (mapMas[i][j+1]==0) graph[mapDat2*i+j][1]=-1;
                else graph[mapDat2*i+j][1]=mapDat2*i+j+1;
                if (mapMas[i+1][j]==0) graph[mapDat2*i+j][2]=-1;
                else graph[mapDat2*i+j][2]=mapDat2*(i+1)+j;
                if (mapMas[i][j-1]==0) graph[mapDat2*i+j][2]=-1;
                else graph[mapDat2*i+j][3]=mapDat2*i+j-1;
            }
        }
        for (i=0; i<mapDat1; i++)
        {
        for (j=0; j<mapDat2; j++)
        {
                for (int i1=0; i1<mapDat1; i1++)  for (int j1=0; j1<mapDat2; j1++) graph[mapDat2*i1+j1][4]=0;
            if (true!=checkThisPoint(mapDat2*i+j))
            {
                int i1=i, j1=j;

                while (mapMas[i1][j1]!=0&&(i1>0||j1>0))
                {
                    if (rand()%2==0&&i1>0) i1--;
                    else j1--;
                }
                mapMas[i1][j1]=1;
            }
        }
        }
    }

    bool checkThisPoint(int n)
    {
        if (graph[n][4]==1) return 0;
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

    void interfaceOfMap()
    {
        if (GetAsyncKeyState('V'))
        {
            mapSize+=0.06;
        }
        if (GetAsyncKeyState('B'))
        {
            mapSize-=0.06;
        }
        if (GetAsyncKeyState(VK_RIGHT))     xOfCenter-=1;
        if (GetAsyncKeyState(VK_LEFT))      xOfCenter+=1;
        if (GetAsyncKeyState(VK_DOWN))      yOfCenter-=1;
        if (GetAsyncKeyState(VK_UP))        yOfCenter+=1;
        if (mapSize<5) mapSize=5;
    }

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
                txRectangle(xOfCenter-(mapDat1-1-i*2)*mapSize, yOfCenter-(mapDat2-1-j*2)*mapSize, xOfCenter-(mapDat1-i*2+1)*mapSize, yOfCenter-(mapDat2-j*2+1)*mapSize);
            }
        }
    }
