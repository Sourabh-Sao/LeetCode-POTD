#include <bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    unordered_map<int, pair<int, int>> positionMap;
    vector<int> rowCount(rows, cols), colCount(cols, rows);

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            positionMap[mat[r][c]] = {r, c};
        }
    }

    for (int idx = 0; idx < arr.size(); ++idx)
    {
        int val = arr[idx];
        auto pos = positionMap[val];
        int row = pos.first;
        int col = pos.second;

        if (--rowCount[row] == 0 || --colCount[col] == 0)
        {
            return idx;
        }
    }

    return -1;
}

int main(){
    //  mat = [[],[]]
    vector<int>arr={1,3,4,2};
    vector<vector<int>> mat{{1,4},{2,3}};

    cout<<firstCompleteIndex(arr,mat);
    return 0;
}