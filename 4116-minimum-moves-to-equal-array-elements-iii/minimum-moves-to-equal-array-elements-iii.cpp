class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;

        for(int val: nums){
            maxi = max(maxi, val);
        }
        int result = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < maxi){
                result += maxi - nums[i];
            }
        }
        return result;
    }
};