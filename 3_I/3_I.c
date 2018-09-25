#include <stdio.h>

void dfs(int n, int nowC, int nowP);

int sumn, sumc; // sumn表示物品总数，sumc表示背包容量

int w[100]; // 每个物品的重量
int p[100]; // 每个物品的价值



int ans = -1; //上一次的最大总价值

int main()
{
	int i,j;
	int output[100]; // 定义一个数组用于存储每组测试数据的最终结果

	j = 0;

	while(1)
	{
		ans = -1;
		scanf("%d %d",&sumn,&sumc);
		if(sumn == 0 && sumc == 0)
		{
			break;
		}

		for(i = 0; i < sumn; i++)
		{
			scanf("%d",&w[i]);
		}

		for(i = 0; i < sumn; i++)
		{
			scanf("%d",&p[i]);
		}
		dfs(0,0,0);

		output[j] = ans;
		j++;
	}

	for(i = 0; i < j; i++)
	{
		printf("%d\n",output[i]);
	}

}


// n 表示第 N 个物品 ，nowC表示当前已用容量，nowP表示当前的总价值
void dfs(int n, int nowC, int nowP){
	// 到了最后一步 sumn+1
	if(n == sumn){
		// 判断当前的价值和之前产生的价值，求出最大的价值
		if(ans < nowP){
			ans = nowP;
		}
	}
	else
	{
		// n 拿了
		// 需要判断能不能拿
		
		// 如果当前已用容量nowC加上当前物品的重量w[n]不超过背包总容量sumc,则可以拿第n个物品
		// 此时当前已用容量为nowC + w[n],当前的价值为nowP + p[n]
		if(nowC + w[n] <= sumc){
			// 拿完第n个物品之后，继续判断第n + 1 个物品
			dfs(n+1, nowC + w[n], nowP + p[n]);
		}
		// 不拿第n个物品，nowC，nowP没有变化，继续判断第n + 1 个物品能不能拿。
		dfs(n +1,nowC,nowP);	
	}
}