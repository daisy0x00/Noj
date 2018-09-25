
#include <stdio.h>

int fa,fb;

void dfs(int a, int b,int k)  //对k枚举状态，a可以取k,b可以取k,a,b可以都不取k,三种情况。
{                             //当前k的情况，
    if(b==1)                  //
    {
        fb=1;
        if(a==1)             
        fa=1;
    }
    if(k==101||(fa&&fb))         return;  //所以确定出a>b就很重要。
    if(a%k==0)  dfs(a/k,b,k+1);   // 枚举a的所有可能情况，保留b的取单一情况
    if(fa&&fb) return;
    if(b%k==0)  dfs(a,b/k,k+1);   // 枚举b的所有可能情况，保留a的取单一情况。
    if(fa&&fb) return;             
    dfs(a,b,k+1);                 //不可能的情况。
}
int main()
{
   int a,b,k;
   while(scanf("%d%d",&a,&b),a!=0||b!=0)
   {
       if(a<b)
        swap(a,b);
       fa=0;
       fb=0;
       k=2;
       dfs(a,b,k);
       if(!fa&&fb)
      printf("%d\n",b);
      else
     printf("%d\n",a);
   }
   return 0;
}