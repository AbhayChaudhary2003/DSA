class Solution {
public:
    vector<vector<int>> grid;

    int fun(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1)
            return 1;

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (grid[i][j] != -1)
            return grid[i][j];

        return grid[i][j] = fun(i + 1, j, m, n) 
                          + fun(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n) {
        grid = vector<vector<int>>(m, vector<int>(n, -1));

        return fun(0, 0, m, n);
    }
};
        
   