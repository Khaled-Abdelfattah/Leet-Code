1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& v, int target) {
4        int n = v.size(), prfx = n;
5        vector<int> mp(2 * n + 1);
6        mp[n] = 1;
7        long long less = 0, ans = 0;
8        for (int it : v) {
9            if (it == target) less += mp[prfx++];
10            else less -= mp[--prfx];
11            mp[prfx]++;
12            ans += less;
13        }
14        return ans;
15    }
16};