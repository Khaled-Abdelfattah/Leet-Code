1class Solution {
2public:
3    int furthestDistanceFromOrigin(string s) {
4        int cnt_ = 0, cntL = 0, cntR = 0;
5        for (auto c : s) {
6            if (c == '_') cnt_++;
7            else if (c == 'L') cntL++;
8            else cntR++;
9        }
10        return abs(cntR - cntL) + cnt_;
11    }
12};