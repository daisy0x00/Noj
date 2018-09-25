#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 21



int tmp[N]; // 临时存储操作数和中间的值
int sLen;
int b[N];
int j = 0;

int add(char s[]);

int main()
{
	//碰到的第一个问题，粗心把s[]的类型设置为int，已解决
	//int s[N];
	char s[N];
	//test
	int i,t;
	

	scanf("%s",s);
	
	sLen = strlen(s);

	printf("\n***********************test*************************\n");
	printf("sLen = %d\n",sLen);

	for(i = 0; i < sLen; i++)
	{
		printf("s[%d] = %c\n",i,s[i]);
	}

	printf("\n***********************test*************************\n");
	
	printf("%d\n",add(s));

	
	printf("\n***********************test*************************\n");


	for(t = 0; t < j; t++)
	{
		printf("b[%d] = %d\n",t,b[t]);
	}

	printf("\n***********************test*************************\n");
	
	return 0;
	
}

int add(char s[N])
{
	int i;
		

	// 遍历字符串s如果遇到数字字符则将其转换为数字，并保存到数组b中，b的下标加一
	// 如果遇到运算符则把b[j-1]和b[j-2]中的数字拿出来进行运算，将运算结果保存到b[j]中
	// 下标加一继续遍历
	
	for(i = 0; i < sLen; i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			// 问题二，运算结果应当保存到当前下标的位置，然后下标加一继续遍历，
			// 之前将它保存着了b[j-2]的位置，数组只是模拟了出栈操作，但实际上并未进行出栈
			switch(s[i])
			{
			case '+' : b[j] = b[j - 2] + b[j - 1];
				j++;
				break;
			case '-' : b[j] = b[j - 2] - b[j - 1];
				j++;
				break;
			case '*' : b[j] = b[j - 2] * b[j - 1];
				j++;
				break;
			case '/' : b[j] = b[j - 2] / b[j - 1];
				j++;
				break;
			}
		}
		else
		{
			//b[j] = atoi(s[i]);
			b[j] = s[i] - 48;
			j++;
		}
	}


	// 问题三，由于每次操作完成后都进行了j++操作，但实际上最终结果是在当时的b[j]中存储的
	// 即结束时的b[j-1]中存储的，所以应该返回b[j-1]而不是b[j]
	return b[j - 1];
	
}
