class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];

            if(mp.count(prefix - k)){
                cnt += mp[prefix - k];
            }
            mp[prefix]++;
        }
        return cnt;
    }
};