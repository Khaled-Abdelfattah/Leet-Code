1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        vector<int> v;
5        for (auto i : grid) {
6            for (auto j : i) {
7                v.push_back(j);
8            }
9        }
10        int start = v[0];
11        for (auto i : v) {
12            if (abs(i - start) % x != 0)
13                return -1;
14        }
15        sort(v.begin(), v.end());
16        int median = v[v.size() / 2];
17        int ans = 0;
18        for (auto i : v) {
19            ans += abs(i - median) / x;
20        }
21        return ans;
22    }
23};