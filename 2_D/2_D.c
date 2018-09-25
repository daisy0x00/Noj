#include <stdio.h>
#include <math.h>

int GetSum(int n);

int main()
{
	int i,num;
	
	for(i = 2 ; i <= 10000 ; i++)
	{
		num = GetSum(i);
		if(GetSum(num) == i && i < num)
		{
			printf("%d %d\n",i,num);
		}
	}
	return 0;
}

int GetSum(int n)
{
	int i,sum = 0;

	for(i = 1 ; i * i <= n ; i++)
	{
		if(n % i == 0)
		{
			if(i == 1 || i * i == n)
			{
				sum += i;
			}
			else
			{
				sum += i + n / i;
			}
		}
	}

	return sum;
}