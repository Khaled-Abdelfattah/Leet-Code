1class Solution {
2public:
3    const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
4    bool containsCycle(vector<vector<char>>& grid) {
5        int n = grid.size();
6        int m = grid[0].size();
7        vector<bool> vis(250005, 0); 
8        auto dfs = [&](this auto&& dfs, int i, int j, int r, int c) -> bool {
9            vis[i * m + j] = 1; 
10            for (int k = 0; k < 4; k++) {         
11                int x = i + dx[k], y = j + dy[k]; 
12                if (x != r || y != c) {
13                    if (x >= 0 && x < n && y >= 0 && y < m) { 
14                        if (grid[x][y] == grid[i][j]) {
15                            if (vis[x * m + y] || dfs(x, y, i, j)) {
16                                return 1;
17                            }
18                        }
19                    }
20                }
21            }
22            return 0;
23        };
24        
25        for (int i = 0; i < n; i++) {
26            for (int j = 0; j < m; j++) {
27                if (!vis[i * m + j] && dfs(i, j, -1, -1)) {
28                    return 1;
29                }
30            }
31        }
32        return 0;
33    }
34};