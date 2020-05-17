//课程表 II

/*
    现在你总共有 n 门课需要选，记为 0 到 n-1。
    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
    给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
    可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

    分析：
        拓扑排序寻找正确路径
        1.先找到入度为0的结点，入度为0代表不被其他课程所需要，即最后完成的；
        2.删除结点，更新入度；循环；
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ret;
    //保存入度的数组
    vector<int> points(numCourses,0);
    //初始化入度
    for(auto&e : prerequisites)
    {
        ++points[e[1]];
    }

    for(int i=0; i < numCourses; ++i)
    {
        int index = -1;

        //寻找入度为0的结点
        for(int j=0; j<numCourses; ++j)
        {
            //入度为0
            if(points[j] == 0)
            {
                index = j;
                points[j] = -1;
                ret.push_back(j);
                break;
            }
        }

        //存在环
        if(index == -1)
        {
            return {};
        }

        //更新入度的数组
        for(auto&e : prerequisites)
        {
            if(e[0] == index)
            {
                --points[e[1]];
            }
        }
    }
    //保存的为从后先前的顺序，翻转
    reverse(ret.begin(), ret.end());
    return ret;
}