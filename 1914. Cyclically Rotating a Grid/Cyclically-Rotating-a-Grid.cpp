1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& vv, int k) {
4        int top = 0, left = 0;
5        int bottom = vv.size() - 1, right = vv[0].size() - 1;
6        while (top < bottom && left < right) {
7            int len = bottom - top, wid = right - left;
8            int x = 2 * len + 2 * wid;
9            int r = k % x;
10            while (r--) {
11                int temp = vv[top][left];
12                for (int i = left; i < right; i++) {
13                    vv[top][i] = vv[top][i + 1];
14                }
15                for (int i = top; i < bottom; i++) {
16                    vv[i][right] = vv[i + 1][right];
17                }
18                for (int i = right; i > left; i--) {
19                    vv[bottom][i] = vv[bottom][i - 1];
20                }
21                for (int i = bottom; i > top; i--) {
22                    vv[i][left] = vv[i - 1][left];
23                }
24                vv[top + 1][left] = temp;
25            }
26            top++, left++;
27            bottom--, right--;
28        }
29        return vv;
30    }
31};