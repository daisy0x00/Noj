#include <stdio.h>

int main()
{
	int a,b,c;

	for(a = 0 ; a < 2 ; a++)
	{
		for(b = 0 ; b < 2 ; b++)
		{
			for(c = 0 ; c < 2 ; c++)
			{
				if((a && !b || !a && b) && (b && !c || !b && c) && (c && a + b == 0 || !c && a + b != 0))
				{
					if(a == 1)
					{
						printf("0\n");
					}
					else if(b == 1)
					{
						printf("1\n");
					}
					else
					{
						printf("2\n");
					}
				}
			}
		}
	}
}