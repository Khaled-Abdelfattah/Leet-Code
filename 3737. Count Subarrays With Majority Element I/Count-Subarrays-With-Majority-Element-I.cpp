1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& v, int target) {
4        int n = v.size();
5        vector<int> prfx(n + 1, 0);
6        for (int i = 0; i < n; i++) {
7            prfx[i + 1] = prfx[i] + (v[i] == target ? 1 : -1);
8        }
9        long long ans = 0;
10        for (int i = 0; i < n; i++) {
11            for (int j = i+1; j <= n; j++) {
12                if (prfx[j] - prfx[i] > 0) {
13                    ans++;
14                }
15            }
16        }
17        return ans;
18    }
19};