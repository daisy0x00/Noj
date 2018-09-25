#include <stdio.h>
#include <math.h>

int sum = 0;
int x[10];
int flag[10][10];
int t = 1;

void QueenBacktrack(int t);
int Judge(int t);
void output();

int main()
{
	int i,j;
	for(i = 1; i <= 8; i++)
	{
		for(j = 1; j <= 8; j++)
		{
			flag[i][j] = 0;
		}
	}
	QueenBacktrack(1);
}

void QueenBacktrack(int t)
{
	int i;
	if(t > 8)
	{
		sum++;    // 解法计数器加一
		output();    // 输出本次求得的解
	}
	else
	{
		for(i = 1; i <= 8; i++)
		{
			// 将第t行的皇后放在了第i列
			x[t] = i;
			// 判断放置在该位置是否合理，如果合理则开始考虑下一行皇后的位置
			if(Judge(t))
			{
				flag[t][x[t]] = 1;
				QueenBacktrack(t + 1);
				flag[t][x[t]] = 0;
			}
		}
	}
}

int Judge(int t)
{
	int j;
	for(j = 1; j < t; j++)
	{
		// 第t个皇后和前面的t - 1个皇后是否在同一列或者同一条斜线上，若有返回0
		if(abs(t - j) == abs(x[t] - x[j]) || x[t] == x[j])
		{
			return 0;
		}
	}
	return 1;
}

void output()
{
	int i,j;
	
	printf("No %d:\n",t);
	t++;
	for(i = 1; i <= 8; i++)
	{
		for(j = 1; j <= 8; j++)
		{
			if(flag[i][j] == 1)
			{
				printf("A");
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
	}
	
}