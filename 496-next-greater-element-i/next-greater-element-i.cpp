class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums2.size();
        unordered_map<int, int> mp;
        stk.push(nums2[n - 1]);
        for (int left = n - 1; left >= 0; left--) {
            while (!stk.empty() && stk.top() <= nums2[left]) {
                stk.pop();
            }
            if (!stk.empty()) {
                mp[nums2[left]] = stk.top();
            }
            stk.push(nums2[left]);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back(mp[num] ? mp[num] : -1);
        }
        return res;
    }
};