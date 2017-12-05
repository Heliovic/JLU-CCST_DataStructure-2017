#include <iostream>
#include <SSort.h>
#include <QuickSort.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define RUN_TIME 10

using namespace std;

int main()
{
    srand(time(0));
    long* CTimes=new long[RUN_TIME];
    long long totalTime=0;
    ofstream clearStat("stat.txt",ios::trunc);
    clearStat.close();
    ofstream outfile("stat.txt",ios::app);
    ofstream outfileQ("statQ.txt",ios::out);
    ofstream outfileS("statS.txt",ios::out);
    ofstream clearQ("sortQ.txt",ios::trunc);
    clearQ.close();
    ofstream clearS("sortS.txt",ios::trunc);
    clearS.close();
    ofstream osQ("sortQ.txt",ios::app);
    ofstream osS("sortS.txt",ios::app);
    cout<<"������N-��������"<<endl<<endl;
    int Number=0;
    cin>>Number;
    outfile<<endl<<"//////////////////////////"<<"��������"<<"//////////////////////////"<<endl<<endl;
    for(int i=0;i<RUN_TIME;i++)
    {
        //cin>>Number;
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"��"<<i+1<<"����������С���"<<endl;
        osQ<<"//////////////////////////"<<"��"<<i+1<<"��"<<"//////////////////////////"<<endl<<endl;
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
        outfileQ<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
        outfile<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    //cout<<"����ʱ��(s): "<<EndStamp-BeginStamp<<endl;
    //cout<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileQ<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileQ.close();

    cout<<"������N-ѡ������"<<endl<<endl;
    totalTime=0;
    cin>>Number;
    outfile<<endl<<"//////////////////////////"<<"ѡ������"<<"//////////////////////////"<<endl<<endl;
    for(int i=0;i<RUN_TIME;i++)
    {
        cout<<"////////////////////////////////////////////";
        cout<<endl<<"��"<<i+1<<"����������С���"<<endl;
        osS<<"//////////////////////////"<<"��"<<i+1<<"��"<<"//////////////////////////"<<endl<<endl;
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
        outfileS<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
        outfile<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }
    cout<<"////////////////////////////////////////////"<<endl<<endl;
    //cout<<"����ʱ��(s): "<<EndStamp-BeginStamp<<endl;
    //cout<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileS<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfile<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    outfileS.close();

    outfile.close();

    clock_t startTime,endTime;
    cout<<"������N-�������򣨴����ݣ�"<<endl<<endl;
    cin>>Number;
    int sum[10][2];
    for(int i=0;i<10;i++)
        for(int j=0;j<2;j++)
            sum[i][j]=0;
    startTime=clock();
    for(int i=0;i<RUN_TIME;i++)
    {
        clock_t start,end;
        start=clock();
        //cout<<"////////////////////////////////////////////";
        //cout<<endl<<"��"<<i+1<<"����������С���"<<endl;
        //cout<<"����������ɴ�����Ԫ�ء���"<<endl;
        QuickSort* QS=new QuickSort(Number,0);
        //cout<<"�������򡭡�"<<endl;
        QS->Sort(QS->NumberArray,0,QS->num-1);
        CTimes[i]=QS->counter;
        totalTime+=QS->counter;
        delete QS;
        end=clock();
        sum[i][0]=start;
        sum[i][1]=end;
        //cout<<"����ʱ�䣺"<<(double)(end-start)/CLOCKS_PER_SEC<<'s'<<endl;
    }
    endTime=clock();
    cout<<endl<<"��ʼʱ�̣�"<<(double)startTime<<endl<<"��ֹʱ�̣�"<<endTime<<endl<<"�ܼ�ʱ�䣺"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<'s'
        <<endl<<"ƽ��ʱ�䣺"<<(double)(endTime-startTime)/(CLOCKS_PER_SEC*RUN_TIME)<<'s'<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"��"<<i+1<<"������ʱ��: "<<(double)(sum[i][1]-sum[i][0])/CLOCKS_PER_SEC<<endl;
    }

    for(int i=0;i<10;i++)
    {
        cout<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }

    cout<<"�ܼƱȽϴ���: "<<(long long)totalTime<<endl<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;

    cout<<endl<<"������N-ѡ�����򣨴����ݣ�"<<endl<<endl;
    cin>>Number;
    startTime=clock();
    for(int i=0;i<RUN_TIME;i++)
    {
        clock_t start,end;
        start=clock();
        //cout<<"////////////////////////////////////////////";
        //cout<<endl<<"��"<<i+1<<"����������С���"<<endl;
        //cout<<"����������ɴ�����Ԫ�ء���"<<endl;
        SSort* SS=new SSort(Number,0);
        //cout<<"�������򡭡�"<<endl;
        SS->Sort();
        CTimes[i]=SS->counter;
        totalTime+=SS->counter;
        delete SS;
        end=clock();
        sum[i][0]=start;
        sum[i][1]=end;
        //cout<<"����ʱ�䣺"<<(double)(end-start)/CLOCKS_PER_SEC<<'s'<<endl;
    }
    endTime=clock();
    cout<<endl<<"��ʼʱ�̣�"<<(double)startTime<<endl<<"��ֹʱ�̣�"<<endTime<<endl<<"�ܼ�ʱ�䣺"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<'s'
        <<endl<<"ƽ��ʱ�䣺"<<(double)(endTime-startTime)/(CLOCKS_PER_SEC*RUN_TIME)<<'s'<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"��"<<i+1<<"������ʱ��: "<<(double)(sum[i][1]-sum[i][0])/CLOCKS_PER_SEC<<endl;
    }

    for(int i=0;i<10;i++)
    {
        cout<<"��"<<i+1<<"������Ƚϴ���: "<<CTimes[i]<<endl;
    }

    cout<<"�ܼƱȽϴ���: "<<(long long)totalTime<<endl<<"ƽ���Ƚϴ���: "<<(long long)totalTime/RUN_TIME<<endl;
    return 0;
}
