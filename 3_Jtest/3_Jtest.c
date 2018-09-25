#include <stdio.h>
#include <math.h>



int n; // ��������ָ��� 
int sum = 0; // ��¼�������ĸ���
int aFlag[17]; //��ǵ�ǰ������û�б��ù�
int b[17]; // ���ڴ��������
int isPrimeFlag[33]; // ��� 1~32�е�����

void output();
void isPrime(); // ��ɸ����¼1~32�е�����
void primeCircle(int t); // �û��ݷ���������

int main()
{
	int i;
	
	scanf("%d",&n);

	memset(aFlag,0,sizeof(aFlag));
	memset(b,0,sizeof(b));

	//test
	printf("\n*******************test*****************\n");
	for(i = 1; i <= n; i++)
	{
		printf("aFlag[%d] = %d\n",i,aFlag[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	printf("\n");

	printf("\n*******************test*****************\n");

	
	// ����isPrimeFlag����Ԫ�ص�ֵ��isPrimeFlag[i]��ֵΪ1��ʾ����iΪ����
	isPrime();

	//test
	printf("\n*******************test*****************\n");
	for(i = 1; i <= n; i++)
	{
		printf("aFlag[%d] = %d\n",i,aFlag[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	printf("\n");

	for(i = 1; i <= n; i++)
	{
		printf("isPrimeFlag[%d] = %d\n",i,isPrimeFlag[i]);
	}
	printf("\n");

	printf("\n*******************test*****************\n");

	b[1] = 1;
	aFlag[1] = 1;
	primeCircle(1);
	printf("sum = %d\n",sum);
	// �û��ݷ���������


}

void primeCircle(int t)
{
	// �ݹ���� 
	// �ж��Ƿ����һ��Ԫ���ˣ�ͬʱ���ж���βԪ��֮���Ƿ�Ϊ������
	// ����������ͬʱ���㣬���ҵ�һ��������
	int i;

	if(t == n && isPrimeFlag[b[1] + b[n]])
	{
		sum++;
		output();
	}
	else
	{
		// ��ǰ��������	
		// �жϵ�ǰ�����ܲ�����
		
	
		for(i = 2; i <= n; i++)
		{
			if(aFlag[i] == 0 && isPrimeFlag[i + b[t]])
			{
				aFlag[i] = 1;
				b[t + 1] = i;
				primeCircle(t + 1);
				aFlag[i] = 0;
			}		
		}
		
		// a[t]���ã��������֦����(�������ѭ������)
		
	} 
}


void isPrime()
{
	int i,j;
	
	//���������⣬д����ʱ����
//	memset(isPrimeFlag,1,sizeof(isPrimeFlag)); // ��isPrimeFlag����Ԫ�س�ʼ��Ϊ1��

	for(i = 1; i <= 32; i++)
	{
		isPrimeFlag[i] = 1;
	}
	
	for(i = 2; i <= sqrt(32); i++)
	{
		if(isPrimeFlag[i] == 1)
		{
			for(j = 2; j * i <= 32; j++)
			{
				isPrimeFlag[i * j] = 0;
			}
		}
	}
}

/*

void isPrime()
{
	int i;

	for(i = 1; i <= 32; i++)
	{
		if(i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13 || i == 17 || i == 19 || i == 23 || i == 29 || i == 31)
		{
			isPrimeFlag[i] = 1;
		}
		else
		{
			isPrimeFlag[i] = 0;
		}
	}
}
*/

void output()
{
	int i;
	
	for(i = 1; i <= n; i++)
	{
		printf("%d\t",b[i]);
	}
	printf("\n");
}

