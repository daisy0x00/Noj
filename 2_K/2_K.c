#include <stdio.h>

int main()
{
	int a,n;

	scanf("%d",&a);

	n = 1;
	while(a != 1)
	{
		if(a % 2 == 0)
		{
			a = a / 2;
		}	
		else
		{
			a = 3 * a + 1;
		}
		n++;
	}

	printf("%d\n",n);

}