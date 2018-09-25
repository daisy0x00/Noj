#include <stdio.h>

int n;
int a[20];

void output();
void search(int m);

int main()
{
	scanf("%d",&n);
	search(0);
}

void search(int m)
{
	if(m == n)
	{
		output();
	}
	else
	{
		a[m] = 0;
		search(m + 1);
		a[m] = 1;
		search(m + 1);
	}
}

void output()
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}

	printf("\n");
}