#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int i;
	stack <int> stack1;
	int num1,num2,num3;
	for(i = 0;i<s.length();i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			num2 = stack1.top();
			stack1.pop();
			num1 = stack1.top();
			stack1.pop();

			if(s[i] == '+')
			{
				num3 = num1+num2;
				stack1.push(num3);
			}
			else
				if (s[i] == '-')
				{
					num3 = num1 - num2;
					stack1.push(num3);
				}
				else
					if (s[i] == '*')
					{
						num3 = num1*num2;
						stack1.push(num3);
					}
					else
					{
						num3 = num1/num2;
						stack1.push(num3);
					}
		}
		else
		{
			stack1.push(s[i]-'0');
		}
	}
	cout<<stack1.top()<<endl;
	
	return 0;
}

 


  
  



 