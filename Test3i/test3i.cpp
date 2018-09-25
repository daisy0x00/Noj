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
        sumP = 0; //目前总价值
        sumW = 0; //目前总重量
        maxP = 0; //最大质量

        search(0);
        cout<<maxP<<endl;

    }

    return 0;
}

void search(int m)
{
    if(m == n) //搜索到了最底层
    {
        if(sumW <= c)
        {
            maxP = max(maxP, sumP); //一直保留所有结果的最大值
        }
    }
    else
    {
        search(m+1);//不装m，直接去装m+1
        if(sumW <= c)
        {
            sumP += p[m];
            sumW += w[m];
            search(m+1); //装完m之后再去装m+1
            /*
              你加完m之后的状态已经传递到下一层了；
              为什么要删除m呢？
              是因为那棵树有很多分支，如果不删掉，再计算其他分支的时候，会将之前分支的sumP和sumW带过去
              由于那个状态已经传递到下一层了，所以删掉之后，不影响此分支的计算。
            */
            sumP -= p[m];
            sumW -= w[m];
        }
    }
}

