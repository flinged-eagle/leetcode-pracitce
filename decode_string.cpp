//字符串解码

/*
    给定一个经过编码的字符串，返回它解码后的字符串。
    编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
    你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

    分析：
        栈的应用
*/

string decodeString(string s) {
    //存储数字的数组
    stack<int> nums;
    //存储[]中间的字符串
    stack<string> strs;
    //存储 [ 的个数
    int bracket = 0;

    string ret;
    int i =0;

    while(i<s.size())
    {
        //获取数字
        if(s[i] <= '9' && s[i] >= '0')
        {
            int num = 0;
            while(s[i] <= '9' && s[i] >= '0')
            {
                num *= 10;
                num += s[i]-'0';
                ++i;
            }
            nums.push(num);
        }

        
        while(s[i] == '[')
        {
            ++bracket;
            ++i;
        }

        //获取 [ ] 中的字符串
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string str;
            while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                str += s[i]; 
                ++i;
            }

            if (banket == 0)
            {
                ret += str;
            }
            else
            {
                //是否需要合并
                if (banket == strs.size())
                {
                    string tmp = strs.top();
                    strs.pop();
                    tmp += str;
                    strs.push(tmp);
                }else
                strs.push(str);
            }
        }
        //当遇到 ] 时
        if (s[i] == ']')
        {
            --banket;
            ++i;

            int num = nums.top();
            nums.pop();
            string tmp = strs.top();
            string str;
            strs.pop();

            for (int j = 0; j < num; ++j)
            {
                str += tmp;
            }

            if (banket != 0)
            {
                //是否需要合并
                if (strs.size() == banket)
                {
                    string tmp2 = strs.top();
                    strs.pop();
                    tmp2 += str;
                    strs.push(tmp2);
                }
                else
                {
                    strs.push(str);
                }
            }
            else
            {
                ret += str;
            }
        }

    }
}