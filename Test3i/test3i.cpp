#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void search(int m);

int n, c;
int w[10], p[10];
int sumW, sumP, maxP;

int main()
{
	int i;
    while(cin>>n>>c)
    {
        if(n==0 && c==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            cin>>w[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
        }
        sumP = 0; //Ŀǰ�ܼ�ֵ
        sumW = 0; //Ŀǰ������
        maxP = 0; //�������

        search(0);
        cout<<maxP<<endl;

    }

    return 0;
}

void search(int m)
{
    if(m == n) //����������ײ�
    {
        if(sumW <= c)
        {
            maxP = max(maxP, sumP); //һֱ�������н�������ֵ
        }
    }
    else
    {
        search(m+1);//��װm��ֱ��ȥװm+1
        if(sumW <= c)
        {
            sumP += p[m];
            sumW += w[m];
            search(m+1); //װ��m֮����ȥװm+1
            /*
              �����m֮���״̬�Ѿ����ݵ���һ���ˣ�
              ΪʲôҪɾ��m�أ�
              ����Ϊ�ǿ����кܶ��֧�������ɾ�����ټ���������֧��ʱ�򣬻Ὣ֮ǰ��֧��sumP��sumW����ȥ
              �����Ǹ�״̬�Ѿ����ݵ���һ���ˣ�����ɾ��֮�󣬲�Ӱ��˷�֧�ļ��㡣
            */
            sumP -= p[m];
            sumW -= w[m];
        }
    }
}

