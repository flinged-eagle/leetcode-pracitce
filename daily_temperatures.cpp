//每日温度

/*
    根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。
    如果之后都不会升高，请在该位置用 0 来代替。
*/

vector<int> dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && T[i] > T[s.top()])
        {
            int previousIndex = s.top();
            ans[previousIndex] = i - previousIndex;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}