//求 1+2+3+....+n

/*
    求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//构造函数法

class tmp
{
public:
    friend class Solution;
    tmp()
    {
        ++step;
        num += step;
    }
    static int num;
    static int step;
};
int tmp::num = 0;
int tmp::step = 0;
class Solution
{
public:
    int sumNums(int n)
    {
        tmp::num = 0;
        tmp::step = 0;
        new tmp[n];
        return tmp::num;
    }
};

//利用 逻辑运算符 特性

int sumNums(int n)
{
    n && (n+=sumNums(n-1));
    return n;
}