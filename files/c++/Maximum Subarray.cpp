class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum = nums[i] + (sum > 0 ? sum : 0);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};