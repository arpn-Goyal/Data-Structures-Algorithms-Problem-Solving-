class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int index = -1;
        int size = nums.size();
        vector<int> prefixSum(size), postfixSum(size);

        prefixSum[0] = 0;
        for(int left = 1; left < nums.size(); left++){
            prefixSum[left] = prefixSum[left - 1] + nums[left - 1];
        }

        postfixSum[size - 1] = 0;
        for(int right = size - 2; right >= 0; right--){
            postfixSum[right] = postfixSum[right + 1] + nums[right + 1];
        }

        for(int i = 0; i < size; i++){
            if(prefixSum[i] == postfixSum[i]){
                return i;
            }
        }
        return -1;
    }
};