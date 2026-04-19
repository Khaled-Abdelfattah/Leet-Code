1class Solution {
2public:
3    int maxDistance(vector<int>& v1, vector<int>& v2) {
4        int n = v1.size(), m = v2.size();
5        int i = 0, j = 0;
6        while (i < n && j < m) {
7            if (v1[i] > v2[j]) {
8                i++;
9            }
10            j++;
11        }
12        return max(0, j - i - 1);
13    }
14};