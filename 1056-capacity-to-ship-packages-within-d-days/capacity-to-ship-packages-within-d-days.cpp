class Solution {
public:
    pair<int, int> findMax(vector<int>& weights) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        return {maxi, sum};
    }
    bool checkThisCapacity(vector<int>& weights, int capacity, int days) {
        int daysNeeded = 1;
        int currentLoad = 0;

        for (int i = 0; i < weights.size(); i++) {

            if (currentLoad + weights[i] > capacity) {
                daysNeeded++;
                currentLoad = weights[i];
            } else {
                currentLoad += weights[i];
            }
        }

        return daysNeeded <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        auto [low, high] = findMax(weights);

        while (low <= high) {
            int mid = (low + high) / 2;

            int capacity = checkThisCapacity(weights, mid, days);
            // then we will look for minimum capacity of ship per day
            if (capacity) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};