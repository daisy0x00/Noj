#include <stdio.h>
#include <math.h>

int main()
{
	int i,a[3],t;

	for(i = 100 ; i <= 999 ; i++)
	{
		t = i;
		a[0] = t % 10;
		t = i / 10;
		a[1] = t % 10;
		a[2] = t / 10;

		if((pow(a[0],3) + pow(a[1],3) + pow(a[2],3)) == i)
		{
			printf("%d\n",i);
		}
	}
}