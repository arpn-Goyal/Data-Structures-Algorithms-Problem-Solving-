class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Remainder, Index
        // We'll have to instialize with {remainder : 0, at Index : -1}
        // Suppose we get same value at 1 index as K
        mp[0] = -1;
        long long prefixSum = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];

            int remainder = prefixSum % k;
            // Checking if Prefix % k = Same Remainder is there
            // Which means Same Remainder
            // Therefore, when we subtract them(to FInd SubarraySum), 
            // the remainders cancel, leaving a multiple of K.
            if(mp.count(remainder)){
                // checking length must be atleast 2
                if(i - mp[remainder] >= 2){
                    return true;
                }
            }
            // Just put this Remainder in the map
            else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};