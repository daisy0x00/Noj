#include <stdio.h>
#include <string.h>

#define N 1001
#define M 2002

int num1Len,num2Len,resultLen;
char num1[N],num2[N];
int result[M];

void Multiplication(int num1Len,int num2Len);

int main()
{
	
//	int i,num1Len,num2Len,resultLen;

	int i;
	scanf("%s",num1);
	scanf("%s",num2);
	memset(result,0,sizeof(result)); // 对result数组进行初始化，将其元素全部置为0

	// 第一个大数的长度为num1Len,第二个大数的长度为num2Len
	// 计算结果的长度resultLen为两个大数的长度之和
	num1Len = strlen(num1);
	num2Len = strlen(num2);
	resultLen = num1Len + num2Len;

	/*
	// test
	printf("num1Len = %d\nnum2Len = %d\nresultLen = %d\n",num1Len,num2Len,resultLen);
	for(i = 0; i <=num1Len; i++)
	{
		// test
		printf("num1[%d] = %d\n",i,num1[i]);
	}
	printf("\n***********************分割线***********************\n");
	for(i = 0; i <num2Len; i++)
	{
		// test
		printf("num2[%d] = %d\n",i,num2[i]);
	}
	
	// test
	for(i = 0; i <=resultLen; i++)
	{
		result[i] = 0;
	}
	*/
	Multiplication(num1Len,num2Len);

	
//	printf("\n进位处理后:\n");
	if(result[0] == 0)
	{
		for(i = 1; i < resultLen; i++)
		{
			// test
			printf("%d",result[i]);
		}
	}
	else
	{
		for(i = 0; i < resultLen; i++)
		{
			printf("%d",result[i]);
			//printf("%d",result[i]);
		}
	}
	printf("\n");
	
}

void Multiplication(int num1Len,int num2Len)
{
	int i,j;

	// 先计算不进位时的结果,将结果存放在result数组中
	
	for(i = 0; i < num1Len; i++)
	{
		
		for(j = 0; j < num2Len; j++)
		{

			// 这里为了防止最左边进位，预留result[1]来存放最高位的进位，
			// 这里的计算结果从result[1]开始存储
			// 由于数组num1和num2是字符型数组，所以这里进行了类型转换
			// 即把字符0~9转换为数数字0~9，字符0的ASCII值是48，所以此处减去48
			// 也可写成num1[i] - '0'，其效果是一样的

		//	result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			result[i + j + 1] += (num1[i] - 48) * (num2[j] - 48);
			
		}
	}

	/*
	// test
	printf("\n***********************test***********************\n");
	for(i = 0; i <=resultLen; i++)
	{
		printf("未进位处理前result[%d] = %d\n",i,result[i]);
	}
	printf("\n***********************test***********************\n");

	*/

	// 进行进位处理
	for(i = resultLen - 1; i > 0; i--)
	{
		result[i - 1] = result[i - 1] + result[i] / 10;
		result[i] = result[i] % 10;
	}	
}





