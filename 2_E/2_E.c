#include <stdio.h>

int commonDivisor(int a,int b);

int main()
{
	int a,b;

	scanf("%d %d",&a,&b);

	printf("%d\n",commonDivisor(a,b));
}

int commonDivisor(int a,int b)
{
	while(1)
	{
		if(a > b)
		{
			a -= b;
		}
		else if(a < b)
		{
			b -= a;
		}
		else
		{
			return a;
		}
	}
}

/*int commonDivisor(int a,int b)
{
	int t;
	
	t = a - b;

	if(t == 0 && t == b)
	{
		return t;
	}
	else 
	{
		if(t > b)
		{
			commonDivisor(t,b);
		}
		else
		{
			commonDivisor(b,t);
		}
	}

}*/