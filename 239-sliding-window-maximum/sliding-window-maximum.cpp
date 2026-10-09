class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0; 
        deque<int> dq;

        for(int right = 0; right < nums.size(); right++){
            // Remove indices outside the window
            if(!dq.empty() && dq.front() <= right - k) 
                dq.pop_front();
            
            // Maintain decreasing order in deque
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }

            dq.push_back(right);

            
            // Add maximum for the current window
            if(right >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};