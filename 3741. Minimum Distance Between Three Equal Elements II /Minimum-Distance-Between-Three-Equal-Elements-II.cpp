1class Solution {
2public:
3    int minimumDistance(vector<int>& v) {
4        unordered_map<int, vector<int>> mp;
5        int n = v.size();
6        for (int i = 0; i < n; i++) {
7            mp[v[i]].push_back(i);
8        }
9        int ans = INT_MAX;
10        for (auto [it, vec] : mp) {
11            int sz = vec.size();
12            if (sz >= 3) {
13                for (int i = 0; i < sz - 2; i++) {
14                    int a = vec[i];
15                    int c = vec[i + 2];
16                    int d = 2 * (c - a);
17                    ans = min(ans, d);
18                }
19            }
20        }
21        return ans == INT_MAX ? -1 : ans;
22    }
23};