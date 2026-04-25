1class Solution {
2public:
3    int maxDistance(int side, vector<vector<int>>& vv, int k) {
4        auto flatten = [&](vector<int>& v) -> long long {
5            long long x = v[0], y = v[1];
6            if (y == 0) return x;
7            if (x == side) return side + y;
8            if (y == side) return 3LL * side - x;
9            return 4LL * side - y;
10        };
11        vector<long long> arr;
12        for (auto &v : vv) arr.push_back(flatten(v));
13        sort(arr.begin(), arr.end());
14        int n = arr.size();
15        auto notValid = [&](long long m) {
16            for (int i = 0; i < n; i++) {
17                int j = i, cnt = 1;
18                long long x;
19                while (cnt < k) {
20                    x = arr[j] + m;
21                    int it = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
22                    if (it == n) break;
23                    j = it;
24                    cnt++;
25                    if (m + arr[j] > arr[i] + 4LL * side) {
26                        cnt = 0;
27                        break;
28                    }
29                }
30                if (cnt == k) return false;
31            }
32            return true;
33        };
34        long long l = 0, r = side, ans = 0, m;
35        while (l <= r) {
36            m = (l + r) / 2;
37            if (!notValid(m)) {
38                ans = m;
39                l = m + 1;
40            } else {
41                r = m - 1;
42            }
43        }
44        return (int)ans;
45    }
46};