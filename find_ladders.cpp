//单词接龙Ⅱ

/*
    给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

    每次转换只能改变一个字母。
    转换过程中的中间单词必须是字典中的单词。

说明:

    如果不存在这样的转换序列，返回一个空列表。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

    
    分析：
        建图， 寻找beginword 和 endword 之间的最短路径
*/

unordered_map<string, int> _id;
vector<string> _word;
//邻接表
vector<vector<int>> edges;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    int id = 0;

    for (const auto &e : wordList)
    {
        _id[e] = id++;
        _word.push_back(e);
    }

    if (!_id.count(endWord))
    {
        return {};
    }

    if (!_id.count(beginWord))
    {
        _id[beginWord] = id++;
        _word.push_back(beginWord);
    }
    //建表
    edges.resize(id);
    for (int i = 0; i < _word.size(); ++i)
    {
        for (int j = i + 1; j < _word.size(); ++j)
        {
            if (transformCheck(_word[i], _word[j]))
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    const int dest = _id[endWord];
    vector<vector<string>> res;
    queue<vector<int>> q;
    vector<int> cost(id, INT_MAX - 2);
    //将初始节点的所有路径入队
    q.push(vector<int>{_id[beginWord]});
    cost[_id[beginWord]] = 0;

    while (!q.empty())
    {
        vector<int> now = q.front();
        q.pop();
        int last = now.back();

        if (last == dest)
        {
            vector<string> tmp;
            for (int index : now)
            {
                tmp.push_back(_word[index]);
            }
            res.push_back(tmp);
        }
        else
        {
            for (int i = 0; i < edges[last].size(); i++)
            {
                int to = edges[last][i];
                if (cost[last] + 1 <= cost[to])
                {
                    cost[to] = cost[last] + 1;
                    vector<int> tmp(now);
                    tmp.push_back(to);
                    q.push(tmp);
                }
            }
        }
    }
    return res;
}

bool transformCheck(const string &str1, const string &str2)
{
    int differences = 0;
    for (int i = 0; i < str1.size() && differences < 2; i++)
    {
        if (str1[i] != str2[i])
        {
            ++differences;
        }
    }
    return differences == 1;
}