#include <stdio.h>

int a[3][3]; // �����洢���������
int used[10]; // �����������1~9�Ƿ��ѱ�����

void output();
void judgeOutput(); // �ж����ɵľ����Ƿ�Ϊ���׻÷�
void search(int n);

int main()
{
/*	int i;

	// ��ʼ��used���飬1~9��δ��ʹ�ù�
	for(i = 1; i <= 9; i++)
	{
		used[i] = 0;
	}
	*/
	// �ӱ��Ϊ0�ĸ��ӿ�ʼ���������
	search(0);
	return 0;
}

// �ҽ�ռ� ��n��ʾ���ӵı������9�����ӵı�Ŵ����Ҵ����������α�Ϊ0~8��
void search(int n) 
{
	int i;
	// �ݹ���ڣ���n == 9ʱ����ʾ���еĸ��Ӷ���������֣����Խ����ݹ�
	if(n == 9)
	{
		// �жϱ������ɵľ����Ƿ�������׻÷�������������������������þ��󣬷�����֮
		judgeOutput();
	}
	else
	{
		// �ڱ��n�ĸ���������������1~9��֮�������ǰ�Ե���i�Ѿ���֮ǰ�ĸ���������ˣ�
		// ���������һ�����֣��ҵ�һ��û�б��ù����������ǰ�ĸ����У����������Ϊ
		// ���ù�������used���������������Ƿ�����֮ǰ�ĸ����У�used[i] = 0,��ʾ
		// ����iδ��ʹ��,used[i] = 1��ʾ����i�Ѿ�������֮ǰ�ĸ����С�
		for(i = 1; i <= 9; i++)
		{
			if(used[i] == 0)
			{
				a[n/3][n%3] = i; // ������i����ñ�����
				used[i] = 1;    // ������i���Ϊ��ʹ��
				search(n + 1); // ȥ��һ������������
				used[i] = 0; // ���ݻ�����ʱ��Ҫ�����ȫ����ԭ���Ա�����һ���
			}
		}
	}
}

void judgeOutput()
{
	int i,flag;
	
	flag = 0;

	// �ж�ÿһ��ÿһ��֮���Ƿ�Ϊ15���������15��flag���Ϊ1
	for(i = 0; i < 3; i++)
	{
		if(a[i][0] + a[i][1] + a[i][2] != 15 || a[0][i] + a[1][i] + a[2][i] != 15)
		{
			flag = 1;
			break;
		}	
	}
	// ������ϵ�һ���������ж������Խ���Ԫ��֮���Ƿ�Ϊ15���������15��flag���Ϊ1
	if(flag == 0)
	{
		if(a[0][0] + a[1][1] + a[2][2] != 15 || a[0][2] + a[1][1] + a[2][0] != 15)
		{
			flag = 1;
		}
	}
	


	// ���ҽ���flagΪ0��ʱ�򣬸þ���������׻÷�������������þ���
	if(flag == 0)
	{
		output();
	}	
}

// �������
void output()
{
	int i,j;

	// ��ĿҪ�����ʱ��������֮���ÿո������ÿһ��ĩβ�����пո�
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(j <= 1)
			{
				printf("%d ",a[i][j]);
			}
			if(j == 2)
			{
				printf("%d",a[i][j]);
			}	
		}	
		printf("\n");
	}
	printf("\n");
}