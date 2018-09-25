#include <stdio.h>

int main()
{
	int n,t;

	scanf("%d",&n);

	if(n > 0)
	{
		while(n != 0)
		{
			t = n % 10;
			printf("%d\n",t);
			n = n / 10;
		}
	}
}