#include <iostream>
#include <Queue.h>

using namespace std;
void ShowMenu(int i);

int main()
{
    Queue* queue=new Queue();

    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        int in;
        switch(operation)
        {
        case 1:
            ShowMenu(1);
            cin>>in;
            queue->Insert(in);
            break;
        case 2:
            queue->Delete();
            break;
        case 3:
            if(queue->front!=NULL)
            cout<<endl<<'['<<queue->Front()<<']'<<endl;
            break;
        case 4:
            queue->Print();
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
        cout<<endl<<"�����������";
        cout<<endl<<"1) �����β"<<endl<<"2) ɾ������"<<endl<<"3) ��ȡ����"<<endl<<"4) ��ʾ����"<<endl<<"0) �˳�"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"���������Ԫ�أ�"<<endl;
    }

}
