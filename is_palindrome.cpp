//回文数

/*
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数.

*/

//转一半的数字
bool isPalindrome(int x)
{
    //需要保证最后一位不能为0
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int reverse = 0;

    while(x > reverse)
    {
        reverse = reverse * 10 + x %10;
        x/=10;
    }

    return  x == reverse || x == reverse/10;
}