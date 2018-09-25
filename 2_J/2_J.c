#include <stdio.h>

#define N 21
#define M 43

int main()
{
	int a[N],b[N],c[M],n,m,i,j,k1,k2,tmp;
	
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}

	scanf("%d",&m);
	for(i = 0 ; i < m ; i++)
	{
		scanf("%d",&b[i]);
	}


	for(j = 0 ; j < n + m ; j++)
	{
		if(j < n)
		{
			c[j] = a[j];
		}
		else
		{
			c[j] = b[j - n];
		}
	}

	for(k1 = 0 ; k1 < m + n - 1 ; k1++)
	{
		for(k2 = k1 + 1 ; k2 < m + n ; k2++)
		{
			if(c[k1] > c[k2])
			{
				tmp = c[k1];
				c[k1] = c[k2];
				c[k2] = tmp;
			}
		}
	}

	for(j = 0;j < n + m ;j++)
	{
		printf("%d\n",c[j]);
	}
	
}