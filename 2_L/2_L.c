#include <stdio.h>


int main()
{
    int i, j, queen[4][8];
    int n,flag;

	flag = 1;
	
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 8 ; j++)
        {
			scanf("%d",&queen[i][j]);
        }
    }

	scanf("%d",&n);
	for(i = 0 ; i < 3 ; i++)
	{
		if(queen[i][n] == 1)
		{
			flag = 0;
            
		}
	}
	
	for(i = 2 , j = n - 1 ; i >= 0 , j >= 0 ; i-- , j--)
	{
		if(queen[i][j] == 1)
		{
			flag = 0;
			
		}
	}
	
	for(i = 2 , j = n + 1 ; i >= 0 , j < 8 ; i-- , j++)
	{
		
		if(queen[i][j] == 1)
		{
			
			flag = 0;
		}
	}
	if(flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
    return 0;
}

