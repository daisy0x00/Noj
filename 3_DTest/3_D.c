#include<stdio.h>

int a[3][3]; //用来存储1~9
int used[10]; //用来记录1~9的是否已被填写

void search(int n); 
void testout(); 
void output(); 

int main()
{
	search(0);
	return 0; 
}

void search(int n)
{ 
	int i;
	if(n==9)
		testout(); 
	else 
	{
		for(i=1;i<=9;i++) 
		{ 
			if(used[i]==0) 
			{
				a[n/3][n%3]=i;
				used[i]=1;//表示该数已经被用过，不能再一次使用 
				search(n+1); 
				used[i]=0; //回溯时使used[i]恢复原值
			}
		}
	}
}

void testout() 
{
	int i,flag=1; 
	for(i=0;i<3;i++) 
	{
		if(a[i][0]+a[i][1]+a[i][2]!=15||a[0][i]+a[1][i]+a[2][i]!=15) 
		{
			flag=0;
			break;
		} 
	} 
	if(flag==1) 
	{
		if(a[0][0]+a[1][1]+a[2][2]!=15||a[0][2]+a[1][1]+a[2][0]!=15)    
			flag=0; 
	} 
	if(flag==1) output();
}

void output() 
{
	int i,j;
	for(i=0;i<3;i++) 
	{ 
		for(j=0;j<3;j++) 
		{ 
			if(j<=1)  
			{
				printf("%d ",a[i][j]);    
			}
			if(j==2)    
			{    	
				printf("%d",a[i][j]);    
			} 
		} 
		printf("\n"); 
	} 
	printf("\n");  
}