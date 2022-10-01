// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0,high = nums.size()-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target)return mid;
            else if(nums[mid] > target)high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};