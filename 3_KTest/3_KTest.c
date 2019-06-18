#include <stdio.h>
#include <stdlib.h>

int a[10000][10000],h,l;

void search(int i,int j)
{
    if(a[i][j] == 0)
    {
        a[i][j] = 2;
        if(j - 1 >= 0)
            search(i,j - 1);
        if(i + 1 < h)
            search(i + 1,j);
        if(j + 1 < l)
            search(i,j + 1);
        if(i - 1 >= 0)
            search(i - 1,j);
    }
}
int main()
{
	int i,j,m,n,t,b;
    scanf("%d %d",&h,&l);
    
    scanf("%d %d",&i,&j);
    scanf("%d %d",&m,&n);
  
    for(t = 0; t < h; t++)
        for(b = 0; b < l; b++)
            scanf("%d",&a[t][b]);
    search(i,j);
    if(a[m][n] == 2)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}