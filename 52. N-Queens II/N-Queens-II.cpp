1class Solution {
2public:
3    vector<bool> col, diag, diag2;
4    int totalNQueens(int n) {
5        col = vector<bool>(n);
6        diag = vector<bool>(2 * n - 1);
7        diag2 = vector<bool>(2 * n - 1);
8        return rec(0);
9    }
10    int rec(int i) {
11        int n = col.size(), cnt = 0;
12        if (i == n) return 1;
13        for (int j = 0; j < n; j++) {
14            if (!col[j] && !diag[i + j] && !diag2[i - j + n - 1]) {
15                col[j] = diag[i + j] = diag2[i - j + n - 1] = 1;
16                cnt += rec(i + 1);
17                col[j] = diag[i + j] = diag2[i - j + n - 1] = 0;
18            }
19        }
20        return cnt;
21    }
22};