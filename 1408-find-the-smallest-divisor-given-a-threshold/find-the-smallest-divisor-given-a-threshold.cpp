class Solution {
public: 
    bool possible(int possibleDivisor, vector<int>& nums, int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i]/(double)possibleDivisor);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            high = max(high, nums[i]);
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(mid, nums, threshold)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};