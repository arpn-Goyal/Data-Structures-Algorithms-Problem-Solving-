class Solution {
public:
    int findMin(vector<int>& bloomDay) {
        int mini = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }
    int findMax(vector<int>& bloomDay) {
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    bool possible(int value, vector<int>& bloomDay, int m, int k){
         int count = 0;
         int bouquets = 0;
         for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= value){
                count++;
            }
            else{
                bouquets += count/k;
                count = 0;  
            }
        }
        // In some cases we might come out of the loop, but we can have actuall no of bouquets formed.
        bouquets += count/k;
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Ofcourse, if no of flowers which are gonna use to make m bouquets are more than size of bloomDays array, then we can't be available to make bouquets for that arr.
        long long val = (long long)m * (long long)k;
        if(val > bloomDay.size())
            return -1;

        int low = findMin(bloomDay), high = findMax(bloomDay);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(mid, bloomDay, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};