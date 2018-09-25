#include <stdio.h>


int main()
{
	int n,i,flag;

	scanf("%d",&n);
	flag = 0;
	if(n >= 2 && n <= 10000)
	{
		for(i = 2 ; i < n ; i ++)
		{
			if(n % i == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

}