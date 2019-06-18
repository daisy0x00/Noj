#include <stdio.h>
#include <math.h>

#define N 1001

int main()
{
	int c[N], a, b, i, j;

	scanf("%d %d", &a, &b);

	for(i = 2; i <= b; i++)
	{
		c[i] = 1;
	}

	for(i = 2; i <= sqrt(b); i++)
	{
		for(j = 2; j * i <= b; j++)
		{
			c[j * i] = 0;
		}
	}

	for(i = 2; i <= b; i++)
	{
		if(c[i] == 1)
		{
			printf("%d\n", i);
		}	
	}
	return 0;
}
