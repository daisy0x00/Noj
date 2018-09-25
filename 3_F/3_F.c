#include <stdio.h>

int dumplings(int m, int n);

int main() 
{
	int m,n;
	
	scanf("%d %d",&m,&n);
	
	printf("%d\n",dumplings(m,n));
	
	return 0;
}

int dumplings(int m, int n)
{ 
	if(m<0) 
	{
		return 0;	
	}
	if(m==1 ||n==1) 
	{
		return 1;	
	}
	return dumplings(m,n-1) + dumplings(m-n,n);
}





