//最大正方形

/*
    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其！！面积！！
                                输入: 
                                1 0 1 0 0
                                1 0 1 1 1
                                1 1 1 1 1
                                1 0 0 1 0

                                输出: 4

    分析：
        1.暴力方法：在每个为1的点向，作为左结点，进行向右和向下的延申，进行判断；
        2.动态规划：在每个为1的结点保存，以自己为右下角的矩形的边长；
            递推式的推导，每个结点的值，因为将本身当作右下角节点，为自己上方，左方，左上方结点的最小值 + 1（本身的长度）;
            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
*/

//暴力方法

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size())
    {
        return 0;
    }

    int row = matrix.size();
    int col = matrix[0].size();
    int MaxSize = 0;    //保存最长边长

    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            if(matrix[i][j] == '1')
            {
                if(MaxSize == 0)
                {
                    MaxSize = 1;
                }
                
                int curMaxSize = min(row-i,col-j);      //当前位置可构成的最大三角形的边长
                //结束k循环的标识符
                bool flag = true;
                for(int k=1; k<curMaxSize; ++k)
                {
                    //对角线的判断
                    if(matrix[i+k][j+k] == '0')
                    {
                        break;
                    }
                    //对称判断
                    for(int m=0; m<k; ++m)
                    {
                        if(matrix[i+k][j+m]=='0' || matrix[i+m][j+k] == '0')
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        MaxSize = max(MaxSize, k+1);
                    }else
                    {
                        break;
                    }   
                }
            }
        }
    }
    return MaxSize*MaxSize;
}


//动态规划

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row+1, vector<int>(col+1,0));

    int MaxSize = 0;
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            if(matrix[i][j] == '1')
            {
                dp[i+1][j+1] = min(dp[i][j],min(dp[i+1][j], dp[i][j+1]))+1;
                MaxSize = max(MaxSize, dp[i+1][j+1]);
            }
        }
    }
    return MaxSize*MaxSize;
}