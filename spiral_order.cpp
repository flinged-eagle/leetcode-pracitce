//顺时针打印矩阵

/*
    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

    分析：
        顺时针打印矩阵，就是 向右 向下 向左 向上 循环 标记矩阵中已经走过的位置；
*/

static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size() ==0 || matrix[0].size()==0)
    {
        return {};
    }
    int row = matrix.size();
    int col = matrix[0].size();
    int total = row * col;
    vector<vector<bool>> visit(row, vector<bool>(col, false));

    int index = 0;
    int x =0, y = 0;
    vector<int> order(total);

    for(int i=0; i<total; ++i)
    {
        order[i] = matrix[x][y];
        visit[x][y] = true;
        int next_x = x + directions[index][0];
        int next_y = y + directions[index][1];

        if(next_x <0  || next_x >= row || next_y < 0 || next_y >= col || visit[next_x][next_y])
        {
            index = (index + 1) % 4;
        }
        x += directions[index][0];
        y += directions[index][1];
    }

    return order;
}