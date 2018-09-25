#include <stdio.h>

int main()
{
	int m,n,x;

	scanf("%d %d",&n,&m);

	while(n != 0)
	{
		x = 2 * (m - 1);
		m = x;
		n--;
	}

	printf("%d\n",x);
}