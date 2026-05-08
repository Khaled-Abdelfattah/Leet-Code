1class Solution {
2public:
3    int minJumps(vector<int>& v) {
4        int n = v.size();
5        int mx = *max_element(v.begin(), v.end());
6        vector<bool> prime(mx + 1, 1);
7        prime[0] = prime[1] = 0;
8        for (long long i = 2; i <= mx; i++) {
9            if (prime[i]) {
10                for (long long j = i * i; j <= mx; j += i) {
11                    prime[j] = 0;
12                }
13            }
14        }
15        vector<vector<int>> indx(mx + 1);
16        for (int i = 0; i < n; i++) {
17            indx[v[i]].push_back(i);
18        }
19        queue<pair<int, int>> q;
20        q.push({0, 0});
21        vector<bool> vis(n);
22        vis[0] = 1;
23        while (!q.empty()) {
24            auto [i, t] = q.front();
25            q.pop();
26            if (i == n - 1)
27                return t;
28            if (i > 0 && !vis[i - 1]) {
29                q.push({i - 1, t + 1});
30                vis[i - 1] = 1;
31            }
32            if (i < n - 1 && !vis[i + 1]) {
33                q.push({i + 1, t + 1});
34                vis[i + 1] = 1;
35            }
36            if (prime[v[i]]) {
37                int p = v[i];
38                for (int j = p; j <= mx; j+=p) {
39                    for (auto it : indx[j]) {
40                        if (!vis[it]) {
41                            q.push({it, t + 1});
42                            vis[it] = 1;
43                        }
44                    }
45                    indx[j].clear();
46                }
47                prime[p] = 0;
48            }
49        }
50        return n - 1;
51    }
52};