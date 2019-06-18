# coding:utf-8
# 踩气球

"""

六一儿童节，小朋友们做踩气球游戏，气球的编号是1～100，两位小朋友各踩了一些气球，要求他们报出自己所踩气球的编号的乘积。
现在需要你编一个程序来判断他们的胜负，判断的规则是这样的：
    如果两人都说了真话，数字大的人赢；
    如果两人都说了假话，数字大的人赢；
    如果报小数字的人说的是真话而报大数字的人说谎，则报小数字的人赢（注意：只要所报的小数字是有可能的，即认为此人说了真话）。


A小  B大     結果
真   真       B
真   假       A
假   假       B


只要证明 小的真  大的假   则输出小的数，否则输出大的


1.1-100每个气球有三种情况，被A踩，被B踩，米有踩
2.如果A踩了一个数x，那他就只能再踩乘积= a/x的数，同理b b/x
3.踩了的数不能再次踩
4.a/x == 1时 a 为真
5.a/x == 1 and b/x == 1时，a b为真  递归结束
6.遍历了所有情况，a/x != 1 a为假，
7.如果深度优先遍历了所有数一次，但a/x != 1 and b/x != 1 后退，遍历其他情况


"""
fa=0
fb=0
DEBUG = True

def check(a, b, m, buf_a, buf_b):
    global fa,fb

    if a==1:
        fa=1
        if b==1:
            fb = 1
            return

    while m > 1:

        if a>=m and a % m==0:
            if fa != 1:
                buf_a.append(m)
            check(a/m, b, m-1, buf_a, buf_b)
            if fa!= 1:
                buf_a.pop()
        if  b >= m and b % m == 0:
            if fb != 1:
                buf_b.append(m)
            check(a, b/m, m-1,buf_a,buf_b)
            if fb != 1:
                buf_b.pop()
        m-=1


def check_nums(a, b, m):
    if a <= 0:  # A假 --->B
        return b
    if a <= m and b <= m:  # A真 B真-->B
        return b

    buf_a, buf_b = [], []

    check(a, b, m, buf_a, buf_b)
    if DEBUG:
        print(buf_a, buf_b)
    if fa and not fb:
        return a

    return b

import sys
import traceback

while True:
    fa = 0
    fb = 0
    try:
        line = sys.stdin.readline()
        a, b = line.strip().split(" ")

        if a == b == "0":
            break

        a, b = (lambda x, y: (int(y), int(x)) if x>y else (int(x),int(y)))(a, b)

        print(check_nums(a, b, 100))

    except:
        print(traceback.format_exc())
        pass