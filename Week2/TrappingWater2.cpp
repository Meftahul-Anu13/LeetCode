#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int water = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                {
                    pq.push({grid[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int minh=0;
        while (!pq.empty())
        {
            int curh= pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            minh = max(minh, curh);
            pq.pop();
            for (auto &direction : directions)
            {
                int new_row = row + direction.first;
                int new_col = col + direction.second;
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col])
                {
                    visited[new_row][new_col] = true;
                    if (grid[new_row][new_col] < minh)
                    {
                        water += minh - grid[new_row][new_col];
                    }
                    pq.push({grid[new_row][new_col], {new_row, new_col}});
                }
            }


        }

        return water;
    }
};