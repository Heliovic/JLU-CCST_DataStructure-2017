#include <iostream>
#include "DisjointSet.h"

using namespace std;

void ShowMenu(int i);

int main()
{
    DisjointSet* DSU;
    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        char x,y;
        switch(operation)
        {
        case 1:
            cout<<endl<<"������Ԫ�ظ���n"<<endl;
            cin>>operation;
            DSU=new DisjointSet(operation);
            break;
        case 2:
            cout<<endl<<"������ȼ۹�ϵ x y��1~n��"<<endl;
            cin>>x>>y;
            DSU->Union(x,y);
            break;
        case 3:
            cin>>x>>y;
            if(DSU->Find(DSU->GetNum(x))==DSU->Find(DSU->GetNum(y)))
            {
                cout<<"��"<<endl;
            }else
            {
                cout<<"��"<<endl;
            }
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
        cout<<endl<<"1) �������鼯"<<endl<<"2) ����ȼ���"<<endl<<"3����ѯ�ȼ۹�ϵ"<<endl<<"0���˳�"<<endl;
        break;
    }
}
