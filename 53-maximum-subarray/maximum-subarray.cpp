class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int largestSum = INT_MIN;
        for(int num : nums){
            sum += num;
            largestSum = max(largestSum, sum);
            if(sum < 0){
                sum = 0;
            }
            
        }
        return largestSum;
    }
};