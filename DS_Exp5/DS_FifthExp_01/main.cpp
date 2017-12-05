#include <iostream>
#include <windows.h>
#include <Graph.h>

using namespace std;

void ShowMenu(int i);

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Graph* G;
    //G->RandomGenerate();
    //G->ShowGraph();

    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        int x,y,z;
        int* visited=new int[G->VertexNum];
        switch(operation)
        {
        case 1:
            cin>>x>>y;
            G=new Graph(x,y);
            G->RandomGenerate();
            G->ShowGraph();
            break;
        case 2:
            G->ShowGraph();
            break;
        case 3:
            cin>>x>>y;
            if(G->GetCost(x,y)==-1)
            {
                cout<<endl<<"�����ڱߣ�"<<endl;  //Edge Not Exist
            }else
            {
                cout<<endl<<G->GetCost(x,y)<<endl;
            }
            break;
        case 4:
            cin>>x>>y>>z;
            G->InsertEdge(x,y,z);
            G->ShowGraph();
            break;
        case 5:
            cin>>x>>y;
            G->DelEdge(x,y);
            G->ShowGraph();
            break;
        case 6:
            cin>>x;
            if(G->GetFirstAdjacent(x)!=NULL)
            {
                cout<<endl<<G->GetFirstAdjacent(x)->VerAdj<<endl;
            }else
            {
                cout<<endl<<"�����ڣ�"<<endl;   //Not Exist
            }
            break;
        case 7:
            cin>>x;
            for(int i=0;i<G->VertexNum;i++)
            {
                visited[i]=0;
            }
            G->DFS(x,visited);
            x=1;
            for(int i=0;i<G->VertexNum;i++)
            {
                if(visited[i]==0)
                {
                    x=0;

                    break;
                }
            }
            if(x)
            {
                cout<<endl<<"�ѱ������е�"<<endl; //All Visited
            }else
            {
                cout<<endl<<"δ�������е�"<<endl; //Not All Visited
            }
            break;
        case 8:
            cin>>x;
            for(int i=0;i<G->VertexNum;i++)
            {
                visited[i]=0;
            }
            G->BFS(x,visited);
            x=1;
            for(int i=0;i<G->VertexNum;i++)
            {
                if(visited[i]==0)
                {
                    x=0;

                    break;
                }
            }
            if(x)
            {
                cout<<endl<<"�ѱ������е�"<<endl; //All Visited
            }else
            {
                cout<<endl<<"δ�������е�"<<endl; //Not All Visited
            }
            break;
        case 9:
            G->AllComponent();
            break;
        }

        ShowMenu(0);
        cin>>operation;
    }

    return 0;
}

void ShowMenu(int i)
{
    switch(i)
    {
    case 0:
        cout<<endl
        <<"1) ����ͼ��������_������"<<endl
        <<"2) ��ӡ"<<endl
        <<"3����ѯȨֵ����_����"<<endl
        <<"4������ߣ���_��_Ȩֵ��"<<endl
        <<"5��ɾ����"<<endl
        <<"6�������һ���ڽӶ���"<<endl
        <<"7��������ȱ���"<<endl
        <<"8��������ȱ���"<<endl
        <<"9����ʾ��ͨ����"<<endl
        <<"0���˳�"<<endl;
        break;
    }
}
