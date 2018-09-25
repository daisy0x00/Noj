#include <stdio.h>

int main()
{
	int n,sum,t,i,tmp;

	scanf("%d",&n);

	sum = 0;
	
	for(i = 1 ; i <= n ; i++)
	{
		t = 1; 

		tmp = i;
		while(tmp != 0)
		{
			t *= tmp;
			tmp--;
		}

		sum += t;
	}

	printf("%d\n",sum);
}