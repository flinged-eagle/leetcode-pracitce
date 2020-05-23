//最小覆盖子串

/*
    给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
    所有字符包含重复
*/

//保存的是窗口中的字符和 T 中所含的字符
unordered_map<char, int> ori_t, cnt_w;

//检查窗口中是否全部含有T中的字符
bool check()
{
    for(const auto&p : ori_t)
    {
        if(cnt_w[p.first] < p.second)
        {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    for(const auto&c :  t)
    {
        ++ori_t[c];
    }

    int l=0, r= -1;     //左右边界
    //len 窗口长度 ansL 窗口左边界
    int len = INT_MAX, ansL = -1; 

    //需要将s.size() 转为int类型 否则会出现r隐式转换为 size_t
    while(r < (int)s.size())
    {
        // t 中含有这个字符
        if(ori_t.find(s[++r]) != ori_t.end())
        {
            ++cnt_w[s[r]];
        }

        //窗口的移动 保证其中含最少字符
        while(check() && l <= r)
        {
            //左右边界距离 小于窗口长度
            if(r-l+1 < len)
            {
                len = r-l+1;
                //保存最小窗口的左边界
                ansL = l;
            }
            //t中含有字符 s[l]
            if(ori_t.find(s[l]) != ori_t.end())
            {
                --cnt_w[s[l]];
            }
            ++l;
        }
    }

    return ansL == -1 ? string() : s.substr(ansL, len);
}