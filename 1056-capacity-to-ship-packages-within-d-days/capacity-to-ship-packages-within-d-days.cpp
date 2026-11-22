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
    int checkThisCapacity(vector<int>& weights, int capacity, int days) {
        int shipCapcaityPerDay = 0;
        int i = 0;
        while (i < weights.size()) {
            shipCapcaityPerDay += weights[i];
            if (shipCapcaityPerDay == capacity) {
                shipCapcaityPerDay = 0;
                days--;
            } else if (shipCapcaityPerDay >= capacity) {
                days--;
                shipCapcaityPerDay = 0;
                i--;
            }
            i++;
        }
        if(shipCapcaityPerDay > 0 && shipCapcaityPerDay < capacity){
            days--;
        }
        return (days >= 0)? true : false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        auto [low, high] = findMax(weights);

        while (low <= high) {
            int mid = (low + high) / 2;

            int capacity = checkThisCapacity(weights, mid, days);
            // then we will look for minimum capacity of ship per day
            if(capacity){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};