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
	memset(result,0,sizeof(result)); // ��result������г�ʼ��������Ԫ��ȫ����Ϊ0

	// ��һ�������ĳ���Ϊnum1Len,�ڶ��������ĳ���Ϊnum2Len
	// �������ĳ���resultLenΪ���������ĳ���֮��
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
	printf("\n***********************�ָ���***********************\n");
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

	
//	printf("\n��λ�����:\n");
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

	// �ȼ��㲻��λʱ�Ľ��,����������result������
	
	for(i = 0; i < num1Len; i++)
	{
		
		for(j = 0; j < num2Len; j++)
		{

			// ����Ϊ�˷�ֹ����߽�λ��Ԥ��result[1]��������λ�Ľ�λ��
			// ����ļ�������result[1]��ʼ�洢
			// ��������num1��num2���ַ������飬�����������������ת��
			// �����ַ�0~9ת��Ϊ������0~9���ַ�0��ASCIIֵ��48�����Դ˴���ȥ48
			// Ҳ��д��num1[i] - '0'����Ч����һ����

		//	result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			result[i + j + 1] += (num1[i] - 48) * (num2[j] - 48);
			
		}
	}

	/*
	// test
	printf("\n***********************test***********************\n");
	for(i = 0; i <=resultLen; i++)
	{
		printf("δ��λ����ǰresult[%d] = %d\n",i,result[i]);
	}
	printf("\n***********************test***********************\n");

	*/

	// ���н�λ����
	for(i = resultLen - 1; i > 0; i--)
	{
		result[i - 1] = result[i - 1] + result[i] / 10;
		result[i] = result[i] % 10;
	}	
}





