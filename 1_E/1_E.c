#include <stdio.h>
#include <math.h>


int main()
{
	int a[3][2],i,j,flag;
	double b[3];

	flag = 0;

	for(i = 0 ; i < 3 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	b[0] = pow((a[0][0] - a[1][0]),2) + pow((a[0][1] - a[1][1]),2);
	b[1] = pow((a[0][0] - a[2][0]),2) + pow((a[0][1] - a[2][1]),2);
	b[2] = pow((a[1][0] - a[2][0]),2) + pow((a[1][1] - a[2][1]),2);


	if(b[0] > b[1])
	{
		if(b[0] > b[2])
		{
			if(b[0] == b[1] + b[2])
			{
				flag = 1;
			}
		}
		else
		{
			if(b[2] == b[0] + b[1])
			{
				flag = 1;
			}
		}
	}
	else
	{
		if(b[1] > b[2])
		{
			if(b[1] == b[0] + b[2])
			{
				flag = 1;
			}
		}
		else
		{
			if(b[2] = b[0] + b[1])
			{
				flag = 1;
			}
		}
	}

	printf("%d\n",flag);
}