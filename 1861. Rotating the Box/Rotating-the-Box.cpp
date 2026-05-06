1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
4        int r = grid.size();
5        int c = grid[0].size();
6        vector<vector<char>> ans(c, vector<char>(r, '.'));
7        for (int i = 0; i < r; i++) {
8            int k = c - 1;
9            for (int j = k; j >= 0; j--) {
10                if (grid[i][j] == '*') {
11                    ans[j][r - i - 1] = '*';
12                    k = j - 1;
13                } else if (grid[i][j] == '#') {
14                    ans[k][r - i - 1] = '#';
15                    k--;
16                }
17            }
18        }
19        return ans;
20    }
21};