#include <stdio.h>
#include <math.h>

# define N 1001

int main()
{
	int c[N],a,b,i,j;

	scanf("%d %d",&a,&b);


	for(i = 2 ; i <= b ; i++)
	{
		c[i] = 1;
	}

	for(i = 2 ; i <= sqrt(b) ; i++)
	{
		if(c[i] == 1)
		{
			for(j = 2 ; j * i <= b ; j++)
			{
				c[i * j] = 0;
			}
		}
	}

	for(i = a ; i <= b ; i++)
	{
		if(c[i] == 1)
		{
			printf("%d\n",i);
		}
	}
	return 1;

}