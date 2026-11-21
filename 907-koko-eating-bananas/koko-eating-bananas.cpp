class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }
    long long  calculateTotalHours(int hourly, vector<int> &piles){
        long long totalHrs = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHrs += ceil((double)piles[i]/ (double)hourly);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search on Answer
        // piles = [3,6,7,11], h = 8
        // beacuse we know maximum bananas-per-hour Koko can eat is 11 in this first example.
        // (We can go above 11 for high range, but we know one thing, maximum bananas-per-hour a koko can eat is 11.)
        // if don't need to go beyond 11 right
        // So we know our answer will lie in btw [1, 11] bananas for this example.
        // Now we can definetly apply Binary Search on this range

        int low = 1, high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low)/2;

            long long totalHrs = calculateTotalHours(mid, piles);

            if(totalHrs <= h){
                // acc to problem we have to find minimum no of interger right, so we can go for minimum interger from this mid
                high = mid - 1; 
            }
            else{
                // simply we have to go further 
                low = mid + 1;
            }
        }
        // minimum integer k will be find on low for sure
        return low;
    }
};