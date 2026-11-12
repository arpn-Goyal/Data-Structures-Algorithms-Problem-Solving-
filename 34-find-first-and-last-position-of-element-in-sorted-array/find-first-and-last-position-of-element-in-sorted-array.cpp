class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int leftMost = -1;
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                leftMost = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return leftMost;
    }
    int rightBound(vector<int> &nums, int target){
        int rightMost = -1;
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                rightMost = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        ans[0] = lowerBound(nums, target);
        ans[1] = rightBound(nums, target);

        return ans;
    }
};