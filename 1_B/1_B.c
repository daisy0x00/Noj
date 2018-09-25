#include <stdio.h>

int main()
{
	int i,sum,t;

	while(scanf("%d",&t) != EOF)
	{
		sum = 0;
		
		for(i = 1 ; i < t ; i++)
		{
			if(t % i == 0)
			{
				sum += i;
			}
		}

		if(sum == t)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

	}
}