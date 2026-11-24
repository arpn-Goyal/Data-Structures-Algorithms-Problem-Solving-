class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            // Find how many missing numbers are there till this index(do same thing for mid)
            int missing = arr[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        // After while loop break,arr[mid] - (mid + 1)
        // Which calculate no of missing numbers for every intergers
        // Low and high will come at opposite Polarity (I don't exactly know how to explain this to interviewrer)
        // Low will come at larger no of missingNumbers > k and high will come at smaller no of missingNumber < k
        // This is what we were looking for to find kth Missing Number
        // What we have done just, we have being calculating no of missingNumbers for each Integer, which is (arr[index] - (index + 1)), Cause index + 1 should have been here
        // And for all these no of MissingNumbers till this index, we applied Binary Search, to find for Kth Missing Number
        // In the end high < k < low
        // To find missing number we can simply apply arr[high] + more => arr[high] + (k - currentMissing) => arr[high] + (k - (arr[high] - (high + 1))) => k + high + 1 => k + low finally
        // Either we can return `high + 1 + k`
        return low + k;
    }
};