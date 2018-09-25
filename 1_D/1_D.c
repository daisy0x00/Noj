#include <stdio.h>

#define N 20

int main()
{
	int n,a[N],i,t;

	scanf("%d",&n);

	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}

	t = a[0];
	for(i = 0 ; i < n ; i++)
	{
		if(t > a[i])
		{
			t = a[i];
		}
	}

	printf("%d\n",t);
	

}