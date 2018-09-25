#include <stdio.h>
#include <math.h>


int getPalindrome_odd(int n);
int getPalindrome_even(int n);
int isPrime(int n);
int getGigit(int n);

int main()
{
	int a,b,i;
	int num,pal;

	scanf("%d %d",&a,&b);

	
	if(a <= 11)
	{
		for(i = a ; i <= 11 && i <= b ; i++)
		{
			if(isPrime(i))
			{
				printf("%d\n",i);
			}
		}
	}
	
	num = getGigit(b);
	
	if(b > 100)
	{
		for(i = 10 ; i < pow(10, num / 2 + 1) ; i++)
		{
			pal = getPalindrome_odd(i);
			
			if(pal >= a && pal <= b)
			{
				if(isPrime(pal))
				{
					printf("%d\n",pal);
				}
			}
		}
	}
	

	return 0;
}

int getPalindrome_odd(int n)
{
	int palindrome = n;
	n /= 10;

	while(n)
	{
		palindrome = palindrome * 10 + n % 10;
		n /= 10;
	}

	return palindrome;
}

int getPalindrome_even(int n)
{
	int palindrome = n;
	while(n)
	{
		palindrome = palindrome * 10 + n % 10;
		n /= 10;
	}
	return palindrome;
}

int isPrime(int n)
{
	int i;

	for(i = 2 ; i <= sqrt(n) ; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int getGigit(int n)
{
	int count = 0;

	while(n)
	{
		n /= 10;
		count++;
	}
	return count;
}