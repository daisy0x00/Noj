// 踩气球
// 题目：气球的编号为1~100，两个人分别报出自己所踩气球的编号的乘积
// case1:如果两个人都说了真话，大数赢
// case2:如果两个人都说了假话，大数赢
// case3:如果小数说的真话，大数说的假话，则小数赢
// 注，只要小数说的数字是可能的，则判定此人说了真话，即当大数与小数有冲突时，此时判定大数说的假话，而小数说的真话
// 回溯法来解

#include <stdio.h>

 

// 标记当前的大数说了真话还是假话
int flag;

// 传入的参数m表示几号气球 
// 传入的参数s表示报的小数
// 传入的参数b表示报的大数
void search(int m, int s, int b);

int main()
{
	// flags: 标记小数是真话还是假话，值为1则是真话，否则为假话 
	// tmp: 交换大数小数时的临时变量
	// sml: 报的小数
	// big: 报的大数
	int flags, tmp, sml, big;
	
	scanf("%d %d",&sml,&big);
	
	// 题目要求输入0,0表示结束
	while(sml != 0 || big != 0)
	{
		// 由于输入没有要求必须大数小数的先后顺序
		// 但是给search函数传入参数时总是小数在前，大数在后
		// 所以这里比较两个数，如果大数在前小数在后则先进行交换再给search函数传参
		if(sml > big)
		{
			tmp = sml;
			sml = big;
			big = tmp;
		}

		flag = 0;

		// 先判断小数是否说了真话
		// 只要小数是可能的结果，则判定小数说了真话
		// 这里如果小数说了真话，则flag会置1
		search(2, sml, 1);
		
		// flags用来标记小数是否说了真话。
		// 若为1，则说了真话，否则为假话。 
		flags = flag;

		// 此时flag用来标记大数是否说了真话
		// 若为1，则说了真话，否则为假话。
		flag = 0;

		search(2, sml, big);
		// 当前仅当小数说真话，大数说假话的情况下，才判定小数赢，其余情况下都是大数赢
		if(flags == 1 && flag == 0)
		{
			printf("%d\n",sml);
		}
		else
		{
			printf("%d\n",big);
		}
		
		// 输入下一组测试数据
		scanf("%d %d",&sml,&big);
	
	}
	return(0);
}

void search(int m, int s, int b)
{
	// 大数和小数都说了真话
	if(s == 1 && b == 1)
	{
		flag = 1;
		return;
	}
	// 报的数字是不可能的乘积
	// 即大数和小数都为假
	if(s > 1 && s < m || b > 1 && b < m)
	{
		return;
	}
	// 气球的号码超过了100，即从2~100都遍历完了
	if(m == 101)
	{
		return;
	}
	else
	{
		// 小数踩了m号气球
		if(s % m == 0)
		{
			search(m + 1, s / m, b);
			if(flag == 1)
			{
				return;
			}
		}
		// 大数踩了m号气球 
		if(b % m == 0)
		{
			search(m + 1, s, b / m);
			if(flag == 1)
			{
				return;
			}
		}
		// 没人踩m号气球
		search(m + 1, s, b);
		if(flag == 1)
		{
			return;
		}
	}
}