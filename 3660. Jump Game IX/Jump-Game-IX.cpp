1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prfx(n), sfx(n), ans(n);
6        prfx[0] = nums[0];
7        sfx[n - 1] = nums[n - 1];
8        for (int i = 1; i < n; i++) {
9            prfx[i] = max(prfx[i - 1], nums[i]);
10        }
11        for (int i = n - 2; i >= 0; i--) {
12            sfx[i] = min(sfx[i + 1], nums[i]);
13        }
14        ans[n - 1] = prfx[n - 1];
15        for (int i = n - 2; i >= 0; i--) {
16            if (prfx[i] > sfx[i + 1]) {
17                ans[i] = ans[i + 1];
18            } else {
19                ans[i] = prfx[i];
20            }
21        }
22        return ans;
23    }
24};