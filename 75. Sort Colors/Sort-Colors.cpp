1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        vector<int> freq(3);
5        for(int i : nums)
6        {
7            freq[i]++;
8        }
9        nums.clear();
10        for(int i = 0;i<3;i++)
11        {
12            while(freq[i]--)
13            {
14                nums.push_back(i);
15            }
16        }
17    }
18};