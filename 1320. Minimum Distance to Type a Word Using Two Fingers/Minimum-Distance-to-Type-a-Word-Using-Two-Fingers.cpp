1class Solution {
2public:
3    int dp[301][27][27]; 
4    int dist(int i, int j) {
5        if (i == 26 || j == 26) return 0; 
6        int x = abs(i / 6 - j / 6);
7        int y = abs(i % 6 - j % 6);
8        return x + y;
9    }
10
11    int solve(int i, int j, int k, string& s) {
12        int &ret = dp[i][j][k];
13        if (i == s.size()) return 0;
14        if (ret != -1) return ret;
15        int idx = s[i] - 'A';
16        int path1 = dist(j, idx) + solve(i + 1, idx, k, s);
17        int path2 = dist(k, idx) + solve(i + 1, j, idx, s);
18        return ret = min(path1, path2);
19    }
20
21    int minimumDistance(string s) {
22        memset(dp, -1, sizeof(dp));
23        return solve(0, 26, 26, s); 
24    }
25};