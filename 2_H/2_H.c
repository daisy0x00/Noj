#include<stdio.h>



int main()
{
	int m,n,i,s,k;
	
	int a[100];
	
	scanf("%d %d",&m,&n);
	
	for(i = 0 ; i < 2 * m ; i++)
	{
		a[i] = i + 1;
	}
	
	s = 0;
	k = 0;
	
	while(s < m)
	{
		for(i = 0 ; i < 2 * m ; i++)
		{
			if(a[i] != 0)
			k++;//报数
			if(k == n)
			{
				a[i] = 0;
				s++;
				k = 0;
			}
			if(s == m)
			{
				break;//当第m个人被淘汰时，退出此循环	
			}
		}
		if(s != m)
		{
			i = 0;
		}
	}

	while(s < 2 * m - 1)//换方向继续循环淘汰
	{
		while(i >= 0)
		{
			if(a[i] != 0)
			k++;
			if(k == n)
			{
				a[i] = 0;
				s++;
				k = 0;
				if(s == 2 * m - 1)
				break;
			}
			i--;
		}
		i = 2 * m - 1;
	}
	for(i = 0 ; i < 2 * m ; i++)
	{
		if(a[i] != 0)
		{
			printf("%d\n",a[i]);
		}
	
	}
	return(0);
}