#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 21



int tmp[N]; // ��ʱ�洢���������м��ֵ
int sLen;
int b[N];
int j = 0;

int add(char s[]);

int main()
{
	//�����ĵ�һ�����⣬���İ�s[]����������Ϊint���ѽ��
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
		

	// �����ַ���s������������ַ�����ת��Ϊ���֣������浽����b�У�b���±��һ
	// ���������������b[j-1]��b[j-2]�е������ó����������㣬�����������浽b[j]��
	// �±��һ��������
	
	for(i = 0; i < sLen; i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			// �������������Ӧ�����浽��ǰ�±��λ�ã�Ȼ���±��һ����������
			// ֮ǰ������������b[j-2]��λ�ã�����ֻ��ģ���˳�ջ��������ʵ���ϲ�δ���г�ջ
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


	// ������������ÿ�β�����ɺ󶼽�����j++��������ʵ�������ս�����ڵ�ʱ��b[j]�д洢��
	// ������ʱ��b[j-1]�д洢�ģ�����Ӧ�÷���b[j-1]������b[j]
	return b[j - 1];
	
}
