#include <stdio.h>

#define N 20

int main()
{
	int n,i,a[N],sum;

	
	while(scanf("%d",&n)!=EOF){
		
		sum = 0;

		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}

		printf("%d\n",sum);
	}

	

	return 0;
}