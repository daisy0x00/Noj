
#include <stdio.h>

int fa,fb;

void dfs(int a, int b,int k)  //��kö��״̬��a����ȡk,b����ȡk,a,b���Զ���ȡk,���������
{                             //��ǰk�������
    if(b==1)                  //
    {
        fb=1;
        if(a==1)             
        fa=1;
    }
    if(k==101||(fa&&fb))         return;  //����ȷ����a>b�ͺ���Ҫ��
    if(a%k==0)  dfs(a/k,b,k+1);   // ö��a�����п������������b��ȡ��һ���
    if(fa&&fb) return;
    if(b%k==0)  dfs(a,b/k,k+1);   // ö��b�����п������������a��ȡ��һ�����
    if(fa&&fb) return;             
    dfs(a,b,k+1);                 //�����ܵ������
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