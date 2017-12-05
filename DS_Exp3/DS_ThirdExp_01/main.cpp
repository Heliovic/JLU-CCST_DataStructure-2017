#include <iostream>
#include <BinaryTree.h>

using namespace std;

void ShowMenu(int i);

int main()
{
    BinaryTree* BTree=new BinaryTree();

    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        char ch;
        Node* tmp;
        switch(operation)
        {
        case 1:
            ShowMenu(1);
            BTree->CreateTree();
            break;
        case 2:
            BTree->PreOrder(BTree->root);
            break;
        case 3:
            BTree->InOrder(BTree->root);
            break;
        case 4:
            BTree->PostOrder(BTree->root);
            break;
        case 5:
            ShowMenu(2);
            cin>>ch;
            tmp=BTree->GetFather(ch);
            if(tmp!=NULL)
            {
                cout<<"���ڵ���:"<<endl<<tmp->data<<endl;
            }else{
                cout<<"δ�ҵ�!"<<endl;
            }
            break;
        case 6:
            ShowMenu(2);
            cin>>ch;
            tmp=BTree->Find(ch);
            if(tmp!=NULL)
            {
                cout<<"�ҵ�����:"<<endl<<tmp->data<<endl;
            }else{
                cout<<"δ�ҵ�!"<<endl;
            }
            break;
        case 7:
            /*if(BTree->IsComplete())
            {
                cout<<"��ȫ������!"<<endl;
            }else{
                cout<<"������ȫ������!"<<endl;
            }*/
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
        cout<<endl<<endl<<"���������:";
        cout<<endl<<"1) ����������"<<endl<<"2) �ȸ�����"<<endl<<"3) �и�����"<<endl<<"4) �������"<<endl<<"5����ȡ���ڵ�"<<endl<<"6������"<<endl/*<<"7���ж��Ƿ���ȫ"<<endl*/<<"0) �˳�"<<endl<<endl;
        break;
    case 1:
        cout<<endl<<"�����������ȸ�����:"<<endl;
        break;
    case 2:
        cout<<endl<<"����������:"<<endl;
        break;
    }

}
