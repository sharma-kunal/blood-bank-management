#include<bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include<conio.h>
#include<fstream>
#include <windows.h>
#define INFINITY 9999
#define MAX 100
using namespace std;


char type[10],bg[10];
int quantity;
int dd[MAX];

bool compare1(pair <int,pair<char*,int>> a,pair<int,pair<char*,int>> b) //decreasing order quantity
{
    return ((a.first)>(b.first));
}

bool compare2(pair <int,pair<char*,int>> a,pair<int,pair<char*,int>> b) // increasing order of hospital name
{
    return ((a.second.first)<(b.second.first));
}

bool com(pair <string,pair<int,int>> a,pair<string,pair<int,int>> b)
{
    return ((a.second.second)<(b.second.second));
}
class dijkstra
{
    int G[MAX][MAX],i,j,n,startnode,temp[20]= {},p,distance[MAX],pred[MAX];

public:

 void brick1()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xB2\xB2  ");
}
void brick2()
{
    int i;
    for(i=0;i<30;i++)
        printf("  \xB2\xB2");
}
void pattern1()
{
    int i;
    for(i=0;i<15;i++)
        printf("\xDB\xDB  \xB2\xB2  ");
}
void pattern2()
{
    int i;
    for(i=0;i<15;i++)
        printf("  \xDB\xDB  \xB2\xB2");
}
void patternline1()
{
    int i;
    for(i=0;i<60;i++)
        printf("\xDB\xB2");
}
void patternline2()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xDB\xDB\xB2\xB2");
}
void patternline3()
{
    int i;
    for(i=0;i<60;i++)
        printf("\xB2\xDB");
}
void patternline4()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xB2\xB2\xDB\xDB");
}

 //Text Position
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    //Cost Matrix
    void cost_matrix()
    {
        ofstream output("file.txt");
        gotoxy(35,9);
        printf("Enter no. of hospitals you want to add in the system: ");
        //output<<"Number of vertices: ";
        scanf("%d",&n);
        output<<n<<endl;
        blood(n);

        cout<<'\n';
        printf("\t\t\t\t\tEnter the linkage of hospitals:  ");
        //output<<"\nEnter the adjacency matrix:\n";
        cout<<'\n';
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&G[i][j]);
                output<<G[i][j]<<' ';
            }
            output<<endl;
        }
        cout<<'\n';
        printf("\t\t\t\t Enter the hospital you are initially in (1 - %d): ",n);
        scanf("%d",&startnode);
    }


    void append()
    {
        ifstream outpu("file.txt");
        gotoxy(35,9);
        printf("Enter no. of hospitals you want to add in the system: ");
        //output<<"Number of vertices: ";
        int temp;
        scanf("%d",&temp);
        blood(temp);
        outpu>>temp;
        cout<<'\n';
        printf("\t\t\t\t\tEnter the linkage of hospital with %d others",temp);
        //output<<"\nEnter the adjacency matrix:\n";
        cout<<'\n';

        int tt[temp+1][temp+1];
        for(int i=0; i<temp; i++)
        {
            for(int j=0; j<temp; j++)
            {
                tt[i][j]=0;
                //char tete;
                outpu>>tt[i][j];
                //cout<<tt[i][j]<<" ";
            }
        }
        for(int i=0;i<temp;i++)
        {
            cin>>tt[temp][i];
            tt[i][temp]=tt[temp][i];
        }
        tt[temp][temp]=0;
        cout<<'\n';
        ofstream xf("file.txt");
        xf<<temp+1;
        xf<<endl;
        for(int i=0;i<temp+1;i++)
        {
            for(int j=0;j<temp+1;j++)
            {
                xf<<tt[i][j];
                xf<<" ";
            }
            xf<<endl;
        }
    }


   //Blood type and quantity
    void blood(int n)
    {

        ofstream bld;
        bld.open("file1.txt",std::ios_base::app);
        for(i=0;i<n;i++)
        { gotoxy(40,12+i);
       cout<<"Enter blood type and quantity for "<<i+1<<":  ";

        cin>>type;
        cin>>quantity;
        bld<<type<<'\n';
        bld<<quantity<<'\n';
        }

    }
    //Path Matrix

    void path_matrix()
    {
        int cost[n][n];
        int visited[n],count,mindistance,nextnode,i,j;

        //pred[] stores the predecessor of each node
        //count gives the number of nodes seen so far
        //create the cost matrix
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(G[i][j]==0)
                    cost[i][j]=INFINITY;
                else
                    cost[i][j]=G[i][j];

        //initialize pred[],distance[] and visited[]
        for(i=1; i<=n; i++)
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }

        distance[startnode]=0;
        visited[startnode]=1;
        count=1;

        while(count<n-1)
        {
            mindistance=INFINITY;

            //nextnode gives the node at minimum distance
            for(i=1; i<=n; i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=1; i<=n; i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
            count++;
        }
    }

    void path_matrix1()
    {
        int cost[n][n];
        int visited[n],count,mindistance,nextnode,i,j;

        //pred[] stores the predecessor of each node
        //count gives the number of nodes seen so far
        //create the cost matrix
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(G[i][j]==0)
                    cost[i][j]=INFINITY;
                else
                    cost[i][j]=G[i][j];

        //initialize pred[],distance[] and visited[]
        for(i=1; i<=n; i++)
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }

        distance[startnode]=0;
        visited[startnode]=1;
        count=1;

        while(count<n-1)
        {
            mindistance=INFINITY;

            //nextnode gives the node at minimum distance
            for(i=1; i<=n; i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=1; i<=n; i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
            count++;
        }
        for(int i=1;i<=n;i++)
            dd[i]=distance[i];
        for(int i=1;i<=n;i++)
            cout<<dd[i]<<" ";
        cout<<endl;
    }

    //WHOLE LIST DISPLAY
    void whole_display()
    {
        //print the path and distance of each node
        int count;
        for(i=1; i<=n; i++)
            if(i!=startnode)
            {
                printf("\n\t\t\t\t%d to %d the lowest cost is: %d \n",startnode,i,distance[i]);
                count=0;
                temp[count]=i;
                j=i;
                do
                {
                    count++;
                    j=pred[j];
                    temp[count]=j;
                }
                while(j!=startnode);
                printf("\t\t\t\tPath is ");
                for(p=count; p>=0; p--)
                {
                    printf("=>%d ",temp[p]);
                }
                cout<<endl;

            }
    }


    void get(char bg[])
    {
        ifstream ifl("file1.txt");
        ifstream if2("file.txt");
        int flag=0;
        vector<pair<int,pair<char*,int>>> p;
        int cc=0;
        int ss=0;
        if2>>ss;
        for(i=0;i<ss;i++)
        {
            ifl>>type;
            ifl>>quantity;
            if(strcmp(type,bg)==0 && quantity>0)
            {
                 p.push_back(make_pair(quantity,make_pair(bg,(i+1))));
                 flag=1;
                 cc+=1;
            }
        }

         if(flag==0)
                cout<<"\t\t\t\tBlood not available\n";
         else{
            int ch=-1;
            cout<<"\t\t\t\tSort on basis of (quantity=1,name=2):-";
            cin>>ch;
            if(ch==1)
            {
                sort(p.begin(),p.end(),compare1);
            }
            else if(ch==2)
            {
                sort(p.begin(),p.end(),compare2);
            }
            for(int i=0;i<cc;i++)
            {
                cout<<"\t\t\t\thospital name: "<<(p[i].second).second<<endl<<"\t\t\t\tquantity: "<<p[i].first<<endl<<"\t\t\t\ttype: "<<(p[i].second).first<<'\n';
            }

            cout<<"\t\t\t\tQuantity you want:-";
            int z;
            cin>>z;
            ifstream ttf("file.txt");
            ttf>>n;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    ttf>>G[i][j];
                    //cout<<i<<" ";
                }
            }
            cout<<"\t\t\t\tEnter source point:-";

            //cout<<n<<" ";
            cin>>startnode;
            path_matrix1();
            ifstream xt1("file1.txt");
            vector<pair<string,pair<int,int>>> pp;
            string bgg;
            for(int i=1;i<=n;i++)
            {
                xt1>>bgg;
                xt1>>quantity;

                pp.push_back(make_pair(bgg,make_pair(quantity,dd[i])));
            }
            sort(pp.begin(),pp.end(),com);
            int dx=0;
            int qx=0;
            int minn=999999;
            for(int i=0;i<n;i++)
            {
                if(strcmp(pp[i].first.c_str(),bg)==0)
                {
                    if(pp[i].second.first>=z)
                    {
                        if(minn>pp[i].second.second)
                            minn=pp[i].second.second;
                    }
                    if(qx<z)
                    {
                        qx+=pp[i].second.first;
                        dx+=pp[i].second.first;
                    }
                }
            }
            cout<<minn<<" "<<dx<<" ";
            if(dx>minn)
                cout<<minn<<endl;
            else
            {
                if(qx<z)
                    cout<<"cannot be obtained";
                else
                    cout<<dx<<endl;
            }
            //ye yhi band hota hai...
        }
    }


    //SOURCE TO DESTINATION LIST DISPLAY
    void source_display(int a)
    {
        //print the path and distance of each node
        int dist=a, count;
        for(i=1; i<=n; i++)
            if(i!=startnode && i==dist)
            {
                printf("\n\t\t\t\t%d to %d the lowest cost is: %d \n",startnode,i,distance[i]);
                count=0;
                temp[count]=i;
                j=i;
                do
                {
                    count++;
                    j=pred[j];
                    temp[count]=j;
                }
                while(j!=startnode);
                printf("\t\t\t\tPath is ");
                for(p=count; p>=0; p--)
                {
                    printf("=>%d ",temp[p]);
                }
                cout<<endl;

            }
    }

    //File input customer
    void file_input()
    {
        ifstream input("file.txt");
        input>>n;
        cout<<"\t\t\t\t\t\t\tNumber of Hospitals: "<<n<<endl;
        printf("\n\t\t\t\tLinkage and hospitals read from file a.\n");

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                input>>G[i][j];
            }

        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }

        printf("\n\t\t\t\tEnter the starting hospital  (1 - %d): ",n);
        scanf("%d",&startnode);
    }


    //Loading....
    void load()
    {
        int row,col,r,c,q;
        gotoxy(50,14);
        printf("loading...");
        gotoxy(30,15);
        for(r=1; r<=45; r++)
        {
            for(q=0; q<=10000000; q++); //to display the character slowly
            printf("%c",177);
        }
    }

    //Header
    void header()
    {
        patternline1();
        patternline2();
        gotoxy(50,3);
        cout<<"Life Saviour"<<endl;
        gotoxy(0,5);
        patternline1();

    }

    //Note
    void note(string nt)
    {
        system("CLS");
        header();
        gotoxy(30,5);
    for(int i=0;i<30;i++)
        printf("\xB2\xDB");
        gotoxy(46,7);
        cout<<"\xB2\xDB"<<nt<<"\xB2\xDB"<<endl;
        gotoxy(28,9);
    for(int i=0;i<30;i++)
        printf("\xB2\xDB");
    }
    //menuprintf("\n last no %d\n",temp[p]);
    void menu ()
    {
        system("CLS");
        header();
         gotoxy(30,7);
    for(int i=0;i<30;i++)
        printf("\xB2\xDB");
    for(int i=0;i<14;i++)
    {   gotoxy(30,8+i);
        printf("\xDB\xB2\n");
    }
    for(int i=0;i<14;i++)
    {   gotoxy(88,8+i);
        printf("\xB2\xDB\n");
    }
     gotoxy(32,21);
    for(int i=0;i<28;i++)
        printf("\xB2\xDB");
        gotoxy(48,7);
        cout<<" Choose your option: ";
        gotoxy(48,9);
        cout<<"1 : Whole list:  ";
        gotoxy(48,10);
        cout<<"2 : Source to Destination:  ";
        gotoxy(50,12);
        cout<<"Enter your option: ";
    }
};

//main function
int main()
{
    system("color f0");
    int op,op2,op3,desti;
    string nt1="Invalid Input",nt2="  Thank You! ";
    dijkstra d;
    d.load();
    system("CLS");
Start:
    d.header();
    d.gotoxy(30,7);
    for(int i=0;i<30;i++)
        printf("\xB2\xDB");
    for(int i=0;i<14;i++)
    {   d.gotoxy(30,8+i);
        printf("\xDB\xB2\n");
    }
    for(int i=0;i<14;i++)
    {   d.gotoxy(88,8+i);
        printf("\xB2\xDB\n");
    }
    d.gotoxy(32,21);
    for(int i=0;i<28;i++)
        printf("\xB2\xDB");

    d.gotoxy(50,9);
    cout<<"Choose your option: "<<endl;
    d.gotoxy(32,11);
    for(int i=0;i<28;i++)
        printf("\xB2\xDB");
    d.gotoxy(48,13);
    cout<<"1: Standard Input (Runtime)"<<endl;
    d.gotoxy(48,14);
    cout<<"2: File Input"<<endl;
    d.gotoxy(48,15);
    cout<<"3: Search blood type"<<endl;
    d.gotoxy(48,16);
    cout<<"4: Exit"<<endl;

    d.gotoxy(50,18);
    cout<<"Enter your option: ";
    cin>>op;


    switch(op)
    {
    case 1 ://Standard Input
        d.menu();
        cin>>op2;
        switch(op2)
        {
        case 1 ://Whole list
            system("CLS");
            d.header();
            d.cost_matrix();
            d.path_matrix();
            d.whole_display();
            cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        case 2 : //append
            system("CLS");
            d.header();
            d.append();
            cout<<endl<<endl<<"\t\t\t\tAppend Successfull!"<<endl;
            cout<<endl<<endl<<"\t\t\t\t\Press any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        default: //Invalid Input
            d.note(nt1);
            cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        }
        break;
    case 2 ://from file input
        d.menu();
        cin>>op3;
        switch(op3)
        {
        case 1 ://from file Whole list
            system("CLS");
            d.header();
            d.file_input();
            d.path_matrix();
            d.whole_display();
            cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;

        case 2 ://from file Source to Destination
            system("CLS");
            d.header();
            d.file_input();
            cout<<"\t\t\t\tEnter the destination node: ";
            cin>>desti;
            d.path_matrix();
            d.source_display(desti);
            cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;

        default://Invalid Input
            d.note(nt1);
            cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        }

        break;


    case 3:
        system("CLS");
        cout<<"\t\t\t\tEnter blood type: ";
         cin>>bg;
         d.get(bg);
         cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
         cout<<"\t\t\t\t=========================";
         getch();
         system("CLS");
         goto Start;
         break;

     case 4 : //Exit
        d.note(nt2);
        getch();
        break;


    default: //Invalid Input
        d.note(nt1);
        cout<<endl<<endl<<"\t\t\t\tPress any key to continue!"<<endl;
            cout<<"\t\t\t\t=========================";
            getch();
            system("CLS");
            goto Start;
        break;
    }
    return 0;
}
