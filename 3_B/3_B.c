#include <stdio.h>

long Fibonacci(int k,int m);

int main()
{
	int k,m;

	scanf("%d %d",&k,&m);

	printf("%ld\n",Fibonacci(k,m));
}

// ���ݷ�Χ�����⣬д����ʱ��ָ��
// int Fibonacci(int k,int m)
long Fibonacci(int k,int m)
{
	//int i,sum;
	//sum = 0;

	if(m < k - 1)
	{
		return 0;
	}
	else if(m == k || m == k - 1)
	{
		return 1;
	}
	/*
	else
	{
		for(i = m - k; i <= m - 1; i++)
		{
			sum += Fibonacci(k,i);
		}
		return sum;
	}
	*/
	else
	{
		return 2 * Fibonacci(k,m - 1) - Fibonacci(k,m - k - 1);
	}

}