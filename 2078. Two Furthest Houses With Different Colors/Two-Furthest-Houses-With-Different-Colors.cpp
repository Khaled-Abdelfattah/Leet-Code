1class Solution {
2public:
3    int maxDistance(vector<int>& v) {
4        int n = v.size(), l = -1, r = -1;
5        int indx0 = v[0], indxN = v[n - 1];
6        for (int i = 0; i < n; i++) {
7            int x = v[i];
8            if (indx0 != x) l = max(l, i);
9            if (indxN != x) r = max(r, n - i - 1);
10        }
11        return max(l, r);
12    }
13};