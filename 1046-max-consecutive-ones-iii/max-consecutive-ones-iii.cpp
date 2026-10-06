class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxCons = 0;
        int countZero = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0)
                countZero++;
            
            if(countZero > k){
                if(nums[left] == 0){
                    countZero--;
                }
                left++;
            }
            maxCons = max(maxCons, right - left + 1);
        }
        return maxCons;
    }
};