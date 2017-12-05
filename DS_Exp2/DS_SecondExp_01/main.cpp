#include <iostream>
#include <Stack.h>

using namespace std;

void ShowMenu(int i);

int main()
{
    Stack* stack=new Stack();
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
            stack->Push(in);
            break;
        case 2:
            stack->Pop();
            break;
        case 3:
            if(stack->top!=-1)
            cout<<endl<<'['<<stack->Peek()<<']'<<endl;
            break;
        case 4:
            stack->Print();
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
        cout<<endl<<"1) ѹջ"<<endl<<"2) ��ջ"<<endl<<"3) ��ȡջ��"<<endl<<"4) ��ʾջ��״��"<<endl<<"0) �˳�"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"������ѹջԪ�أ�"<<endl;
    }

}
