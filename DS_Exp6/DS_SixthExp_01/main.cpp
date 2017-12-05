#include <iostream>
#include <QuickSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits>

#define RUN_TIME 10

using namespace std;

int main()
{
    srand(time(0));
    int Number=0;
    cin>>Number;
    long* CTimes=new long[RUN_TIME];
    long long totalTime=0;
    ofstream outfile("stat.txt",ios::out);
    ofstream clear("sort.txt",ios::trunc);
    clear.close();
    ofstream os("sort.txt",ios::app);
    time_t EndStamp,BeginStamp=time(NULL);
    for(int i=0;i<RUN_TIME;i++)
    {
        //cin>>Number;
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"��"<<i+1<<"����������С���"<<endl;
        os<<"//////////////////////////"<<"��"<<i+1<<"��"<<"//////////////////////////"<<endl<<endl;
        cout<<"����������ɴ�����Ԫ�ء���"<<endl;
        QuickSort* QS=new QuickSort(Number);
        cout<<"�������򡭡�"<<endl;
        QS->Sort(QS->NumberArray,0,QS->num-1);
        cout<<"����У����ȷ�ԡ���"<<endl;
        QS->CheckCorrection();
        CTimes[i]=QS->counter;
        totalTime+=QS->counter;
        cout<<endl<<"�Ƚϴ���: "<<QS->counter<<endl; //Comparison Time
        cout<<"���ڱ������ݡ���"<<endl;
        QS->WriteOut();
        delete QS;
        outfile<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    EndStamp=time(NULL);
    cout<<"����ʱ��(s): "<<EndStamp-BeginStamp<<endl;
    cout<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;

    return 0;
}
