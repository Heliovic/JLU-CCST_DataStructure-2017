#include <iostream>
#include <SSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

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
        SSort* SS=new SSort(Number);
        cout<<"�������򡭡�"<<endl;
        SS->Sort();
        cout<<"����У����ȷ�ԡ���"<<endl;
        SS->CheckCorrection();
        CTimes[i]=SS->counter;
        totalTime+=SS->counter;
        cout<<endl<<"�Ƚϴ���: "<<SS->counter<<endl; //Comparison Time
        cout<<"���ڱ������ݡ���"<<endl;
        SS->WriteOut();
        delete SS;
        outfile<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    EndStamp=time(NULL);
    cout<<"����ʱ��(s): "<<EndStamp-BeginStamp<<endl;
    cout<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    return 0;
}
