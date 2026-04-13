1class Solution {
2public:
3    int getMinDistance(vector<int>& v, int x, int start) {
4        int mn = INT_MAX, n = v.size();
5        for (int i = 0; i < n; i++) {
6            if (v[i] == x) {
7                mn = min(mn, abs(i - start));
8            }
9        }
10        return mn;
11    }
12};