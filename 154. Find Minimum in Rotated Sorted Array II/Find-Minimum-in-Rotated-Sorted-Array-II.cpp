1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        return *min_element(nums.begin(),nums.end());
5    }
6};