#include <stdio.h>

void dfs(int n, int nowC, int nowP);

int sumn, sumc; // sumn��ʾ��Ʒ������sumc��ʾ��������

int w[100]; // ÿ����Ʒ������
int p[100]; // ÿ����Ʒ�ļ�ֵ



int ans = -1; //��һ�ε�����ܼ�ֵ

int main()
{
	int i,j;
	int output[100]; // ����һ���������ڴ洢ÿ��������ݵ����ս��

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


// n ��ʾ�� N ����Ʒ ��nowC��ʾ��ǰ����������nowP��ʾ��ǰ���ܼ�ֵ
void dfs(int n, int nowC, int nowP){
	// �������һ�� sumn+1
	if(n == sumn){
		// �жϵ�ǰ�ļ�ֵ��֮ǰ�����ļ�ֵ��������ļ�ֵ
		if(ans < nowP){
			ans = nowP;
		}
	}
	else
	{
		// n ����
		// ��Ҫ�ж��ܲ�����
		
		// �����ǰ��������nowC���ϵ�ǰ��Ʒ������w[n]����������������sumc,������õ�n����Ʒ
		// ��ʱ��ǰ��������ΪnowC + w[n],��ǰ�ļ�ֵΪnowP + p[n]
		if(nowC + w[n] <= sumc){
			// �����n����Ʒ֮�󣬼����жϵ�n + 1 ����Ʒ
			dfs(n+1, nowC + w[n], nowP + p[n]);
		}
		// ���õ�n����Ʒ��nowC��nowPû�б仯�������жϵ�n + 1 ����Ʒ�ܲ����á�
		dfs(n +1,nowC,nowP);	
	}
}