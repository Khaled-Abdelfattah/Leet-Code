1class Solution {
2public:
3    vector<string> letterCombinations(string s) {
4        vector<string> ans;
5
6        if (s.empty()) {
7            return ans;
8        }
9
10        unordered_map<char, string> mp = {
11            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
12            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
13        };
14
15        backtrack(s, 0, "", ans, mp);
16
17        return ans;
18    }
19
20    void backtrack(const string& s, int i, string str, vector<string>& ans,
21                   const unordered_map<char, string>& mp) {
22        if (i == s.size()) {
23            ans.push_back(str);
24            return;
25        }
26
27        string S = mp.at(s[i]);
28        for (char ss : S) {
29            backtrack(s, i + 1, str + ss, ans, mp);
30        }
31    }
32};