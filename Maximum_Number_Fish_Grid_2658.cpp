#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return 0;
    int fish = grid[i][j];
    grid[i][j] = 0; // Mark visited
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto d : dir)
        fish += dfs(i + d[0], j + d[1], grid);
    return fish;
}
int findMaxFish(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), mxFish = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] > 0)
                mxFish = max(mxFish, dfs(i, j, grid));
        }
    }
    return mxFish;
}

int main()
{
    vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};   
    cout << findMaxFish(grid) << endl;
    return 0;
}