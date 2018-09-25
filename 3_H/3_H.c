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
		sum++;    // �ⷨ��������һ
		output();    // ���������õĽ�
	}
	else
	{
		for(i = 1; i <= 8; i++)
		{
			// ����t�еĻʺ�����˵�i��
			x[t] = i;
			// �жϷ����ڸ�λ���Ƿ�������������ʼ������һ�лʺ��λ��
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
		// ��t���ʺ��ǰ���t - 1���ʺ��Ƿ���ͬһ�л���ͬһ��б���ϣ����з���0
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