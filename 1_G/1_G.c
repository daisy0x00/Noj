#include <stdio.h>

int main()
{
	int a;

	scanf("%d",&a);
	if(a > 1 && a <= 10000)
	{
		printf("%d\n",a);
		while(a != 1)
		{
			if(a % 2 == 1)
			{
				a = 3 * a + 1;
				printf("%d\n",a);
			}	
			else
			{
				a = a / 2;
				printf("%d\n",a);
			}
		}
	}
	else
	{
		return 0;
	}
	
	
}