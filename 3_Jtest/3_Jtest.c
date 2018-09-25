#include <stdio.h>
#include <math.h>



int n; // 输入的数字个数 
int sum = 0; // 记录素数环的个数
int aFlag[17]; //标记当前数字有没有被用过
int b[17]; // 用于存放素数环
int isPrimeFlag[33]; // 标记 1~32中的素数

void output();
void isPrime(); // 用筛法记录1~32中的素数
void primeCircle(int t); // 用回溯法求素数环

int main()
{
	int i;
	
	scanf("%d",&n);

	memset(aFlag,0,sizeof(aFlag));
	memset(b,0,sizeof(b));

	//test
	printf("\n*******************test*****************\n");
	for(i = 1; i <= n; i++)
	{
		printf("aFlag[%d] = %d\n",i,aFlag[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	printf("\n");

	printf("\n*******************test*****************\n");

	
	// 设置isPrimeFlag数组元素的值，isPrimeFlag[i]的值为1表示数字i为素数
	isPrime();

	//test
	printf("\n*******************test*****************\n");
	for(i = 1; i <= n; i++)
	{
		printf("aFlag[%d] = %d\n",i,aFlag[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("isPrimeFlag[%d] = %d\n",i,isPrimeFlag[i]);
	}
	printf("\n");

	printf("\n*******************test*****************\n");

	b[1] = 1;
	aFlag[1] = 1;
	primeCircle(1);
	printf("sum = %d\n",sum);
	// 用回溯法求素数环


}

void primeCircle(int t)
{
	// 递归出口 
	// 判断是否到最后一个元素了，同时再判断首尾元素之和是否为素数，
	// 若两个条件同时满足，则找到一个素数环
	int i;

	if(t == n && isPrimeFlag[b[1] + b[n]])
	{
		sum++;
		output();
	}
	else
	{
		// 当前的数拿了	
		// 判断当前的数能不能拿
		
	
		for(i = 2; i <= n; i++)
		{
			if(aFlag[i] == 0 && isPrimeFlag[i + b[t]])
			{
				aFlag[i] = 1;
				b[t + 1] = i;
				primeCircle(t + 1);
				aFlag[i] = 0;
			}		
		}
		
		// a[t]不拿，将这个子枝剪掉(跳出这次循环即可)
		
	} 
}


void isPrime()
{
	int i,j;
	
	//这里有问题，写博客时需标记
//	memset(isPrimeFlag,1,sizeof(isPrimeFlag)); // 将isPrimeFlag数组元素初始化为1，

	for(i = 1; i <= 32; i++)
	{
		isPrimeFlag[i] = 1;
	}
	
	for(i = 2; i <= sqrt(32); i++)
	{
		if(isPrimeFlag[i] == 1)
		{
			for(j = 2; j * i <= 32; j++)
			{
				isPrimeFlag[i * j] = 0;
			}
		}
	}
}

/*

void isPrime()
{
	int i;

	for(i = 1; i <= 32; i++)
	{
		if(i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13 || i == 17 || i == 19 || i == 23 || i == 29 || i == 31)
		{
			isPrimeFlag[i] = 1;
		}
		else
		{
			isPrimeFlag[i] = 0;
		}
	}
}
*/

void output()
{
	int i;
	
	for(i = 1; i <= n; i++)
	{
		printf("%d\t",b[i]);
	}
	printf("\n");
}

