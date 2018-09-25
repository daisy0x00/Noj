#include <stdio.h>
#include <malloc.h>

//构建结构体
typedef struct Node{
	int num;
	struct Node *next;
}JoseNode,*PNode,*HNode;

//函数声明
int JoseInit(HNode *h);
int JoseInsert(JoseNode *h,int pos,int x);
void TraverseList(HNode h,int m);
int JoseDelete(HNode h,int m,int k);

int  main()
{
	int i,n,k;

	HNode h = (HNode )malloc(sizeof(JoseNode));

	scanf("%d %d",&n,&k);
	
	JoseInit(&h);
	
	for(i = 1 ; i <= n ; i++)
	{
		JoseInsert(h,i,i);
	}

	TraverseList(h,n);

	if(k > 1)
	{
		JoseDelete(h,n,k);
	}
	else
	{
		printf("%d\n",n);
	}

	return 0;
}

//初始化循环单链表
int JoseInit(HNode *h)
{
	if(!h)
	{
		return 0;
	}
	else
	{
		(*h)->next = (*h);
		return 1;
	}
}

//单链表插入操作
int JoseInsert(JoseNode *h,int pos,int x)
{
	PNode p = h,q;
	int i = 1;
	if(pos == 1)
	{
		p->num = x;
		p->next = p;
		return 1;
	}
	while(i < pos - 1)
	{
		p = p->next;
		i++;
	}
	q = (PNode)malloc(sizeof(JoseNode));
	q->num = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//遍历
void TraverseList(HNode h,int m)
{
	int i = 0;
	PNode p = h;
	while(i < m)
	{
		p = p->next;
		i++;
	}
}

//出局函数
int JoseDelete(HNode h,int m,int k)
{
	int i;
	PNode p = h,q;
	while(m > 1)
	{
		for(i = 1 ; i < k - 1 ; i++)
		{
			p = p->next;
		}

		q = p->next;
		p->next = q->next;
		free(q);

		p = p->next;
		m--;
	}
	
	printf("%d\n",p->num);
	return 1;
}


















/*int JosephProblem(int n,int m);

int main()
{
	int sum,count;
	
	scanf("%d %d",&sum,&count);

	for(i = 1 ; i <= sum - 1 ; i++)
	{
		result = JosephProblem(sum,count,i) + 1;
	}

	printf("%d\n",result);

}

int JosephProblem(int sum,int value,int n)
{
	if(n == 1)
	{
		return (sum + value - 1) % sum;
	}
	else
	{
		return (JosephProblem(sum - 1,value,n - 1) + value) % sum;
	}
}
*/