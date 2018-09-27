#include <stdio.h>


int n, m;
int l[101][101];

void init(); 

int main()
{
	int i, j;
	
	scanf("%d %d",&n,&m);

	init();

	for(i = 2; i <= n; i++)
	{
		for(j = 2; j <= m; j++)
		{
			// 考虑有空盘子时的情况
			l[i][j] = l[i][j - 1];

			// 当且仅当饺子数大于等于盘子数的时候才有无空盘子的情况
			// 若饺子数小于盘子数则必然会有空盘子存在。
			if(i >= j)
			{
				l[i][j] += l[i - j][j];
			}
		}
	}
	printf("%d\n",l[n][m]);

}

void init()
{
	int i;
	
	// 当饺子数为0或者1时，装法均只有1种
	for(i = 0; i <= m; i++)
	{
		l[0][i] = 1;
		l[1][i] = 1;
	}
	// 当盘子数为1时，装法只有一种（这里不考虑盘子为0的情况）
	for(i = 0; i <= n; i++)
	{
		l[i][1] = 1;
	}
}