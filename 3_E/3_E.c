#include <stdio.h>

char a[10];
int n;

void output();
void swap(char *a,char *b);
void search(int m);

int main()
{
	int i;
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		a[i] = 'a' + i;
	}

	search(0);
}

void search(int m)
{
	int i;

	if(m == n)
	{
		output();
	}
	else
	{
		for(i = m; i < n; i++)
		{
			swap(&a[i],&a[m]);
			search(m + 1);
			swap(&a[i],&a[m]);
		
		}
	}
}

void swap(char *a,char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void output()
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%c",a[i]);
	}

	printf("\n");
}
