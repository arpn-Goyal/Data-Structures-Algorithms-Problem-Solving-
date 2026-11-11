class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;

        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            // We are looking for Minimum Element 
            // So just store min_left if its and move to the next half of the rotated sorted array
            if(nums[left] <= nums[mid]){
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
            // otherwise 
            else if(nums[mid] < nums[right]){
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }
        return ans;
    }
};