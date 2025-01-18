#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                int cost = grid[x][y] != i + 1;
                if(dp[nx][ny] > dp[x][y] + cost){
                    dp[nx][ny] = dp[x][y] + cost;
                    q.push({nx, ny});
                }
            }
        }
    }
    return dp[n - 1][m - 1];
}